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
const int Dic[5][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{0,0} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int Dis(int sr, int sc, int er, int ec)
{
    return abs(sr - er) + abs(sc - ec);
}

int N;
vector<pair<int, int>> Arr;
int DP[1000001][5];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1000001; i++)
        for (int j = 0; j < 5; j++)
            DP[i][j] = INF;

    cin >> N;

    int sr, sc;
    cin >> sr >> sc;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        Arr.push_back({ a,b });
    }

    for (int i = 0; i < 5; i++)
        DP[0][i] = Dis(sr, sc, Arr[0].first + Dic[i][0], Arr[0].second + Dic[i][1]);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
            {
                int ar = Arr[i - 1].first + Dic[j][0];
                int ac = Arr[i - 1].second + Dic[j][1];
                int br = Arr[i].first + Dic[k][0];
                int bc = Arr[i].second + Dic[k][1];
                DP[i][k] = min(DP[i][k], DP[i - 1][j] + Dis(ar, ac, br, bc));
            }
    }

    cout << min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2], DP[N - 1][3], DP[N - 1][4] }) << endl;

}