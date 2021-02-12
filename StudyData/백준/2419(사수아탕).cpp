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
		return (int)n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;


int n, m;
vector<int> CandyPos;
//(현재 좌표)//(나머지한쪽좌표)//방향
int DP[302][302][2];

int D(int first, int second, int dic, int eat)
{
	if (eat == 0)
		return 0;
	if (first > second)
		return INF;
	if (DP[first][second][dic] != -1)
		return DP[first][second][dic];
	int Value = INF;

	if (dic == 1)
	{
		if (second + 1 <= n)
			Value = min(Value, D(first, second + 1, 0, eat - 1) + eat * abs(CandyPos[second + 1] - CandyPos[first]));
		if (first - 1 >= 0)
			Value = min(Value, D(first - 1, second, 1, eat - 1) + eat * abs(CandyPos[first - 1] - CandyPos[first]));
	}
	else if (dic == 0)
	{
		if (second + 1 <= n)
			Value = min(Value, D(first, second + 1, 0, eat - 1) + eat * abs(CandyPos[second + 1] - CandyPos[second]));
		if (first - 1 >= 0)
			Value = min(Value, D(first - 1, second, 1, eat - 1) + eat * abs(CandyPos[first - 1] - CandyPos[second]));
	}
	return DP[first][second][dic] = Value;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	CandyPos.resize(n);
	for (int i = 0; i < n; i++)
		cin >> CandyPos[i];
	CandyPos.push_back(0);

	sort(CandyPos.begin(), CandyPos.end());

	int index = 0;

	for (int i = 0; i < CandyPos.size(); i++)
		if (CandyPos[i] == 0)
		{
			index = i;
			break;
		}

	int Result = 0;

	for (int c = 1; c <= n; c++)
	{
		Init(DP, -1);
		Result = max(Result, c * m - D(index, index, 0, c));
	}

	cout << Result << endl;

}