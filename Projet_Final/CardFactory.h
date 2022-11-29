#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include <algorithm>


using namespace std;

class CardFactory {
    CardFactory();
public:
    vector<Card*> cards;
    static CardFactory* getFactory();
    Deck getDeck();
    
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
        cards.push_back(new green);
    }

    for (int i = 0; i < 12; i++) {
        cards.push_back(new soy);
    }

    for (int i = 0; i < 10; i++) {
        cards.push_back(new Black);
    }

    for (int i = 0; i < 8; i++) {
        cards.push_back(new red);
    }

    for (int i = 0; i < 6; i++) {
        cards.push_back(new garde);
    }
}

CardFactory* CardFactory::getFactory() {
    static CardFactory cards;
    return &cards;
}

Deck CardFactory::getDeck() {
    Deck deck(in, this); //isteam??
    return deck;
}