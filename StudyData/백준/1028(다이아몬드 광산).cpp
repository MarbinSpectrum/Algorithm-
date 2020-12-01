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

int R, C;
char MAP[1000][1000];
char Get(int r, int c)
{
    if (r < 0 || r >= R || c < 0 || c >= C)
        return '0';
    return MAP[r][c];
}

int LD[1000][1000];
int GetLD(int r, int c)
{
    if (LD[r][c] != -1)
        return LD[r][c];
    if (Get(r, c) == '1')
        return LD[r][c] = GetLD(r + 1, c - 1) + 1;
    else
        return LD[r][c] = 0;
}
int RD[1000][1000];
int GetRD(int r, int c)
{
    if (RD[r][c] != -1)
        return RD[r][c];
    if (Get(r, c) == '1')
        return RD[r][c] = GetRD(r + 1, c + 1) + 1;
    else
        return RD[r][c] = 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init(LD, -1);
    Init(RD, -1);

    cin >> R >> C;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> MAP[r][c];

    int Result = 0;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
        {
            int size = min(GetLD(r, c), GetRD(r, c));

            for (int i = size; i >= 1; i--)
            {
                int b = i - 1;

                if (GetRD(r + b, c - b) >= i && GetLD(r + b, c + b) >= i)
                {
                    Result = max(Result, i);
                }
            }
        }

    cout << Result << endl;
}


