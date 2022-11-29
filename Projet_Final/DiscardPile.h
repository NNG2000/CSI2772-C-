#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"

using std::vector;

class DiscardPile {
private:
    vector<Card*> discardCards;
public:
    DiscardPile(istream&, const CardFactory*);
    DiscardPile& operator+=(Card*);
    void print(std::ostream&);
    void printTop(std::ostream&);
    Card* pickup();
    Card* top();

};

DiscardPile::DiscardPile(istream& in, const CardFactory* cardFactory) { //istream??
    //discardCards = cardFactory->cards;
}

DiscardPile& DiscardPile::operator+=(Card* card) {
    discardCards.push_back(card);
    return *this;
}

void DiscardPile::print(std::ostream& insert) {
    for (int i = 0; i < discardCards.size(); ++i) {
        insert << discardCards[i];
    }
}

void DiscardPile::printTop(std::ostream& insert) {
    insert << discardCards[discardCards.size()-1];
}

Card* DiscardPile::pickup() {
    if (discardCards.size() == 0)
        return nullptr;
    Card* carteSup = discardCards.back();
    discardCards.pop_back();
    return carteSup;
}

Card* DiscardPile::top() {
    if (discardCards.size() == 0)
        return nullptr;
    Card* carteSup = discardCards.back();
    return carteSup;
}