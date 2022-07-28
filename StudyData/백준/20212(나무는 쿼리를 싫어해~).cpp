#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

struct Node
{
	Node* left;
	Node* right;
	int v;
	int lazy;
	Node()
		: left(NULL)
		, right(NULL)
		, v(0)
		, lazy(0)
	{
	}
	void push(int s, int e)
	{
		if (lazy == 0)
			return;
		v += lazy * (e - s + 1);
		if (s == e)
		{
			lazy = 0;
			return;
		}
		if (left == NULL)
			left = new Node();
		if (right == NULL)
			right = new Node();
		left->lazy += lazy;
		right->lazy += lazy;
		lazy = 0;
	}
};
Node* root;

long long Sum(Node* node, int s, int e, int l, int r)
{
	if (node == NULL)
		return 0;

	node->push(s, e);

	if (l > e || r < s)
		return 0;

	if (l <= s && e <= r)
		return node->v;

	return Sum(node->left, s, (s + e) / 2, l, r) +
		Sum(node->right, (s + e) / 2 + 1, e, l, r);
}

void Update(Node* node, int s, int e, int l, int r, int add)
{
	node->push(s, e);

	if (l > e || r < s)
		return;

	if (l <= s && e <= r)
	{
		node->lazy += add;
		node->push(s, e);
		return;
	}

	if (node->left == NULL)
		node->left = new Node();
	if (node->right == NULL)
		node->right = new Node();

	Update(node->left, s, (s + e) / 2, l, r, add);
	Update(node->right, (s + e) / 2 + 1, e, l, r, add);

	node->v = node->left->v + node->right->v;
}

int N;
vector<pair<int, pair<int, tuple<int, int, int>>>> Query;
vector<pair<int, int>> Ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	root = new Node();
	std::cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		if (a == 1)
		{
			cnt++;
			Query.push_back({ cnt ,{a,{b,c,d}} });
		}
		else
		{
			Query.push_back({ d ,{a,{b,c,i}} });
		}
	}

	sort(Query.begin(), Query.end());

	for (int i = 0; i < N; i++)
	{
		if (Query[i].second.first == 1)
		{
			int s = get<0>(Query[i].second.second);
			int e = get<1>(Query[i].second.second);
			int add = get<2>(Query[i].second.second);
			Update(root, 1, INF, s, e, add);
		}
		else
		{
			int s = get<0>(Query[i].second.second);
			int e = get<1>(Query[i].second.second);
			int sum = Sum(root, 1, INF, s, e);
			Ans.push_back({ get<2>(Query[i].second.second),sum });
		}
	}

	sort(Ans.begin(), Ans.end());

	for (int i = 0; i < Ans.size(); i++)
	{
		std::cout << Ans[i].second << endl;
	}

}