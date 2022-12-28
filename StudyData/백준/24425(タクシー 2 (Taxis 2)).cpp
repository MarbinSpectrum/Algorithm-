#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e15;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N, M, Q, L;
vector<pair<int, int>> V[200001];
int Dist[200001][31];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N >> M >> Q >> L;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        V[a].emplace_back(b, c);
        V[b].emplace_back(a, c);
    }

    for (int i = 1; i <= N; i++)
        for(int j = 0; j <= 30; j++)
            Dist[i][j] = INF;

    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({ -1,{1,0} });
    Dist[1][0]= 1;

    while (pq.empty() == false)
    {
        pair<int, int> nowPos = pq.top().second;
        int nowValue = -pq.top().first;
        pq.pop();

        for (pair<int, int> nextP : V[nowPos.first])
        {
            int color = nextP.second;
            int nextBlueStack = color == 2 ? nowPos.second + 1 : nowPos.second;
            pair<int, int> nextPos = { nextP.first ,nextBlueStack };
            int nextValue = nowValue + pow(2, nowPos.second);

            if (nextBlueStack > 30)
            {
                continue;
            }

            if (Dist[nextPos.first][nextBlueStack] > nextValue)
            {
                Dist[nextPos.first][nextBlueStack] = nextValue;
                pq.push({ -nextValue,nextPos });
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int a;
        std::cin >> a;
        int minValue = INF;
        for (int j = 0; j <= 30; j++)
            minValue = min(minValue, Dist[a][j]);
        if (minValue > L)
            std::cout << "Large" << endl;
        else
            std::cout << minValue << endl;
    }

}