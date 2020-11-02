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

vector<long long> TreeMin;
long long Arr[1000001];
int N, M, K;


long long InitMin(int node, int start, int end)
{
	if (start == end)
		TreeMin[node] = Arr[start];
	else
		TreeMin[node] = min(InitMin(node * 2, start, (start + end) / 2), InitMin(node * 2 + 1, (start + end) / 2 + 1, end));
	return TreeMin[node];
}

long long GetMin(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1000000001;

	if (left <= start && end <= right)
		return TreeMin[node];

	return min(GetMin(node * 2, start, (start + end) / 2, left, right), GetMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
long long Update(int node, int start, int end, int index, long long After)
{
	if (start == end && end == index)
	{
		Arr[index] = After;
		TreeMin[node] = After;
		return TreeMin[node];
	}
	if (start > index || end < index)
		return TreeMin[node];

	TreeMin[node] = min(Update(node * 2, start, (start + end) / 2, index, After), Update(node * 2 + 1, (start + end) / 2 + 1, end, index, After));

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
		if (a == 1)
		{
			Update(1, 0, N - 1, b - 1, c);
		}
		else if (a == 2)
			cout << GetMin(1, 0, N - 1, b - 1, c - 1) << "\n";
	}
}