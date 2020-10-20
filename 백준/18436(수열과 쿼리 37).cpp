#include<iostream>
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
long long InitEven(int node, int start, int end)
{
	if (start == end)
	{
		if (Arr[end] % 2 == 0)
			Tree[node] = 1;
		else
			Tree[node] = 0;
	}
	else
		Tree[node] = InitEven(node * 2, start, (start + end) / 2) + InitEven(node * 2 + 1, (start + end) / 2 + 1, end);

	return Tree[node];
}

long long SumEven(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return Tree[node];
	return SumEven(node * 2, start, (start + end) / 2, left, right) + SumEven(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	int H = ceil(log2f(N));
	H = 1 << (H + 1);
	Tree.resize(H);
	InitEven(1, 0, N - 1);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			if (Arr[b - 1] % 2 != c % 2)
			{
				if (c % 2 == 0)
					Update(1, 0, N - 1, b - 1, 1);
				else
					Update(1, 0, N - 1, b - 1, -1);
			}


		}
		else if (a == 2)
			cout << SumEven(1, 0, N - 1, b - 1, c - 1) << "\n";
		else if (a == 3)
		{
			long long temp = SumEven(1, 0, N - 1, b - 1, c - 1);
			cout << abs(b - c) + 1 - temp << "\n";
		}
	}
}