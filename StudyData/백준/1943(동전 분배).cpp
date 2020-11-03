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

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int T, N;
bool DP[200][200001];
pair<int, int> Coin[200];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	T = 3;

	while (T--)
	{
		cin >> N;
		Init(DP, false);
		for (int i = 0; i < 100; i++)
			Coin[i] = { 0,0 };

		for (int i = 0; i < N; i++)
		{
			cin >> Coin[i].first;
			cin >> Coin[i].second;
		}

		for (int n = 0; n <= Coin[0].second; n++)
			DP[0][n * Coin[0].first] = true;

		for (int i = 1; i < N; i++)
			for (int j = 0; j <= 100000; j++)
				if (DP[i - 1][j])
					for (int n = 0; n <= Coin[i].second; n++)
						DP[i][j + n * Coin[i].first] = true;

		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += Coin[i].first * Coin[i].second;

		if (sum & 1)
			cout << 0 << endl;
		else
		{
			bool flag = false;
			sum /= 2;
			for (int i = 0; i < N; i++)
				if (DP[i][sum])
					flag = true;

			if (flag)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
}
