#include "player.h"
#include "dealer.h"

#include <iostream>
#include <new>
using namespace std;

void ShowFirstCard(const int PLAYER_NUM, Dealer dealer, Player player);
void ShowCard(const int PLAYER_NUM, Player player);

int main()
{
	bool turn1 = true;
	bool fin = false;
	int playerNum = 0;

	do
	{
		cout << "プレイ人数を入力してください > " << flush;
		cin >> playerNum;
		if (playerNum > 0) break;
	} while (true);
	Player* player;
	Dealer dealer;
	player = new(nothrow) Player[playerNum];
	if (player != nullptr)
	{

		ShowFirstCard(playerNum, dealer, *player);

		while (true)
		{
			int endCount = 0;
			for (int i = 0; i < playerNum; i++)
			{
				if (player[i].end == true)
				{
					endCount++;
				}
			}
			if (endCount == playerNum)
			{
				dealer.HitOrStandDealer(dealer);
				for (int i = 0; i < *dealer.hand / dealer.hand[0]; i++)
				{
					cout << "ディーラーの" << i << "枚目のカードは..." << endl;
					if (dealer.hand[i] / 13 == 0) cout << "ダイヤの" << flush;
					else if (dealer.hand[i] / 13 == 1) cout << "スペードの" << flush;
					else if (dealer.hand[i] / 13 == 2) cout << "クラブの" << flush;
					else if (dealer.hand[i] / 13 == 3) cout << "ハートの" << flush;

					cout << (dealer.hand[i] % 13 + 1) << " です。" << endl;
					cout << endl;
				}
				cout << endl;
				break;
			}
			else
			{
				for (int i = 0; i < playerNum; i++)
				{
					player[i].HitOrStandPlayer(*player);
					ShowCard(i, *player);
				}
			}
		}
		int dscore = 0;
		if (dealer.hand != nullptr)
		{
			int size = sizeof * dealer.hand / sizeof dealer.hand[0];
			for (int i = 0; i < size; i++)	// 一旦スコアを計算する
			{
				if (dealer.hand[i] % 13 >= 10)
				{
					dscore += 10;
				}
				else if (dealer.hand[i] % 13 == 0)
				{
					dscore += 11;
				}
				else
				{
					dscore += dealer.hand[0] % 13 + 1;
				}
			}
		}
		cout << "ディーラーのスコアは..." << dscore << endl;
		int* pscore;
		pscore = new (nothrow) int[playerNum];

		if (pscore != nullptr)
		{
			for (int i = 0; i < playerNum; i++)
			{
				pscore[i] = 0;
				for (int j = 0; j < *player[i].hand / player[i].hand[0]; i++)
				{
					if (player[i].hand[j] % 13 >= 10)
					{
						pscore[i] += 10;
					}
					else if (player[i].hand[j] % 13 == 0)
					{
						pscore[i] += 11;
					}
					else
					{
						pscore[i] += player[i].hand[j] % 13 + 1;
					}
				}
				cout << "プレイヤー" << i + 1 << "のスコアは..." << pscore[i] << endl;

				if (pscore[i] >= 22 || pscore[i] < dscore)
				{
					cout << "負け" << endl;
				}
				if (pscore[i] == 21 && dscore == 21)
				{
					cout << "ひきわけ" << endl;
				}
				else
				{
					cout << "勝ち" << endl;
				}
			}
			delete[] pscore;
			pscore = nullptr;
		}
		delete[] player;
		player = nullptr;
	}
}

void ShowCard(const int PLAYER_NUM, Player * player)
{
	cout << "プレイヤー" << PLAYER_NUM << "のカードは..." << endl;

	for (int i = 0; i < *player[PLAYER_NUM].hand / player[PLAYER_NUM].hand[0]; i++)
	{
		if (player[PLAYER_NUM].hand[i] / 13 == 0) cout << "ダイヤの" << flush;
		else if (player[PLAYER_NUM].hand[i] / 13 == 1) cout << "スペードの" << flush;
		else if (player[PLAYER_NUM].hand[i] / 13 == 2) cout << "クラブの" << flush;
		else if (player[PLAYER_NUM].hand[i] / 13 == 3) cout << "ハートの" << flush;

		cout << (player[PLAYER_NUM].hand[i] % 13 + 1) << endl;
		cout << endl;
	}
	cout << endl;
}

void ShowFirstCard(const int PLAYER_NUM, Dealer dealer, Player * player)
{
	cout << "ディーラーの1枚目のカードは..." << endl;

	if (dealer.hand[0] / 13 == 0) cout << "ダイヤの" << flush;
	else if (dealer.hand[0] / 13 == 1) cout << "スペードの" << flush;
	else if (dealer.hand[0] / 13 == 2) cout << "クラブの" << flush;
	else if (dealer.hand[0] / 13 == 3) cout << "ハートの" << flush;

	cout << (dealer.hand[0] % 13 + 1) << " です。" << endl;
	cout << endl;
	cout << endl;

	for (int i = 0; i < PLAYER_NUM; i++)
	{
		cout << "プレイヤー" << i + 1 << "のカードは..." << endl;

		if (player[i].hand[0] / 13 == 0) cout << "ダイヤの" << flush;
		else if (player[i].hand[0] / 13 == 1) cout << "スペードの" << flush;
		else if (player[i].hand[0] / 13 == 2) cout << "クラブの" << flush;
		else if (player[i].hand[0] / 13 == 3) cout << "ハートの" << flush;

		cout << (player[i].hand[0] % 13 + 1) << endl;

		if (player[i].hand[1] / 13 == 0) cout << "ダイヤの" << flush;
		else if (player[i].hand[1] / 13 == 1) cout << "スペードの" << flush;
		else if (player[i].hand[1] / 13 == 2) cout << "クラブの" << flush;
		else if (player[i].hand[1] / 13 == 3) cout << "ハートの" << flush;

		cout << (player[i].hand[1] % 13 + 1) << endl;
		cout << endl;

		int score = 0;
		if (player[i].hand[0] % 13 >= 10)
		{
			score += 10;
		}
		if (player[i].hand[1] % 13 >= 10)
		{
			score += 10;
		}
		if (player[i].hand[0] % 13 == 0)
		{
			score += 11;
		}
		if (player[i].hand[1] % 13 == 0)
		{
			if (player[i].hand[0] % 13 == 0)
			{
				score += 1;
			}
			else
			{
				score += 11;
			}
		}
		if (player[i].hand[0] % 13 < 10 && player[i].hand[0] % 13 != 0)
		{
			score += player[i].hand[0] % 13 + 1;
		}
		if (player[i].hand[1] % 13 < 10 && player[i].hand[1] % 13 != 0)
		{
			score += player[i].hand[1] % 13 + 1;
		}

		if (score == 21)
		{
			cout << "ブラックジャック" << endl;
			player[i].end = true;
		}
		else
		{
			cout << score << endl;
		}

		cout << endl;
		cout << endl;
	}
}