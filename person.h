#ifndef PERSON_H_20241112_1443
#define PERSON_H_20241112_1443

#include "deck.h"

#include "card.h"

#include "deck.h"

class Person :
	public Card
{
public:
	Person();
	~Person();

	Person(const Person& other);

	void operator= (const Person& other);

	Trump* hand;
	Trump* handSub;
	bool end;
};

#endif // !PERSON_H_20241112_1443
