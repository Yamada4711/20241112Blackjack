#include "player.h"
#include <iostream>
#include <new>
using namespace std;

//
//Player::Player(const int PLAYER_NUM)
//{
//	player = new(nothrow) Person[PLAYER_NUM];
//	if (player != nullptr)
//	{
//		// ��������΂����̂��Y�ꂽ
//	}
//}
//
//Player::~Player()
//{
//	if (player != nullptr)
//	{
//		delete[] player;
//		player = nullptr;
//	}
//}

void Player::HitOrStandPlayer(Player & player)
{
	char choice[10];
	do
	{
		do		// Hit �� Stand ����͂���܂ŌJ��Ԃ�
		{
			for (int i = 0; i < 10; i++)
			{
				choice[i] = ' ';
			}
			cout << "Hit or Stand? > " << flush;
			cin >> choice;

			if (choice == "Hit" || "Stand") break;
			else cout << "���͂������t���Ԉ���Ă��܂��B" << endl;
		} while (true);

		if (choice == "Stand")
		{
			end = true; // Stand�Ȃ炱�̃v���C���[�̃^�[���͏I���
			return;
		}

		if (hand != nullptr)
		{
			int size = sizeof * hand / sizeof hand[0]; // ���݂̔z��̒������擾
			delete[] hand;								// �������̉��
			hand = new(nothrow) Trump[size + 1];		// �������̊m��
			if (hand != nullptr)
			{
				if (handSub != nullptr)
				{
					for (int i = 0; i < size; i++)
					{
						hand[i] = handSub[i];	// ���܂ň������J�[�h���Ď擾
					}
					hand[size] = (Trump)Deck::Pull();	// �V�����J�[�h���擾
					delete[] handSub;					// �f�[�^�ۊǗp�̔z������
					handSub = new(nothrow) Trump[size + 1];	// �f�[�^�ۊǗp�̔z��̃��������Ď擾
					if (handSub != nullptr)
					{
						for (int i = 0; i < size + 1; i++)
						{
							handSub[i] = hand[i];	// �f�[�^�ۊǗp�̔z��ɃJ�[�h�ԍ����i�[
						}
					}
				}
			}
		}
	} while (true);
}