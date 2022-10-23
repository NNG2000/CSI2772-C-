
#include <iostream>
using namespace std;
enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };
struct Card {
	Color color;
	Face face;
};
int main() {
	Card game[32];
	//VOTRE CODE VIENT ICI
	int n = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			game[n].color = static_cast<Color>(i);
			game[n].face = static_cast<Face>(j);
			n++;
		}
	}
}
	