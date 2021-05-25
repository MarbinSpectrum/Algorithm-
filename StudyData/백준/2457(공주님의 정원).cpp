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
#define float long double
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

	return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int Month[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
int N;
int Day[800];
vector<pair<int, int>> Arr;
vector<int> V[800];
bool Visit[800];
int ans = INF;

int BFS(int n)
{
	for (int i = 0; i < 800; i++)
		Visit[i] = false;
	int start = Arr[n].first;

	queue<pair<int, int>> Q;
	Q.push({ n,1 });
	Visit[n] = true;

	while (!Q.empty())
	{
		int now = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if (start <= Month[2] + 1 && Arr[now].second >= Month[11])
			return d;
		else if (Month[2] + 1 < start && start <= Month[11] && Arr[now].second >= start + 365 - 1)
			return d;
		else if (start > Month[11] && Arr[now].second >= Month[11] + 365)
			return d;
		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i];
			if (Visit[next])
				continue;
			Q.push({ next,d + 1 });
			Visit[next] = true;
		}
	}
	return INF;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int startDay = Month[a - 1] + b;
		int endDay = Month[c - 1] + d - 1;
		if (startDay > endDay)
			endDay += 365;

		Day[startDay] = max(Day[startDay], endDay);
	}

	for (int i = 0; i < 800; i++)
		if (Day[i])
			Arr.push_back({ i,Day[i] });

	for (int i = 0; i < Arr.size(); i++)
		for (int j = 0; j < Arr.size(); j++)
		{
			if (i == j)
				continue;
			int S = Arr[i].first;
			int E = Arr[i].second;
			if (E + 1 > 365)
				E -= 365;
			if (E + 1 >= Arr[j].first)
				V[i].push_back(j);
		}

	for (int i = 0; i < Arr.size(); i++)
		ans = min(ans, BFS(i));

	if (ans == INF)
		ans = 0;
	cout << ans << endl;
}