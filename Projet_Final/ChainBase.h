#include "Card.h"

class ChainBase {
protected:
	virtual void addCard(Card*) = 0;
	virtual void print(ostream&) const = 0;
public:
	virtual bool checkCard(Card*) = 0;
	virtual int sell() = 0;
	virtual int getSize() = 0;
	virtual string getType() = 0;
	friend ostream& operator << (ostream& out, const ChainBase& cb) {
		cb.print(out);
		return out;
	};
	ChainBase& operator+= (Card* card) {
		this->addCard(card);
		return *this;
	};

