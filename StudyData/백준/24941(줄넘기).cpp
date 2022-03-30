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

int N;
int A[500001];
map<int, int> A_map;
int A_Back[500001];

int Q;
vector<pair<int, int>> Query[500001];

int ans[500001];

int SegArr[500001];
int Segment[10000000];

void Update(int l, int r, int idx, int val, int node)
{
	if (l == r)
	{
		SegArr[l] = val;
		Segment[node] = val;
		return;
	}
	int m = (l + r) / 2;
	if (l <= idx && idx <= m)
	{
		Update(l, m, idx, val, node * 2);
	}
	else
	{
		Update(m + 1, r, idx, val, node * 2 + 1);
	}
	Segment[node] = max(Segment[node * 2], Segment[node * 2 + 1]);
}
int Get(int l, int r, int s, int e, int node)
{
	int m = (l + r) / 2;
	if (s <= l && r <= e)
	{
		return Segment[node];
	}
	else if (r < s || l > e)
	{
		return 0;
	}
	else
	{
		return max(Get(l, m, s, e, node * 2), Get(m + 1, r, s, e, node * 2 + 1));
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> A[i];
		A_map[A[i]] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		A_Back[i] = A_map[A[i]];
		A_map[A[i]] = i;
	}
	//for (int i = 0; i < N; i++)
	//{
	//	cout << A_Back[i] << " ";
	//}
	//cout << endl;

	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		Query[b].push_back({ a,i });
	}

	for (int i = 0; i < N; i++)
	{
		int Back_idx = A_Back[i];
		if (Back_idx != -1)
		{
			int len = i - Back_idx + 1;
			//cout << i << " ";
			//Debug(Back_idx, len);
			Update(0, N - 1, Back_idx, len, 1);
		}
		//for (int j = 0; j < N; j++)
		//	cout << SegArr[j] << " ";
		//cout << endl;
		for (int j = 0; j < Query[i].size(); j++)
		{
			ans[Query[i][j].second] = Get(0, N - 1, Query[i][j].first, i, 1);
			//Debug(Query[i][j].second, ans[Query[i][j].second]);
		}
	}
	for (int i = 0; i < Q; i++)
	{
		std::cout << ans[i] << endl;
	}

}