#include "deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
	for (int i = 0; i < DECK_CAPACITY; i++)
	{
		// �܂��J�[�h�������Ă��Ȃ��̂ŁA
		// ���Ɉ������J�[�h������z������\���l�ŏ���������
		flippedCard[i] = EMPTY; 
	}
}

void Deck::InitRand()
{
	srand((unsigned int)time(NULL));
}

int Deck::Pull()
{
	int pullCard = EMPTY; // �J�[�h��ۊǂ���ϐ�����ŏ�����
	do
	{
		pullCard = rand() % 52; // �J�[�h������
		for (int i = 0; i < DECK_CAPACITY; i++)
		{
			if (flippedCard[i] == pullCard) break; // �I�΂ꂽ�J�[�h�����łɈ�����Ă�����for���𔲂��ăJ�[�h����������
			else if (flippedCard[i] == EMPTY)
			{
				flippedCard[i] = pullCard; // �I�΂ꂽ�J�[�h���܂�������Ă��Ȃ�������J�[�h�̔ԍ����L�^���ď������I��
				return pullCard;
			}
		}
	} while (true);
}