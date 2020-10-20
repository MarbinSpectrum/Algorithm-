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

//트리
vector<int> TempTree[MAX];
vector<int> Tree[MAX];
void SetTree(int n)
{
	Visit[n] = true;
	for (int i = 0; i < TempTree[n].size(); i++)
	{
		int child = TempTree[n][i];
		if (!Visit[child])
			Tree[n].push_back(child);
	}

	for (int i = 0; i < TempTree[n].size(); i++)
	{
		int child = TempTree[n][i];
		if (!Visit[child])
			SetTree(child);
	}
}

//x정점의 가중치
int A[MAX];
//x가 세그먼트 트리에서 몇번째노드인지 저장
int Numbering[MAX];
//Numbering을 노드기준으로 정렬//x에 해당하는 값을 가지고있다.
vector<int> NumberingSort(1);

void SetNumbering(int n)
{
	for (int i = 0; i < Tree[n].size(); i++)
	{
		int child = Tree[n][i];
		SetNumbering(child);
	}
	Numbering[n] = NumberingSort.size();
	NumberingSort.push_back(A[n]);
}
//x의 자식수가 몇개인지 저장
int NumChild[MAX];
void SetNumChild(int n)
{
	int temp = Tree[n].size();
	for (int i = 0; i < Tree[n].size(); i++)
	{
		int child = Tree[n][i];
		SetNumChild(child);
		temp += NumChild[child];
	}
	NumChild[n] = temp;
}

vector<int> SegTree;
void InitSegTree(int node, int left, int right)
{
	if (left == right)
		SegTree[node] = NumberingSort[left];
	else
	{
		int mid = (left + right) / 2;
		InitSegTree(node * 2, left, mid);
		InitSegTree(node * 2 + 1, mid + 1, right);
		SegTree[node] = SegTree[node * 2] + SegTree[node * 2 + 1];
	}
}

vector<int> SegLazy;
void UpdateLazy(int node, int left, int right)
{
	if (SegLazy[node] != 0)
	{
		SegTree[node] += SegLazy[node] * (right - left + 1);
		if (left != right)
		{
			SegLazy[node * 2] += SegLazy[node];
			SegLazy[node * 2 + 1] += SegLazy[node];
		}
		SegLazy[node] = 0;
	}
}
void UpdateSeg(int node, int start, int end, int left, int right, int diff)
{
	UpdateLazy(node, left, right);
	if (left > end || right < start)
		return;
	if (start <= left && right <= end)
	{
		SegTree[node] += diff * (right - left + 1);
		if (left != right)
		{
			SegLazy[node * 2] += diff;
			SegLazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (left + right) / 2;
	UpdateSeg(node * 2, start, end, left, mid, diff);
	UpdateSeg(node * 2 + 1, start, end, mid + 1, right, diff);
	SegTree[node] = SegTree[node * 2] + SegTree[node * 2 + 1];
}

int GetSeg(int node, int start, int end, int left, int right)
{
	UpdateLazy(node, left, right);
	if (left > end || right < start)
		return 0;
	if (start <= left && right <= end)
		return SegTree[node];
	int mid = (left + right) / 2;
	return GetSeg(node * 2, start, end, left, mid) + GetSeg(node * 2 + 1, start, end, mid + 1, right);
}

vector<int> Result;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//입력부
	cin >> N >> M;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	SegTree.resize(tree_size);
	SegLazy.resize(tree_size);

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		if (i == 1)
			cin >> a;
		else
		{
			cin >> a >> b;
			TempTree[b].push_back(i);
			TempTree[i].push_back(b);
		}
		A[i] = a;
	}

	//해결부
	Init(Visit, false);
	Init(Numbering, 0);
	Init(NumChild, 0);
	SetTree(1);
	SetNumbering(1);
	SetNumChild(1);

	InitSegTree(1, 1, N);

	for (int i = 0; i < M; i++)
	{
		char a;
		int b, c;
		cin >> a;
		if (a == 'u')
		{
			cin >> b;
			Result.push_back(GetSeg(1, Numbering[b], Numbering[b], 1, N));
		}
		else if (a == 'p')
		{
			cin >> b >> c;
			UpdateSeg(1, Numbering[b] - NumChild[b], Numbering[b], 1, N, c);
			UpdateSeg(1, Numbering[b], Numbering[b], 1, N, -c);
		}
	}

	for (int i = 0; i < Result.size(); i++)
		cout << Result[i] << endl;

}