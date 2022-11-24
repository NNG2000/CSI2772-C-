
#include <iostream>
#include <iostream>
using namespace std;
#include <cassert> //for assert()
#include <string.h>

enum color { club, diamond, heart, spade };

class Card
{
public: virtual string getName();
public: virtual int getCardsPerCoin(int coins);
public: virtual void print(ostream& out);
public: friend ostream& operator << (ostream&, Card&);
      //private : string name;

};

ostream& operator << (ostream& affiche, Card& myCard) {
    myCard.print(affiche);
    return affiche;
};

class Blue : virtual public Card {
    const int  maxCard = 20;
    string name = "Blue";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 4;
        break;
    case 2:
        numberCards = 6;
        break;
    case 3:
        numberCards = 8;
        break;
    case 4:
        numberCards = 10;
        break;
    default:
        return 0;
    }

    return numberCards;

}
public: string getName() {
    return name;
}
public: void print(ostream& out) {
    char id = 'B';
    out.put(id);
}

};

class Chili : virtual public Card {
    const int maxCard = 18;
    string name = "Chili";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 3;
        break;
    case 2:
        numberCards = 6;
        break;
    case 3:
        numberCards = 8;
        break;
    case 4:
        numberCards = 9;
        break;
    default:
        return 0;

    }

    return numberCards;

}
public: string getName() {
    return name;
}
public: void print(ostream& out) {
    char id = 'C';
    out.put(id);
}

};

class Stink : virtual public Card {
    const int maxCard = 16;
    string name = "Stink";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 3;
        break;
    case 2:
        numberCards = 5;
        break;
    case 3:
        numberCards = 7;
        break;
    case 4:
        numberCards = 8;
        break;
    default:
        return 0;
    }

    return numberCards;

}
public: string getName() {
    return name;
}
public: void print(ostream& out) {
    char id = 'S';
    out.put(id);
}
};

class green : virtual public Card {
    const int maxCard = 14;
    string name = "Green";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 3;
        break;
    case 2:
        numberCards = 5;
        break;
    case 3:
        numberCards = 6;
        break;
    case 4:
        numberCards = 7;
        break;
    default:
        return 0;

    }

    return numberCards;

}

public: string getName() {
    return name;
}

public: void print(ostream& out) {
    char id = 'G';
    out.put(id);
}

};

class soy : virtual public Card {
    const int maxCard = 12;
    string name = "Soy";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 2;
        break;
    case 2:
        numberCards = 4;
        break;
    case 3:
        numberCards = 6;
        break;
    case 4:
        numberCards = 7;
        break;
    default:
        return 0;
    }

    return numberCards;
}

public: string getName() {
    return name;
}

public: void print(ostream& out) {
    char id = 'S';
    out.put(id);
}

};

class Black : virtual public Card {
    const int maxCard = 10;
    string name = "Black";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 2;
        break;
    case 2:
        numberCards = 4;
        break;
    case 3:
        numberCards = 5;
        break;
    case 4:
        numberCards = 6;
        break;
    default:
        return 0;

    }

    return numberCards;

}

public: string getName() {
    return name;
}

public: void print(ostream& out) {
    char id = 'B';
    out.put(id);
}

};

class red : virtual public Card {
    const int maxCard = 8;
    string name = "Red";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 1:
        numberCards = 2;
        break;
    case 2:
        numberCards = 3;
        break;
    case 3:
        numberCards = 4;
        break;
    case 4:
        numberCards = 5;
        break;

    default:
        return 0;
    }

    return numberCards;
}

public: string getName() {
    return name;
}

public: void print(ostream& out) {
    char id = 'R';
    out.put(id);
}
};

class garde : virtual public Card {
    const int maxCard = 6;
    string name = "Garde";
private: string cardList[20] = { name };
public: int getCardsPerCoin(int coins) {
    int numberCards = 0;
    switch (coins) {
    case 2:
        numberCards = 2;
        break;
    case 3:
        numberCards = 3;
        break;
    default:
        return 0;
    }

    return numberCards;

}

public: string getName() {
    return name;
}

public: void print(ostream& out) {
    char id = 'G';
    out.put(id);
}

};
