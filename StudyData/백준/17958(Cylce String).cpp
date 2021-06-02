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

pair<int, char> A['z' - 'a' + 1];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string s;
	cin >> s;
	sort(s.begin(), s.end());

	for (char i = 'a'; i <= 'z'; i++)
		A[i - 'a'].second = i;

	for (int i = 0; i < s.length(); i++)
		A[s[i] - 'a'].first--;

	sort(A, A + 'z' - 'a' + 1);
	for (char i = 'a'; i <= 'z'; i++)
		A[i - 'a'].first = -A[i - 'a'].first;

	string t = "";
	for (char i = 'a'; i <= 'z'; i++)
		for (int j = 0; j < A[i - 'a'].first; j++)
			t += A[i - 'a'].second;

	s = t;

	int b = 1;
	for (; b < s.length(); b++)
		if (s[b] != s[0])
			break;

	if (b <= s.length() / 2)
	{
		cout << "YES" << endl;
		cout << s << endl;
	}
	else if (s[0] == s[s.length() - 1])
	{
		cout << "NO" << endl;
	}
	else
	{
		if (b == s.length() - 1)
		{
			cout << "NO" << endl;
			return 0;
		}
		else if (b == s.length() - 2 && s[b] == s[s.length()-1])
		{
			cout << "NO" << endl;
			return 0;
		}

		swap(s[s.length() / 2], s[b]);
		if (s[0] == s[s.length() - 1])
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			cout << s << endl;
		}
	}

}