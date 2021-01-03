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
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

vector<pair<int, long long>> TreeMin;
long long Arr[1000001];
int N, M;

pair<int, long long> InitMin(int node, int start, int end)
{
	if (start == end)
		TreeMin[node] = { start,Arr[start] };
	else
	{
		pair<int, long long> a = InitMin(node * 2, start, (start + end) / 2);
		pair<int, long long> b = InitMin(node * 2 + 1, (start + end) / 2 + 1, end);
		if (a.second < b.second)
			TreeMin[node] = a;
		else if (a.second == b.second)
		{
			if (a.first < b.first)
				TreeMin[node] = a;
			else
				TreeMin[node] = b;
		}
		else
			TreeMin[node] = b;
	}
	return TreeMin[node];
}

pair<int, long long> GetMin(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return { 100000000000,100000000000 };

	if (left <= start && end <= right)
		return TreeMin[node];

	pair<int, long long> a = GetMin(node * 2, start, (start + end) / 2, left, right);
	pair<int, long long> b = GetMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a.second < b.second)
		return a;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return a;
		else
			return b;
	}
	else
		return b;
}

pair<int, long long> Update(int node, int start, int end, int index, long long After)
{
	if (start == end && end == index)
	{
		Arr[index] = After;
		TreeMin[node].second = After;
		return TreeMin[node];
	}
	if (start > index || end < index)
		return TreeMin[node];

	pair<int, long long> a = Update(node * 2, start, (start + end) / 2, index, After);
	pair<int, long long> b = Update(node * 2 + 1, (start + end) / 2 + 1, end, index, After);
	if (a.second < b.second)
		TreeMin[node] = a;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			TreeMin[node] = a;
		else
			TreeMin[node] = b;
	}
	else
		TreeMin[node] = b;

	return TreeMin[node];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int H = ceil(log2f(N));
	TreeMin.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	InitMin(1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 2)
			cout << GetMin(1, 0, N - 1, b - 1, c - 1).first + 1 << "\n";
		else
		{
			Update(1, 0, N - 1, b - 1, c);
		}

	}
}
