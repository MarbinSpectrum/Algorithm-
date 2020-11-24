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

// C++ 
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
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
int DP[101][101][101];
int const MOD = 10007;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DP[1][1][1] = 1;


    for (int i = 2; i <= N; i++)
    {
        for (int a = 1; a <= i; a++)
            for (int b = 1; b <= i; b++)
            {
                if (a == b)
                    continue;
                if (a != b || i - 1 == 1)
                {
                    DP[a][b][i] += DP[a][b][i - 1];
                    DP[a][b][i] %= MOD;
                }
                if (a - 1 != b || i - 1 == 1)
                {
                    DP[a][b][i] += DP[a - 1][b][i - 1];
                    DP[a][b][i] %= MOD;
                }
                if (a - 1 != b - 1 || i - 1 == 1)
                {
                    DP[a][b][i] += DP[a - 1][b - 1][i - 1];
                    DP[a][b][i] %= MOD;
                }
                if (a != b - 1 || i - 1 == 1)
                {
                    DP[a][b][i] += DP[a][b - 1][i - 1];
                    DP[a][b][i] %= MOD;
                }
            }
    }
    if (N == 1)
        cout << 0 << endl;
    else
    {
        int Result = 0;
        for (int a = 1; a <= N; a++)
            for (int b = 1; b <= N; b++)
            {
                if (a == b)
                    continue;
                Result += DP[a][b][N];
                Result %= MOD;
            }

        cout << Result << endl;


    }

}
