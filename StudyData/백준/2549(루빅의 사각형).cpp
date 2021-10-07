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

int Ceil(float n)
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

int ans = 8;
tuple<int, int, int> TempValue[8];
tuple<int, int, int> AnsValue[8];
int Map[4][4];
int temp[4];
void Move(int rc, int a, int b)
{
	b = (b + 4) % 4;
	if (rc == 0)
	{

		for (int i = 0; i < 4; i++)
		{
			temp[(i + b) % 4] = Map[a][i];
		}
		for (int i = 0; i < 4; i++)
		{
			Map[a][i] = temp[i];
		}

	}
	else
	{

		for (int i = 0; i < 4; i++)
		{
			temp[(i + b) % 4] = Map[i][a];
		}
		for (int i = 0; i < 4; i++)
		{
			Map[i][a] = temp[i];
		}

	}
}

int CmpMap()
{
	int v = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (Map[i][j] != i * 4 + j + 1)
				v++;
		}
	return v;
}

void DFS(int cnt)
{
	if (ans <= cnt)
		return;
	int cmpValue = CmpMap();
	if (cmpValue == 0)
	{
		ans = cnt;
		for (int i = 0; i < ans; i++)
		{
			AnsValue[i] = TempValue[i];
		}
		return;
	}

	if (Ceil(cmpValue / (float)4) + cnt >= ans)
		return;

	for (int rc = 0; rc <= 1; rc++)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 1; j <= 3; j++)
			{
				Move(rc, i, j);
				TempValue[cnt] = { rc,i,j };
				DFS(cnt + 1);
				Move(rc, i, -j);
			}
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> Map[i][j];
		}

	DFS(0);

	cout << ans << endl;
	for (int i = 0; i < ans; i++)
	{
		cout << get<0>(AnsValue[i]) + 1 << " ";
		cout << get<1>(AnsValue[i]) + 1 << " ";
		cout << get<2>(AnsValue[i]) << endl;
	}

}