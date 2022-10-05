#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//////////////////////////////////////////////////////////////////////// 

const int MAX = 250005;
int N, M, K;
vector<pair<int, int>> V[MAX];
int Dist[MAX];
vector<int> A;
int Owner[MAX];
float Ans[MAX];
vector<pair<pair<int, int>, int>> Edge;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		std::cin >> a >> b >> w;
		V[a].push_back({ b,w });
		V[b].push_back({ a,w });

		Edge.push_back({ {a,b},w });
	}

	for (int i = 1; i <= N; i++)
	{
		Dist[i] = INF;
		Owner[i] = INF;
	}

	std::cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a;
		std::cin >> a;
		A.push_back(a);
	}

	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < A.size(); i++)
	{
		int a = A[i];
		pq.push({ 0,{a,a } });
		Dist[a] = 0;
		Owner[a] = a;
	}

	while (pq.empty() == false)
	{
		pair<int, pair<int, int>> nowQ = pq.top();
		pq.pop();

		int nowP = nowQ.second.first;
		int nowOwner = nowQ.second.second;
		int nowCost = -nowQ.first;

		if (Dist[nowP] < nowCost)
			continue;

		for (int i = 0; i < V[nowP].size(); i++)
		{
			pair<int, int> next = V[nowP][i];
			int nextP = next.first;
			int nextCost = nowCost + next.second;

			if (Dist[nextP] > nextCost)
			{
				Dist[nextP] = nextCost;
				Owner[nextP] = nowOwner;
				pq.push({ -nextCost,{nextP,nowOwner } });

			}
			else if (Dist[nextP] == nextCost && Owner[nextP] > nowOwner)
			{
				Owner[nextP] = nowOwner;
				pq.push({ -nextCost,{nextP,nowOwner } });
			}
		}
	}

	for (int i = 0; i < Edge.size(); i++)
	{
		int a = Edge[i].first.first;
		int b = Edge[i].first.second;
		int cost = Edge[i].second;

		if (Owner[a] == Owner[b])
		{
			Ans[Owner[a]] += cost;
		}
		else
		{
			float sum = Dist[a] + cost + Dist[b];
			Ans[Owner[a]] += abs((float)Dist[a] - sum * 0.5);
			Ans[Owner[b]] += abs((float)Dist[b] - sum * 0.5);
		}
	}

	cout << fixed << setprecision(1);
	for (int i = 0; i < A.size(); i++)
	{
		cout << Ans[A[i]] << endl;
	}
}