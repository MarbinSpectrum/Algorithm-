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

    int v = temp * temp;
    if (b % 2 == 1)
        v *= a;
    return v;
}

const int INF = 8999999999999999999;
const int Dic[5][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{0,0} };
const int Dic8[8][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{+1,+1},{-1,-1} ,{+1,-1}, {-1,+1} };
////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M;
int MAP[50][50];
int Simulation_MAP[50][50];
int zeroNum = 0;
vector<pair<int, int>> Virus;

int Simulation(int bit)
{
    {
        int check = 0;
        for (int i = 1; i <= bit; i *= 2)
            if (bit & i)
                check++;
        if (check != M)
            return INF;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (MAP[i][j] == 2)
                Simulation_MAP[i][j] = -2;
            else if (MAP[i][j] == 1)
                Simulation_MAP[i][j] = -1;
            else
                Simulation_MAP[i][j] = 0;

    int zeroSpace = zeroNum;

    if (zeroSpace == 0)
        return 1;

    queue <pair<int, int>> Queue;
    for (int i = 1; i <= bit; i *= 2)
        if (bit & i)
        {
            int ii = log2(i);
            Queue.push(Virus[ii]);
            Simulation_MAP[Virus[ii].first][Virus[ii].second] = 1;
        }


    while (!Queue.empty())
    {
        pair<int, int> now = Queue.front();
        Queue.pop();
        int v = Simulation_MAP[now.first][now.second];

        for (int i = 0; i < 4; i++)
        {
            int ar = now.first + Dic[i][0];
            int ac = now.second + Dic[i][1];
            if (ar < 0 || ac < 0 || ar >= N || ac >= N)
                continue;
            if (Simulation_MAP[ar][ac] >= 1)
                continue;
            if (Simulation_MAP[ar][ac] == -1)
                continue;
            Queue.push({ ar,ac });
            if (Simulation_MAP[ar][ac] == 0)
                zeroSpace--;
            if (zeroSpace == 0)
                return v + 1;
            Simulation_MAP[ar][ac] = v + 1;
        }
    }

    //cout << endl;
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        if(Simulation_MAP[i][j] == -1)
    //            cout << "-" << " ";
    //        else
    //            cout << Simulation_MAP[i][j] - 1 << " ";
    //    cout << endl;
    //}
    //cout << endl;

    return INF;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (MAP[i][j] == 2)
                Virus.push_back({ i,j });
            else if (MAP[i][j] == 0)
                zeroNum++;


    int ans = INF;

    for (int i = 1; i < (1 << Virus.size()); i++)
        ans = min(ans,Simulation(i));

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans - 1 << endl;

    return 0;
}