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
float A_W[1001];
float B_W[1001];
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
		cin >> A_W[i];
	for (int i = 1; i <= M; i++)
		cin >> B_W[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (A_W[i] * 0.5f <= B_W[j] && B_W[j] <= A_W[i] * 0.75f)
				A[i].push_back(j);
			else if (A_W[i] <= B_W[j] && B_W[j] <= A_W[i] * 1.25f)
				A[i].push_back(j);
		}

	int Result = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(Check, false, sizeof(Check));
		Result += DFS(i);
	}

	cout << Result << "\n";

}