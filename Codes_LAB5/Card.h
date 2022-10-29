#include <iostream>
using namespace std;
#include <cassert> //for assert()
#include <string>

enum color { club, diamond, heart, spade };

class Card {
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();
private:
    color col;
    int val;
};

/*Constructor*/
Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    //which indicates an error message if the expression is false.
    col = c;
    val = v;
}
void Card::write() {
    string cardName;
    switch (val) {
    case 1:
        cardName = "Ace";
        break;
    case 11:
        cardName = "Jack";
        break;
    case 12:
        cardName = "Queen";
        break;
    case 13:
        cardName = "King";
        break;
    default:
        cardName = to_string(val);
        break;
    }
    switch (col) {
    case 0:
        cout << cardName << " of " << "clubs";
        break;
    case 1:
        cout << cardName << " of " << "diamonds";
        break;
    case 2:
        cout << cardName << " of " << "hearts";
        break;
    case 3:
        cout << cardName << " of " << "spades";
        break;
    }
}