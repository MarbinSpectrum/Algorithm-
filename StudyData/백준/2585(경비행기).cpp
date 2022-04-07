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

		if (flag && temp.size() == 0)
			continue;
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

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

////////////////////////////////////////////////////////////////////////

int N,K;
vector<int> V[1002];
vector<pair<int, int>> P;
bool Visit[1002];
int Dis[1002][1002];

float Distance(int a, int b)
{
	return sqrt((P[a].first - P[b].first) * (P[a].first - P[b].first) + (P[a].second - P[b].second) * (P[a].second - P[b].second));
}
int L(float a)
{
	a /= 10.0f;
	return Ceil(a);
}
bool BFS(int a)
{
	memset(Visit, false, sizeof(Visit));
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	Visit[0] = true;
	while (!Q.empty())
	{
		pair<int, int> now = Q.front();
		Q.pop();

		if (now.second > K)
			continue;

		for (int i = 0; i < V[now.first].size(); i++)
		{
			if (Visit[V[now.first][i]])
				continue;
			if (L(Distance(now.first, V[now.first][i])) > a)
				continue;

			pair<int, int> next = { V[now.first][i],now.second + 1 };
			Q.push(next);
			Visit[next.first] = true;
		}
	}
	return Visit[N + 1];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	std::cin >> N >> K;
	P.push_back({ 0,0 });
	for (int i = 0; i < N; i++)
	{
		int a, b;
		std::cin >> a >> b;
		P.push_back({ a,b });
	}
	P.push_back({ 10000,10000 });

	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			if (i == j)
				continue;
			//int a = Distance(i, N + 1);
			//int b = Distance(j, N + 1);
			//if (a < b)
			//	continue;
			V[i].push_back(j);
		}
	}
	int s = 0;
	int e = INF;
	while (s < e)
	{
		int m = (s + e) / 2;
		if (BFS(m))
		{
			e = m;
		}
		else
		{
			s = m + 1;
		}
	}
	std::cout << e << endl;
}