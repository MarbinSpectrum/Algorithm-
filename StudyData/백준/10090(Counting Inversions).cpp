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

vector<int> Tree;
vector<int> Lazy;
int Arr[1000001];
int Arr2[1000001];
int N, M, K;
int Init(int node, int start, int end)
{
	if (start == end)
		Tree[node] = Arr[start];
	else
		Tree[node] = Init(node * 2, start, (start + end) / 2) + Init(node * 2 + 1, (start + end) / 2 + 1, end);

	return Tree[node];
}

int Sum(int node, int start, int end, int left, int right)
{
	if (Lazy[node] != 0)
	{
		Tree[node] += (end - start + 1) * Lazy[node];
		if (start != end)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return Tree[node];

	return Sum(node * 2, start, (start + end) / 2, left, right) + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void Update(int node, int start, int end, int left, int right, int add)
{
	if (Lazy[node] != 0)
	{
		Tree[node] += (end - start + 1) * Lazy[node];
		if (start != end)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	if (left > end || right < start)
		return;

	if (left <= start && end <= right)
	{
		Tree[node] += (end - start + 1) * add;
		if (start != end)
		{
			Lazy[node * 2] += add;
			Lazy[node * 2 + 1] += add;
		}
		return;
	}

	Update(node * 2, start, (start + end) / 2, left, right, add);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, add);

	Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int H = ceil(log2f(N));
	Tree.resize(pow(2, H + 1));
	Lazy.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		Arr[i] = i;
	for (int i = 0; i < N; i++)
		cin >> Arr2[i];

	Init(1, 0, N - 1);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += Sum(1, 0, N - 1, Arr2[i] - 1, Arr2[i] - 1);
		Update(1, 0, N - 1, Arr2[i], N - 1, -1);
	}
	cout << ans << endl;
}