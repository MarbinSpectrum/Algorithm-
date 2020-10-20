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

//int upper_bound(deque<int> arr, int key)
//{
//	int start = 0;
//	int end = arr.size() - 1;
//	int mid;
//	while (end > start)
//	{
//		mid = (start + end) / 2;
//		if (arr[mid] <= key)
//			start = mid + 1;
//		else
//			end = mid;
//	}
//	return end + 1;
//}

vector<deque<int>> SegTree;
void InitSeg(int node, int left, int right)
{
	if (left == right)
		SegTree[node].push_back(A[left]);
	else
	{
		int mid = (left + right) / 2;
		InitSeg(node * 2, left, mid);
		InitSeg(node * 2 + 1, mid + 1, right);
		deque<int> temp0 = SegTree[node * 2];
		deque<int> temp1 = SegTree[node * 2 + 1];
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
//
//void UpdateSeg(int node, int start, int end, int left, int right, int diff)
//{
//	if (left > end || right < start)
//		return;
//	int mid = (left + right) / 2;
//	UpdateSeg(node * 2, start, end, left, mid, diff);
//	UpdateSeg(node * 2 + 1, start, end, mid + 1, right, diff);
//}

int GetSeg(int node, int start, int end, int left, int right, int find)
{
	if (left > end || right < start)
		return 0;
	if (start <= left && right <= end)
	{
		//cout << "Arr : ";
		//for (int i = 0; i < SegTree[node].size(); i++)
		//	cout << SegTree[node][i] << " ";
		//cout << endl;
		//int idx = upper_bound(SegTree[node], find);
		//if (SegTree[node].size() == idx)
		//	return SegTree[node][idx - 1] > find ? 1 : 0;
		//else
		//	return SegTree[node].size() - idx + 1;
		return SegTree[node].end() - upper_bound(SegTree[node].begin(), SegTree[node].end(), find);
	}
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

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	SegTree.resize(tree_size);

	for (int i = 1; i <= N; i++)
		cin >> A[i];


	//해결부

	InitSeg(1, 1, N);

	cin >> M;

	int d = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d = GetSeg(1, a, b, 1, N, c);
		Result.push_back(d);
	}

	for (int i = 0; i < Result.size(); i++)
		cout << Result[i] << endl;

}