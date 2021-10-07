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

int N;
vector<bool> MAP;
vector<int> Arr;
vector<pair<int, int>> Data;
int ans = 0;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	Arr.resize(N);
	MAP.resize(N);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		Data.push_back({ a,i });
		MAP[i] = (a > 0);
	}

	{
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (MAP[i] && !flag)
			{
				flag = true;
				ans++;
			}
			else if (!MAP[i] && flag)
			{
				flag = false;
			}
		}
	}

	sort(Data.begin(), Data.end());

	int Ans = ans;
	int back = -1;
	for (int i = 0; i < N; i++)
	{
		if (Data[i].first == 0)
			continue;

		int idx = Data[i].second;
		if (back != Data[i].first)
		{
			//Debug(back, ans);
			Ans = max(ans, Ans);
			back = Data[i].first;
		}

		MAP[idx] = false;

		if (idx == 0)
		{
			if (!MAP[idx + 1])
			{
				ans--;
				continue;
			}
		}
		else if (idx == N - 1)
		{
			if (!MAP[idx - 1])
			{
				ans--;
				continue;
			}
		}
		else if (MAP[idx - 1] && MAP[idx + 1])
		{
			ans++;
			continue;
		}
		else if (!MAP[idx - 1] && !MAP[idx + 1])
		{
			ans--;
			continue;
		}
	}
	Ans = max(ans, Ans);
	cout << Ans << endl;
}