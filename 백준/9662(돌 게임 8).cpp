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
const int Prime[] =
{
	2 ,3 ,5 ,7 ,11 ,13 ,17, 19 ,23 ,29,
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
	73 ,79 ,83 ,89 ,97 ,101 ,103 ,107 ,109 ,113,
	127 ,131, 137, 139 ,149 ,151, 157 ,163 ,167 ,173,
	179 ,181, 191, 193, 197, 199, 211, 223 ,227 ,229,
	233 ,239 ,241 ,251 ,257 ,263 ,269 ,271 ,277 ,281,
	283 ,293 ,307 ,311 ,313 ,317 ,331 ,337 ,347 ,349,
	353 ,359 ,367 ,373 ,379 ,383 ,389 ,397 ,401 ,409,
	419 ,421 ,431 ,433 ,439 ,443 ,449 ,457 ,461 ,463,
	467 ,479 ,487 ,491 ,499 ,503 ,509 ,521 ,523 ,541
};

////////////////////////////////////////////////////////////////////////

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, K;
	cin >> M >> K;

	int arr[22];
	for (int i = 0; i < K; ++i)
		cin >> arr[i];

	long long N;
	long long R = 0;
	long long DP[20001][2];   //패턴을 찾기위한 DP
	long long Pattern[20001];
	int patternSize = 3000;

	DP[0][0] = 1;
	DP[0][1] = 0;

	for (int i = 1; i <= 20000; i++)
	{
		DP[i][1] = 0;
		for (int j = 0; j < K; j++)
		{
			if (i - arr[j] >= 0 && DP[i - arr[j]][0] == 1)
			{
				DP[i][1] = 1;
				break;
			}
		}

		DP[i][0] = 1;
		for (int j = 0; j < K; j++)
		{
			if (i - arr[j] >= 0 && DP[i - arr[j]][1] == 0)
			{
				DP[i][0] = 0;
				break;
			}
		}
	}

	while (patternSize > 0)
	{
		for (int i = 1; i <= patternSize; i++)
		{
			if ((DP[i + 0 * patternSize][1] == DP[i + 1 * patternSize][1]) &&
				(DP[i + 1 * patternSize][1] == DP[i + 2 * patternSize][1]) &&
				(DP[i + 2 * patternSize][1] == DP[i + 3 * patternSize][1]) &&
				(DP[i + 3 * patternSize][1] == DP[i + 4 * patternSize][1]))
			{

			}
			else
			{
				patternSize--;
				continue;
			}
		}
		break;
	}

	if (M <= 20000)
	{
		for (int i = 1; i <= M; i++)
			if (DP[i][1] == 0)
				R++;

		cout << R;
		return 0;
	}
	else
	{
		int a = 0;
		for (int i = 3000; i < 3000 + patternSize; i++)
			if (DP[i][1] == 0)
				a++;

		int d = 0;
		for (int i = 0; i <= 3000 + (M - 3000) % patternSize; i++)
			if (DP[i][1] == 0)
				d++;

		cout << (M - 3000) / patternSize * a + d - 1;
		//printf("[%d %d %d]\n", a, b, d);
	}



}