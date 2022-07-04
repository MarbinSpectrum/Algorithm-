#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

////////////////////////////////////////////////////////////////////////

int T, N, D, K;
std::vector<int> Array;
int DP[2000000][20];
int tea[2000000];
int result = 0;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T >> N >> D >> K;
	for (int i = 0; i < N; i++)
	{
		int a;
		std::cin >> a;
		Array.push_back(a);
	}

	sort(Array.begin(), Array.end());

	for (int i = 0; i < N; i++)
	{
		int s = 0;
		int e = i;
		while (s <= e)
		{
			int m = (s + e) / 2;
			if (Array[i] - Array[m] + 1 <= D)
			{
				e = m - 1;
				tea[i] = max(tea[i], i - m + 1);
			}
			else
			{
				s = m + 1;
			}
		}
	}

	for (int j = 0; j < K; j++)
		for (int i = 0; i < N; i++)
		{
			DP[i][j] = max(
				(i - 1 >= 0 ? DP[i - 1][j] : 0),
				tea[i] + ((i - tea[i] >= 0 && j - 1 >= 0) ? DP[i - tea[i]][j - 1] : 0));
			result = max(DP[i][j], result);
		}

	std::cout << result << endl;
}