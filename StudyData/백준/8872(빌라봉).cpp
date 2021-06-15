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


int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
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
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	int temp = Pow(a, b / 2);
	if (b % 2 == 0)
		return temp * temp;
	else
		return temp * temp * a;
}

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M, L;
vector<pair<int, int>> V[100001];
bool Visit[100001];

pair<int, int> Node = { -1,-1 };
void DFS(int a, int b, int p)
{
	Visit[a] = true;
	bool flag = false;
	for (int i = 0; i < V[a].size(); i++)
	{
		int next = V[a][i].first;
		if (p == next)
			continue;
		flag = true;
		DFS(next, b + V[a][i].second, a);
	}
	if (!flag)
		if (Node.first < b)
			Node = { b,a };
}
pair<int, int> Par[100001];
bool Check[100001];
void BFS(int a)
{
	queue<int> Q;
	Check[a] = true;
	Q.push(a);

	while (!Q.empty())
	{
		int temp = Q.front();
		Q.pop();
		for (int i = 0; i < V[temp].size(); i++)
		{
			int next = V[temp][i].first;
			if (Check[next])
				continue;
			Par[next] = { temp, V[temp][i].second };
			Check[next] = true;
			Q.push(next);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> L;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	int R = 0;
	vector<int> Arr;
	for (int i = 0; i < N; i++)
		if (!Visit[i])
		{
			Node = { -1,-1 };
			DFS(i, 0, -1);

			int a = Node.second;
			Node = { -1,-1 };
			DFS(a, 0, -1);


			BFS(a);

			int b = Node.second;
			vector<int> tempArr;
			int sum0 = 0;
			int sum1 = 0;

			while (a != b)
			{
				tempArr.push_back(Par[b].second);
				sum0 += Par[b].second;
				b = Par[b].first;
			}
			R = max(R, sum0);
			int result = INF;
			for (int i = 0; i < tempArr.size(); i++)
			{
				sum0 -= tempArr[i];
				sum1 += tempArr[i];
				result = min(result, max(sum0, sum1));
			}
			if (result == INF)
				result = 0;
			Arr.push_back(result);
		}

	sort(Arr.begin(), Arr.end());
	reverse(Arr.begin(), Arr.end());
	if (Arr.size() == 1)
		cout << max(R, Arr[0]);
	else if (Arr.size() == 2)
		cout << max(R, Arr[0] + Arr[1] + L);
	else
		cout << max(R, max(Arr[0], Arr[2] + L) + Arr[1] + L);
}