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

int N;
int Cost[17][17];
int P;
int DP[100000];
int BN[100000];
int BitNum(int bit)
{
    if (BN[bit] != INF)
        return BN[bit];
    int v = 0;
    for (int i = 0; i < N; i++)
        if (bit & (1 << i))
            v++;
    return BN[bit] = v;
}
int D(int bit)
{
    if (BitNum(bit) >= P)
        return 0;
    if (DP[bit] != INF)
        return DP[bit];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (!(bit & (1 << i)))
                continue;
            if (bit & (1 << j))
                continue;
            //cout << i << " , " << j << endl;
            DP[bit] = min(DP[bit], D(bit | (1 << j)) + Cost[i][j]);
        }
    return DP[bit];
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 100000; i++)
        DP[i] = INF;
    for (int i = 0; i < 100000; i++)
        BN[i] = INF;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Cost[i][j];

    string s;
    cin >> s;
    int startBit = 0;
    for (int i = 0; i < N; i++)
        if (s[i] == 'Y')
            startBit |= (1 << i);

    cin >> P;

    if (BitNum(startBit) == 0 && P > 0)
        cout << -1 << endl;
    else if (BitNum(startBit) >= P)
        cout << 0 << endl;
    else
        cout << D(startBit) << endl;

}

