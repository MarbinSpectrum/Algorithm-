﻿#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>

#pragma warning(disable:4996)

using namespace std;

int N, M;
long long Arr[1000001];
vector<long long> Tree;
vector<long long> Result;
long long Init(int node, int start, int end)
{
	if (start == end)
		Tree[node] = Arr[end];
	else
		Tree[node] = Init(node * 2, start, (start + end) / 2) + Init(node * 2 + 1, (start + end) / 2 + 1, end);

	return Tree[node];
}

long long Sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return Tree[node];
	return Sum(node * 2, start, (start + end) / 2, left, right) + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

long long Update(int node, int start, int end, int index, long long change)
{
	if (start == end && index == start)
	{
		Tree[node] = change;
		Arr[index] = change;
	}
	else if (start <= index && index <= end)
		Tree[node] = Update(node * 2, start, (start + end) / 2, index, change) + Update(node * 2 + 1, (start + end) / 2 + 1, end, index, change);

	return Tree[node];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int H = ceil(log2f(N));
	H = 1 << (H + 1);
	Tree.resize(H);
	Init(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			long long r = Sum(1, 0, N - 1, min(b - 1, c - 1), max(b - 1, c - 1));
			Result.push_back(r);
		}
		else
			Update(1, 0, N - 1, b - 1, c);
	}

	for (int i = 0; i < Result.size(); i++)
		cout << Result[i] << "\n";
}