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

int N;
vector<pair<int, int>> Block;

int LeftDP[300];
int Left(int n)
{
    if (LeftDP[n] != -1)
        return LeftDP[n];

    int check = Block[n].first - Block[n].second;
    pair<int, int> value = { check, -1 };

    int t = lower_bound(Block.begin(), Block.end(), value) - Block.begin();

    LeftDP[n] = t;
    for (int i = t; i < n; i++)
        LeftDP[n] = min(LeftDP[n], Left(i));
    return  LeftDP[n];
}

int RightDP[300];
int Right(int n)
{
    if (RightDP[n] != -1)
        return RightDP[n];

    int check = Block[n].first + Block[n].second;
    pair<int, int> value = { check, INF };

    int t = upper_bound(Block.begin(), Block.end(), value) - Block.begin();

    RightDP[n] = t - 1;
    for (int i = n; i < t; i++)
        RightDP[n] = max(RightDP[n], Right(i));
    return  RightDP[n];
}

int DP[300][300];
int Solution(int a, int b)
{
    if (DP[a][b] != -1)
        return DP[a][b];

    if (a > b)
        return DP[a][b] = 0;

    if (RightDP[a] >= b || LeftDP[b] <= a)
        return DP[a][b] = 1;

    DP[a][b] = INF;

    for (int i = a; i <= b; i++)
        DP[a][b] = min(DP[a][b], Solution(a, LeftDP[i] - 1) + Solution(LeftDP[i], RightDP[i]) + Solution(RightDP[i] + 1, b));
    return DP[a][b];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init(LeftDP, -1);
    Init(RightDP, -1);
    Init(DP, -1);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, h;
        cin >> x >> h;
        Block.push_back({ x,h });
    }

    sort(Block.begin(), Block.end());

    for (int i = 0; i < N; i++)
    {
        Left(i);
        Right(i);
    }

    cout << Solution(0, N - 1) << endl;


}
