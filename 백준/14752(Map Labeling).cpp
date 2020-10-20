#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <tuple>
#include <list>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 9999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int DP[10001];
int Pos[10001];
int Width[10001];
int N;
int Result = 10000;
int Get(int idx)
{
	if (idx >= N)
		return 0;

	if (DP[idx] != -1)
		return DP[idx];

	int pre_P = Pos[idx];
	int now_P = Pos[idx];
	int now_W = Width[idx];
	int a = N - idx - 1;
	int b = 0;

	for (int i = idx + 1; i < N; i++)
	{
		now_P = pre_P + Width[i];
		if (now_P < Pos[i])
			a = min(a, b + Get(i));

		if (!(Pos[i] <= now_P && pre_P <= Pos[i]))
			b++;

		pre_P = now_P;
	}

	DP[idx] = min(a, b);

	return DP[idx];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Pos[i];
	for (int i = 0; i < N; i++)
		cin >> Width[i];

	vector<pair<int, int>> temp;
	for (int i = 0; i < N; ++i)
		temp.push_back({ Pos[i], Width[i] });
	sort(temp.begin(), temp.end());
	for (int i = 0; i < N; i++)
	{
		Pos[i] = temp[i].first;
		Width[i] = temp[i].second;
	}

	if (N <= 2)
	{
		cout << 0 << endl;
		return 0;
	}

	Init(DP, -1);

	for (int i = 0; i < N; i++)
		DP[i] = Get(i);

	for (int i = 0; i < N; i++)
		Result = min(Result, DP[i] + i);

	cout << Result << endl;
}
