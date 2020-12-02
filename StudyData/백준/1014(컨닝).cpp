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

int C;
int N, M;
int Result;
int BitMask(int n)
{
    return 1 << n;
}
int GetDigit(int Bit)
{
    int value = 0;
    for (int check = 0; check < N; check++)
        if (Bit & BitMask(check))
            value++;
    return value;
}
char MAP[20][20];
bool Check(int n,int FrontBit, int Bit)
{
    for (int check = 0; check < N; check++)
    {
        if (MAP[check][n] == 'x' && (Bit & BitMask(check)))
            return false;
        if (((FrontBit & BitMask(check - 1)) || (FrontBit & BitMask(check)) || (FrontBit & BitMask(check + 1))) && (Bit & BitMask(check)))
            return false;
    }
    return true;
}
int DP[20][2000];
int D(int m,int Bit)
{
    if (m >= M)
        return 0;
    if (DP[m][Bit] != -1)
        return DP[m][Bit];
    DP[m][Bit] = 0;
    for (int bit = 0; bit < (1 << N); bit++)
        if (Check(m, Bit, bit))
            DP[m][Bit] = max(DP[m][Bit], D(m + 1, bit) + GetDigit(bit));
    return DP[m][Bit];
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;
    while (C--)
    {
        Result = -1;
        Init(DP, -1);
        cin >> N >> M;
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
                cin >> MAP[n][m];

        for (int bit = 0; bit < (1 << N); bit++)
            if (Check(0, 0, bit))
                Result = max(Result,D(0, bit));

        cout << Result << endl;
    }
   

}


