﻿#include<iostream>
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
long long Size[1001];
long long Speed[1001];
long long Intellect[1001];

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

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Size[i] >> Speed[i] >> Intellect[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			if (Size[i] >= Size[j] && Speed[i] >= Speed[j] && Intellect[i] >= Intellect[j])
			{
				if (Size[i] == Size[j] && Speed[i] == Speed[j] && Intellect[i] == Intellect[j])
				{
					if (i < j)
						A[i].push_back(j);
				}
				else
					A[i].push_back(j);
			}
		}


	int Result = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(Check, false, sizeof(Check));
		DFS(i);
		memset(Check, false, sizeof(Check));
		DFS(i);
	}

	int sub = 0;
	for (int i = 1; i <= N; i++)
		if (Link[i] > 0)
			Result++;

	cout << N - Result << "\n";

}