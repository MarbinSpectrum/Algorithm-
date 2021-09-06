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

int T;
vector<tuple<int, int, int>> V[101];
int Dist[101][10001];
int N, M, K;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 101; i++)
			V[i].clear();

		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			V[u].push_back({ d,c,v });
		}

		memset(Dist, INF, sizeof(Dist));

		Dist[1][0] = 0;
		priority_queue<tuple<int, int, int>> PQ;
		PQ.push({ 0,0,1 });

		int ans = INF;

		while (!PQ.empty())
		{
			int dis = -get<0>(PQ.top());
			int cost = get<1>(PQ.top());
			int now = get<2>(PQ.top());

			PQ.pop();

			if (Dist[now][cost] < dis)
				continue;
			if (cost > M)
				continue;
			if (ans == INF && now == N)
			{
				ans = dis;
				break;
			}

			for (int i = 0; i < V[now].size(); i++)
			{
				int nextDis = dis + get<0>(V[now][i]);
				int nextCost = cost + get<1>(V[now][i]);
				int next = get<2>(V[now][i]);

				if (nextCost > M)
					continue;

				if (Dist[next][nextCost] > nextDis)
				{
					Dist[next][nextCost] = nextDis;

					for (int j = nextCost; j <= M; j++)
						if (Dist[next][j] > nextDis)
							Dist[next][j] = nextDis;



					PQ.push({ -nextDis,nextCost, next });
				}
			}
		}

		for (int i = 0; i <= M; i++)
			ans = min(ans, Dist[N][i]);

		if (ans == INF)
			cout << "Poor KCM" << endl;
		else
			cout << ans << endl;
	}


}