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
long long mod = 1000000007;
int N, M, K;
long long Init(int node, int start, int end)
{
	if (start == end)
		Tree[node] = Arr[start];
	else
		Tree[node] = ((Init(node * 2, start, (start + end) / 2) % mod) * (Init(node * 2 + 1, (start + end) / 2 + 1, end) % mod)) % mod;

	return Tree[node];
}

long long Mul(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return Tree[node];

	return ((Mul(node * 2, start, (start + end) / 2, left, right) % mod) * (Mul(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % mod)) % mod;
}

long long Update(int node, int start, int end, int index, long long After)
{
	if (start == end && end == index)
	{
		Arr[index] = After;
		Tree[node] = After;
		return Tree[node];
	}
	if (start > index || end < index)
		return Tree[node];

	Tree[node] = ((Update(node * 2, start, (start + end) / 2, index, After) % mod) * (Update(node * 2 + 1, (start + end) / 2 + 1, end, index, After) % mod) % mod);
	return Tree[node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	int H = ceil(log2f(N));
	Tree.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	Init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			b--;
			Update(1, 0, N - 1, b, c);
		}
		else if (a == 2)
		{
			b--;
			c--;
			cout << Mul(1, 0, N - 1, b, c) % mod << endl;
		}


	}
}