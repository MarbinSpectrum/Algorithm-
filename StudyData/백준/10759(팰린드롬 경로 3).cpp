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

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

const int MOD = 1000000007;
int N;
char MAP[501][501];
int DP[501][501];
int NextDP[501][501];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> MAP[i][j];
	for (int i = 1; i <= N; i++)
		DP[i][i] = 1;

	for (int i = 1; i <= N - 1; i++)
	{
		for (int r1 = 1; r1 <= N; r1++)
			for (int r2 = N; r2 >= r1; r2--)
			{
				int c1 = N - r1 + 1 - i;
				int c2 = N - r2 + 1 + i;
				if (c1 <= 0 || c2 > N)
					continue;
				if (MAP[r1][c1] != MAP[r2][c2])
					continue;
				NextDP[r1][r2] += DP[r1][r2] % MOD;
				NextDP[r1][r2] %= MOD;
				NextDP[r1][r2] += DP[r1 + 1][r2] % MOD;
				NextDP[r1][r2] %= MOD;
				NextDP[r1][r2] += DP[r1][r2 - 1] % MOD;
				NextDP[r1][r2] %= MOD;
				NextDP[r1][r2] += DP[r1 + 1][r2 - 1] % MOD;
				NextDP[r1][r2] %= MOD;
			}

		for(int a = 1; a <= N; a++)
			for (int b = 1; b <= N; b++)
			{
				DP[a][b] = NextDP[a][b];
				NextDP[a][b] = 0;
			}

	}

	cout << DP[1][N] % MOD << endl;
}
