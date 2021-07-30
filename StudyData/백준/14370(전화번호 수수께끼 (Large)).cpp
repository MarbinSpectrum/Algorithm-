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

const int INF = 8999999999999999999;

////////////////////////////////////////////////////////////////////////

using namespace std;

string s;
int alpha[26];
int ans[11];
string A[10] =
{
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};
bool flag = false;
int Find[10] = { 0,6,4,8,3,2,5,9,7,1 };
void DFS(int f)
{
	if (flag)
		return;
	if (f >= 10)
	{
		for (int i = 0; i < 26; i++)
			if (alpha[i] != 0)
				return;

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < ans[i]; j++)
				cout << i;
		cout << endl;
		flag = true;
		return;
	}
	else
	{
		int ff = Find[f];

		if (ff == 0)
		{
			int j = alpha['Z' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;

				DFS(f + 1);
			}

		}
		else if (ff == 6)
		{
			int j = alpha['X' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;

				DFS(f + 1);
			}
		}
		else if (ff == 4)
		{
			int j = alpha['U' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;

				DFS(f + 1);
			}
		}
		else if (ff == 8)
		{
			int j = alpha['G' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;

				DFS(f + 1);
			}
		}
		else if (ff == 3)
		{
			int j = alpha['H' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;

				DFS(f + 1);
			}
		}
		else if (ff == 2)
		{
			int j = alpha['W' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;
				DFS(f + 1);
			}
		}
		else if (ff == 5)
		{
			int j = alpha['F' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;
				DFS(f + 1);
			}
		}
		else if (ff == 9)
		{
			int j = alpha['I' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;
				DFS(f + 1);
			}
		}
		else if (ff == 7)
		{
			int j = alpha['S' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;
				DFS(f + 1);
			}
		}
		else if (ff == 1)
		{
			int j = alpha['N' - 'A'];
			{
				for (int i = 0; i < A[ff].length(); i++)
					alpha[A[ff][i] - 'A'] -= j;

				ans[ff] += j;
				DFS(f + 1);
			}
		}
	}
}
int t = 0;
void Sol()
{
	t++;
	cin >> s;
	flag = false;
	memset(alpha, 0, sizeof(alpha));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < s.length(); i++)
		alpha[s[i] - 'A']++;
	cout << "Case #" << t << ": ";
	DFS(0);

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
		Sol();
}