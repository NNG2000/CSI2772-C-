#include <iostream>
#include <iostream>
#include <vector>
using namespace std;
#include <cassert> //for assert()
#include <string.h>
#include "CardFactory.h"
#include <ChainBase.h>
#include <Card.h>
/*
je suppose que c'est pour créer le nombre de carte nécessaire pour chacune d'elle
lors d'un tour Exple: maximum 20 cartes Bleu, 18 cartes Chili, ...
*/
/*
Mon patron Chain 
*/
template <class T> class Chain : public ChainBase, public vector <T*>{

	Chain();
	Chain(istream&, const CardFactory*);
	bool checkCard(Card*);						//returns true if it's legal to add the card to the chain.
	Chain<T>& operator+= (Card* card);
	int sell();
	void addCard(Card*);
	int getSize();
	string getType();
	friend ostream& operator << (ostream& sortie, Chain<T> c) {
		sortie << c.getType() << '\t';

		if (c.getSize() > 0) {
			for (int i = 0; i < c.getSize(); i++)
				sortie << c.getType().at(0);
		}

		return sortie;
	};
    protected: string type;
	void print(ostream& out) const {
		out << (*this);
	};
};

/*
creation d'une classe pour les exceptions à retourner lorsque les cartes sont de types différents 
*/
class IllegalType : public exception
{
	virtual const char* what() const throw()
	{
		return "This card couldn't be add; The type of the card doesn't match in this chain ";
	}
};

template<class T> inline Chain<T>::Chain()
{
	T temp;
	type = temp.getName();
}

template<class T> Chain<T>::Chain(istream& in, const CardFactory* cf) {

	char c;

	while (in >> c) {
		if (c != ' ') {
			Card* card = (cf->getCard(c));
			(*this).push_back(card);
		}

	}

}

template<class T> bool Chain<T>::checkCard(Card* card)
{
	return (type.compare((*card).getName()) == 0);
}

template<class T> Chain<T>& Chain<T>::operator+=(Card* card)
{

	if (checkCard(card)) {
		T* temp = new T();
		this->push_back(temp);
	}
	else {
		throw IllegalType();
	}

	return *this;
}

/*
puisse qu'on a un maximum de 4 piéce de monnaie pour un certain nombre de carte, 
on retournera la monnaie correspondante au nombre de cartes minimales nécessaires. 
*/
template<class T> int Chain<T>::sell()
{
	T temp;
	for (int cns = 4; cns > 0; cns--) {
		if (this->getSize() >= temp.getCardsPerCoin(cns)) {
			return cns;

		}
	}

	return 0;
}

template<class T> void Chain<T>::addCard(Card* card)
{
	(*this) += card;
}

template<class T> inline int Chain<T>::getSize()
{
	return this->size();
}

template<class T> inline string Chain<T>::getType()
{
	return type;
}