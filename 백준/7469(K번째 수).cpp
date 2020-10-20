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

//각정점 방문 체크
bool Visit[MAX];

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
		vector<int> temp0 = SegTree[node * 2];
		vector<int> temp1 = SegTree[node * 2 + 1];
		int a = 0;
		int b = 0;
		while (temp0.size() > a || temp1.size() > b)
		{
			if (a < temp0.size() && b < temp1.size())
			{
				if (temp0[a] <= temp1[b])
				{
					SegTree[node].push_back(temp0[a]);
					a++;
				}
				else
				{
					SegTree[node].push_back(temp1[b]);
					b++;
				}
			}
			else if (temp0.size() > a&& temp1.size() <= b)
			{
				SegTree[node].push_back(temp0[a]);
				a++;
			}
			else if (temp0.size() <= a && temp1.size() > b)
			{
				SegTree[node].push_back(temp1[b]);
				b++;
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

vector<int> Result;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//입력부
	cin >> N;
	cin >> M;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	SegTree.resize(tree_size);

	for (int i = 1; i <= N; i++)
		cin >> A[i];


	//해결부

	InitSeg(1, 1, N);


	for (int i = 0; i < M; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c;
		int left = -1000000000;
		int right = 1000000000;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			//mid 이상인수 갯수
			d = GetSeg(1, a, b, 1, N, mid);
			//mid 미만인수 갯수
			e = abs(b - a + 1) - d;

			//Debug(e, d);
			//Debug(mid, "");
			if (e >= c)
				right = mid - 1;
			else
				left = mid + 1;
		}
		Result.push_back(right);
	}

	for (int i = 0; i < Result.size(); i++)
		cout << Result[i] + 1 << endl;

}