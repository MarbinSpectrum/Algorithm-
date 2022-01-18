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

int N, M;
vector<pair<int, pair<int, int>>> Arr;
vector<pair<int,int>> V[101];

int Dist[101];
int FindDist(int a,int b)
{
	for (int i = 1; i <= N; i++)
		Dist[i] = INF;
	Dist[a] = 0;
	priority_queue<pair<int, int>> Q;
	Q.push({ 0,a });
	while (!Q.empty())
	{
		pair<int, int> temp = Q.top();
		Q.pop();
		int d = -temp.first;
		int now = temp.second;
		if (Dist[now] < d)
			continue;
		for (int i = 0; i < V[now].size(); i++)
		{
			int nd = d + V[now][i].first;
			int next = V[now][i].second;
			if (Dist[next] > nd)
			{
				Dist[next] = nd;
				Q.push({ -nd,next });
			}
		}
	}
	return Dist[b];
}

bool Visit[101][101];
vector<pair<int, pair<int, int>>> ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			int a;
			std::cin >> a;
			Arr.push_back({ a,{i,j} });
		}
	}
	sort(Arr.begin(), Arr.end());

	for (int i = 0; i < Arr.size(); i++)
	{
		int a = Arr[i].second.first;
		int b = Arr[i].second.second;
		int dist = Arr[i].first;
		int findDist = FindDist(a, b);
		//현재갈수잇는 경로가 없거나,   현재경로가 dist보다 클때 ==> 간선추가
		if (findDist == INF || findDist > dist)
		{
			V[a].push_back({ dist,b });
			V[b].push_back({ dist,a });	
			ans.push_back({ dist,{a,b} });
			Visit[a][b] = Visit[b][a] = true;
		}
		//현재경로가 dist와 같다 => 추가할필요가 없다.
		else if (findDist == dist) 
		{
			continue;
		}
		//일어날수 없는 현상이다 
		else if (findDist < dist)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	sort(ans.begin(), ans.end());

	if(ans.size() == M)
	{
		cout << 1 << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].second.first << " ";
			cout << ans[i].second.second << " ";
			cout << ans[i].first << endl;
		}
		return 0;
	} 	
	else if (ans.size() < M)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (Visit[i][j] == Visit[j][i] && Visit[i][j] == false)
				{
					ans.push_back({ 500,{i,j} });
					Visit[i][j] = true;
				}
			}
		}
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].second.first << " ";
			cout << ans[i].second.second << " ";
			cout << ans[i].first << endl;
		}
		cout << 1 << endl;
		return 0;
	}
	else
	{
		cout << 0 << endl;
		return 0;
	}
}