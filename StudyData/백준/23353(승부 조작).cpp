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

int N;
int MAP[2000][2000];
int ans = 1;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		int s = 0;
		int a = 0;
		int b = 0;
		for (int e = 0; e < N; e++)
		{
			if (MAP[i][e] == 0)
			{
				while (e >= s)
				{
					if (MAP[i][s] == 1)
						a--;
					else if (MAP[i][s] == 2)
						b--;
					s++;
				}
			}
			else if (MAP[i][e] == 1)
			{
				a++;
			}
			else if (MAP[i][e] == 2)
			{
				b++;
				while (b >= 2)
				{
					if (MAP[i][s] == 1)
						a--;
					else if (MAP[i][s] == 2)
						b--;
					s++;
				}
			}
			ans = max(ans,a + b);
		}
	}

	for (int i = 0; i < N; i++)
	{
		int s = 0;
		int a = 0;
		int b = 0;
		for (int e = 0; e < N; e++)
		{
			if (MAP[e][i] == 0)
			{
				while (e >= s)
				{
					if (MAP[s][i] == 1)
						a--;
					else if (MAP[s][i] == 2)
						b--;
					s++;
				}
			}
			else if (MAP[e][i] == 1)
			{
				a++;
			}
			else if (MAP[e][i] == 2)
			{
				b++;
				while (b >= 2)
				{
					if (MAP[s][i] == 1)
						a--;
					else if (MAP[s][i] == 2)
						b--;
					s++;
				}
			}
			ans = max(ans, a + b);
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		pair<int, int> s = { 0,i };
		pair<int, int> e = { 0,i };
		int a = 0;
		int b = 0;
		while(e.first < N && e.second < N)
		{
			if (MAP[e.first][e.second] == 0)
			{
				while (e.first >= s.first)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second++;
				}
			}
			else if (MAP[e.first][e.second] == 1)
			{
				a++;
			}
			else if (MAP[e.first][e.second] == 2)
			{
				b++;
				while (b >= 2)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second++;
				}
			}
			e.first++;
			e.second++;
			ans = max(ans, a + b);
		}
	}
	for (int i = 0; i < N; i++)
	{
		pair<int, int> s = { i,0 };
		pair<int, int> e = { i,0 };
		int a = 0;
		int b = 0;
		while (e.first < N && e.second < N)
		{
			if (MAP[e.first][e.second] == 0)
			{
				while (e.first >= s.first)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second++;
				}
			}
			else if (MAP[e.first][e.second] == 1)
			{
				a++;
			}
			else if (MAP[e.first][e.second] == 2)
			{
				b++;
				while (b >= 2)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second++;
				}
			}
			e.first++;
			e.second++;
			ans = max(ans, a + b);
		}
	}

	for (int i = 0; i < N; i++)
	{
		pair<int, int> s = { 0,i };
		pair<int, int> e = { 0,i };
		int a = 0;
		int b = 0;
		while (e.first < N && e.second >= 0)
		{
			if (MAP[e.first][e.second] == 0)
			{
				while (e.first >= s.first)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second--;
				}
			}
			else if (MAP[e.first][e.second] == 1)
			{
				a++;
			}
			else if (MAP[e.first][e.second] == 2)
			{
				b++;
				while (b >= 2)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second--;
				}
			}
			e.first++;
			e.second--;
			ans = max(ans, a + b);
		}
	}
	for (int i = 0; i < N; i++)
	{
		pair<int, int> s = { i,N - 1 };
		pair<int, int> e = { i,N - 1 };
		int a = 0;
		int b = 0;
		while (e.first < N && e.second >= 0)
		{
			if (MAP[e.first][e.second] == 0)
			{
				while (e.first >= s.first)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second--;
				}
			}
			else if (MAP[e.first][e.second] == 1)
			{
				a++;
			}
			else if (MAP[e.first][e.second] == 2)
			{
				b++;
				while (b >= 2)
				{
					if (MAP[s.first][s.second] == 1)
						a--;
					else if (MAP[s.first][s.second] == 2)
						b--;
					s.first++;
					s.second--;
				}
			}
			e.first++;
			e.second--;
			ans = max(ans, a + b);
		}
	}
	cout << ans << endl;
}