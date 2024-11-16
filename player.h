#ifndef PLAYER_H_20241112_1450
#define PLAYER_H_20241112_1450

#include "person.h"

class Player :
	public Person
{
public:
	//Player(const int PLAYER_NUM);
	//~Player();

	void HitOrStandPlayer(Player& player);

	//static Person* player;
};

#endif // !PLAYER_H_20241112_1450
