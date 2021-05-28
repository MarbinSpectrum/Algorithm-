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
#define int unsigned long long
#define float double
#define Debug(a,b) cout << a << " " << b << endl

int Mul(int x, int y, int mod)
{
	return (__int128)x * y % mod;
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

bool MillerRabin(int n, int a)
{
	int r = 0;
	int d = n - 1;
	while (d % 2 == 0)
	{
		r++;
		d = d >> 1;
	}
	int x = Pow(a, d, n);
	if (x == 1 || x == n - 1)
		return true;
	for (int i = 0; i < r - 1; i++)
	{
		x = Pow(x, 2, n);
		if (x == n - 1)
			return true;
	}
	return false;


}
int SameplePrime[13] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };
bool IsPrime(int n)
{
	if (n <= 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 0; i < 13; i++)
	{
		if (n == SameplePrime[i])
			return true;
		if (!MillerRabin(n, SameplePrime[i]))
			return false;
	}
	return true;
}

int PollardRho(int n)
{
	if (IsPrime(n))
		return n;
	if (n <= 1)
		return 1;
	if (n % 2 == 0)
		return 2;
	int x = rand() % (n - 2) + 2;
	int y = x;
	int c = rand() % (n - 1) + 1;
	int d = 1;

	while (d == 1)
	{
		x = (Mul(x, x, n) + c + n) % n;
		y = (Mul(y, y, n) + c + n) % n;
		y = (Mul(y, y, n) + c + n) % n;
		int ABS = x > y ? x - y : y - x;
		d = GCD(ABS, n);
		if (d == n)
			return PollardRho(n);
	}

	if (IsPrime(d))
		return d;
	else
		return PollardRho(d);

}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> ans;

	while (N > 1)
	{
		int d = PollardRho(N);
		ans.push_back(d);
		N /= d;
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}