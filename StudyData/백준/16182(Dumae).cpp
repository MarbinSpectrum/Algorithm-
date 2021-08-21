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
int L[300001];
int R[300001];
vector<int> V1[300001];
vector<int> V2[300001];
int d1[300001];
int d2[300001];
vector<int> A[300001];
vector<int> B[300001];

int Par[300001];
int FindP(int n)
{
	if (Par[n] == n)
		return n;
	else
		return Par[n] = FindP(Par[n]);
}
vector<tuple<int, int, int>> Arr;
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
	return get<1>(a) < get<1>(b);
}
int ans[300001];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;

		L[i] = a;
		R[i] = b;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
			
		V1[a].push_back(b);
		V2[b].push_back(a);
		d1[b]++;
		d2[a]++;
	}

	{
		queue<int> Queue;
		for (int i = 1; i <= N; i++)
			if (d1[i] == 0)
				Queue.push(i);
		while (!Queue.empty())
		{
			int now = Queue.front();
			Queue.pop();
			for (auto i : V1[now])
			{
				L[i] = max(L[i], L[now] + 1);
				d1[i]--;
				if(d1[i] == 0)
					Queue.push(i);
			}
		}
		for (int i = 1; i <= N; i++)
			if (d1[i] != 0)
			{
				cout << -1 << endl;
				return 0;
			}
	}


	{
		queue<int> Queue;
		for (int i = 1; i <= N; i++)
			if (d2[i] == 0)
				Queue.push(i);
		while (!Queue.empty())
		{
			int now = Queue.front();
			Queue.pop();
			for (auto i : V2[now])
			{
				R[i] = min(R[i], R[now] - 1);
				d2[i]--;
				if (d2[i] == 0)
					Queue.push(i);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		Arr.push_back({ L[i],R[i],i });
	sort(Arr.begin(),Arr.end(), cmp);
	for (int i = 1; i <= N; i++)
		Par[i] = i;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		a = get<0>(Arr[i]);
		b = get<1>(Arr[i]);
		c = get<2>(Arr[i]);
		int left = FindP(a);
		if(left > b || left < a)
		{
			cout << -1 << endl;
			return 0;
		}
		ans[left] = c;
		Par[left] = left + 1;
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << endl;

}