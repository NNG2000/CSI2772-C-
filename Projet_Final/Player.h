#include <string>
#include <iostream>
#include "CardFactory.h"
#include <exception>
#include "Chain.h"
#include "Hand.h"

using namespace std;

//class Exception create in case the the indexe is out of box or the coins are not enough
class ChainDoesntExist : public exception
{
	virtual const char* what() const throw()
	{
		return "Chain index is out of bounds";
	}
};

class NotEnoughCoins : public exception
{
	virtual const char* what() const throw()
	{
		return "Not enough coins to buy a third chain";
	}

	friend ostream& operator << (ostream& out, NotEnoughCoins e) {
		out << e.what();
		return out;
	}

};

//Container of max size 3, for the chains.
class ChainContainer {
	int n;
	ChainBase* chain1;
	ChainBase* chain2;
	ChainBase* chain3;

public: ChainContainer() {
		n = 0;
		chain1 = NULL;
		chain2 = NULL;
		chain3 = NULL;
	};

	ChainBase& operator[](int i) {
		if (0 <= i && i < n) {
			if (i == 0)
				return *chain1;
			if (i == 1)
				return *chain2;
			return *chain3;
		}
		else
			throw ChainDoesntExist();
	};

	ChainBase& back() {
		return (*this)[n - 1];
	};

	bool addChain(ChainBase* chain) {
		if (n == 3)
			return false;
		if (n == 0)
			chain1 = chain;
		if (n == 1)
			chain2 = chain;
		if (n == 2)
			chain3 = chain;
		n++;

		return true;
	};

	int size() {
		return n;
	};

	bool removeChain() {
		if (n == 0)
			return false;
		if (n == 1)
			chain1 = NULL;
		if (n == 2)
			chain2 = NULL;
		if (n = 3)
			chain3 = NULL;
		n--;
		return true;
	};

	bool removeChain(int i) {

		if (0 <= i && i < n) {
			if (i == 0) {
				chain1 = chain2;
				chain2 = chain3;
			}
			if (i <= 1) {
				chain2 = chain3;
			}
			chain3 = NULL;
			n--;
			return true;
		}
		else
			throw ChainDoesntExist();
	};
};

class Player {
	string name;
	int numCoins;
	int maxNumChains;
	ChainContainer chains;
	Hand* hand;

public:
	Player(std::string&);			// constructor that creates a Player with a given name.
	string getName();				// get the name of the player.
	int getNumCoins();				// get the number of coins currently held by the player.
	Player& operator+=(int);		// add a number of coins
	Player& operator+=(Card*);		// add a card to the player's hand
	int getMaxNumChains();			// returns either 2 or 3.
	int getNumChains();				// returns the number of non - zero chains
	ChainBase& operator[](int i);		// returns the chain at position i.
	void buyThirdChain();			//adds an empty third chain to the player for two coins
	void printHand(ostream&, bool); //prints the top card of the player's hand (with
	//argument false) or all of the player's hand (with 
	//argument true) to the supplied ostream.
	void print(ostream&);
	Player(istream&, CardFactory*); //constructor that accepts an istream and reconstruct the Player from file
	friend ostream& operator << (ostream&, Player);
	template<class T> bool addChain();		//return false if the chain can't be added.
	bool addToChain(Card*);
	void sellChain(int i);
	Hand* getHand() { return hand; }

private:
	void addChain(char);
};

Player::Player(string& playerName) {
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
	hand = new Hand();
}


string Player::getName() {
	return name;
}

int Player::getNumCoins() {
	return numCoins;
}

Player& Player:: operator +=(int i) {
	numCoins = numCoins + i;
	return(*this);
}

Player& Player::operator+=(Card* card)
{
	*hand += card;
	return *this;
}

int Player::getMaxNumChains() {
	return maxNumChains;
}

int Player::getNumChains() {
	return chains.size();

}


ChainBase& Player:: operator[](int i) {
	if (i < getNumChains())
		return	 chains[i];
	else
		throw ChainDoesntExist();
}

//It is assumed that a player only needs to buy a third chain only once.
void Player::buyThirdChain() {
	if (numCoins < 3)
		throw NotEnoughCoins();
	else {
		numCoins = numCoins - 3;

		maxNumChains++;
	}

}

