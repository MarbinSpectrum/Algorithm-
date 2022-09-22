#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//////////////////////////////////////////////////////////////////////// 

int N,M,Q;
int Arr[200002];
vector<int> Arr2[200002];
vector<pair<int,int>> Query;
int ans[200002];
int QueryAns[3][200002];
int PrefixSum[200002];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
		PrefixSum[i] = PrefixSum[i - 1] + Arr[i];
	}

	for (int i = 0; i < Q; i++)
	{
		int a, b;
		std::cin >> a >> b;
		Query.emplace_back(a, b);
	}

	for (int i = 1; i <= N; i++)
	{
		int b = i + 1;
		int c = i + 1 + (Arr[i] / M);
		Arr2[b].push_back(i);
		Arr2[c].push_back(-i);
	}

	int cnt = 0;
	int totalE = 0;

	for (int i = 1; i <= N; i++)
	{
		int RemainValue = 0;
		for (int j = 0; j < Arr2[i].size(); j++)
		{
			if (Arr2[i][j] > 0)
				cnt++;
			else
			{
				cnt--;
				RemainValue += Arr[-Arr2[i][j]] % M;
			}
		}

		int nowE = cnt * M + RemainValue;
		totalE += nowE;
		QueryAns[2][i] = nowE;
		QueryAns[1][i] = PrefixSum[i] - totalE;
	}

	for (int i = 0; i < Q; i++)
	{
		int a = Query[i].first;
		int b = Query[i].second;
		cout << QueryAns[a][b] << endl;
	}
}