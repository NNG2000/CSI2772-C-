#include <iostream>
using namespace std;
#include <cassert> //for assert()
#include <string.h>

enum color { club, diamond, heart, spade };

class Card
{   
    public virtual string getName();
    public virtual int getCardsPerCoin(int coins);
    public virtual void print(ostream& out);
    private string name;
    int point;


};

class Blue : public virtual card {
    const maxCard = 20;
    name = "Blue";
    private string[20] = {name};
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 4;
            break;
        case 2:
            return 6;
            break;
        case 3:
            return 8;
            break;
        case 4:
            return 10;
            break;
        default:
            return 0;
        }

    }
    public string getName() {
        return name;
    }

};

class Chili : public virtual card {
    const maxCard = 18;
    name = "Chili";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 3;
            break;
        case 2:
            return 6;
            break;
        case 3:
            return 8;
            break;
        case 4:
            return 9;
            break;
        default:
            return 0;

        }

    }
    public string getName() {
        return name;
    }

};

class Stink : public virtual card {
    const maxCard = 16;
    name = "Stink";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 3;
            break;
        case 2:
            return 5;
            break;
        case 3:
            return 7;
            break;
        case 4:
            return 8;
            break;
        default:
            return 0;

        }

    }
    public string getName() {
        return name;
    }
};

class green : public virtual card {
    const maxCard = 14;
    name = "Green";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 3;
            break;
        case 2:
            return 5;
            break;
        case 3:
            return 6;
            break;
        case 4:
            return 7;
            break;
        default:
            return 0;

        }

    }
    public string getName() {
        return name;
    }

};

class soy : public virtual card {
    const maxCard = 12;
    name = "Soy";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 2;
            break;
        case 2:
            return 4;
            break;
        case 3:
            return 6;
            break;
        case 4:
            return 7;
            break;
        default:
            return 0;

        }

    }
    public string getName() {
        return name;
    }

};

class Black : public virtual card {
    const maxCard = 10;
    name = "Black";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 2;
            break;
        case 2:
            return 4;
            break;
        case 3:
            return 5;
            break;
        case 4:
            return 6;
            break;
        default:
            return 0;

        }

    }
    public string getName() {
        return name;
    }

};

class red : public virtual card {
    const maxCard = 8;
    name = "Red";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 1:
            return 2;
            break;
        case 2:
            return 3;
            break;
        case 3:
            return 4;
            break;
        case 4:
            return 5;
            break;

        }
        default:
            return 0;

    }
    public string getName() {
        return name;
    }
};

class garde : public virtual card {
    const maxCard = 6;
    name = "Garde";
    private string[20] = { name };
    public int getCardsPerCoin(int coins) {
        switch (coins) {
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;

        }
        default:
            return 0;

    }
    public string getName() {
        return name;
    }

};



