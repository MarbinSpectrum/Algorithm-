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

int B, N;
int F[5005];
float DP[35][5005];

float D(int a,int b)
{
	if (a == 0 || b >= N)
		return 0;
	if (DP[a][b] != INF)
		return DP[a][b];
	DP[a][b] = INF;

	if (a != 1)
	{
		float sum = 0;
		float num = 0;
		float powSum = 0;
		for (int i = b; i < N; i++)
		{
			num++;
			sum += F[i];
			powSum += F[i] * F[i];
			float avg = sum / num;
			DP[a][b] = min(DP[a][b], powSum - 2 * avg * sum + num * avg * avg + D(a - 1, i + 1));
		}
	}
	else
	{
		float sum = 0;
		float num = 0;
		float powSum = 0;
		for (int i = b; i < N; i++)
		{
			num++;
			sum += F[i];
			powSum += F[i] * F[i];
		}
		float avg = sum / num;

		DP[a][b] = min(DP[a][b], powSum - 2 * avg * sum + num * avg * avg + D(a - 1, N));
	}
	return DP[a][b];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cout << fixed;
	cout.precision(6);

	for (int i = 0; i < 35; i++)
		for (int j = 0; j < 5005; j++)
			DP[i][j] = INF;

	cin >> B >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> F[i];
	}

	cout << D(B, 0) << endl;
}