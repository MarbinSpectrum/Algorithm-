#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

struct Edge
{
	int v, w, p;
	Edge(int av, int aw, int ap)
	: v(av)
	, w(aw)
	, p(ap)
	{
	}
};
int N, M, X;
vector<Edge> V[200001];
int Dist[200001];

int F(int a,int b)
{
	for (int i = 0; i < N; i++)
		Dist[i] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,0 });
	Dist[0] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (Dist[now] < cost)
			continue;

		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i].v;
			int w = V[now][i].w;
			int p = V[now][i].p;

			int nextCost = Dist[now] + w + 
				((p == 0) ? 0 : 
				(p == 1) ? a : b);

			if (Dist[next] > nextCost)
			{
				Dist[next] = nextCost;
				pq.push({ -nextCost,next });
			}
		}
	}
	return Dist[N - 1];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		a--, b--;

		V[a].emplace_back(b, c, d);
		V[b].emplace_back(a, c, d);
	}

	int s = 0;
	int e = X;
	while (3 <= e - s)
	{
		int L = (s * 2 + e) / 3;
		int R = (s + e * 2) / 3;
		if (F(L, X - L) >= F(R, X - R))
			e = R;
		else
			s = L;
	}

	int Result = -1;
	for (int i = s; i <= e; i++)
		Result = max(Result, F(i, X - i));

	cout << Result << endl;
}