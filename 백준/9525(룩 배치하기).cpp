#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include <string.h>

#pragma warning(disable:4996)

using namespace std;

int N, K;
vector<int> A[5002];
int Map[101][101];
int RowMap[101][101];
int ColMap[101][101];
bool Check[5002];
int Link[5002];

bool DFS(int n)
{
	for (int i = 0; i < A[n].size(); i++)
	{
		int idx = A[n][i];
		if (Check[idx])
			continue;
		Check[idx] = true;
		if (Link[idx] == 0 || DFS(Link[idx]))
		{
			Link[idx] = n;
			return true;
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			char cc;
			cin >> cc;
			if (cc == '.')
				Map[r][c] = 0;
			else
				Map[r][c] = 2;
		}

	int a = 0;
	bool flag = false;
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (Map[r][c] != 2)
			{
				if (!flag)
				{
					flag = true;
					a++;
				}
				ColMap[r][c] = a;
			}
			else
				flag = false;
		}
		flag = false;
	}

	int b = 0;
	flag = false;
	for (int c = 1; c <= N; c++)
	{
		for (int r = 1; r <= N; r++)
		{
			if (Map[r][c] != 2)
			{
				if (!flag)
				{
					flag = true;
					b++;
				}
				RowMap[r][c] = b;
			}
			else
				flag = false;
		}
		flag = false;
	}

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			if (Map[r][c] == 0)
			{
				int a = ColMap[r][c];
				int b = RowMap[r][c];
				A[a].push_back(b);
			}
	int Result = 0;
	for (int i = 1; i < 5002; i++)
	{
		memset(Check, false, sizeof(Check));
		Result += DFS(i);
	}
	cout << Result << "\n";

}