#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

#include <algorithm>
using namespace std;

class CardFactory;

class Deck {
    vector<Card*> cardDeck;
public:
    Deck(istream&, const CardFactory*);
    Card* draw();

    void insertion(ostream&);

    Deck(const CardFactory*);
    //friend ostream& operator << (ostream&, Deck);

    //vector<Card*>& operator = (Card* card);
    
};

Deck::Deck(istream& in, const CardFactory* cardFactory) { //isteam??
    vector<Card*> tCardDeck;
    char cardType[104];
    in.getline(cardType, 104);
    int i = 0;
    while (cardType[i] != NULL) {
        Card* newCard = NULL;
        if (cardType[i] == 'B') {
            newCard = new Blue();
        }
        else if (cardType[i] == 'C') {
            newCard = new Chili();
        }
        else if (cardType[i] == 'S') {
            newCard = new Stink();
        }
        else if (cardType[i] == 'G') {
            newCard = new Green();
        }
        else if (cardType[i] == 's') {
            newCard = new soy();
        }
        else if (cardType[i] == 'b') {
            newCard = new black();
        }
        else if (cardType[i] == 'R') {
            newCard = new Red();
        }
        else if (cardType[i] == 'g') {
            newCard = new garden();
        }
        tCardDeck.push_back(newCard);
        i++;
    }
    cardDeck  = tCardDeck;
    std::random_shuffle(cardDeck.begin(), cardDeck.end());
    //cardDeck = cardFactory->cards;
}

/*
vector<Card*>& Deck:: operator = (vector<Card*> cardDeck){

        for (int i=0; i<cardDeck.size(); ++i){
            this.push_back(cardDeck[i]);
        }

    return *this;
    }
*/

Deck::Deck(const CardFactory* cardFactory)
{
    cardDeck = cardFactory->cards;
    std::random_shuffle(cardDeck.begin(), cardDeck.end());
}

Card* Deck::draw() {
    if (cardDeck.size() == 0)
        return nullptr;
    Card* carteSup = cardDeck.back();
    cardDeck.pop_back();
    return carteSup;
}

void Deck::insertion(ostream& insert) {
    for (int i = 0; i < cardDeck.size(); ++i) {
        insert << cardDeck[i];
    }
}


// implémentation de la classe CardFactory

class Deck;

class CardFactory {
    CardFactory();
public:
    vector<Card*> cards;
    static CardFactory* getFactory();
    Deck getDeck();
    Card* getCard(char) const;
    
};

CardFactory::CardFactory() {
    for (int i = 0; i < 20; i++) {
        cards.push_back(new Blue);
    }

    for (int i = 0; i < 18; i++) {
        cards.push_back(new Chili);
    }

    for (int i = 0; i < 16; i++) {
        cards.push_back(new Stink);
    }

    for (int i = 0; i < 14; i++) {
        cards.push_back(new Green);
    }

    for (int i = 0; i < 12; i++) {
        cards.push_back(new soy);
    }

    for (int i = 0; i < 10; i++) {
        cards.push_back(new black);
    }

    for (int i = 0; i < 8; i++) {
        cards.push_back(new Red);
    }

    for (int i = 0; i < 6; i++) {
        cards.push_back(new garden);
    }
}

CardFactory* CardFactory::getFactory() {
    static CardFactory cards;
    return &cards;
}

Deck CardFactory::getDeck() {

    Deck deck(this); //isteam??
    return deck;
}

Card* CardFactory::getCard(char type) const {  //used when we create Deck
    Card* newCard = NULL;

    if (type == 'B') {
        newCard = new Blue();
    }
    else if (type == 'C') {
        newCard = new Chili();
    }
    else if (type == 'S') {
        newCard = new Stink();
    }
    else if (type == 'G') {
        newCard = new Green();
    }
    else if (type == 's') {
        newCard = new soy();
    }
    else if (type == 'b') {
        newCard = new black();
    }
    else if (type == 'R') {
        newCard = new Red();
    }
    else if (type == 'g') {
        newCard = new garden();
    }

    return newCard;

}