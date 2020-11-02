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
int N, M;

void Init(int node, int start, int end)
{
	if (start == end)
		Tree[node] = Arr[start];
	else
	{
		Tree[node] = 0;
		Init(node * 2, start, (start + end) / 2);
		Init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long Get(int node, int start, int end, int index, long long sum)
{
	if (start > index || end < index)
		return 0;
	sum += Tree[node];
	if (start == end)
		return sum;
	return Get(node * 2, start, (start + end) / 2, index, sum) + Get(node * 2 + 1, (start + end) / 2 + 1, end, index, sum);
}

void Update(int node, int start, int end, int left, int right, long long  k)
{
	if (left <= start && end <= right)
	{
		Tree[node] += k;
		return;
	}
	if (start > right || end < left)
		return;

	Update(node * 2, start, (start + end) / 2, left, right, k);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, k);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int H = ceil(log2f(N));
	Tree.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	Init(1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c, d;
		cin >> a;
		if (a == 2)
		{
			cin >> b;
			cout << Get(1, 0, N - 1, b - 1, 0) << "\n";
		}
		else
		{
			cin >> b >> c >> d;
			Update(1, 0, N - 1, b - 1, c - 1, d);
		}

	}
}