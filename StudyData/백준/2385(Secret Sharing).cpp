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

int N;
vector<string> Arr[2];

bool cmp(string a, string b) {
	return a + b < b + a;
}
string Arrtemp[101];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s[0] == '0')
			Arr[1].push_back(s);
		else
			Arr[0].push_back(s);
	}

	{
		vector<string> ans;

		for (int i = 0; i < Arr[0].size(); i++)
		{
			Arrtemp[0] = Arr[0][i];

			int a = 1;
			for (int j = 0; j < Arr[0].size(); j++)
			{
				if (i == j)
					continue;
				Arrtemp[a] = Arr[0][j];
				a++;
			}
			for (int j = 0; j < Arr[1].size(); j++)
			{
				Arrtemp[a] = Arr[1][j];
				a++;
			}
			sort(Arrtemp + 1, Arrtemp + N, cmp);
			string ansTemp = "";
			for (int j = 0; j < N; j++)
				ansTemp += Arrtemp[j];
			ans.push_back(ansTemp);
		}

		sort(ans.begin(), ans.end());

		if (ans.size() == 0)
			cout << "INVALID" << endl;
		else
			cout << ans[0] << endl;

	}

}