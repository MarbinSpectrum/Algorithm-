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

const int MOD = 1000000007;

using namespace std;

int T, N;
char MAP[2000][2000];

void Color(int a, int b, int w, char c, int dic)
{
	for (int j = b; j < b + w; j++)
		for (int i = a; i < a + w; i++)
		{
			if (dic == 0 && a + w * 0.5f <= i && b + w * 0.5f <= j)
				continue;
			if (dic == 1 && a + w * 0.5f > i && b + w * 0.5f <= j)
				continue;
			if (dic == 2 && a + w * 0.5f > i && b + w * 0.5f > j)
				continue;
			if (dic == 3 && a + w * 0.5f <= i && b + w * 0.5f > j)
				continue;
			MAP[j][i] = c;
		}
}

void DFS(int a, int b, int w, int dic)
{
	if (w == 4)
	{
		if (dic == 0)
		{
			Color(a, b, w * 0.5, 'b', 0);
			Color(a + w * 0.25, b + w * 0.25, w * 0.5, 'a', 0);
			Color(a, b + w * 0.5, w * 0.5, 'c', 3);
			Color(a + w * 0.5, b, w * 0.5, 'c', 1);
		}
		else if (dic == 1)
		{
			Color(a, b, w * 0.5, 'b', 0);
			Color(a + w * 0.5, b, w * 0.5, 'c', 1);
			Color(a + w * 0.25, b + w * 0.25, w * 0.5, 'a', 1);
			Color(a + w * 0.5, b + w * 0.5, w * 0.5, 'b', 2);
		}
		else if (dic == 2)
		{
			Color(a + w * 0.25, b + w * 0.25, w * 0.5, 'a', 2);
			Color(a + w * 0.5, b + w * 0.5, w * 0.5, 'b', 2);
			Color(a + w * 0.5, b , w * 0.5, 'c', 1);
			Color(a, b + w * 0.5, w * 0.5, 'c', 3);
		}
		else if (dic == 3)
		{
			Color(a, b, w * 0.5, 'b', 0);
			Color(a + w * 0.5, b + w * 0.5, w * 0.5, 'b', 2);
			Color(a + w * 0.25, b + w * 0.25, w * 0.5, 'a', 3);
			Color(a, b + w * 0.5, w * 0.5, 'c', 3);
		}
		return;
	}

	if (dic == 0)
	{
		DFS(a, b, w * 0.5, 0);
		DFS(a + w * 0.5, b, w * 0.5, 1);
		DFS(a, b + w * 0.5, w * 0.5, 3);
		DFS(a + w * 0.25, b + w * 0.25, w * 0.5, 0);
	}
	else if (dic == 1)
	{
		DFS(a, b, w * 0.5, 0);
		DFS(a + w * 0.5, b, w * 0.5, 1);
		DFS(a + w * 0.25, b + w * 0.25, w * 0.5, 1);
		DFS(a + w * 0.5, b + w * 0.5, w * 0.5, 2);
	}
	else if (dic == 2)
	{
		DFS(a + w * 0.5, b, w * 0.5, 1);
		DFS(a, b + w * 0.5, w * 0.5, 3);
		DFS(a + w * 0.5, b + w * 0.5, w * 0.5, 2);
		DFS(a + w * 0.25, b + w * 0.25, w * 0.5, 2);
	}
	else if (dic == 3)
	{
		DFS(a, b, w * 0.5, 0);
		DFS(a, b + w * 0.5, w * 0.5, 3);
		DFS(a + w * 0.25, b + w * 0.25, w * 0.5, 3);
		DFS(a + w * 0.5, b + w * 0.5, w * 0.5, 2);
	}
}

int x, y;
void DFS2(int a, int b,int w)
{
	if (w == 2)
	{
		int temp = a / 2 + b / 2;
		char nc = temp % 2 == 0 ? 'b' : 'c';
		if (x < a + w * 0.5 && y < b + w * 0.5)
		{
			Color(a, b, w, nc, 2);
		}
		else if (x < a + w * 0.5 && y >= b + w * 0.5)
		{
			Color(a, b, w, nc, 1);
		}
		else if (x >= a + w * 0.5 && y < b + w * 0.5)
		{
			Color(a, b, w, nc, 3);
		}
		else if (x >= a + w * 0.5 && y >= b + w * 0.5)
		{
			Color(a, b, w, nc, 0);
		}

		return;
	}
	if (x < a + w * 0.5 && y < b + w * 0.5)
	{
		DFS(a, b, w, 2);
		DFS2(a, b, w * 0.5);
	}
	else if (x < a + w * 0.5 && y >= b + w * 0.5)
	{
		DFS(a, b, w, 1);
		DFS2(a, b + w * 0.5, w * 0.5);
	}
	else if (x >= a + w * 0.5 && y < b + w * 0.5)
	{
		DFS(a, b, w, 3);
		DFS2(a + w * 0.5, b , w * 0.5);
	}
	else if (x >= a + w * 0.5 && y >= b + w * 0.5)
	{
		DFS(a, b, w, 0);
		DFS2(a + w * 0.5, b + w * 0.5, w * 0.5);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> T >> N;
	while (T--)
	{
		for (int i = 0; i < 2000; i++)
			for (int j = 0; j < 2000; j++)
				MAP[i][j] = ' ';

		cin >> y >> x;
		x--;
		y--;
		MAP[y][x] = '@';
		DFS2(0, 0, 1 << N);

		for (int i = 0; i < (1 << N); i++)
		{
			for (int j = 0; j < (1 << N); j++)
				cout << MAP[i][j];
			cout << endl;
		}
	}

}