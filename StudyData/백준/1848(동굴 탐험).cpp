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

using namespace std;

int N, M;
int Cost[5001][5001];
vector<pair<int,int>> V[5001];
vector<int> Arr;
int NodeAB[5001];
int Dist[5001];
int ans = INF;
void D(int s, int m)
{
	for (int i = 0; i < N; i++)
		NodeAB[i] = -1;

	int flag = 0;
	for (int i = 0; i < Arr.size(); i++)
	{
		NodeAB[Arr[i]] = m;
		flag++;
		if (flag >= s)
		{
			flag = 0;
			m = !m;
		}
	}

	memset(Dist, INF, sizeof(Dist));
	priority_queue<pair<int, int>> Q;
	Q.push({ 0,1 });
	Dist[1] = 0;
	
	while (!Q.empty())
	{
		int now = Q.top().second;
		int cost = -Q.top().first;
		Q.pop();
		if (Dist[now] < cost) 
			continue;
		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i].first;

			if (now == 1 && NodeAB[next] == 0)
				continue;
			if (next == 1 && NodeAB[now] == 0)
				continue;

			int nextCost = cost + V[now][i].second;
			if (Dist[next] > nextCost)
			{
				Dist[next] = nextCost;
				Q.push({-nextCost,next });
			}
		}
	}

	for (int i = 0; i < Arr.size(); i++)
		if (NodeAB[Arr[i]] == 0)
			ans = min(ans, Dist[Arr[i]] + Cost[Arr[i]][1]);
}

void F(int s)
{
	if (s >= Arr.size())
		return;
	D(s, 0);
	D(s, 1);
	F(s * 2);
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Cost[a][b] = c;
		Cost[b][a] = d;
		V[a].push_back({ b,c });
		V[b].push_back({ a,d });
	}
	for (int i = 0; i < V[1].size(); i++)
		Arr.push_back(V[1][i].first);
	
	F(1);

	cout << ans << endl;
}