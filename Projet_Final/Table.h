#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"
#include "DiscardPile.h"
#include "Player.h"
#include "TradeArea.h"

using std::vector;

class Table {
    vector<Player> players;
    Deck* deck;
    DiscardPile* discard;
    TradeArea* ta;
public:
    bool win(string&);
    void printHand(bool);
    friend ostream& operator << (ostream&, Table);
    Table(istream&, const CardFactory*);
};

bool Table::win(string& name)
{
	if (players[0].getNumCoins() > players[1].getNumCoins())
		name = players[0].getName();
	else
		name = players[1].getName();
	return deck.last();
}

Table::Table(istream& in, CardFactory* cardFactory)
{
	Player* player1 = new Player(in, cardFactory);
	Player* player2 = new Player(in, cardFactory);

	players.push_back(*player1);
	players.push_back(*player2);

	discard = new DiscardPile(in, cardFactory);
	ta = new TradeArea(in, cardFactory);
	deck = new Deck(in, cardFactory);

}
void Table::printHand(bool affiche) {

	players[0].printHand(affiche);
	players[1].printHand(affiche);
}

ostream& operator<<(ostream& out, Table t)
{
	out << "------Table------\n";
	for (Player player : t.players) {
		out << player << "\n";
	}
	out << "Top of discard pile:\n" << *t.discard << "\n" << "Trading area:\n" << *t.ta << "\n";
	out << "-----------------\n";

	return out;
}
