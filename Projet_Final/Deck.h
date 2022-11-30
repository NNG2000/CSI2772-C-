#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"
#include <algorithm>

class Deck {
    vector<Card*> cardDeck;
public:
    Deck(istream&, const CardFactory*);
    Card* draw();

    void insertion(ostream&);

    Deck(const CardFactory*);
    //friend ostream& operator << (ostream&, Deck);
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
    cardDeck = tCardDeck;
    std::random_shuffle(cardDeck.begin(), cardDeck.end());
    //cardDeck = cardFactory->cards;
}

Deck::Deck(const CardFactory* cardFactory)
{
    cardDeck = cardFactory->cards;
    std::random_shuffle(cardDeck.begin(), cardDeck.end());
}

Card* Deck::draw() {
    if (cardDeck.size() == 0)
        return nullptr;
    Card* carteSup=cardDeck.back();
    cardDeck.pop_back();
    return carteSup;
}

void Deck::insertion(ostream& insert) {
    for (int i = 0; i < cardDeck.size(); ++i) {
        insert<<cardDeck[i];
    }
}
