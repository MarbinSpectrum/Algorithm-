#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

struct Pos
{
	int x, y, z;
	Pos(int ax, int bx, int cx)
	: x(ax)
	,y(bx)
	,z(cx)
	{
	}
};
int N, K;
vector<Pos> P;
vector<int> V[500001];
int Dist[500001];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	for (int i = 0; i <= N + K; i++)
		Dist[i] = INF;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		P.emplace_back(a, b, c);
	}

	{
		vector<int> arr;
		for (int i = 0; i < N; i++)
			arr.push_back(i);

		sort(arr.begin(), arr.end(),
				[](int a, int b) -> bool
				{
					if (P[a].x != P[b].x)
						return P[a].x < P[b].x;
					return P[a].y < P[b].y;
				});
		for (int i = 0; i < arr.size() - 1; i++)
		{
			int a = arr[i];
			int b = arr[i + 1];
			V[a].push_back(b);
			V[b].push_back(a);
		}
	}

	{
		vector<int> arr;
		for (int i = 0; i < N; i++)
			arr.push_back(i);

		sort(arr.begin(), arr.end(),
			[](int a, int b) -> bool
			{
				if (P[a].y != P[b].y)
					return P[a].y < P[b].y;
				return P[a].x < P[b].x;
			});
		for (int i = 0; i < arr.size() - 1; i++)
		{
			int a = arr[i];
			int b = arr[i + 1];
			V[a].push_back(b);
			V[b].push_back(a);
		}
	}

	{
		for (int i = 0; i < N; i++)
		{
			int x = P[i].z % K;
			int y = (K - x) % K;
			V[i].push_back(N + x + 1);
			V[N + y + 1].push_back(i);
		}
	}

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
			int next = V[now][i];

			if (now < N)
			{
				if (next < N)
				{
					int len = min(abs(P[now].x - P[next].x), abs(P[now].y - P[next].y));
					int nextCost = Dist[now] + len;

					if (Dist[next] > nextCost)
					{
						Dist[next] = nextCost;
						pq.push({ -nextCost,next });
					}
				}
				else
				{
					int nextCost = Dist[now] + P[now].z;
					if (Dist[next] > nextCost)
					{
						Dist[next] = nextCost;
						pq.push({ -nextCost,next });
					}
				}
			}
			else
			{
				int nextCost = Dist[now] + P[next].z;
				if (Dist[next] > nextCost)
				{
					Dist[next] = nextCost;
					pq.push({ -nextCost,next });
				}
			}		
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << Dist[i] << endl;
	}
}