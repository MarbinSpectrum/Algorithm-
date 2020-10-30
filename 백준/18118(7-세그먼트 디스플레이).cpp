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

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int T, N, M;
int Result = 0;
//자릿수 나머지

int DP[100][100000];
int UseDigit[100][100000];

void F(int deep, int m)
{
	if (UseDigit[deep][m] + 1 != deep + 1)
		return;

	int Next = 0;
	for (int i = 0; i <= 9; i++)
	{
		Next = (DP[deep][m] * M + m) * 10 + i;
		DP[deep + 1][Next % M] = max(DP[deep + 1][Next % M], Next / M);
		UseDigit[deep + 1][Next % M] = UseDigit[deep][m] + 1;
	}
	Next = (DP[deep][m] * M + m) * 100 + 11;
	DP[deep + 1][Next % M] = max(DP[deep + 1][Next % M], Next / M);
	UseDigit[deep + 1][Next % M] = UseDigit[deep][m] + 1;

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		Result = 0;
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 100000; j++)
				DP[i][j] = 0;
		for (int i = 0; i <= 9; i++)
			for (int j = 1; j <= 100000; j++)
				UseDigit[i][j] = 1 + i;
		cin >> N >> M;

		for (int i = 1; i <= N; i++)
			for (int j = 0; j <= M; j++)
				F(i - 1, j);

		cout << DP[N][0] * M << endl;
	}

}
