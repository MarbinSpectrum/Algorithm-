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


//최소값을 가지고있는 세그먼트트리
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int H = ceil(log2f(N));
	TreeMin.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	InitMin(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << GetMin(1, 0, N - 1, a - 1, b - 1) << "\n";

	}
}