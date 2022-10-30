using namespace std;
class Player {
public:
    Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer
    (isComputer) {}
    int play();
private:
    CardsSet inHand;
    CardsSet& packet;
    const bool computer;
    int countPoints();
};

int Player::play() {
    char answer[3];
    bool pick= true;
    if (!computer) {
        cout << "Do you want to pick a card : " << endl;
        cin >> answer;
        pick = answer[0] == 'y';
        while (pick) {
            int points;
            inHand.put(packet.take());
            points = countPoints();
            cout << "your points are: " << points << endl;
            cout << "Do you want to pick a card : " << endl;
            cin >> answer;
            pick = answer[0] == 'y';
        }
    }
    else {
        int point;
        inHand.put(packet.take());
        point = countPoints();
        while (point <= 19) {
            inHand.put(packet.take());
            point = countPoints();
        }
    }
    return countPoints();
}

int Player::countPoints() {
    int numcards = inHand.numCards();
    int points = 0;
    for (int i = 0; i < numcards; i++) {
        points += inHand.lookIn(i).value();
    }
    while (points <= 8) {
        for (int i = 0; i < numcards; i++) {
            if (inHand.lookIn(i).value() == 1)
                points += 13;
        }
    }
    return points;

}

