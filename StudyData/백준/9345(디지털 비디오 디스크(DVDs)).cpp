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

int N,K;
int Arr[1000000];
int Min_Tree[1000000];
int Max_Tree[1000000];
void Init(int n, int s, int e)
{
    Min_Tree[n] = s;
    Max_Tree[n] = e;
    if(s == e)
        return;
    Init(n * 2, s, (s + e) / 2);
    Init(n * 2 + 1, (s + e) / 2 + 1, e);
}

int Min_Update(int n, int s, int e, int index ,int value)
{   
    if (s > index || e < index)
        return Min_Tree[n];
    Min_Tree[n] = min(Min_Tree[n], value);
    if (s == e)
    {
        Min_Tree[n] = value;
        Arr[index] = value;
        return Min_Tree[n];
    }
    int a = Min_Update(n * 2, s, (s + e) / 2, index, value);
    int b = Min_Update(n * 2 + 1, (s + e) / 2 + 1, e, index, value);
    return Min_Tree[n] = min(a, b);
}

int Max_Update(int n, int s, int e, int index, int value)
{
    if (s > index || e < index)
        return Max_Tree[n];
    Max_Tree[n] = max(Max_Tree[n], value);
    if (s == e)
    {
        Max_Tree[n] = value;
        Arr[index] = value;
        return Max_Tree[n];
    }
    int a = Max_Update(n * 2, s, (s + e) / 2, index, value);
    int b = Max_Update(n * 2 + 1, (s + e) / 2 + 1, e, index, value);
    return Max_Tree[n] = max(a, b);
}

int Min_GetValue(int n, int s, int e, int l, int r)
{
    if (l > e || r < s)
        return INF;
    if (l <= s && e <= r)
        return Min_Tree[n];
    return min(Min_GetValue(n * 2, s, (s + e) / 2, l, r), Min_GetValue(n * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int Max_GetValue(int n, int s, int e, int l, int r)
{
    if (l > e || r < s)
        return -1;
    if (l <= s && e <= r)
        return Max_Tree[n];
    return max(Max_GetValue(n * 2, s, (s + e) / 2, l, r), Max_GetValue(n * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        Init(1, 1, N);
        for (int i = 1; i <= N; i++)
            Arr[i] = i;
        for (int i = 0; i < K; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            b++;
            c++;
            if (a == 0)
            {
                int bV = Arr[b];
                int cV = Arr[c];
                Max_Update(1, 1, N, b, cV);
                Max_Update(1, 1, N, c, bV);
                Min_Update(1, 1, N, b, cV);
                Min_Update(1, 1, N, c, bV);
            }
            else
            {
                int minV = Min_GetValue(1, 1, N, b, c);
                int maxV = Max_GetValue(1, 1, N, b, c);
                //Debug(minV, maxV);
                if (minV == b && maxV == c)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}