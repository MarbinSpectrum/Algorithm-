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

int N;
int Arr[20];

int BitNum[100000];
int GetBitNum(int n)
{
	if (BitNum[n] != -1)
		return BitNum[n];
	BitNum[n] = 0;
	int nn = n;
	while (nn > 0)
	{
		if (nn % 2 != 0)
			BitNum[n]++;
		nn /= 2;
	}
	return BitNum[n];
}

//현재 기숙사 도달상태 //망토의 위치
int DP[100000][2];

int D(int bit, int a)
{
	if (DP[bit][a] != -1)
		return DP[bit][a];
	if (GetBitNum(bit) == N)
		return DP[bit][a] = 0;

	DP[bit][a] = INF;

	if (a == 0)
	{


		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (i == j)
					continue;
				if (bit & (1 << i))
					continue;
				if (bit & (1 << j))
					continue;
				DP[bit][a] = min(DP[bit][a], max(Arr[i], Arr[j]) + D((bit | (1 << i)) | (1 << j), 1));
			}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!(bit & (1 << i)))
				continue;
			DP[bit][a] = min(DP[bit][a], Arr[i] + D(bit - (1 << i), 0));
		}


	}

	return DP[bit][a];

}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init(DP, -1);
	Init(BitNum, -1);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	cout << D(0, 0) << endl;
}
