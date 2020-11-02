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

const int MAX = 500001;
int N, M;

int A[MAX];

vector<vector<int>> SegTree;
void InitSeg(int node, int left, int right)
{
	if (left == right)
		SegTree[node].push_back(A[left]);
	else
	{
		int mid = (left + right) / 2;
		InitSeg(node * 2, left, mid);
		InitSeg(node * 2 + 1, mid + 1, right);

		deque<int> temp0;
		for (int i = 0; i < SegTree[node * 2].size(); i++)
			temp0.push_back(SegTree[node * 2][i]);
		deque<int> temp1;
		for (int i = 0; i < SegTree[node * 2 + 1].size(); i++)
			temp1.push_back(SegTree[node * 2 + 1][i]);

		while (temp0.size() > 0 || temp1.size() > 0)
		{
			if (!temp0.empty() && !temp1.empty())
			{
				if (temp0.front() <= temp1.front())
				{
					SegTree[node].push_back(temp0.front());
					temp0.pop_front();
				}
				else
				{
					SegTree[node].push_back(temp1.front());
					temp1.pop_front();
				}
			}
			else if (!temp0.empty() && temp1.empty())
			{
				SegTree[node].push_back(temp0.front());
				temp0.pop_front();
			}
			else if (temp0.empty() && !temp1.empty())
			{
				SegTree[node].push_back(temp1.front());
				temp1.pop_front();
			}
		}
	}
}

int GetSeg(int node, int start, int end, int left, int right, int find)
{
	if (left > end || right < start)
		return 0;
	if (start <= left && right <= end)
		return SegTree[node].end() - upper_bound(SegTree[node].begin(), SegTree[node].end(), find);
	int mid = (left + right) / 2;
	return GetSeg(node * 2, start, end, left, mid, find) + GetSeg(node * 2 + 1, start, end, mid + 1, right, find);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//입력부
	cin >> N;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	SegTree.resize(tree_size);

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	//해결부

	InitSeg(1, 1, N);

	int d = 0;
	for (int i = 1; i <= N; i++)
		cout << GetSeg(1, 1, i, 1, N, A[i]) + 1 << endl;
}