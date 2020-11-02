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

int N, M, K1, K2;
vector<int> A[10001];
vector<int> B[10001];
bool Check[10001];
int LinkA[10001];
int LinkB[10001];

bool DFS_A(int n)
{
	for (int i = 0; i < A[n].size(); i++)
	{
		int idx = A[n][i];
		if (Check[idx])
			continue;
		Check[idx] = true;
		if (LinkA[idx] == 0 || DFS_A(LinkA[idx]))
		{
			LinkA[idx] = n;
			return true;
		}
	}
	return false;
}

bool DFS_B(int n)
{
	for (int i = 0; i < B[n].size(); i++)
	{
		int idx = B[n][i];
		if (Check[idx])
			continue;
		Check[idx] = true;
		if (LinkB[idx] == 0 || DFS_B(LinkB[idx]))
		{
			LinkB[idx] = n;
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

	cin >> N >> M >> K1 >> K2;
	for (int i = 1; i <= K1; i++)
	{
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
	}

	for (int i = 1; i <= K2; i++)
	{
		int a, b;
		cin >> a >> b;
		B[a].push_back(b);
	}

	int Result_A = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(Check, false, sizeof(Check));
		Result_A += DFS_A(i);
	}

	int Result_B = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(Check, false, sizeof(Check));
		Result_B += DFS_B(i);
	}
	if (Result_A < Result_B)
		cout << "네 다음 힐딱이\n";
	else
		cout << "그만 알아보자\n";


}