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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int MOD = 1000000007;
int Par[5001];
int Find(int a)
{
    if (a != Par[a])
        return Par[a] = Find(Par[a]);
    return Par[a];
}


void Uni(int a, int b)
{
    int A = Find(a);
    int B = Find(b);
    Par[A] = B;
}
int N, M;

int C[5001][5001];
int DP[5001];
int D(int n)
{
    if (DP[n] != -1)
        return DP[n];
    if (n <= 1)
        return DP[n] = 1;
    DP[n] = 0;
    for (int k = 0; k <= n - 1; k++)
    {
        DP[n] += (C[n - 1][k] * D(n - 1 - k)) % MOD;
        DP[n] %= MOD;
    }
    return DP[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    C[1][0] = 1;
    C[1][1] = 1;
    for (int i = 2; i < 5001; i++)
        for (int j = 0; j <= i; j++)
            C[i][j] = (C[i - 1][j] + (j - 1 < 0 ? 0 : C[i - 1][j - 1])) % MOD;

    cin >> N >> M;
    int num = N;
    for (int i = 1; i <= 5000; i++)
        Par[i] = i;
    for (int i = 0; i <= 5000; i++)
        DP[i] = -1;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b))
        {
            Uni(a, b);
            num--;
        }
        cout << D(num) << endl;
    }
}

