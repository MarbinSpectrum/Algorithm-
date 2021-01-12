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

// C++ 
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
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

const int MAX_V = 20001;

int N, M;
int K;
vector<pair<int, int>> V[MAX_V];
int Dis[MAX_V];

void dijkstra(int start)
{
	for (int i = 0; i < MAX_V; i++)
		Dis[i] = INF;
	Dis[start] = 0;

	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curVertex = pq.top().second;

		pq.pop();

		if (Dis[curVertex] < cost)
			continue;

		for (int i = 0; i < V[curVertex].size(); i++)
		{
			int neighbor = V[curVertex][i].first;

			int neighborDistance = cost + V[curVertex][i].second;

			if (Dis[neighbor] > neighborDistance)
			{
				Dis[neighbor] = neighborDistance;
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}
	}

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> K;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		//V[b].push_back({ a,c });
	}

	dijkstra(K);

	for (int i = 1; i <= N; i++)
	{
		if (Dis[i] == INF)
			cout << "INF" << endl;
		else
			cout << Dis[i] << endl;

	}

}
