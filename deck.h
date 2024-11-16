#ifndef DECK_H_20241112_1501
#define DECK_H_20241112_1501

#include "card.h"

class Deck :
	public Card
{
public:
	Deck();

	void InitRand();

	static int Pull();

private:
	static const int DECK_CAPACITY = 52;
	static int flippedCard[DECK_CAPACITY]; // ó†ï‘Ç≥ÇÍÇΩÉJÅ[Éh
};

#endif // !DECK_H_20241112_1501
