#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int N, M, K;
pair<int, int> Pos[300000];
vector<int> Node;
int V[300000][2][2];
int Dist[300000][2];

priority_queue<pair<int, pair<int, int>>> pq;
int ans = INF;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 300000; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Dist[i][j] = INF;
			for (int k = 0; k < 2; k++)
			{
				V[i][j][k] = -1;
			}
		}
	}

	std::cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		std::cin >> a >> b;
		Pos[i] = { a,b };
		Node.push_back(i);
	}

	sort(Node.begin(), Node.end(),
		[](int a, int b) -> bool
		{
			if(Pos[a].first != Pos[b].first)
				return Pos[a].first < Pos[b].first;
			return Pos[a].second < Pos[b].second;
		});
	for (int i = 0; i < K - 1; i++)
		if (Pos[Node[i]].first == Pos[Node[i + 1]].first)
		{
			V[Node[i]][0][0] = Node[i + 1];
			V[Node[i + 1]][0][1] = Node[i];
		}

	for (int i = 0; i < K; i++)
		if (Pos[Node[i]].first == 1)
		{
			pq.push({ -(Pos[Node[i]].second - 1),{ Node[i],0 } });
			Dist[Node[i]][0] = 0;
			break;
		}

	sort(Node.begin(), Node.end(),
		[](int a, int b) -> bool
		{
			if (Pos[a].second != Pos[b].second)
				return Pos[a].second < Pos[b].second;
			return Pos[a].first < Pos[b].first;
		});
	for (int i = 0; i < K - 1; i++)
		if (Pos[Node[i]].second == Pos[Node[i + 1]].second)
		{
			V[Node[i]][1][0] = Node[i + 1];
			V[Node[i + 1]][1][1] = Node[i];
		}

	while (!pq.empty())
	{
		//노드번호,스위치상태,비용
		pair<int,pair<int, int>> now = pq.top();
		int cost = -now.first;
		//cout << "(" << Pos[now.second.first].first << " " << Pos[now.second.first].second << ") ";
		//cout << now.second.second << " ";
		//cout << now.first << endl;

		pq.pop();

		if (now.second.second == 0 && Pos[now.second.first].first == N)
			ans = min(ans, cost + M - Pos[now.second.first].second);
		if (now.second.second == 1 && Pos[now.second.first].second == M)
			ans = min(ans, cost + N - Pos[now.second.first].first);

		{
			int state = now.second.second == 1 ? 0 : 1;
			int nextCost = cost + 1;
			if (Dist[now.second.first][state] > nextCost)
			{
				pq.push({ -nextCost, {now.second.first,state} });
				Dist[now.second.first][state] = nextCost;
			}
		}
		{
			int a = now.second.first;
			int b = V[now.second.first][now.second.second][0];
			if (b != -1)
			{
				int c = abs(Pos[a].first - Pos[b].first) + abs(Pos[a].second - Pos[b].second);
				int nextCost = cost + c;
				pair<int, pair<int, int>> next = { -nextCost,{ b,now.second.second } };
				if (Dist[b][now.second.second] > nextCost)
				{
					pq.push(next);
					Dist[b][now.second.second] = nextCost;
				}
			}
		}
		{
			int a = now.second.first;
			int b = V[now.second.first][now.second.second][1];

			if (b != -1)
			{
				int c = abs(Pos[a].first - Pos[b].first) + abs(Pos[a].second - Pos[b].second);
				int nextCost = cost + c;
				pair<int, pair<int, int>> next = { -nextCost,{ b,now.second.second } };
				if (Dist[b][now.second.second] > nextCost)
				{
					pq.push(next);
					Dist[b][now.second.second] = nextCost;
				}
			}
	
		}
	}

	if (ans == INF)
		std::cout << -1 << endl;
	else
		std::cout << ans << endl;
}