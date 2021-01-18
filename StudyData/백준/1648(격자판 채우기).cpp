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

const int MOD = 9901;

int N, M;
int DP[15][1 << 15];
int StartBitCheck[1 << 15];
int startBitCheck(int bit)
{
	if (StartBitCheck[bit] != -1)
		return StartBitCheck[bit];
	StartBitCheck[bit] = 0;
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		if (bit & (1 << i))
		{
			if (count % 2 == 1)
				return StartBitCheck[bit] = 0;
		}
		else
			count++;
	}
	if (count % 2 == 1)
		return StartBitCheck[bit] = 0;
	else
		return StartBitCheck[bit] = 1;
}
int D(int n, int bitA)
{
	if (DP[n][bitA] != -1)
		return DP[n][bitA];
	if (n >= N)
		return 1;
	DP[n][bitA] = 0;
	
	for (int bitB = 0; bitB < (1 << M); bitB++)
	{
		bool flag = true;
		if (bitA & bitB)
			flag = false;
		int bitC = bitA | bitB;
		if (startBitCheck(bitC) == 0)
			flag = false;
		if (n == N - 1)
		{
			if (bitB > 0)
				flag = false;
			if(startBitCheck(bitA) == 0)
				flag = false;
		}
		if (flag)
		{
			DP[n][bitA] += D(n + 1, bitB) % MOD;
			DP[n][bitA] %= MOD;
		}
	}
	return DP[n][bitA] % MOD;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init(DP, -1);
	Init(StartBitCheck, -1);

	cin >> N >> M;

	int result = 0;

	for (int bit = 0; bit < (1 << M); bit++)
		if (startBitCheck(bit) == 1)
		{
			bool flag = true;
			if (0 == N - 1)
				if (bit > 0)
					flag = false;

			if (flag)
			{
				result += D(1, bit) % MOD;
				result %= MOD;
			}
		}

	cout << result << endl;

}