void Player::printHand(ostream& out, bool notTopCard) {
	if (notTopCard) {
		out << *hand;
	}
	else {

		out << hand->top();
	}


}//prints the top card of the player's hand (with
								//argument false) or all of the player's hand (with 
								//argument true) to the supplied ostream.


Player::Player(istream& in, CardFactory* cf) {
	getline(in, name, '\t');

	in >> numCoins;
	in >> maxNumChains;
	hand = new Hand(in, cf);
	char type;
	int size;
	string chainInfo;
	string tmp;
	for (int i = 0; i < 3; i++) {
		getline(in, chainInfo);
		if (chainInfo.compare("NULL") != 0) {
			type = chainInfo.at(0);
			size = atoi(chainInfo.substr(2).c_str());
			addChain(type);
			for (int i = 0; i < size; i++) {
				addToChain(cf->getCard(type));
			}

		}

	}


}


template<class T>
bool Player::addChain() {
	static_assert(std::is_base_of<Card, T>::value, "T is not derived from Card");
	if (chains.size() <= maxNumChains) {
		T temp;
		if (temp.getName() == "Garden") {
			addChain('g');
		}
		if (temp.getName() == "Soy") {
			addChain('s');
		}
		if (temp.getName() == "Black") {
			addChain('b');
		}
		if (temp.getName() == "Blue" || temp.getName() == "Green" || temp.getName() == "Red" || temp.getName() == "Stink" || temp.getName() == "Chili") {
			addChain(temp.getName()[0]);
		}
		return true;
	}
	//else
	return false;
}


bool Player::addToChain(Card* card)
{
	if (card == nullptr)
		return false;
	for (int i = 0; i < chains.size(); i++) {
		if ((*this)[i].legal(card)) {
			(*this)[i] += card;
			return true;
		}
	}
	//else
	if (chains.size() < maxNumChains) {
		if (card->getName() == "Garden") {
			addChain('g');
		}
		if (card->getName() == "Soy") {
			addChain('s');
		}
		if (card->getName() == "Black") {
			addChain('b');
		}
		if (card->getName() == "Blue" || card->getName() == "Green" || card->getName() == "Red" || card->getName() == "Stink" || card->getName() == "Chili") {
			addChain(card->getName()[0]);
		}		chains.back() += card;
		return true;
	}
	//else
	return false;
}

void Player::sellChain(int i) {
	numCoins += chains[i].sell();
	chains.removeChain(i);
}

void Player::addChain(char type)
{
	if (type == 'B') {
		ChainBase* newChain = new Chain<Blue>;
		chains.addChain(newChain);
	}
	else if (type == 'C') {
		ChainBase* newChain = new Chain<Chili>;
		chains.addChain(newChain);
	}
	else if (type == 'S') {
		ChainBase* newChain = new Chain<Stink>;
		chains.addChain(newChain);
	}
	else if (type == 'G') {
		ChainBase* newChain = new Chain<Green>;
		chains.addChain(newChain);
	}
	else if (type == 's') {
		ChainBase* newChain = new Chain<Soy>;
		chains.addChain(newChain);
	}
	else if (type == 'b') {
		ChainBase* newChain = new Chain<Black>;
		chains.addChain(newChain);
	}
	else if (type == 'R') {
		ChainBase* newChain = new Chain<Red>;
		chains.addChain(newChain);
	}
	else if (type == 'g') {
		ChainBase* newChain = new Chain<Garden>;
		chains.addChain(newChain);
	}
}


//constructor that accepts an istream and reconstruct the Player from file
 /*
 Text File Format:
 Line 1: name /t nb of coins
 Line 2: chain 1 info  **if not null
 Line 3: chain 2 info  **if not null
 Line 4: chain 3 info  **if not null
 */

ostream& operator<<(ostream& out, Player p)
{
	out << p.getName() << '\t' << p.getNumCoins() << " coins\n";
	for (int i = 0; i < p.getNumChains(); i++)
		out << p[i] << "\n";
	return out;
}

void Player::print(ostream& out)				//print all cards
{

	out << getName() << '\t' << getNumCoins() << ' ' << getMaxNumChains() << "\n";
	out << *hand << "\n";
	for (int i = 0; i < 3; i++) {
		if (i < getNumChains())
			out << chains[i].getType().at(0) << " " << chains[i].getSize() << "\n";
		else
			out << "NULL" << "\n";
	}

}
