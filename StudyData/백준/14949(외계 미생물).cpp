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

const int MOD = 1000000007;
int H, W;

int C[1000][1000];
int GetC(int r, int c)
{
    if (r < 0 || r >= 1000 || c < 0 || c >= 1000)
        return 0;
    return C[r][c];
}

int DP[10][300];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init(DP, 0);
    DP[0][1] = 1;

    ///////////////////////////////////////////////////////////

    C[0][0] = 1;
    for (int r = 1; r <= 700; r++)
        for (int c = 0; c <= r; c++)
            C[r][c] = (GetC(r - 1, c) % MOD + GetC(r - 1, c - 1) % MOD) % MOD;

    ///////////////////////////////////////////////////////////

    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        //현재자식수
        for (int a = 1; a <= W; a++)
        {
            //전의자식수
            for (int b = 1; b <= W; b++)
            {
                DP[i][a] += (DP[i - 1][b] * C[b + a - 1][b - 1]) % MOD;
                DP[i][a] %= MOD;
            }
        }
    }

    int Result = 0;
    for (int a = 1; a <= 300; a++)
    {
        Result += DP[H][a];
        Result %= MOD;
    }

    cout << Result << endl;

}
