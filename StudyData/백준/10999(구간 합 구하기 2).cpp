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
vector<long long> Lazy;
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
	if (Lazy[node] != 0)
	{
		Tree[node] += (end - start + 1) * Lazy[node];
		if (start != end)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return Tree[node];

	return Sum(node * 2, start, (start + end) / 2, left, right) + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void Update(int node, int start, int end, int left, int right, long long add)
{
	if (Lazy[node] != 0)
	{
		Tree[node] += (end - start + 1) * Lazy[node];
		if (start != end)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	if (left > end || right < start)
		return;

	if (left <= start && end <= right)
	{
		Tree[node] += (end - start + 1) * add;
		if (start != end)
		{
			Lazy[node * 2] += add;
			Lazy[node * 2 + 1] += add;
		}
		return;
	}

	Update(node * 2, start, (start + end) / 2, left, right, add);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, add);

	Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	int H = ceil(log2f(N));
	Tree.resize(pow(2, H + 1));
	Lazy.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	Init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c, d;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			b--;
			c--;
			Update(1, 0, N - 1, b, c, d);
		}
		else if (a == 2)
		{
			cin >> b >> c;
			b--;
			c--;
			cout << Sum(1, 0, N - 1, b, c) << endl;
		}


	}
}