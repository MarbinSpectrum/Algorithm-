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

vector<pair<long long, int>> Tree;
long long Arr[1000001];
int N, M;

void Init(long long node, long long start, long long end)
{
	if (start == end)
		Tree[node] = { Arr[start],0 };
	else
	{
		Tree[node] = { 0,0 };
		Init(node * 2, start, (start + end) / 2);
		Init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long Get(long long node, long long start, long long end, long long index, long long sum)
{
	if (start > index || end < index)
		return 0;
	if (Tree[node].first > 0)
		sum += Tree[node].first + abs(index - start) * Tree[node].second;
	if (start == end)
		return sum;
	return Get(node * 2, start, (start + end) / 2, index, sum) + Get(node * 2 + 1, (start + end) / 2 + 1, end, index, sum);
}

void Update(long long node, long long start, long long end, long long left, long long right)
{
	if (left <= start && end <= right)
	{
		Tree[node].first += (long long)1 + abs(left - start);
		Tree[node].second += 1;
		return;
	}
	if (start > right || end < left)
		return;

	Update(node * 2, start, (start + end) / 2, left, right);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
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
		long long a, b, c;
		cin >> a;
		if (a == 2)
		{
			cin >> b;
			cout << Get(1, 0, N - 1, b - 1, 0) << "\n";
		}
		else
		{
			cin >> b >> c;
			Update(1, 0, N - 1, b - 1, c - 1);
		}

	}
}