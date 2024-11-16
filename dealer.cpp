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
			for (int i = 0; i < size; i++)	// 一旦スコアを計算する
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

			delete[] hand;								// メモリの解放
			hand = new(nothrow) Trump[size + 1];		// メモリの確保

			if (hand != nullptr)
			{
				if (handSub != nullptr)
				{
					for (int i = 0; i < size; i++)
					{
						hand[i] = handSub[i];	// 今まで引いたカードを再取得
					}

					hand[size] = (Trump)Deck::Pull();	// 新しいカードを取得
					delete[] handSub;					// データ保管用の配列を解放
					handSub = new(nothrow) Trump[size + 1];	// データ保管用の配列のメモリを再取得

					if (handSub != nullptr)
					{
						for (int i = 0; i < size + 1; i++)
						{
							handSub[i] = hand[i];	// データ保管用の配列にカード番号を格納
						}
					}
				}
			}
		}
	} while (true);
}