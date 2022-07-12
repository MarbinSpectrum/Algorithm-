#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

////////////////////////////////////////////////////////////////////////

int Q;
vector<tuple<int, int, int>> Query1;
map<int, vector<pair<int,pair<int, int>>>> Query2;

int N = 0;
map<int, int> Idx;
int Num[200000];
int Tree[3000000];
int TreeC[3000000];
int Lazy[3000000];

int Sum(int node, int s, int e, int l, int r)
{
	if (Lazy[node] != 0)
	{
		Tree[node] += (Num[e] - Num[s] + 1) * Lazy[node];
		if (s != e)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	if (l > e || r < s)
		return 0;

	if (l <= s && e <= r)
	{
		cout << "+(" << node << ")";
		cout << Tree[node] << endl;
		return Tree[node];
	}

	int add = 0;
	if (!((s <= l && r <= (s + e) / 2) || ((s + e) / 2 + 1 <= l && r <= e)))
	{
		cout << "++(" << node << ")";
		cout << TreeC[node] << endl;
		add = TreeC[node];
	}

	return Sum(node * 2, s, (s + e) / 2, l, r)
		+ Sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r) + add;
}

void Update(int node, int s, int e,int l, int r, int add)
{
	if (Lazy[node] != 0)
	{
		Tree[node] += (Num[e] - Num[s] + 1) * Lazy[node];
		if (s != e)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	if (l > e || r < s)
		return;
	if (l <= s && e <= r)
	{
		Tree[node] += (Num[e] - Num[s] + 1) * add;
		//cout << (Num[e] - Num[s] + 1) * add << endl;
		if (s != e)
		{
			Lazy[node * 2] += add;
			Lazy[node * 2 + 1] += add;
		}
		return;
	}

	TreeC[node] += (Num[(s + e) / 2 + 1] - Num[(s + e) / 2] - 1) * add;

	Update(node * 2, s, (s + e) / 2, l, r, add);
	Update(node * 2 + 1, (s + e) / 2 + 1, e, l, r, add);

	Tree[node] = Tree[node * 2] + Tree[node * 2 + 1] + TreeC[node];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Q;

	set<int> num;

	for (int i = 0; i < Q; i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		if (num.find(b) == num.end())
			num.insert(b);
		if (num.find(c) == num.end())
			num.insert(c);

		if (a == 1)
		{
			Query1.push_back({ b,c,d });
		}
		else if (a == 2)
		{
			Query2[d].push_back({ i,{ b,c } });
		}
	}

	for (set<int>::iterator iter = num.begin(); iter != num.end(); iter++)
	{
		N++;
		Idx[*iter] = N;
		Num[N] = *iter;
		//cout << *iter << " ";
	}
	cout << endl;

	for (int i = 0; i < Query1.size(); i++)
	{
		int b = get<0>(Query1[i]);
		int c = get<1>(Query1[i]);
		int d = get<2>(Query1[i]);
		cout << "!";
		cout << Idx[b] << " " << Idx[c] << endl;
		cout << b << " " << c << endl << endl;
		Update(1, 1, N, Idx[b], Idx[c], d);
		if (Query2.find(i+1) != Query2.end())
		{
			vector<pair<int, pair<int, int>>>& li = Query2[i+1];

			for (int j = 0; j < li.size(); j++)
			{
				b = li[j].second.first;
				c = li[j].second.second;
				cout << "@";
				cout << Idx[b] << " " << Idx[c] << endl;
				cout << b << " " << c << endl;
				std::cout << Sum(1, 1, N, Idx[b], Idx[c]) << endl << endl;
			}
		}
	}

}