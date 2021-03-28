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

const int N_MAX = 50;
const int M_MAX = 50;
const int BIT_MAX = 1 << 6;
int N, M;
int DP[N_MAX][M_MAX][BIT_MAX];

char MAP[N_MAX][M_MAX];
char GetMAP(int n, int m)
{
    if (0 <= n && n < N && 0 <= m && m < M)
        return MAP[n][m];
    return '#';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < N_MAX; i++)
        for (int j = 0; j < M_MAX; j++)
            MAP[i][j] = '#';

    for (int i = 0; i < N_MAX; i++)
        for (int j = 0; j < M_MAX; j++)
            for (int k = 0; k < BIT_MAX; k++)
                DP[i][j][k] = INF;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAP[i][j];

    pair<int, int> StartPos;
    //시작지점 찾기
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (MAP[i][j] == '0')
                    StartPos = { i,j };
    }

    vector<pair<int, int>> EndPos;
    //도착지점 찾기
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (MAP[i][j] == '1')
                    EndPos.push_back({ i,j });
    }

    //모험시작
    {

        queue<tuple<int, int, int>> Queue;
        DP[StartPos.first][StartPos.second][0] = 0;
        Queue.push({ StartPos.first ,StartPos.second ,0 });

        while (!Queue.empty())
        {
            tuple<int, int, int> nowState = Queue.front();
            Queue.pop();
            int nowValue = DP[get<0>(nowState)][get<1>(nowState)][get<2>(nowState)];

            for (int i = 0; i < 4; i++)
            {
                int ar = get<0>(nowState) + Dic[i][0];
                int ac = get<1>(nowState) + Dic[i][1];
                int abit = get<2>(nowState);
                char nextState = GetMAP(ar, ac);

                if (nextState == '#')
                    continue;

                if ('A' <= nextState && nextState <= 'F')
                    if (!(abit & (1 << (nextState - 'A'))))
                        continue;

                if ('a' <= nextState && nextState <= 'f')
                    abit |= (1 << (nextState - 'a'));

                if (DP[ar][ac][abit] != INF)
                    continue;

                DP[ar][ac][abit] = nowValue + 1;
                Queue.push({ ar,ac ,abit });
            }
        }
    }

    int Result = INF;
    for (int i = 0; i < EndPos.size(); i++)
        for (int j = 0; j < BIT_MAX; j++)
            Result = min(Result, DP[EndPos[i].first][EndPos[i].second][j]);

    if (Result == INF)
        cout << -1 << endl;
    else
        cout << Result << endl;
}