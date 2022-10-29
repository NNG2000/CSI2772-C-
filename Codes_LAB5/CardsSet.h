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
    srand(time_t(0));
    int nc = number;
    Card *secondset=new Card[nc];
    int *num=new int[nc];
    for (int n = 0; n < nc; n++)
        num[n] = n;
    random_shuffle(num, num + nc);

    for (int i = 0; i < nc; i++)
        secondset[i] = set[num[i]];

    for (int i = 0; i < nc; i++) {
        set[i] = secondset[i];
    }
}

Card CardsSet::take() {
    return set[--number];
}

void CardsSet::put(Card k) {
    if (number < 52)
        set[number++] = k;
}

Card CardsSet::lookIn(int no) {
    if (no > number)
        return set[0];
    int position = number - no;
    return set[position];

}