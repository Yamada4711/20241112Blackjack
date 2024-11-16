#ifndef DEALER_H_20241112_1437
#define DEALER_H_20241112_1437

#include "person.h"

class Dealer :
	public Person
{
public:
	void HitOrStandDealer(Dealer& dealer);

	//static Person dealer;
};

#endif // !DEALER_H_20241112_1437
