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
#define float long double
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

int N;
int V[1000001];
int Idx[1000001];

int Tree[1000001][2];
int Sum(int i, int a)
{
    int ans = 0;
    while (i > 0)
    {
        ans += Tree[i][a];
        i -= (i & -i);
    }
    return ans;
}
void Update(int i, int a, int num)
{
    while (i <= N)
    {
        Tree[i][a] += num;
        i += (i & -i);
    }
}

const int MOD = 1000000007;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> V[i];

    vector<pair<int, int>> TempArr;
    for (int i = 1; i <= N; i++)
        TempArr.push_back({ V[i],i });
    sort(TempArr.begin(), TempArr.end());
    for (int i = 1; i <= N; i++)
        Idx[TempArr[i - 1].second] = i;

    int ans = 1;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += V[i];
        int a = Sum(N, 0) - Sum(Idx[i], 0);
        int b = Sum(N, 1) - Sum(Idx[i], 1);

        int temp = 0;
        temp += V[i] * (i - a - 1) - (sum - b - V[i]);
        temp %= MOD;
        temp += b - V[i] * a;
        temp %= MOD;

        if (i > 1)
        {
            ans *= temp;
            ans %= MOD;
        }

        Update(Idx[i], 0, 1);
        Update(Idx[i], 1, V[i]);
    }

    cout << ans << endl;
}