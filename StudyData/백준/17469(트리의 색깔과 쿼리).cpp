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

int N,Q;
int Link[100001];
vector<pair<int, int>> Query;

int P[100001];
set<int> Color[100001];

int FindP(int n)
{
	if (n == P[n])
		return n;
	else
		return P[n] = FindP(P[n]);
}
void UniP(int a, int b)
{
	a = FindP(a);
	b = FindP(b);
	if (Color[a].size() < Color[b].size())
		swap(a, b);
	for (set<int>::iterator iter = Color[b].begin(); iter != Color[b].end(); iter++)
		if (Color[a].find(*iter) == Color[a].end())
			Color[a].insert(*iter);
	P[b] = a;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> Q;

	for (int i = 2; i <= N; i++)
		cin >> Link[i];

	for (int i = 1; i <= N; i++)
		P[i] = i;

	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		Color[i].insert(a);
	}

	for (int i = 0; i < Q + N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		Query.push_back({ a,b });
	}

	vector<int> Ans;
	while (!Query.empty())
	{
		pair<int, int> Q = Query.back();
		Query.pop_back();

		if (Q.first == 1)
		{
			int a = FindP(Q.second);
			int b = FindP(Link[Q.second]);
			UniP(a, b);
			int c = Color[a].size();
		
		}
		else
		{
			int a = Color[FindP(Q.second)].size();
			Ans.push_back(a);
		}
	}

	reverse(Ans.begin(), Ans.end());

	for (int i = 0; i < Ans.size(); i++)
		cout << Ans[i] << endl;


}