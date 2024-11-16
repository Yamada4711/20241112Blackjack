#include "dealer.h"
#include <iostream>
#include <new>
using namespace std;

void Dealer::HitOrStandDealer(Dealer& dealer)
{
	do
	{
		if (hand != nullptr)
		{
			int score = 0;
			int size = sizeof * hand / sizeof hand[0];
			int aceCount = 0;
			for (int i = 0; i < size; i++)	// ��U�X�R�A���v�Z����
			{
				if (hand[i] % 13 >= 10)
				{
					score += 10;
				}
				else if (hand[i] % 13 == 0)
				{
					score += 11;
					aceCount++;
				}
				else
				{
					score += hand[0] % 13 + 1;
				}
			}

			if (score >= 22)
			{
				if (aceCount >= 2)
				{
					for (int i = aceCount; i > 1; i--)
					{
						score -= 10;
					}
				}
				if (score >= 22)
				{
					for (int i = 0; i < size; i++)
					{
						if (hand[i] % 13 == 0) score -= 10;
					}
				}
			}

			if (score >= 17)
			{
				end = true;
				return;
			}

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