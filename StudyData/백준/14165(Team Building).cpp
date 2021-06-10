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
const int Dic9[9][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{+1,+1},{-1,+1},{1,-1},{-1,-1},{0,0} };
////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M, K;
int DP[1005][1005][20];
vector<int> A;
vector<int> B;
const int MOD = 1000000009;
int D(int a, int b, int c)
{
	if (c >= K)
		return 1;
	if (a >= N || b >= M)
		return 0;
	if (DP[a][b][c] != -1)
		return DP[a][b][c];
	DP[a][b][c] = 0;
	if (A[a] > B[b])
	{
		DP[a][b][c] += D(a + 1, b + 1, c + 1);
		DP[a][b][c] = (DP[a][b][c] + MOD) % MOD;
	}
	DP[a][b][c] += D(a + 1, b, c);
	DP[a][b][c] = (DP[a][b][c] + MOD) % MOD;
	DP[a][b][c] += D(a, b + 1, c);
	DP[a][b][c] = (DP[a][b][c] + MOD) % MOD;
	DP[a][b][c] -= D(a + 1, b + 1, c);
	DP[a][b][c] = (DP[a][b][c] + MOD) % MOD;

	return DP[a][b][c];
}
bool cmp(int a, int b)
{
	return a < b;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, -1, sizeof(DP));

	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		B.push_back(a);
	}
	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end(), cmp);

	cout << D(0, 0, 0) << endl;
}