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

vector<pair<tuple<int, int, int>, int>> arr;

int Tree[120005][2];
void Update(int n, int s, int e, int l, int r, int add)
{
    if (s > r || e < l)
        return;
    if (l <= s && e <= r)
        Tree[n][0] += add;
    else
    {
        int m = (s + e) / 2;
        Update(n * 2, s, m, l, r, add);
        Update(n * 2 + 1, m + 1, e, l, r, add);
    }

    if (Tree[n][0])
        Tree[n][1] = e - s + 1;
    else
    {
        if (s == e)
            Tree[n][1] = 0;
        else
            Tree[n][1] = Tree[n * 2][1] + Tree[n * 2 + 1][1];
    }
}

int ans = 0;

bool compare(pair<tuple<int, int, int>, int> a, pair<tuple<int, int, int>, int> b)
{
    return get<0>(a.first) < get<0>(b.first);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        //¿Þ
        arr.push_back({ { x1,y1 + 1,y2 + 1},+1 });
        //¿À
        arr.push_back({ { x2,y1 + 1,y2 + 1 },-1 });
    }
    sort(arr.begin(), arr.end(), compare);

    int bx = get<0>(arr[0].first);
    for (int i = 0; i < arr.size(); i++)
    {
        ans += abs(bx - get<0>(arr[i].first)) * Tree[1][1];
        bx = get<0>(arr[i].first);
        Update(1, 1, 30002, get<1>(arr[i].first), get<2>(arr[i].first) - 1, arr[i].second);
    }

    cout << ans << endl;

}