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
int N, M;

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
		else if (a.second == b.second)
		{
			if (a.first < b.first)
				TreeMin[node] = a;
			else
				TreeMin[node] = b;
		}
		else
			TreeMin[node] = b;
	}
	return TreeMin[node];
}

pair<int, long long> GetMin(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return { 1000000,1000000 };

	if (left <= start && end <= right)
		return TreeMin[node];

	pair<int, long long> a = GetMin(node * 2, start, (start + end) / 2, left, right);
	pair<int, long long> b = GetMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a.second < b.second)
		return a;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return a;
		else
			return b;
	}
	else
		return b;
}

pair<int, long long> Update(int node, int start, int end, int index, long long After)
{
	if (start == end && end == index)
	{
		Arr[index] = After;
		TreeMin[node].second = After;
		return TreeMin[node];
	}
	if (start > index || end < index)
		return TreeMin[node];

	pair<int, long long> a = Update(node * 2, start, (start + end) / 2, index, After);
	pair<int, long long> b = Update(node * 2 + 1, (start + end) / 2 + 1, end, index, After);
	if (a.second < b.second)
		TreeMin[node] = a;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			TreeMin[node] = a;
		else
			TreeMin[node] = b;
	}
	else
		TreeMin[node] = b;

	return TreeMin[node];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int H = ceil(log2f(N));
	TreeMin.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	InitMin(1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 2)
			cout << GetMin(1, 0, N - 1, b - 1, c - 1).first + 1 << "\n";
		else
		{
			Update(1, 0, N - 1, b - 1, c);
		}

	}
}