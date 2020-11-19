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

int S, A, B, C;
int DP[51][51][51][51];
const int MOD = 1000000007;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> A >> B >> C;
    if (S > A + B + C)
    {
        cout << 0 << endl;
        return 0;
    }

    DP[0][0][0][0] = 1;

    for (int s = 0; s < 51; s++)
        for (int a = 0; a < 51; a++)
            for (int b = 0; b < 51; b++)
                for (int c = 0; c < 51; c++)
                {
                    if (DP[s][a][b][c] != 0)
                    {
                        DP[s + 1][a + 1][b][c] += DP[s][a][b][c];
                        DP[s + 1][a + 1][b][c] %= MOD;
                        DP[s + 1][a][b + 1][c] += DP[s][a][b][c];
                        DP[s + 1][a][b + 1][c] %= MOD;
                        DP[s + 1][a][b][c + 1] += DP[s][a][b][c];
                        DP[s + 1][a][b][c + 1] %= MOD;
                        DP[s + 1][a + 1][b + 1][c] += DP[s][a][b][c];
                        DP[s + 1][a + 1][b + 1][c] %= MOD;
                        DP[s + 1][a + 1][b][c + 1] += DP[s][a][b][c];
                        DP[s + 1][a + 1][b][c + 1] %= MOD;
                        DP[s + 1][a][b + 1][c + 1] += DP[s][a][b][c];
                        DP[s + 1][a][b + 1][c + 1] %= MOD;
                        DP[s + 1][a + 1][b + 1][c + 1] += DP[s][a][b][c];
                        DP[s + 1][a + 1][b + 1][c + 1] %= MOD;
                    }
                }

    cout << DP[S][A][B][C] << endl;

   
}
