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
vector<pair<int, int>> Card;
vector<pair<int, int>> Arr;
vector<int> Arr1;
vector<int> Arr2;
vector<int> Array;

vector<int> Tree[1000000];
void Init(int a, int l, int r)
{
	for (int i = l; i <= r; i++)
		Tree[a].push_back(Array[i]);

	if (l == r)
		return;

	sort(Tree[a].begin(), Tree[a].end());

	int m = (l + r) / 2;
	Init(a * 2, l, m);
	Init(a * 2 + 1, m + 1, r);
}

int Query(int a, int l, int r, int s, int e, int b)
{
	int res = 0;

	if (e < l || r < s)
		return 0;

	if (s <= l && r <= e)
	{
		int c = lower_bound(Tree[a].begin(), Tree[a].end(), b) - Tree[a].begin();
		if (0 <= c && c < Tree[a].size())
			return Tree[a].size() - c;
		else
			return 0;
	}

	int m = (l + r) / 2;
	res = Query(a * 2, l, m, s, e, b) + Query(a * 2 + 1, m + 1, r, s, e, b);

	return res;
}
int MaxSeg[1000000];
int InitMax(int a, int l, int r)
{
	if (l == r)
		return MaxSeg[a] = l;
	int m = (l + r) / 2;
	int aa = InitMax(a * 2, l, m);
	int bb = InitMax(a * 2 + 1, m + 1, r);
	
	if (Arr2[aa] > Arr2[bb])
		MaxSeg[a] = aa;
	else
		MaxSeg[a] = bb;

	return MaxSeg[a];
}
int QueryMax(int a, int l, int r, int s, int e)
{
	int res = 0;

	if (e < l || r < s)
		return -1;

	if (s <= l && r <= e)
		return MaxSeg[a];

	int m = (l + r) / 2;

	int aa = QueryMax(a * 2, l, m, s, e);
	int bb = QueryMax(a * 2 + 1, m + 1, r, s, e);
	//Debug(l, r);
	//Debug(aa, bb);
	if(aa < 0)
		res = bb;
	else if (bb < 0)
		res = aa;
	else
	{
		if (Arr2[aa] > Arr2[bb])
			res = aa;
		else
			res = bb;
	}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	//Arr2.push_back(3);
	//Arr2.push_back(4);
	//Arr2.push_back(6);
	//Arr2.push_back(1);
	//Arr2.push_back(2);

	//InitMax(1, 0, 4);

	//cout << QueryMax(1, 0, 4, 1, 4) << endl;

	//return 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		Card.push_back({ a,b });
	}
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		Arr.push_back({ a,i });
		Array.push_back(a);
	}
	sort(Arr.begin(), Arr.end());

	for (int i = 0; i < M; i++)
	{
		Arr1.push_back(Arr[i].first);
		Arr2.push_back(Arr[i].second);
	}

	Init(1, 0, M - 1);
	InitMax(1, 0, M - 1);
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int mMin = min(Card[i].first, Card[i].second);
		int mMax = max(Card[i].first, Card[i].second);
		int sp = (lower_bound(Arr1.begin(), Arr1.end(), mMin) - Arr1.begin());
		int ep = (lower_bound(Arr1.begin(), Arr1.end(), mMax) - Arr1.begin());
		int a = 0;

		if (sp < ep)
		{
			int start = QueryMax(1, 0, M - 1, sp, ep - 1);
			start = Arr2[start];
			a = Query(1, 0, M - 1, start+1, M - 1, mMax);
			ans += a % 2 == 0 ? mMax : mMin;
			//cout << "!";
			//Debug(sp, ep);
			//Debug("!", start);
		}
		else
		{
			a = Query(1, 0, M - 1, 0, M - 1, mMax);
			ans += a % 2 == 0 ? Card[i].first : Card[i].second;
		}
		//cout << a << endl;
	}

	cout << ans << endl;
}