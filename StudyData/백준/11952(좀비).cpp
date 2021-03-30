#ifndef _GLIBCXX_NO_ASSERT 
#include <cassert> 
#endif #include <cctype>
#include <cerrno> 
#include <cfloat> 
#include <ciso646> 
#include <climits> 
#include <clocale> 
#include <cmath> 
#include <csetjmp> 
#include <csignal>
#include <cstdarg> 
#include <cstddef>
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#if __cplusplus >= 201103L 
#include <ccomplex> 
#include <cfenv> 
#include <cinttypes> 
#include <cstdalign> 
#include <cstdbool>
#include <cstdint> 
#include <ctgmath>
#include <cwchar> 
#include <cwctype>
#endif 
//
//// C++ 
#include <algorithm> 
#include <bitset> 
#include <complex> 
#include <deque> 
#include <exception> 
#include <fstream> 
#include <functional> 
#include <iomanip> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <iterator> 
#include <limits> 
#include <list> 
#include <locale> 
#include <map> 
#include <memory> 
#include <new> 
#include <numeric>
#include <ostream> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <stdexcept> 
#include <streambuf> 
#include <string> 
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <vector> 
//
#if __cplusplus >= 201103L 
#include <array> 
#include <atomic> 
#include <chrono> 
#include <condition_variable> 
#include <forward_list> 
#include <future> 
#include <initializer_list> 
#include <mutex> 
#include <random> 
#include <ratio>
#include <regex> 
#include <scoped_allocator> 
#include <system_error> 
#include <thread> 
#include <tuple> 
#include <typeindex> 
#include <type_traits> 
#include <unordered_map> 
#include <unordered_set> 
#endif

#pragma warning(disable:4996)

using namespace std;


#define endl "\n"
#define int long long
#define float double
#define Debug(a,b) cout << a << " " << b << endl


int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int Ceil(double n)
{
    if (n - (int)(n) > 0)
        return (int)n + 1;
    else
        return n;
}

int Pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int temp = Pow(a, b / 2);

    return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

const int N_MAX = 100000;

int N, M, K, S;
int p, q;

bool ZombieCity[N_MAX + 1];
queue<pair<int, int>> WarningQueue;
bool WarningCity[N_MAX + 1];
int Accommodation_Cost[N_MAX + 1];

vector<int> V[N_MAX + 1];
int Dist[N_MAX + 1];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> S;

    cin >> p >> q;

    for (int i = 0; i < K; i++)
    {
        int a;
        cin >> a;
        ZombieCity[a] = true;
        WarningQueue.push({ a,0 });
        WarningCity[a] = true;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    while (!WarningQueue.empty())
    {
        pair<int, int> NowPos = WarningQueue.front();
        WarningQueue.pop();
        for (int i = 0; i < V[NowPos.first].size(); i++)
        {
            int next = V[NowPos.first][i];
            if (WarningCity[next])
                continue;
            if (NowPos.second + 1 > S)
                continue;
            WarningQueue.push({ next,NowPos.second + 1 });
            WarningCity[next] = true;
        }
    }

    for (int i = 0; i <= N_MAX; i++)
        Accommodation_Cost[i] = WarningCity[i] ? q : p;

    for (int i = 0; i <= N_MAX; i++)
        Dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0,1 });
    Dist[1] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (Dist[now] < dist)
            continue;
        if (ZombieCity[now])
            continue;

        for (int i = 0; i < V[now].size(); i++)
        {
            int next = V[now][i];
            int cost = dist + Accommodation_Cost[next];

            if (cost < Dist[next])
            {
                Dist[next] = cost;
                pq.push({ -cost,next });
            }
        }
    }

    cout << Dist[N] - Accommodation_Cost[N] << endl;

}