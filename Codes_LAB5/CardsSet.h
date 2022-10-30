#include "myFile.h"

class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }
private:
    Card set[52];
    int number;
};

void CardsSet::novSet() {
    int s = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            set[s] = Card(static_cast<color>(i), j);
            s++;
        }
    }
    number = 52;
}

void CardsSet::shuffle() {
    srand(time(0));
    random_shuffle(set, set + number);
    
}
    

Card CardsSet::take() {
    number--;
    return set[number];
}

void CardsSet::put(Card k) {
    if (number < 52)
        set[number] = k;
    number++;
}

Card CardsSet::lookIn(int no) {
    if (no > number)
        return set[0];
    int position = number - no;
    return set[position];
}

