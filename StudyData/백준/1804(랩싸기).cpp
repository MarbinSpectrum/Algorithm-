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
#define Init(a,b) memset(a,b,sizeof(a))

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

int N, K, B;
map<int, int> MAP;
vector<pair<int, int>> Arr;
int DP[1005][1005][4];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1005; i++)
        for (int j = 0; j < 1005; j++)
            for (int k = 0; k < 4; k++)
                DP[i][j][k] = INF;

    cin >> N >> K >> B;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[b] = MAP[b] | (1 << (a - 1));
    }
    Arr.push_back({ 0,0 });
    for (map<int, int>::iterator iter = MAP.begin(); iter != MAP.end(); iter++)
        Arr.push_back(*iter);
    N = Arr.size() - 1;
    DP[0][0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int bit = Arr[i].second;

        for (int k = 1; k <= K; k++)
        {
            for (int j = 0; j < 4; j++)
                DP[i][k][0] = min(DP[i][k][0], DP[i - 1][k - 1][j] + 2);
            DP[i][k][0] = min(DP[i][k][0], DP[i - 1][k][0] + 2 * (Arr[i].first - Arr[i - 1].first));

            if (bit == 1)
            {
                for (int j = 0; j < 4; j++)
                    DP[i][k][1] = min(DP[i][k][1], DP[i - 1][k - 1][j] + 1);
                DP[i][k][1] = min(DP[i][k][1], DP[i - 1][k][1] + (Arr[i].first - Arr[i - 1].first));
                DP[i][k][1] = min(DP[i][k][1], DP[i - 1][k][3] + (Arr[i].first - Arr[i - 1].first));
            }
            if (bit == 2)
            {
                for (int j = 0; j < 4; j++)
                    DP[i][k][2] = min(DP[i][k][2], DP[i - 1][k - 1][j] + 1);
                DP[i][k][2] = min(DP[i][k][2], DP[i - 1][k][2] + (Arr[i].first - Arr[i - 1].first));
                DP[i][k][2] = min(DP[i][k][2], DP[i - 1][k][3] + (Arr[i].first - Arr[i - 1].first));
            }
            if(k > 1)
                for (int j = 0; j < 4; j++)
                    DP[i][k][3] = min(DP[i][k][3], DP[i - 1][k - 2][j] + 2);
            for (int j = 1; j < 4; j++)
                DP[i][k][3] = min(DP[i][k][3], DP[i - 1][k - 1][j] + 1 + (Arr[i].first - Arr[i - 1].first));
            DP[i][k][3] = min(DP[i ][k][3], DP[i - 1][k][3] + 2 * (Arr[i].first - Arr[i - 1].first));
        }
    }
    
    int Result = INF;

    for (int i = 0; i < 4; i++)
        Result = min(Result, DP[N][K][i]);

    cout << Result << endl;

}