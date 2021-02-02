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

int N, K, S;
int A[100001];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> S;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		A[a] = b;
	}

	int result = 0;

	int bus = 0;

	int Left = 0;
	int FL = -1;
	while (true)
	{
		if (Left != S)
		{
			if (bus + A[Left] >= K)
			{
				if (bus == 0 && A[Left] > 0)
					FL = Left;
				int a = K - bus;
				A[Left] -= a;

				result += abs(S - FL) * 2;
				bus = 0;
			}
			else
			{
				if (bus == 0 && A[Left] > 0)
					FL = Left;
				bus += A[Left];
				A[Left] = 0;
				Left++;
			}
		}
		else
		{
			if (bus > 0)
			{
				result += abs(S - FL) * 2;
				bus = 0;
			}
			break;
		}
	}

	int Right = 100000;
	int FR = -1;
	while (true)
	{
		if (Right != S)
		{
			if (bus + A[Right] >= K)
			{
				if (bus == 0 && A[Right] > 0)
					FR = Right;
				int a = K - bus;
				A[Right] -= a;

				result += abs(S - FR) * 2;
				bus = 0;
			}
			else
			{
				if (bus == 0 && A[Right] > 0)
					FR = Right;
				bus += A[Right];
				A[Right] = 0;
				Right--;
			}
		}
		else
		{
			if (bus > 0)
			{
				result += abs(S - FR) * 2;
				bus = 0;
			}
			break;
		}
	}


	cout << result << endl;
}