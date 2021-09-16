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

int N, M;
vector<pair<int, int>> foxV[6000];
int foxDist[6000];
vector<pair<pair<int, int>, int>> wolfV[6000][2];
int wolfDist[6000][2];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		foxDist[i] = INF;
		wolfDist[i][0] = INF;
		wolfDist[i][1] = INF;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b,c;
		cin >> a >> b >> c;
		foxV[a].push_back({ b,c * 2 });
		foxV[b].push_back({ a,c * 2 });
		wolfV[a][0].push_back({ { b,1 }, c });
		wolfV[b][0].push_back({ { a,1 }, c });
		wolfV[a][1].push_back({ { b,0 }, c * 4 });
		wolfV[b][1].push_back({ { a,0 }, c * 4 });
	}

	{
		queue<pair<int, int>> Q;
		Q.push({ 0,1 });
		foxDist[1] = 0;
		while (!Q.empty())
		{
			int now = Q.front().second;
			int cost = -Q.front().first;
			Q.pop();
			if (foxDist[now] < cost)
				continue;
			for (int i = 0; i < foxV[now].size(); i++)
			{
				int next = foxV[now][i].first;
				int nextCost = cost + foxV[now][i].second;
				if (nextCost >= foxDist[next])
					continue;
				foxDist[next] = nextCost;
				Q.push({ -nextCost,next });
			}
		}
	}
	{
		queue<pair<int, pair<int,int>>> Q;
		Q.push({ 0,{1,0} });
		wolfDist[1][0] = 0;
		while (!Q.empty())
		{
			pair<int, int> now = Q.front().second;
			int cost = -Q.front().first;
			Q.pop();
			if (wolfDist[now.first][now.second] < cost)
				continue;
			for (int i = 0; i < wolfV[now.first][now.second].size(); i++)
			{
				pair<int, int> next = wolfV[now.first][now.second][i].first;
				int nextCost = cost + wolfV[now.first][now.second][i].second;
				if (nextCost >= wolfDist[next.first][next.second])
					continue;
				wolfDist[next.first][next.second] = nextCost;
				Q.push({ -nextCost,next });
			}
		}
	}

	int ans = 0;

	for (int i = 2; i <= N; i++)
		if (foxDist[i] < min(wolfDist[i][0], wolfDist[i][1]))
			ans++;

	cout << ans << endl;
}