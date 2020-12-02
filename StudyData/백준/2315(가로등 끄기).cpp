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

int N, M;
pair<int, int> Data[1005];
int S[1005];
int GetS(int a, int b)
{
    return S[b] - S[a - 1];
}
int DP[1005][1005][2];
int D(int L, int R, int Dic)
{
    if (DP[L][R][Dic] != INF)
        return DP[L][R][Dic];

    int CostTime = GetS(1, L) + GetS(R, N);
    int nowPos = (Dic == 0) ? Data[L + 1].first : Data[R - 1].first;
    int L_Cost = CostTime * abs(nowPos - Data[L].first);
    int R_Cost = CostTime * abs(nowPos - Data[R].first);

    if (L >= 1 && R <= N)
        DP[L][R][Dic] = min({ DP[L][R][Dic],D(L - 1,R,0) + L_Cost ,D(L,R + 1,1) + R_Cost });
    else if (L < 1 && R <= N)
        DP[L][R][Dic] = min({ DP[L][R][Dic],D(L,R + 1,1) + R_Cost });
    else if (L >= 1 && R > N)
        DP[L][R][Dic] = min({ DP[L][R][Dic],D(L - 1,R,0) + L_Cost });
    else
        DP[L][R][Dic] = 0;

    return DP[L][R][Dic];

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 1005; i++)
        for (int j = 0; j < 1005; j++)
        {
            DP[i][j][0] = INF;
            DP[i][j][1] = INF;
        }

    cin >> N >> M;
    for (int n = 1; n <= N; n++)
        cin >> Data[n].first >> Data[n].second;
    sort(Data, Data + N);

    for (int n = 1; n <= N; n++)
        S[n] = S[n - 1] + Data[n].second;

    cout << D(M - 1, M + 1, 0) << endl;

}


