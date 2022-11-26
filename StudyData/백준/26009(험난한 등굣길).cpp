#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int N, M, K;
bool Block[3005][3005];
bool IndexOut(int pR, int pC)
{
	return !(0 < pR && pR <= N && 0 < pC && pC <= M);
}
int Dist[3005][3005];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	std::cin >> K;

	while (K--)
	{
		int R, C, D;
		std::cin >> R >> C >> D;

		Block[R][C] = true;

		for (int i = 0; i <= D; i++)
		{
			int aR = R - i * 1 + D;
			int aC = C + i * 1;
			if (IndexOut(aR, aC))
				continue;
			Block[aR][aC] = true;
		}
		for (int i = 0; i <= D; i++)
		{
			int aR = R - i * 1;
			int aC = C - i * 1 + D;
			if (IndexOut(aR, aC))
				continue;
			Block[aR][aC] = true;
		}
		for (int i = 0; i <= D; i++)
		{
			int aR = R + i * 1 - D;
			int aC = C - i * 1;
			if (IndexOut(aR, aC))
				continue;
			Block[aR][aC] = true;
		}
		for (int i = 0; i <= D; i++)
		{
			int aR = R + i * 1;
			int aC = C + i * 1 - D;
			if (IndexOut(aR, aC))
				continue;
			Block[aR][aC] = true;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			Dist[i][j] = INF;

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{ 1,1 } });
	Dist[1][1] = 0;

	while (pq.empty() == false)
	{
		pair<int, pair<int, int>> now = pq.top();
		pq.pop();

		int nowCost = -now.first;
		pair<int, int> nowPos = now.second;

		for (int i = 0; i < 4; i++)
		{
			int nextCost = nowCost + 1;
			pair<int, int> nextPos =
			{ nowPos.first + Dic[i][0],nowPos.second + Dic[i][1] };
			if (IndexOut(nextPos.first, nextPos.second))
				continue;		
			if (Block[nextPos.first][nextPos.second])
				continue;
			if (Dist[nextPos.first][nextPos.second] > nextCost)
			{
				Dist[nextPos.first][nextPos.second] = nextCost;
				pq.push({ -nextCost,nextPos });
			}
		}
	}

	if (Dist[N][M] != INF)
	{
		std::cout << "YES" << endl;
		std::cout << Dist[N][M] << endl;
	}
	else
		std::cout << "NO" << endl;
}