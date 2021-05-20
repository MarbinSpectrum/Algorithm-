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

int N;
int DP[401][2 << 3];
const int MOD = 1000000;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DP[0][7] = 1;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 7)
            {
                DP[i + 3][3] += DP[i][j];
                DP[i + 3][3] %= MOD;

                DP[i + 2][1] += DP[i][j];
                DP[i + 2][1] %= MOD;

                DP[i + 4][7] += DP[i][j];
                DP[i + 4][7] %= MOD;

                DP[i + 3][6] += DP[i][j];
                DP[i + 3][6] %= MOD;

                DP[i + 3][5] += DP[i][j];
                DP[i + 3][5] %= MOD;

                DP[i + 3][6] += DP[i][j];
                DP[i + 3][6] %= MOD;

                DP[i + 2][4] += DP[i][j];
                DP[i + 2][4] %= MOD;

                DP[i + 4][7] += DP[i][j];
                DP[i + 4][7] %= MOD;

                DP[i + 3][3] += DP[i][j];
                DP[i + 3][3] %= MOD;

                DP[i + 3][5] += DP[i][j];
                DP[i + 3][5] %= MOD;
            }
            else if (j == 3)
            {
                DP[i + 4][6] += DP[i][j];
                DP[i + 4][6] %= MOD;

                DP[i + 1][7] += DP[i][j];
                DP[i + 1][7] %= MOD;

                DP[i + 3][1] += DP[i][j];
                DP[i + 3][1] %= MOD;

                DP[i + 3][1] += DP[i][j];
                DP[i + 3][1] %= MOD;

                DP[i + 3][2] += DP[i][j];
                DP[i + 3][2] %= MOD;
            }
            else if (j == 6)
            {
                DP[i + 4][3] += DP[i][j];
                DP[i + 4][3] %= MOD;

                DP[i + 1][7] += DP[i][j];
                DP[i + 1][7] %= MOD;

                DP[i + 3][4] += DP[i][j];
                DP[i + 3][4] %= MOD;

                DP[i + 3][4] += DP[i][j];
                DP[i + 3][4] %= MOD;

                DP[i + 3][2] += DP[i][j];
                DP[i + 3][2] %= MOD;
            }
            else if (j == 4)
            {
                DP[i + 1][6] += DP[i][j];
                DP[i + 1][6] %= MOD;

                DP[i + 2][7] += DP[i][j];
                DP[i + 2][7] %= MOD;

                DP[i + 2][7] += DP[i][j];
                DP[i + 2][7] %= MOD;

                DP[i + 4][2] += DP[i][j];
                DP[i + 4][2] %= MOD;

                DP[i + 4][1] += DP[i][j];
                DP[i + 4][1] %= MOD;

                DP[i + 5][3] += DP[i][j];
                DP[i + 5][3] %= MOD;

                DP[i + 5][3] += DP[i][j];
                DP[i + 5][3] %= MOD;

                DP[i + 1][3] += DP[i][j];
                DP[i + 1][3] %= MOD;
            }
            else if (j == 1)
            {
                DP[i + 1][3] += DP[i][j];
                DP[i + 1][3] %= MOD;

                DP[i + 2][7] += DP[i][j];
                DP[i + 2][7] %= MOD;

                DP[i + 2][7] += DP[i][j];
                DP[i + 2][7] %= MOD;

                DP[i + 4][2] += DP[i][j];
                DP[i + 4][2] %= MOD;

                DP[i + 4][4] += DP[i][j];
                DP[i + 4][4] %= MOD;

                DP[i + 5][6] += DP[i][j];
                DP[i + 5][6] %= MOD;

                DP[i + 5][6] += DP[i][j];
                DP[i + 5][6] %= MOD;

                DP[i + 1][6] += DP[i][j];
                DP[i + 1][6] %= MOD;
            }
            else if (j == 2)
            {
                DP[i + 2][7] += DP[i][j];
                DP[i + 2][7] %= MOD;

                DP[i + 2][7] += DP[i][j];
                DP[i + 2][7] %= MOD;
            }
            else if (j == 5)
            {
                DP[i + 1][7] += DP[i][j];
                DP[i + 1][7] %= MOD;

                DP[i + 3][1] += DP[i][j];
                DP[i + 3][1] %= MOD;

                DP[i + 3][2] += DP[i][j];
                DP[i + 3][2] %= MOD;

                DP[i + 4][6] += DP[i][j];
                DP[i + 4][6] %= MOD;

                DP[i + 3][4] += DP[i][j];
                DP[i + 3][4] %= MOD;

                DP[i + 3][2] += DP[i][j];
                DP[i + 3][2] %= MOD;

                DP[i + 4][3] += DP[i][j];
                DP[i + 4][3] %= MOD;
            }
        }
    }

    cout << DP[N][7] << endl;
}