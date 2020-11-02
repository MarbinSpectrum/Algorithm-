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

int N, M;
vector<int> A[1001];
bool Check[1001];
int Link[1001];
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

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int W;
		cin >> W;
		for (int j = 0; j < W; j++)
		{
			int temp;
			cin >> temp;
			A[i].push_back(temp);
		}
	}

	int Result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			memset(Check, false, sizeof(Check));
			Result += DFS(i);
		}
	}

	cout << Result << "\n";

}