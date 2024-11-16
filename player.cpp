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
//		// 何をすればいいのか忘れた
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
		do		// Hit か Stand を入力するまで繰り返す
		{
			for (int i = 0; i < 10; i++)
			{
				choice[i] = ' ';
			}
			cout << "Hit or Stand? > " << flush;
			cin >> choice;

			if (choice == "Hit" || "Stand") break;
			else cout << "入力した言葉が間違っています。" << endl;
		} while (true);

		if (choice == "Stand")
		{
			end = true; // Standならこのプレイヤーのターンは終わり
			return;
		}

		if (hand != nullptr)
		{
			int size = sizeof * hand / sizeof hand[0]; // 現在の配列の長さを取得
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