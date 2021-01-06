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

int N;

int DP[1000001];
int GetNum(int n, int start, int c)
{
	int ten = 1;
	int count = 0;
	int value = 0;
	while (n > 0)
	{
		if (count >= start && c > 0)
		{
			int a = n % 10;
			value += a * ten;
			ten *= 10;
			c--;
		}

		count++;
		n /= 10;
	}

	return value;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DP[1] = 0;
	DP[2] = 0;
	DP[3] = 0;
	DP[4] = 0;
	DP[5] = 0;
	DP[6] = 0;
	DP[7] = 0;
	DP[8] = 0;
	DP[9] = 0;

	for (int nn = 10; nn <= 1000000; nn++)
	{
		set<int> Set;
		int tt = log10(nn) + 1;
		for (int i = 1; i < tt; i++)
		{
			for (int j = 0; j < tt; j++)
			{
				if (j + i > tt)
					break;
				int s = GetNum(nn, j, i);
				if (s == 0)
					continue;
				if (Set.find(s) == Set.end())
					Set.insert(s);
			}
		}

		for (set<int>::iterator iter = Set.begin(); iter != Set.end(); iter++)
			if (DP[nn - (*iter)] == 0)
			{
				DP[nn] = (*iter);
				break;
			}
	}

	int N;
	cin >> N;

	if (DP[N] != 0)
		cout << DP[N] << endl;
	else
		cout << -1 << endl;
}
