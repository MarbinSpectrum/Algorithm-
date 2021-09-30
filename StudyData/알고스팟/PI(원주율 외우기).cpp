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
#include <unordered_map> 
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

int Mul(int x, int y, int mod)
{
	return x * y % mod;
}

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
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
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		b = b >> 1;
		a = (a * a);
	}
	return res;
}
int Pow(int a, int b, int p)
{
	int res = 1;
	a = a % p;
	while (b > 0)
	{
		if (b & 1)
			res = Mul(res, a, p);
		b = b >> 1;
		a = Mul(a, a, p);
	}
	return res;
}

const long long INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int DP[10005];
string s;
vector<int> S;

void Sol()
{
	cin >> s;
	S.resize(s.length() + 10);
	for (int i = 0; i < S.size(); i++)
		S[i] = INF;
	for (int i = 0; i < s.length(); i++)
		S[i] = s[i] - '0';

	memset(DP, INF, sizeof(DP));
	DP[0] = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (S[i] == S[i + 1] && S[i] == S[i + 2])
		{
			DP[i + 3] = min(DP[i] + 1, DP[i + 3]);
			if (S[i] == S[i + 3])
			{
				DP[i + 4] = min(DP[i] + 1, DP[i + 4]);
				if (S[i] == S[i + 4])
				{
					DP[i + 5] = min(DP[i] + 1, DP[i + 5]);
				}
			}	
		}

		if (S[i] == S[i + 1] - 1 && S[i] == S[i + 2] - 2)
		{
			DP[i + 3] = min(DP[i] + 2, DP[i + 3]);
			if (S[i] == S[i + 3] - 3)
			{
				DP[i + 4] = min(DP[i] + 2, DP[i + 4]);
				if (S[i] == S[i + 4] - 4)
				{
					DP[i + 5] = min(DP[i] + 2, DP[i + 5]);
				}
			}
		}
		if (S[i] == S[i + 1] + 1 && S[i] == S[i + 2] + 2)
		{
			DP[i + 3] = min(DP[i] + 2, DP[i + 3]);
			if (S[i] == S[i + 3] + 3)
			{
				DP[i + 4] = min(DP[i] + 2, DP[i + 4]);
				if (S[i] == S[i + 4] + 4)
				{
					DP[i + 5] = min(DP[i] + 2, DP[i + 5]);
				}
			}
		}

		if (S[i] != S[i + 1] && S[i] == S[i + 2])
		{
			DP[i + 3] = min(DP[i] + 4, DP[i + 3]);
			if (S[i + 1] == S[i + 3])
			{
				DP[i + 4] = min(DP[i] + 4, DP[i + 4]);
				if (S[i] == S[i + 4])
				{
					DP[i + 5] = min(DP[i] + 4, DP[i + 5]);
				}
			}
		}

		int dis = S[i] - S[i + 1];
		if (S[i] - S[i + 1] == dis && S[i + 1] - S[i + 2] == dis)
		{
			DP[i + 3] = min(DP[i] + 5, DP[i + 3]);
			if (S[i + 2] - S[i + 3] == dis)
			{
				DP[i + 4] = min(DP[i] + 5, DP[i + 4]);
				if (S[i + 3] - S[i + 4] == dis)
				{
					DP[i + 5] = min(DP[i] + 5, DP[i + 5]);
				}
			}
		}

		DP[i + 1] = min(DP[i] + 10, DP[i + 1]);
		DP[i + 2] = min(DP[i] + 10, DP[i + 2]);
		DP[i + 3] = min(DP[i] + 10, DP[i + 3]);
		DP[i + 4] = min(DP[i] + 10, DP[i + 4]);
		DP[i + 5] = min(DP[i] + 10, DP[i + 5]);
	}
	cout << DP[s.length()] << endl;
}
int C;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> C;
	while (C--)
	{
		Sol();
	}
}