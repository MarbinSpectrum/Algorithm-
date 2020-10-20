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

int N, B, U;
int Result = -1;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B >> U;

	if (N >= B)
	{
		cout << 1 << endl;
		return 0;
	}

	queue<pair<int, tuple<int, int, int>>> Queue;
	Queue.push({ 0,make_tuple(N, B, 0) });
	while (!Queue.empty())
	{
		int t = Queue.front().first;
		int n = get<0>(Queue.front().second);
		int b = get<1>(Queue.front().second);
		int enemy = get<2>(Queue.front().second);
		Queue.pop();
		//cout << t << "] " << n << " " << b << " " << enemy << endl;
		if (n <= 0)
			continue;

		if (enemy <= 0 && b > 0)
		{
			int next_b = b - n;
			if (next_b <= 0)
			{
				Result = t + 1;
				break;
			}
			Queue.push({ t + 1,make_tuple(n, next_b, (next_b > 0 ? U : 0)) });
		}
		else if (enemy > 0 && b <= 0)
		{
			int next_enemy = enemy - n;
			if (next_enemy <= 0)
			{
				Result = t + 1;
				break;
			}
			Queue.push({ t + 1,make_tuple(n - next_enemy, 0, next_enemy) });
		}
		else if (enemy > 0 && b > 0)
		{
			if (enemy < n)
			{
				int next_enemy = 0;
				int next_b = b - abs(enemy - n);
				Queue.push({ t + 1,make_tuple(n - next_enemy, next_b, (next_b > 0 ? U : 0)) });
			}
			if (b < n)
			{
				int next_enemy = enemy - abs(b - n);
				int next_b = 0;
				Queue.push({ t + 1,make_tuple(n - next_enemy, 0, next_enemy) });
			}
			if (Result != -1)
				break;
		}
		else
		{
			Result = t;
			break;
		}
	}


	cout << Result << endl;
	return 0;



}