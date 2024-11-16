#include "person.h"
#include <iostream>
#include <new>
#include <algorithm>
using namespace std;

Person::Person()
{
	hand = new(nothrow) Trump[2];
	if (hand != nullptr)
	{
		for (int i = 0; i < 2; i++)
		{
			hand[i] = (Trump)Deck::Pull();
		}
	}
	handSub = new(nothrow) Trump[sizeof hand / sizeof * hand];
	if (handSub != nullptr)
	{
		if (hand != nullptr)
		{
			for (int i = 0; i < 2; i++)
			{
				handSub[i] = hand[i];
			}
		}
	}
	end = false;
}

Person::~Person()
{
	if (hand != nullptr)
	{
		delete[] hand;
		hand = nullptr;
	}
}

Person::Person(const Person& other)
{
	int size = *other.hand / other.hand[0];
	hand = new(nothrow) Trump[size];
	if (hand != nullptr)
	{
		copy(other.hand, other.hand + size, hand);
	}
	handSub = new(nothrow) Trump[size];
	if (handSub != nullptr)
	{
		copy(other.handSub, other.handSub + size, handSub);
	}
	end = other.end;
}

void Person::operator= (const Person& other)
{
	int size = *other.hand / other.hand[0];
	if (hand != nullptr)
	{
		delete[] hand;

		hand = new(nothrow) Trump[size];
		if (hand != nullptr)
		{
			copy(other.hand, other.hand + size, hand);
		}
	}
	if (handSub != nullptr)
	{
		delete[] handSub;

		handSub = new(nothrow) Trump[size];
		if (handSub != nullptr)
		{
			copy(other.handSub, other.handSub + size, handSub);
		}
	}
	end = other.end;
}