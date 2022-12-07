
#pragma once
#include <iostream>
#include <vector>
using namespace std;


void main() {
	Boolean game = true;
	char save;
	string gagnant;

	while (game) {
		//setup
		cout << "Voulez-vous commenzer une nouvelle partie ? (o ou n)";
		cin >> save >> endl;
		//input players, initialization of deck, draw 5 cards from each hand
		if (save == 'o') {
			game = false;
			string joueur1, joureur2;
			cout << "Veuillez inserer le nom du premier joueur: " << endl;
			cin >> joueur1;
			cout << "Veuillez inserer le nom du deuxieme joueur: " << endl;
			cin >> joueur2;
			Table* table = new Table(joueur1, joueur2);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 5; j++) {
					table.players[i] += table->deck->draw();
					//table->players.get(i) += table->deck->draw();
				}
			}
		}
		//load paused game
		else {
			CardFactory* factory = CardFactory::getFactory();
			ifstream saved("Bohnanza.txt");
			if (saved.is_open()) {
				game = false;
				Table* table = new Table(saved, factory);
				return table;
			}
			else
				cout << "Il n'y a aucune partie sauvegardee" << endl;
		}
	}

	//while there are still cards
	while (!table->win(gagnant)) {
		cout << "Voulez-vous sauver le jeu et quitter? (o ou n)"<<endl;
		char reponse;
		cin >> reponse;
		//if pause save game to file
		if (reponse == 'o') {
			ofstream save("Bohnanza.txt");
			if (save) {
				table.players[0].print(save);
				table.players[1].print(save);
				(*table.discard).print(save);
				save << "\n" << *table.ta;
				save << "\n" << *table.deck << endl;
				save.close();
			}
			return;
		}
		else {
			//for each player
			for (int i = 0; i < 2; i++) {
				Player& joueur = table.players[i];
				//display table
				cout << *table << "\n";
				cout << "Votre main: " << *joueur.getHand() << endl;
				//player draws top card
				joueur += table->deck->draw();
				//if trade area is not empty
				if (!table->ta->empty()) {
					char reponse;
					int i = 0;
					bool jeter=true;

					while (i < table->ta->cardTypes.size()) {
						string sorte = table->ta->getCardType(i);
						cout << *table << "\n";
						cout << "Voulez-vous ajouter les cartes de la sorte " << sorte << " ? (o ou n) " << endl;
						cin >> reponse;
						if (reponse == 'o') {
							Card* carte = table->ta->trade(sorte);
							while (carte != nullptr) {
								//Add to correct chain.
								if (joueur.addToChain(carte)) {
									carte = table->ta->trade(sorte);
								}
								else {
									bool next = false;
									bool echanger = true;
									bool possible =true;
									char reponse = ' ';
									if (joueur.getMaxNumChains() < 3) {
										cout << "Voulez-vous acheter une nouvelle chaine? (o ou n) ";
										cin >> reponse;
										if (reponse == 'o') {
											try {
												joueur.buyThirdChain();
												echanger = false;
												next = true;
											}
											catch (NotEnoughCoins e) {
												cout << "Vous n'avez pas assez d'argent pour acheter une nouvelle chaine." << "\n";
											}
										}
									}
									if (echanger) {
										if (possible) {
											cout << "Voulez-vous echanger l'une de vos chaine? (y/n) ";
											cin >> reponse;
										}
										else {
											cout << "Veuillez vendre une chaine pour la remplacer.\n" << endl;
										}
										if (reponse == 'o' || !possible) {
											next = true;
											bool valid=false;
											int chaine;
											for (int i = 0; i < joueur.getNumChains(); i++)
												cout <<"Chaine " i + 1 << " de type " << joueur[i] << endl;
											while (!valid) {
												cout << endl << "Veuillez entrer le numero de la chaine que vous voulez echanger : ";
												cin >> chaine;
												if (!(0 < chaine && chaine <= joueur.getNumChains())) {
													cout << "Le numero est invalide. ";
													valid = false;
												}
											}
											chaine--;
											joueur.sellChain(chaine);
										}
									}

									if (!next) {
										carte = nullptr;
										i++;
									}
								}

							}
							i--;
						}	
						else if (jeter) {
							Card* carte = table->ta->trade(sorte);
							while (carte) {
								(*table->discard) += carte;
								carte = table->ta->trade(sorte);
							}
							cout <<"Le type "<< sorte << " a ete mis dans la pile au rebut " << endl << endl;
							i--;

						}
						i++;
					}


					cout << *table << "\n";
				}
				else {
					cout << *table << "\n";
					cout << "Votre main: " << *joueur.getHand() << endl;
				}




				cout << "Jeu de la premiere carte de votre main: " << joueur.getHand()->top() << "\n";
				bool continue = true;
				while (continue) {
					Card* topcard = joueur.getHand()->play();
					if (joueur.addToChain(topcard)) {
						for (int i = 0; i < joueur.getNumChains(); i++) {
							if (joueur[i].sell() > 0) {
								joueur.sellChain(i);
								cout << "Chaine vendue" << endl;
								cout << *table << "\n";
							}
						}
					}

					else {
						bool next = false;
						bool echanger = true;
						bool possible = true;
						char reponse = ' ';
						if (joueur.getMaxNumChains() < 3) {
							cout << "Voulez-vous acheter une nouvelle chaine? (o ou n) ";
							cin >> reponse;
							if (reponse == 'o') {
								try {
									joueur.buyThirdChain();
									echanger = false;
									next = true;
								}
								catch (NotEnoughCoins e) {
									cout << "Vous n'avez pas assez d'argent pour acheter une nouvelle chaine." << "\n";
								}
							}
						}
						if (echanger) {
							if (possible) {
								cout << "Voulez-vous echanger l'une de vos chaine? (y/n) ";
								cin >> reponse;
							}
							else {
								cout << "Veuillez vendre une chaine pour la remplacer.\n" << endl;
							}
							if (reponse == 'o' || !possible) {
								next = true;
								bool valid = false;
								int chaine;
								for (int i = 0; i < joueur.getNumChains(); i++)
									cout << "Chaine " i + 1 << " de type " << joueur[i] << endl;
								while (!valid) {
									cout << endl << "Veuillez entrer le numero de la chaine que vous voulez echanger : ";
									cin >> chaine;
									valid = true;
									if (!(0 < chaine && chaine <= joueur.getNumChains())) {
										cout << "Le numero est invalide. ";
										valid = false;
									}
								}
								chaine--;
								joueur.sellChain(chaine);
							}
						}
						joueur.addToChain(topcard);

					}
					//if (joueur.getHand()->size() == 0)
						//continue = false;

					if (joueur.getHand()->size() > 0) {
						cout << joueur << endl;
						cout << "Votre main: " << *joueur.getHand() << endl;
						cout << "Voulez-vous jouer une deuxieme carte? " << joueur.getHand()->top() << " (o ou n) ";
						cin >> reponse;
						if (reponse == 'n' || (joueur.getHand()->size() == 0))
							continue = false;
					}

					if (joueur.getHand()->size() > 0) {
						//discard an arbitrairy card from the players hand
						cout << player << endl << "Votre main: " << *joueur.getHand() << "\n";
						cout << "Voulez-vous jeter une carte arbitraire? (o ou n) ";
						cin >> reponse;
						if (reponse == 'o') {
							cout << endl << *joueur.getHand() << "\n";
							//for (int i = 1; i <= joueur.getHand()->size(); i++) {
								//cout << i;
							//}
							//cout << endl << endl;
							bool valid = false;
							int position;
							while (!valid) {
								cout << "Veuillez indiquer la position de la carte a jeter: ";
								cin >> reponse;
								valid = true;
								position = reponse - '0';
								if (!(position <= joueur.getHand()->size() && 0 < position)) {
									cout << "Le numero est invalide. " << endl;
									valid = false;
								}
							}
							(*table->discard) += (*joueur.getHand())[position];
						}
					}
					//draw three cards from the deck and place in trade area
					for (int i = 0; i < 3; i++) {
						(*table->ta) += table->deck->draw();
					}
					while (!(table->discard->isEmpty()) && table->ta->legal(table->discard->top())) {
						(*table->ta) += table->discard->pickUp();
					}

					char reponse;
					int i = 0;
					bool jeter = false;

					while (i < table->ta->cardTypes.size()) {
						string sorte = table->ta->getCardType(i);
						cout << *table << "\n";
						cout << "Voulez-vous ajouter les cartes de la sorte " << sorte << " ? (o ou n) " << endl;
						cin >> reponse;
						if (reponse == 'o') {
							Card* carte = table->ta->trade(sorte);
							while (carte != nullptr) {
								//Add to correct chain.
								if (joueur.addToChain(carte)) {
									carte = table->ta->trade(sorte);
								}
								else {
									bool next = false;
									bool echanger = true;
									bool possible = true;
									char reponse = ' ';
									if (joueur.getMaxNumChains() < 3) {
										cout << "Voulez-vous acheter une nouvelle chaine? (o ou n) ";
										cin >> reponse;
										if (reponse == 'o') {
											try {
												joueur.buyThirdChain();
												echanger = false;
												next = true;
											}
											catch (NotEnoughCoins e) {
												cout << "Vous n'avez pas assez d'argent pour acheter une nouvelle chaine." << "\n";
											}
										}
									}
									if (echanger) {
										if (possible) {
											cout << "Voulez-vous echanger l'une de vos chaine? (y/n) ";
											cin >> reponse;
										}
										else {
											cout << "Veuillez vendre une chaine pour la remplacer.\n" << endl;
										}
										if (reponse == 'o' || !possible) {
											next = true;
											bool valid = false;
											int chaine;
											for (int i = 0; i < joueur.getNumChains(); i++)
												cout << "Chaine " i + 1 << " de type " << joueur[i] << endl;
											while (!valid) {
												cout << endl << "Veuillez entrer le numero de la chaine que vous voulez echanger : ";
												cin >> chaine;
												if (!(0 < chaine && chaine <= joueur.getNumChains())) {
													cout << "Le numero est invalide. ";
													valid = false;
												}
											}
											chaine--;
											joueur.sellChain(chaine);
										}
									}

									if (!next) {
										carte = nullptr;
										i++;
									}
								}

							}
							i--;
						}
						else if (jeter) {
							Card* carte = table->ta->trade(sorte);
							while (carte) {
								(*table->discard) += carte;
								carte = table->ta->trade(sorte);
							}
							cout << "Le type " << sorte << " a ete mis dans la pile au rebut " << endl << endl;
							i--;

						}
						i++;
					}
					for (int i = 0; i < 2; i++)
						joueur += table->deck->draw();
				}
			}
		}
		catch (DeckEmpty d) {
			if (table->win(gagnant)) {
				cout <<  winner << " est le gagnant de la partie"<endl;
				remove("Bohnanza.txt"); 
				//cout << endl << endl;
				system("pause");
				return ;
			}
		}
	}
	cout << winner << " est le gagnant de la partie" < endl;
	remove("Bohnanza.txt");
	//cout << endl << endl;
	system("pause");
	return;
}
	
	
