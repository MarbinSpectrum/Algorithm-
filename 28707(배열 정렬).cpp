#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e18;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N;
vector<int> A;
int startDigit;
int endDigit;
int M;
vector<int> l;
vector<int> r;
vector<int> c;

int GetDigit(const vector<int> temp)
{
    int keyValue = 0;
    int ten = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        keyValue += temp[i] * ten;
        ten *= 10;
    }
    return keyValue;
}

int GetSwapValue(int digit, int lValue, int rValue)
{
    int ten0 = pow(10, lValue - 1);
    int ten1 = pow(10, rValue - 1);
    int lNum = (digit - digit % ten0 - (digit / (ten0 * 10)) * (ten0 * 10)) / ten0;
    int rNum = (digit - digit % ten1 - (digit / (ten1 * 10)) * (ten1 * 10)) / ten1;

    digit -= lNum * ten0;
    digit -= rNum * ten1;
    digit += lNum * ten1;
    digit += rNum * ten0;

    return digit;
}

int Dis[100000000];

void dijkstra(int start)
{
    for (int i = 0; i < 100000000; i++)
        Dis[i] = INF;
    Dis[start] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if (Dis[now] < cost)
            continue;

        for (int i = 0; i < M; i++)
        {
            int next = GetSwapValue(now, N - l[i] + 1, N - r[i] + 1);

            int nextDis = cost + c[i];

            if (Dis[next] > nextDis)
            {
                Dis[next] = nextDis;
                pq.push(make_pair(-nextDis, next));
            }
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;

    int keyValue = 0;
    vector<int> temp;
    for (int i = 0; i < N; i++)
    {
        temp.push_back(i + 1);
        int a;
        std::cin >> a;
        a--;
        A.push_back(a);
    }

    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        int q, w, e;
        std::cin >> q >> w >> e;
        l.push_back(q);
        r.push_back(w);
        c.push_back(e);
    }

    startDigit = GetDigit(A);
    sort(A.begin(), A.end());
    endDigit = GetDigit(A);

    dijkstra(startDigit);

    if (Dis[endDigit] != INF)
        std::cout << Dis[endDigit] << endl;
    else
        std::cout << -1 << endl;
}
