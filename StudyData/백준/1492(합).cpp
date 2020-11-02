#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>

#pragma warning(disable:4996)

using namespace std;

long long N, K;
long long mod = 1000000007;
long long Pascal[100][100];
long long d[100][100];
long long GetPascal(int a, int b)
{
	if (a < 0 || a >= 100 || b < 0 || b >= 100)
		return 0;
	return Pascal[a][b];
}
long long Power(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a % mod;
	long long x = Power(a, b / 2);
	if (b & 1)
		return ((a * x) % mod * x) % mod;
	else
		return (x * x) % mod;
}
long long F_Value[100];
void F(int k)
{
	long long temp = Power(N + 1, k + 1);
	temp--;
	if (temp < 0)
		temp += mod;
	for (int j = 0; j < k; j++)
		temp = (temp - d[j][k + 1] + mod) % mod;
	F_Value[k] = (temp * Power(GetPascal(k + 1, k), mod - 2)) % mod;
	for (int j = k; j <= K + 1; j++)
		d[k][j] = (F_Value[k] * GetPascal(j, k)) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(F_Value, -1, sizeof(F_Value));
	Pascal[0][0] = 1;
	for (int i = 1; i < 100; i++)
		for (int j = 0; j <= i; j++)
			Pascal[i][j] = (GetPascal(i - 1, j) + GetPascal(i - 1, j - 1)) % mod;
	cin >> N >> K;
	for (int k = 0; k <= K; k++)
		F(k);
	cout << F_Value[K] << endl;
}