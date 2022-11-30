#include "CardFactory.h"

class Hand : public vector<Card*> {
	std::vector<Card*> myHand;
public:
	Hand() {};								//default constructor
	Hand& operator+=(Card*);				//adds the card to the rear of the hand.
	Card* play();							//returns and removes the top card from the player's hand
	Card* top();							//returns but does not remove the top card from the player's hand.
	Card* operator[](int);					//returns and removes the Card at a given index.
	Hand(istream&, const CardFactory*);
	friend ostream& operator << (ostream&, Hand);
	void print(std::ostream& out); // to print the hand

};


Hand& Hand::operator+=(Card* card) {
    myHand.push_back(card);
    return *this;
}

Card* Hand::play() {
    Card* cardPtr = nullptr;

    if (!myHand.empty()) {
        cardPtr = myHand.front();
        myHand.pop_back();
    }

    return cardPtr;
}

Card* Hand::top() {
    return myHand.front();
}

Card* Hand::operator[](int index) {
    Card* cardPtr = nullptr;
    if (!myHand.empty()) {
        cardPtr = myHand.at(index);
        myHand.erase(myHand.begin() + index); //to remove the card at the index inside the hand
    }
    return cardPtr;
}


Hand::Hand(std::istream& input, const CardFactory*) {
}

void Hand::print(std::ostream& out) {
    out << "Hand: [ ";
    for (auto& cards : myHand) {
        cards->print(out);
        std::cout << ", ";
    }
    out << "]" << std::endl;
}

ostream& operator<<(ostream& out, Hand h)
{
    for (vector<Card*>::reverse_iterator it = h.rbegin(); it != h.rend(); it++) {
        out << (*it);
    }
    return out;
}