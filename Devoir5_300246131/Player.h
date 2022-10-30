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
    if (packet.numCards() == 51) {
        Card card = packet.lookIn(0);
        inHand.empty();
        inHand.put(card);
    }
   
    char answer[3];
    bool pick= true;
    if (!computer) {
        cout << "You get Card: ";
        inHand.lookIn(1).write(); cout << endl;
        int points = countPoints();
        cout << endl<<"Your score is " << points << " points" << endl;
        cout << "Any additional Card ? ";
        cin >> answer;
        pick = answer[0] == 'y';
        while (pick) {
            inHand.put(packet.take());
            cout << "You get Card: ";
            packet.lookIn(0).write(); cout << endl;
            points = countPoints();
            cout << endl<<"Your score is " << points << " points"<<endl;
            if (countPoints() < 21) {
                cout << "Any additional Card ? ";
                cin >> answer;
                pick = answer[0] == 'y';
            }
            else
                pick = false;
        }
    }
    else {
        int point;
        inHand.empty();
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
        points += inHand.lookIn(numcards-i).value();
    }
    for (int i = 0; i < numcards; i++) {
        if (inHand.lookIn(numcards-i).value() == 1 && points<8)
            points += 13;
    }
    return points;

}

