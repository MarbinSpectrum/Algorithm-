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
#define float long double
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

	return temp * temp * ((b % 2) ? a : 1);
}

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M, K, B;
int DP[1003][1003];
pair<int, int> Type[1001];
vector<pair<int, int>> Arr;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> B;
	Arr.push_back({ -1,0 });
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		Type[b] = { Type[b].first + a,Type[b].second + 1 };
		Arr.push_back({ b,a });
	}

	sort(Arr.begin(), Arr.end());

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int a = Type[Arr[i].first].first;
			int b = Type[Arr[i].first].second;
			if (Arr[i].first != Arr[i - 1].first && j - b >= 0)
			{
				int& temp = DP[i + b][j - b];
				temp = max(temp, DP[i][j] + a + B);
			}
			{
				int& temp = DP[i + 1][j - 1];
				temp = max(temp, DP[i][j] + Arr[i].second);
			}
			{
				int& temp = DP[i + 1][j];
				temp = max(temp, DP[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 1003; i++)
		for (int j = 0; j < 1003; j++)
			ans = max(ans, DP[i][j]);

	cout << ans << endl;
}