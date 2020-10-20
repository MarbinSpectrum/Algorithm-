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

vector<pair<int, long long>> TreeMax;
long long Arr[1000001];
int N, M;

pair<int, long long> InitMin(int node, int start, int end)
{
	if (start == end)
		TreeMax[node] = { start,Arr[start] };
	else
	{
		pair<int, long long> a = InitMin(node * 2, start, (start + end) / 2);
		pair<int, long long> b = InitMin(node * 2 + 1, (start + end) / 2 + 1, end);
		if (a.second < b.second)
			TreeMax[node] = b;
		else
			TreeMax[node] = a;
	}
	return TreeMax[node];
}

pair<int, long long> GetMax(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return { 0,0 };

	if (left <= start && end <= right)
		return TreeMax[node];

	pair<int, long long> a = GetMax(node * 2, start, (start + end) / 2, left, right);
	pair<int, long long> b = GetMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a.second < b.second)
		return b;
	else
		return a;
}

pair<int, long long> Update(int node, int start, int end, int index, long long After)
{
	if (start == end && end == index)
	{
		Arr[index] = After;
		TreeMax[node].second = After;
		return TreeMax[node];
	}
	if (start > index || end < index)
		return TreeMax[node];

	pair<int, long long> a = Update(node * 2, start, (start + end) / 2, index, After);
	pair<int, long long> b = Update(node * 2 + 1, (start + end) / 2 + 1, end, index, After);
	if (a.second < b.second)
		TreeMax[node] = b;
	else
		TreeMax[node] = a;

	return TreeMax[node];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int H = ceil(log2f(N));
	TreeMax.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	InitMin(1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 2)
		{
			int i, ja, jb;
			i = GetMax(1, 0, N - 1, b - 1, c - 1).first;
			ja = -1;
			jb = -1;
			if (b - 1 <= i - 1)
				ja = GetMax(1, 0, N - 1, b - 1, i - 1).first;
			if (i + 1 <= c - 1)
				jb = GetMax(1, 0, N - 1, i + 1, c - 1).first;

			if (ja != -1 && jb != -1)
				cout << Arr[i] + max(Arr[ja], Arr[jb]) << "\n";
			else if (ja == -1 && jb != -1)
				cout << Arr[i] + Arr[jb] << "\n";
			else if (ja != -1 && jb == -1)
				cout << Arr[i] + Arr[ja] << "\n";
		}
		else
			Update(1, 0, N - 1, b - 1, c);

	}
}