#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N, M;
int MAP[2005][2005];

bool ZeroCheck()
{
	vector<vector<bool>> Visit(N, vector<bool>(M,false));

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	Visit[0][0] = true;

	while (Q.empty() == false)
	{
		pair<int, int> now = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ar = now.first + Dic[i][0];
			int ac = now.second + Dic[i][1];
			if (ar < 0 || ac < 0 || ar >= N || ac >= M)
				continue;
			if (MAP[ar][ac] == 1)
				continue;
			if (Visit[ar][ac])
				continue;
			Q.push({ ar, ac });
			Visit[ar][ac] = true;
		}
	}

	return (Visit[N-1][M-1] == false);
}

bool OneCheck()
{
	vector<vector<int>> Visit(N, vector<int>(M,0));

	{
		queue<pair<int, int>> Q1;
		for (int i = 0; i < N; i++)
			if (MAP[i][0] == 1)
			{
				Q1.push({ i,0 });
				Visit[i][0] = 1;
			}
		for (int i = 0; i < M; i++)
			if (MAP[N - 1][i] == 1)
			{
				Q1.push({ N - 1,i });
				Visit[N - 1][i] = 1;
			}


		while (Q1.empty() == false)
		{
			pair<int, int> now = Q1.front();
			Q1.pop();

			for (int i = 0; i < 8; i++)
			{
				int ar = now.first + Dic[i][0];
				int ac = now.second + Dic[i][1];
				if (ar < 0 || ac < 0 || ar >= N || ac >= M)
					continue;
				if (MAP[ar][ac] == 0)
					continue;
				if (Visit[ar][ac] > 0)
					continue;
				Q1.push({ ar, ac });
				Visit[ar][ac] = 1;
			}
		}
	}

	{
		queue<pair<int, int>> Q2;
		for (int i = 0; i < M; i++)
			if (MAP[0][i] == 1)
			{
				Q2.push({ 0,i });
				Visit[0][i] = 2;
			}
		for (int i = 0; i < N; i++)
			if (MAP[i][M - 1] == 1)
			{
				Q2.push({ i,M - 1 });
				Visit[i][M - 1] = 2;
			}


		while (Q2.empty() == false)
		{
			pair<int, int> now = Q2.front();
			Q2.pop();

			for (int i = 0; i < 8; i++)
			{
				int ar = now.first + Dic[i][0];
				int ac = now.second + Dic[i][1];
				if (ar < 0 || ac < 0 || ar >= N || ac >= M)
					continue;
				if (MAP[ar][ac] == 0)
					continue;
				if (Visit[ar][ac] > 0)
					continue;
				Q2.push({ ar, ac });
				Visit[ar][ac] = 2;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == N-1 && j == M-1)
				continue;
			if (MAP[i][j] != 0)
				continue;
			bool one = false;
			bool two = false;
			for (int k = 0; k < 8; k++)
			{
				int ai = i + Dic[k][0];
				int aj = j + Dic[k][1];
				if (ai < 0 || aj < 0 || ai >= N || aj >= M)
				{
					if (ai < 0)
						two = true;
					if (ai >= N)
						one = true;
					if (aj < 0)
						one = true;
					if (aj >= M)
						two = true;
					continue;
				}
				if (Visit[ai][aj] == 1)
					one = true;
				if (Visit[ai][aj] == 2)
					two = true;
			}

			if (one && two)
				return true;
		}
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			std::cin >> MAP[i][j];

	if (ZeroCheck())
	{
		std::cout << "0" << endl;
		return 0;
	}

	if (OneCheck())
	{
		std::cout << "1" << endl;
		return 0;
	}

	std::cout << "2" << endl;
	return 0;
}