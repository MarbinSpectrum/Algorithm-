#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int int
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//////////////////////////////////////////////////////////////////////// 

const int MAX = 6005;
int W, H, K;
int MAP[MAX][MAX][3];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> W >> H >> K;
	for (int i = 0; i < K; i++)
	{
		int t;
		std::cin >> t;
		if (t == 1)
		{
			int px, py, qx, qy;
			std::cin >> px >> py >> qx >> qy;
			px++;
			py++;
			qx++;
			qy++;

			MAP[py][px][0]++;
			MAP[py][qx + 1][0]--;
			MAP[qy + 1][px][0]--;
			MAP[qy + 1][qx + 1][0]++;
		}
		else if (t == 2)
		{
			int px, py, r;
			std::cin >> px >> py >> r;
			px++;
			py++;

			MAP[py - r][px][1]++;
			MAP[py + 1][px - r - 1][1]--;
			MAP[py - r + 1][px][1]++;
			MAP[py + 1][px - r - 1 + 1][1]--;


			MAP[py + 1][px + r + 1][1]--;
			MAP[py + r + 2][px][1]++;
			MAP[py + 1][px + r + 1 - 1][1]--;
			MAP[py + r + 1][px][1]++;
		}
	}
	H += 2;
	W += 2;

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			MAP[i][j][0] += MAP[i][j - 1][0];

	for (int j = 1; j <= W; j++)
		for (int i = 1; i <= H; i++)
			MAP[i][j][0] += MAP[i - 1][j][0];

	for (int j = 1; j <= W; j++)
		for (int ai = 1, aj = j; (ai <= H, aj >= 0); ai++, aj--)
			MAP[ai][aj][1] += MAP[ai - 1][aj + 1][1];
	for (int i = 2; i <= H; i++)
		for (int ai = i, aj = W; (ai <= H, aj >= 0); ai++, aj--)
			MAP[ai][aj][1] += MAP[ai - 1][aj + 1][1];

	for (int j = 1; j <= W; j++)
		for (int ai = 1, aj = j; (ai <= H, aj <= W); ai++, aj++)
			MAP[ai][aj][1] += MAP[ai - 1][aj - 1][1];
	for (int i = 2; i <= H; i++)
		for (int ai = i, aj = 1; (ai <= H, aj <= W); ai++, aj++)
			MAP[ai][aj][1] += MAP[ai - 1][aj - 1][1];

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			MAP[i][j][2] = MAP[i][j][0] + MAP[i][j][1];

	H -= 2;
	W -= 2;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (MAP[i][j][2] % 2 == 0)
				cout << ".";
			else
				cout << "#";
		}
		cout << endl;
	}
}