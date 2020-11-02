#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

#pragma warning(disable:4996)

using namespace std;

int N, K;
int MinT = 0;
int Result = 999999999;
int DataMap[101];
deque<pair<int, int>> Data;
int G(int t, pair<int, int> d)
{
	return 30 + (d.first - t) * d.second;
}
void S(deque<pair<int, int>> arr, int T, int k)
{
	if (arr.size() == 0)
	{
		Result = min(Result, T);
		return;
	}
	MinT = 987654321;
	for (int i = 0; i < arr.size(); i++)
		MinT = min(MinT, arr[i].first);
	sort(arr.begin(), arr.end(), [](pair<int, int> A, pair<int, int> B) -> bool { return G(MinT, A) < G(MinT, B); });
	int tt = MinT;
	while (!arr.empty())
	{
		int t = G(tt, arr.front());
		arr.pop_front();
		if (k + 1 <= K) S(arr, T + t, k + 1);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(DataMap, -1, sizeof(DataMap));
	cin >> N >> K;
	for (int a, b, i = 0; i < N; i++) {
		cin >> a >> b;
		DataMap[a] = max(DataMap[a], b);
	}
	for (int i = 0; i <= 100; i++)
		if (DataMap[i] > 0)
			Data.push_back({ i,DataMap[i] });
	S(Data, 0, 0);
	cout << Result << "\n";
}