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
#define float double
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int SqrtN = 1;
bool cmp(const tuple<int, int, int> A, const tuple<int, int, int> B)
{
	int Al = get<0>(A);
	int Ar = get<1>(A);
	int Bl = get<0>(B);
	int Br = get<1>(B);

	if (Al / SqrtN != Bl / SqrtN)
		return Al / SqrtN < Bl / SqrtN;
	return Ar < Br;
}

int N;
int A[100001];
int M;
vector<tuple<int, int, int>> Query;
int Result[100001];
int Number[1000001];
int s = 0;
int e = 0;
int value = 0;
void Count(int L,int R)
{
	while (s != L)
	{
		if (s < L)
		{
			Number[A[s]]--;
			if (Number[A[s]] == 0)
				value--;
			s++;
		}
		else if (s > L)
		{
			Number[A[s - 1]]++;
			if (Number[A[s - 1]] == 1)
				value++;
			s--;
		}
	}

	while (e != R)
	{
		if (e < R)
		{
			Number[A[e + 1]]++;
			if (Number[A[e + 1]] == 1)
				value++;
			e++;
		}
		else if (e > R)
		{
			Number[A[e]]--;
			if (Number[A[e]] == 0)
				value--;
			e--;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	SqrtN = sqrt(N);
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		Query.push_back(make_tuple(a, b, i));
	}

	sort(Query.begin(), Query.end(), cmp);

	for (int i = 0; i < Query.size(); i++)
	{
		int l = get<0>(Query[i]);
		int r = get<1>(Query[i]);
		int a = get<2>(Query[i]);
		Count(l, r);
		Result[a] = value;
	}

	for (int i = 1; i <= M; i++)
		cout << Result[i] << endl;
}
