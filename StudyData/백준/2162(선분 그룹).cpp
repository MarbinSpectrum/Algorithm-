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
vector< pair < pair<int, int>, pair<int, int>>> Arr;

int CCW(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3)
{
    int op = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    op -= (p1.first * p3.second + p2.first * p1.second + p3.first * p2.second);

    if (op > 0) return 1;
    else if (op == 0) return 0;
    else return -1;
}

bool CheckIntersect(int line1, int line2)
{
    pair<int, int> p1 = Arr[line1].first;
    pair<int, int> p2 = Arr[line1].second;
    pair<int, int> p3 = Arr[line2].first;
    pair<int, int> p4 = Arr[line2].second;

    int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
    int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

    if (line1_2 == 0 && line2_1 == 0)
    {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);

        return p1 <= p4 && p3 <= p2;
    }
    return line1_2 <= 0 && line2_1 <= 0;
}

int Child[5001];
int Par[5001];

int GetPar(int n)
{
    if (n != Par[n])
        return Par[n] = GetPar(Par[n]);
    else
        return Par[n];
}

void Joint(int a,int b)
{
    a = GetPar(a);
    b = GetPar(b);
    if (a == b)
        return;
    Par[a] = b;
    Child[b] += Child[a];
}
bool Check[5001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Arr.push_back({ {a,b},{c,d} });
        Par[i] = i;
        Child[i] = 1;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (CheckIntersect(i, j))
            {
               // cout << "!!";
              //  Debug(i, j);
                Joint(i, j);
            }

    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < N; i++)
    {
        int a = GetPar(i);
        if (!Check[a])
        {
            Check[a] = true;
            ans2++;
        }
        ans = max(ans,Child[a]);
    }
    cout << ans2 << endl;
    cout << ans << endl;



    return 0;
}