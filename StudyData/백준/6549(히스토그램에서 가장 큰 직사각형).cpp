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

vector<pair<int, long long>> TreeMin;
long long Arr[1000001];
int N;
long long Result = 0;

//최소값과 해당 인덱스를 가지고있는 세그먼트트리
pair<int, long long> InitMin(int node, int start, int end)
{
	if (start == end)
		TreeMin[node] = { start,Arr[start] };
	else
	{
		pair<int, long long> a = InitMin(node * 2, start, (start + end) / 2);
		pair<int, long long> b = InitMin(node * 2 + 1, (start + end) / 2 + 1, end);
		if (a.second < b.second)
			TreeMin[node] = a;
		else
			TreeMin[node] = b;

	}
	return TreeMin[node];
}

pair<int, long long> GetMin(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return { 0,1000000001 };

	if (left <= start && end <= right)
		return TreeMin[node];

	pair<int, long long> a = GetMin(node * 2, start, (start + end) / 2, left, right);
	pair<int, long long> b = GetMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a.second < b.second)
		return a;
	else
		return b;
}

void DFS(int left, int right)
{
	if (left <= right)
	{
		pair<int, long long> h = GetMin(1, 0, N - 1, left, right);
		long long w = abs(left - right) + 1;
		Result = max(w * h.second, Result);
		DFS(left, h.first - 1);
		DFS(h.first + 1, right);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> N;
		Result = 0;
		if (N == 0)
			break;
		int H = ceil(log2f(N));
		TreeMin.resize(pow(2, H + 1));
		for (int i = 0; i < N; i++)
			cin >> Arr[i];
		InitMin(1, 0, N - 1);
		DFS(0, N - 1);
		cout << Result << endl;

	}


}