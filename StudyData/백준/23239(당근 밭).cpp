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
#define float long double
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
int Ceil(int a, int b)
{
	return (a % b == 0) ? (a / b) : (a / b + 1);
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

vector<string> split(string input, vector<char> check)
{
	vector<string> answer;
	input += check[0];
	string temp = "";
	for (int i = 0; i < input.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < check.size(); j++)
			if (input[i] == check[j])
			{
				flag = true;
				break;
			}
		if (flag && temp.size() > 0)
		{
			answer.push_back(temp);
			temp = "";
		}
		else
		{
			temp += input[i];
		}
	}
	return answer;
}

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int w, h, L;
int ans = 0;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> w >> h >> L;
	if (L <= h && L <= w)
	{
		for (int i = 0; i < L; i++)
		{
			int a = L - i;
			int b = sqrt(L * L - a * a);
			ans += b * 2 + 1;
		}
		for (int i = 0; i < L; i++)
		{
			int a = i;
			int b = sqrt(L * L - a * a);
			ans += b;
		}
		cout << ans << endl;
	}
	else if (L > h && L <= w)
	{
		for (int i = 0; i < L; i++)
		{
			int a = L - i;
			int b = sqrt(L * L - a * a);
			ans += b * 2 + 1;
		}
		for (int i = 0; i < L; i++)
		{
			int a = i;
			int b = sqrt(L * L - a * a);
			ans += b;
		}
		int Lh = L - h;
		for (int i = 0; i < Lh; i++)
		{
			int a = i;
			int b = sqrt(Lh * Lh - a * a);
			ans += b;
		}
		cout << ans << endl;
	}
	else if (L <= h && L > w)
	{
		for (int i = 0; i < L; i++)
		{
			int a = L - i;
			int b = sqrt(L * L - a * a);
			ans += b * 2 + 1;
		}
		for (int i = 0; i < L; i++)
		{
			int a = i;
			int b = sqrt(L * L - a * a);
			ans += b;
		}
		int Lw = L - w;
		for (int i = 1; i < Lw; i++)
		{
			int a = i;
			int b = sqrt(Lw * Lw - a * a);
			ans += b;
		}
		ans += Lw;
		cout << ans << endl;
	}
	else if (L > h && L > w && L <= w + h)
	{
		int Lw = L - w;
		int Lh = L - h;
		for (int i = 0; i < L; i++)
		{
			int a = L - i;
			int b = sqrt(L * L - a * a);
			ans += b * 2 + 1;
		}
		for (int i = 0; i < L; i++)
		{
			int a = i;
			int b = sqrt(L * L - a * a);
			ans += b;
		}

		for (int i = 0; i < Lh; i++)
		{
			int a = i;
			int b = sqrt(Lh * Lh - a * a);
			ans += b;
		}

		for (int i = 0; i < Lw; i++)
		{
			int a = i;
			int b = sqrt(Lw * Lw - a * a);
			ans += b;
		}

		cout << ans << endl;
	}
	else
	{
		int Lw = L - w;
		int Lh = L - h;
		for (int i = 0; i < L; i++)
		{
			int a = L - i;
			int b = sqrt(L * L - a * a);
			ans += b * 2 + 1;
		}
		for (int i = 0; i < L; i++)
		{
			int a = i;
			int b = sqrt(L * L - a * a);
			ans += b;
		}
		for (int i = 0; i < w; i++)
		{
			int a = i;
			int b = sqrt(Lh * Lh - a * a);
			ans += b;
		}

		for (int i = w; i < L; i++)
		{
			int a0 = i;
			int b0 = 0;
			if (Lh * Lh - a0 * a0 > 0)
				b0 = sqrt(Lh * Lh - a0 * a0) + h;
			int a1 = i - w;
			int b1 = 0;
			if (Lw * Lw - a1 * a1 > 0)
				b1 = sqrt(Lw * Lw - a1 * a1);
			ans += max(b0, b1);
		}
		ans += Lw;
		ans -= h;

		cout << ans << endl;
	}
}