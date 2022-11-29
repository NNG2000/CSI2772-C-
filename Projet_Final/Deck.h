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

};

Deck::Deck(istream& in, const CardFactory* cardFactory) { //isteam??
    std::random_shuffle(cardDeck.begin(), cardDeck.end());
    cardDeck = cardFactory->cards;
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
