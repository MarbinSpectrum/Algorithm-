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

int MAP[3][3];
int Result[3][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
};

int ans = -1;

int TempMAP[3][3];
int TempValue = 0;
void MakeMAP()
{
	int temp = TempValue;
	for (int i = 0; i < 9; i++)
	{
		int a = 8 - i;
		TempMAP[a / 3][a % 3] = temp % 10;
		temp /= 10;
	}
}
int MakeInt()
{
	int v = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			v *= 10;
			v += TempMAP[i][j];
		}
	return v;
}
set<int> SET;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	pair<int, int> start;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 0)
			{
				start = { i,j };
				MAP[i][j] = 9;
			}
		}

	queue<pair<int, int>> Q;
	{
		TempValue = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				TempValue *= 10;
				TempValue += MAP[i][j];
			}
		SET.insert(TempValue);
		Q.push({ TempValue ,0 });
	}
	while (!Q.empty())
	{
		pair<int, int> now = Q.front();
		Q.pop();
		if (now.first == 123456789)
		{
			ans = now.second;
			break;
		}

		int r = 0;
		int c = 0;
		TempValue = now.first;
		MakeMAP();

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (TempMAP[i][j] == 9)
				{
					r = i;
					c = j;
					break;
				}

		for (int i = 0; i < 4; i++)
		{
			int ar = r + Dic[i][0];
			int ac = c + Dic[i][1];

			if (ar < 0 || ac < 0 || ar >= 3 || ac >= 3)
				continue;

			TempValue = now.first;
			MakeMAP();
			swap(TempMAP[ar][ac], TempMAP[r][c]);
			TempValue = MakeInt();

			if (SET.find(TempValue) != SET.end())
				continue;

			{

				SET.insert(TempValue);
				Q.push({ TempValue ,now.second + 1 });
			}
		}
	}

	cout << ans << endl;
}