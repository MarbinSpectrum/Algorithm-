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

int N, M;
vector<pair<int, int>> V[200001];
int Paper[200001];
int Dist[200001];
int Back[200001];
int nowPaper[200001];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		V[u].push_back({ v,w });
		V[v].push_back({ u,w });
	}
	int SumPaper = 0;
	for (int i = 1; i <= N; i++)
	{
		Dist[i] = INF;
		nowPaper[i] = -1;
		std::cin >> Paper[i];
		SumPaper += Paper[i];
	}

	priority_queue<pair<int, int>> Q;
	Q.push({ 0,1 });
	Dist[1] = 0;
	nowPaper[1] = Paper[1];
	Back[1] = 1;

	while (!Q.empty())
	{
		pair<int, int> now = Q.top();
		Q.pop();
		int nowCost = -now.first;
		int nowPont = now.second;

		if (nowCost > Dist[nowPont])
			continue;

		for (int i = 0; i < V[nowPont].size(); i++)
		{
			pair<int, int> next = V[nowPont][i];
			int nextCost = nowCost + next.second;
			int nextPoint = next.first;

			if (Dist[nextPoint] >= nextCost)
			{
				Dist[nextPoint] = nextCost;
				Q.push({ -nextCost,nextPoint });

				if (nowPaper[nextPoint] <= nowPaper[nowPont] + Paper[nextPoint])
				{
					nowPaper[nextPoint] = nowPaper[nowPont] + Paper[nextPoint];
					Back[nextPoint] = nowPont;
				}
			}
		}
	}

	if (nowPaper[N] == SumPaper)
	{
		stack<int> ans;
		int a = N;
		ans.push(N);
		while (Back[a] != a)
		{
			a = Back[a];
			ans.push(a);
		}
		std::cout << ans.size() << endl;
		while (!ans.empty())
		{
			std::cout << ans.top() << " ";
			ans.pop();
		}
		std::cout << endl;
	}
	else
	{
		std::cout << -1 << endl;
	}
}