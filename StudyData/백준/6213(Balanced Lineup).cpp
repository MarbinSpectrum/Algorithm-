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

    return temp * temp * ((b % 2) ? 1 : a);
}

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, Q;

int MaxTree[500000];
void MaxUpdate(int n, int l, int r, int idx, int value)
{
    MaxTree[n] = max(MaxTree[n], value);
    if (l == r)
        return;
    int m = (l + r) / 2;
    if (l <= idx && idx <= m)
        MaxUpdate(n * 2, l, m, idx, value);
    else
        MaxUpdate(n * 2 + 1, m + 1, r, idx, value);
}
int MaxGet(int n, int l, int r, int s, int e)
{
    if (s > r || l > e)
        return 0;
    if (s <= l && r <= e)
        return MaxTree[n];
    int m = (l + r) / 2;
    return max(MaxGet(n * 2, l, m, s, e), MaxGet(n * 2 + 1, m + 1, r, s, e));
}


int MinTree[500000];
void MinUpdate(int n, int l, int r, int idx, int value)
{
    MinTree[n] = min(MinTree[n], value);
    if (l == r)
        return;
    int m = (l + r) / 2;
    if (l <= idx && idx <= m)
        MinUpdate(n * 2, l, m, idx, value);
    else
        MinUpdate(n * 2 + 1, m + 1, r, idx, value);
}
int MinGet(int n, int l, int r, int s, int e)
{
    if (s > r || l > e)
        return INF;
    if (s <= l && r <= e)
        return MinTree[n];
    int m = (l + r) / 2;
    return min(MinGet(n * 2, l, m, s, e), MinGet(n * 2 + 1, m + 1, r, s, e));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(MinTree, INF, sizeof(MinTree));
    memset(MaxTree, 0, sizeof(MaxTree));

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        MaxUpdate(1, 1, N, i, a);
        MinUpdate(1, 1, N, i, a);
    }
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        //Debug(MaxGet(1, 1, N, a, b), MinGet(1, 1, N, a, b));
        cout << MaxGet(1, 1, N, a, b) - MinGet(1, 1, N, a, b) << endl;
    }

    return 0;
}