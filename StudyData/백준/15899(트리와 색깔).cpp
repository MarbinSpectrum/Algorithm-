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

const int MAX = 200005;
int N, M, C;
int P[MAX];
bool Visit[MAX];
int Color[MAX];
int Color2[MAX];
std::vector<int> V[MAX];
int DFS(int a)
{
	Visit[a] = true;
	for (int i = 0; i < V[a].size(); i++)
	{
		int next = V[a][i];
		if (Visit[next])
			continue;
		P[a] += DFS(next);
	}
	return P[a];
}
int NumP[MAX];
int NumIdx = 1;
bool Visit2[MAX];
void SetNum(int a)
{
	Visit2[a] = true;
	NumP[a] = NumIdx++;
	for (int i = 0; i < V[a].size(); i++)
	{
		int next = V[a][i];
		if (Visit2[next])
			continue;
		SetNum(next);
	}
}

std::vector<int> colorTree[2000000];
void Init(int node, int a, int b)
{
	if (a == b)
	{
		colorTree[node].push_back(Color2[a]);
		return;
	}
	Init(node * 2, a, (a + b) / 2);
	Init(node * 2 + 1, (a + b) / 2 + 1, b);
	int p0 = 0;
	int p1 = 0;
	while (p0 < colorTree[node*2].size() || p1 < colorTree[node * 2 + 1].size())
	{
		if (p0 < colorTree[node * 2].size() && p1 < colorTree[node * 2 + 1].size())
		{
			if (colorTree[node * 2][p0] <= colorTree[node * 2 + 1][p1])
			{
				colorTree[node].push_back(colorTree[node * 2][p0]);
				p0++;
			}
			else
			{
				colorTree[node].push_back(colorTree[node * 2 + 1][p1]);
				p1++;
			}
		}
		else if (p0 < colorTree[node * 2].size() && p1 >= colorTree[node * 2 + 1].size())
		{
			colorTree[node].push_back(colorTree[node * 2][p0]);
			p0++;
		}
		else if (p0 >= colorTree[node * 2].size() && p1 < colorTree[node * 2 + 1].size())
		{
			colorTree[node].push_back(colorTree[node * 2 + 1][p1]);
			p1++;
		}
	}
}

int Query(int node, int a, int b, int f, int e,int color)
{
	int result = 0;

	if (f <= a && b <= e)
	{
		result =
		upper_bound(colorTree[node].begin(), colorTree[node].end(), color) -
			colorTree[node].begin();
	}
	else if (b < f || e < a)
		result = 0;
	else
	{
		result += Query(node * 2, a, (a + b) / 2, f, e, color);
		result += Query(node * 2 + 1, (a + b) / 2 + 1, b, f, e, color);
	}
	return result;
}

const int MOD = 1000000007;
int answer = 0;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < MAX; i++)
		P[i] = 1;

	std::cin >> N >> M >> C;
	for (int i = 1; i <= N; i++)
		std::cin >> Color[i];
	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;
		std::cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	DFS(1);
	SetNum(1);

	for (int i = 1; i <= N; i++)
	{
		int idx = NumP[i];
		Color2[idx] = Color[i];
	}
	Init(1, 1, N);


	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		int size = P[a];
		a = NumP[a];
		answer = (answer + Query(1, 1, N, a, a + size - 1, b)) % MOD;
	}

	std::cout << answer << endl;
}

