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

const int INF = 0x3f3f3f3f3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int DP[1001][201];
int N, T;
pair<int, int> Arr[201];
int Dist[201][201];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	memset(DP, -1, sizeof(DP));

	std::cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		int c, e;
		std::cin >> c >> e;
		Arr[i] = { c,e };
		if (c == 0)
		{
			DP[0][i] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> Dist[i][j];
		}
	}

	for (int t = 1; t <= T; t++)
	{
		for (int e = 0; e < N; e++)
		{
			if (DP[t - 1][e] != -1)
				DP[t][e] = max(DP[t][e], DP[t - 1][e] + Arr[e].second);
			for (int s = 0; s < N; s++)
			{
				int temp = t - Dist[s][e];
				if (s == e || temp < 0)
					continue;
				if (DP[temp][s] != -1 && DP[temp][s] >= Arr[e].first)
					DP[t][e] = max(DP[t][e], DP[temp][s]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= T; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//cout << DP[i][j] << " ";
			ans = max(ans, DP[i][j]);
		}
		//cout << endl;
	}
	cout << ans << endl;
}