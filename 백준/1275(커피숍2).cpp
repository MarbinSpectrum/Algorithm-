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

vector<long long> Tree;
long long Arr[1000001];

int N, M, K;
long long Init(int node, int start, int end)
{
	if (start == end)
		Tree[node] = Arr[start];
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

void Update(int node, int start, int end, int index, long long diff)
{
	if (start == end && end == index)
	{
		Arr[index] += diff;
		Tree[node] += diff;
		return;
	}
	if (start > index || end < index)
		return;
	Tree[node] += diff;
	Update(node * 2, start, (start + end) / 2, index, diff);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int H = ceil(log2f(N));
	Tree.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	Init(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << Sum(1, 0, N - 1, min(a - 1, b - 1), max(a - 1, b - 1)) << "\n";
		Update(1, 0, N - 1, c - 1, d - Arr[c - 1]);


	}
}