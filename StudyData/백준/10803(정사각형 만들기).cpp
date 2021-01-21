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


int N, M;
//i j크기의 사각형을 잘라서 만드는 최소값
int DP[10005][105];
int D(int n, int m)
{
	if (n < m) 
		swap(n, m);
	if (DP[n][m] != INF)
		return DP[n][m];
	if (n % m == 0)
		return DP[n][m] = n / m;
	if (n > m * 3)
		DP[n][m] = min(DP[n][m], D(m, n - m) + 1);
	else
	{
		for (int i = 1; i < n; i++)
		{
			int a = i;
			int b = n - a;
			if (a > b)
				break;
			int Check = D(a, m) + D(b, m);
			DP[n][m] = min(DP[n][m], Check);
		}

		for (int i = 1; i < m; i++)
		{
			int a = i;
			int b = m - a;
			if (a > b)
				break;
			int Check = D(n, a) + D(n, b);
			DP[n][m] = min(DP[n][m], Check);
		}
	}

	return DP[n][m];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < 101; j++)
			DP[i][j] = INF;

	cin >> N >> M;

	cout << D(N, M) << endl;
}
