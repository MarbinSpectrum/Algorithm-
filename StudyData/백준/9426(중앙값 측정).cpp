#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <tuple>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 9999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

const int MAX = 250001;

vector<int> SegTree;
int Arr[MAX];
int N, M, K;

int Get(int node, int start, int end, int find)
{
	if (start == end)
		return start;
	if (SegTree[node * 2] >= find)
		return Get(node * 2, start, (start + end) / 2, find);
	else
		return Get(node * 2 + 1, (start + end) / 2 + 1, end, find - SegTree[node * 2]);
}

int Update(int node, int start, int end, int index, long long diff)
{
	if (end < index || index < start)
		return SegTree[node];
	if (start == end)
	{
		SegTree[node] += diff;
		return SegTree[node];
	}
	int mid = (start + end) / 2;
	return SegTree[node] = Update(node * 2, start, mid, index, diff) + Update(node * 2 + 1, mid + 1, end, index, diff);

}

int Result = 0;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//입력부
	cin >> N;
	cin >> M;

	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	SegTree.resize(tree_size);

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	//해결부

	for (int i = 0; i < M - 1; i++)
		Update(1, 0, MAX - 1, Arr[i], 1);

	for (int i = M - 1; i < N; i++)
	{
		Update(1, 0, MAX - 1, Arr[i], 1);
		Result += Get(1, 0, MAX - 1, (M + 1) / 2);
		Update(1, 0, MAX - 1, Arr[i - M + 1], -1);
	}

	cout << Result << endl;

}