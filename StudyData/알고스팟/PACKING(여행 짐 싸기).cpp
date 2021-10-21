#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <tuple>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float double
#define Debug(a,b) cout << a << " " << b << endl

int Mul(int x, int y, int mod)
{
	return x * y % mod;
}

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return (int)n + 1;
	else
		return n;
}

int Pow(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		b = b >> 1;
		a = (a * a);
	}
	return res;
}
int Pow(int a, int b, int p)
{
	int res = 1;
	a = a % p;
	while (b > 0)
	{
		if (b & 1)
			res = Mul(res, a, p);
		b = b >> 1;
		a = Mul(a, a, p);
	}
	return res;
}

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int C,N,W;
int DP[105][1005];
string Arr1[105];
int Arr2[105];
int Arr3[105];
pair<int, int> Par[105][1005];
void Sol()
{
	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 1005; j++)
		{
			Par[i][j] = { 0,0 };
			DP[i][j] = 0;
		}
	}

	cin >> N >> W;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr1[i] >> Arr3[i] >> Arr2[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			if (j + Arr3[i] <= W && DP[i - 1][j] + Arr2[i] > DP[i][j + Arr3[i]])
			{
				DP[i][j + Arr3[i]] = DP[i - 1][j] + Arr2[i];
				Par[i][j + Arr3[i]] = { 1, j };
			}
			if (j <= W && DP[i - 1][j] >= DP[i][j])
			{
				DP[i][j] = DP[i - 1][j];
				Par[i][j] = { 0, j };
			}
		}
	}

	pair<int, int> ans = { -1,0 };
	for (int j = 0; j <= 1000; j++)
	{
		if (ans.first < DP[N][j])
		{
			ans.first = DP[N][j];
			ans.second = j;
		}
	}

	{
		int a = N;
		int b = ans.second;

		vector<string> Str;
		while (b != 0)
		{
			if (Par[a][b].first == 1)
			{
				Str.push_back(Arr1[a]);
			}
			a--;
			b = Par[a+1][b].second;
		}

		cout << ans.first << " " << Str.size() << endl;
		for (int i = 0; i < Str.size(); i++)
		{
			cout << Str[i] << endl;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> C;
	while (C--)
	{
		Sol();
	}
}