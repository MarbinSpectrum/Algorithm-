#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

map<string, int> Pn;
struct Pos
{
	int r, c;
	int pocket;
};
Pos pos[30];
int Dist(int a, int b)
{
	return abs(pos[a].r - pos[b].r) + abs(pos[a].c - pos[b].c);
}

int N;
const int MAX1 = 1 << 21;
const int MAX2 = 30;
int DP[MAX1][MAX2];
int D(int bit, int p)
{
	if (bit == (1 << Pn.size()) - 1)
		return Dist(p, 0);
	int& ret = DP[bit][p];
	if (ret != INF)
		return ret;
	for (int i = 1; i <= N; i++)
	{
		if (bit & (1 << pos[i].pocket))
			continue;
		ret = min(ret, D(bit | (1 << pos[i].pocket), i) + Dist(p, i));
	}
	return ret;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < MAX1; i++)
		for (int j = 0; j < MAX2; j++)
			DP[i][j] = INF;
	pos[0] = { 0,0,0 };

	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		string c;
		std::cin >> a >> b >> c;

		if (Pn.find(c) == Pn.end())
		{
			int newNum = Pn.size();
			Pn[c] = newNum;
		}
		pos[i] = { a,b,Pn[c] };
	}

	std::cout << D(0, 0) << endl;
}