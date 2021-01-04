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

const int MOD = 10007;

int C[201][201];
int DP[101][101];
int D(int a, int b)
{
	if (DP[a][b] != -1)
		return DP[a][b];
	if (b == 0)
		return DP[a][b] = 1;
	if (a == 0 && b > 0)
		return DP[a][b] = 0;
	else
	{
		int A = (D(a - 1, b - 3) * C[4][3]) % MOD;
		A = (A + (D(a - 1, b - 2) * C[4][2]) % MOD) % MOD;
		A = (A + (D(a - 1, b - 1) * C[4][1]) % MOD) % MOD;
		A = (A + (D(a - 1, b - 0) * C[4][0]) % MOD) % MOD;
		return DP[a][b] = A;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init(DP, -1);
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;
	for (int i = 2; i < 101; i++)
		for (int j = 0; j <= i; j++)
			C[i][j] = (C[i - 1][j] + (j - 1 < 0 ? 0 : C[i - 1][j - 1])) % MOD;

	int N;
	cin >> N;

	if (N < 4)
		cout << 0 << endl;
	else
	{
		int Result = 0;
		for (int i = 4; i <= N; i += 4)
		{
			int flag = ((i / 4) % 2 ? 1 : -1);

			Result = (Result + flag * C[13][i / 4] * C[52 - i][N - i]) % MOD;
		}

		cout << (Result + MOD) % MOD << endl;
	}

}
