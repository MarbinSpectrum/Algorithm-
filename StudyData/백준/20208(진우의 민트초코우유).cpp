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

int N, M, H;
int Map[10][10];
pair<int, int> House;
vector< pair<int, int>> Milk;
bool DP[5000][200][11];
int Result = 0;
int Distance(pair<int, int> A, pair<int, int> B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}
void D(int bit, int hp, int now)
{
    if (DP[bit][hp][now])
        return;
    DP[bit][hp][now] = true;
    for (int i = 1; i < Milk.size(); i++)
    {
        if (i == now)
            continue;
        if (bit & (1 << i))
            continue;
        if (Distance(Milk[now], Milk[i]) <= hp)
            D(bit | (1 << i), hp - Distance(Milk[now], Milk[i]) + H, i);
    }
    if (Distance(Milk[now], Milk[0]) <= hp)
    {
        int R = 0;
        for (int i = 1; i < Milk.size(); i++)
            if (bit & (1 << i))
                R++;
        Result = max(Result, R);
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init(DP, false);

    cin >> N >> M >> H;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> Map[r][c];

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (Map[r][c] == 1)
                Milk.push_back({ r,c });
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (Map[r][c] == 2)
                Milk.push_back({ r,c });

    D(0, M, 0);

    cout << Result << endl;
}
