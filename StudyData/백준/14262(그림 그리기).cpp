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

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M, T;
char MAP[51][51];
char BOARD[500][500];

void Paste(int a)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (MAP[i][j] != '.')
				BOARD[a + i][a + j] = MAP[i][j];
}
tuple<int, int, int> Color()
{
	int r, g, b;
	r = g = b = 0;
	for (int i = 0; i < 150; i++)
		for (int j = 0; j < 150; j++)
		{
			if (BOARD[i][j] == 'R')
				r++;
			else if (BOARD[i][j] == 'G')
				g++;
			else if (BOARD[i][j] == 'B')
				b++;
		}
	return { r,g,b };
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];

	if (T <= 100)
	{
		for (int i = 0; i < T; i++)
		{
			Paste(i);
		}
		tuple<int, int, int> ans = Color();

		cout << get<0>(ans) << endl;
		cout << get<1>(ans) << endl;
		cout << get<2>(ans) << endl;
	}
	else
	{
		for (int i = 0; i < 100; i++)
		{
			Paste(i);
		}
		tuple<int, int, int> ans0 = Color();
		Paste(100);
		tuple<int, int, int> ans1 = Color();
		tuple<int, int, int> dis = { get<0>(ans1) - get<0>(ans0) ,get<1>(ans1) - get<1>(ans0)  ,get<2>(ans1) - get<2>(ans0) };

		T -= 101;
		tuple<int, int, int> ans = { get<0>(ans1) + get<0>(dis) * T ,get<1>(ans1) + get<1>(dis) * T  ,get<2>(ans1) + get<2>(dis) * T };

		cout << get<0>(ans) << endl;
		cout << get<1>(ans) << endl;
		cout << get<2>(ans) << endl;
	}


}