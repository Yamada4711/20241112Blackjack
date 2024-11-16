#include "deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
	for (int i = 0; i < DECK_CAPACITY; i++)
	{
		// まだカードを引いていないので、
		// 既に引いたカードを入れる配列を空を表す値で初期化する
		flippedCard[i] = EMPTY; 
	}
}

void Deck::InitRand()
{
	srand((unsigned int)time(NULL));
}

int Deck::Pull()
{
	int pullCard = EMPTY; // カードを保管する変数を空で初期化
	do
	{
		pullCard = rand() % 52; // カードを引く
		for (int i = 0; i < DECK_CAPACITY; i++)
		{
			if (flippedCard[i] == pullCard) break; // 選ばれたカードがすでに引かれていたらfor文を抜けてカードを引き直す
			else if (flippedCard[i] == EMPTY)
			{
				flippedCard[i] = pullCard; // 選ばれたカードがまだ引かれていなかったらカードの番号を記録して処理を終了
				return pullCard;
			}
		}
	} while (true);
}