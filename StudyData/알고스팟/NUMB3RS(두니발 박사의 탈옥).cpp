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

int c, n, d, p,t;
float DP[100][100];
vector<int> V[100];
float D(int a, int b)
{
	if (a == 0 && b == p)
	{
		return 1;
	}

	if (DP[a][b] != -1)
	{
		return DP[a][b];
	}

	float& ret = DP[a][b];
	ret = 0;

	for (int i = 0; i < V[b].size(); i++)
	{
		int next = V[b][i];
		ret += D(a - 1, next) / (float)(V[next].size());
	}

	return ret;
}

void Sol()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			DP[i][j] = -1;
		}
		V[i].clear();
	}

	cin >> n >> d >> p;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a)
			{
				V[i].push_back(j);
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		cout << D(d, a) << " ";
	}
	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cout << fixed;
	cout.precision(10);

	cin >> c;
	while (c--)
	{
		Sol();
	}

}