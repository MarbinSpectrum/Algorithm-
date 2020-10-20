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
		Tree[node] = Init(node * 2, start, (start + end) / 2) * Init(node * 2 + 1, (start + end) / 2 + 1, end);

	return Tree[node];
}

long long Mul(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return Tree[node];

	return Mul(node * 2, start, (start + end) / 2, left, right) * Mul(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
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

	Tree[node] = Update(node * 2, start, (start + end) / 2, index, After) * Update(node * 2 + 1, (start + end) / 2 + 1, end, index, After);
	return Tree[node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> N >> M)
	{
		string s = "";
		int H = ceil(log2f(N));
		Tree.resize(pow(2, H + 1));
		for (int i = 0; i < N; i++)
		{
			long long temp;
			cin >> temp;
			if (temp > 0)
				Arr[i] = +1;
			else if (temp < 0)
				Arr[i] = -1;
			else
				Arr[i] = 0;
		}
		Init(1, 0, N - 1);

		for (int i = 0; i < M; i++)
		{
			char a;
			cin >> a;
			if (a == 'C')
			{
				long long b, c;
				cin >> b >> c;
				b--;
				long long temp;
				if (c > 0)
					temp = +1;
				else if (c < 0)
					temp = -1;
				else
					temp = 0;
				Update(1, 0, N - 1, b, temp);
			}
			else
			{
				long long b, c;
				cin >> b >> c;
				b--;
				c--;
				long long R = Mul(1, 0, N - 1, b, c);
				if (R > 0)
					s += "+";
				else if (R < 0)
					s += "-";
				else
					s += "0";
			}
		}
		cout << s << "\n";
	}
}