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

int N, M, K;

vector<int> Result;
bool flag = true;
void NMK(int n, int m, int k, int deep)
{
	//cout << n << " ";
	//cout << m << " ";
	//cout << k << endl;

	if (n + 1 == m + k)
	{
		int a = k;
		for (int i = 0; i < k; i++)
		{
			Result.push_back(a + deep);
			a--;
		}
		int b = k + 1;
		for (int i = 0; i < m - 1; i++)
		{
			Result.push_back(b + deep);
			b++;
		}
	}
	else
	{
		int a = k;
		for (int i = 0; i < k; i++)
		{
			Result.push_back(a + deep);
			a--;
		}

		int next_N = n - k;
		int next_M = m - 1;
		int next_K = n - k - m + 2;

		if (next_K > K)
		{
			if (next_M <= 1)
				flag = false;
			else
				NMK(next_N, next_M, K, deep + k);
		}
		else
			NMK(next_N, next_M, next_K, deep + k);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	if (M + K <= N + 1)
		NMK(N, M, K, 0);
	else
		flag = false;

	if (flag)
	{
		for (int i = 0; i < Result.size(); i++)
			cout << Result[i] << " ";
		cout << "\n";
	}
	else
		cout << -1 << "\n";
}