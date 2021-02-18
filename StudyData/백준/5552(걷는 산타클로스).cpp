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

vector<pair<int, int>> Pos;
vector<int> X;
vector<int> Y;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W,H,N;
	cin >> W >> H;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a,b;
		cin >> a >> b;
		Pos.push_back({ a,b });
	}

	for (int i = 0; i < N; i++)
		X.push_back(Pos[i].first);

	for (int i = 0; i < N; i++)
		Y.push_back(Pos[i].second);

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	int startX = X[(X.size() - 1) / 2];
	int endX = X[X.size() / 2];

	int startY = Y[(Y.size() - 1) / 2];
	int endY = Y[Y.size() / 2];

	pair<pair<int, int>, int> Result;
	Result.second = INF;


	for (int xf = 0; xf < 2; xf++)
	{
		for (int yf = 0; yf < 2; yf++)
		{
			int ax = xf == 0 ? startX : endX;
			int ay = yf == 0 ? startY : endY;

			int maxDis = 0;
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				int dis = abs(ax - Pos[i].first) + abs(ay - Pos[i].second);
				sum += dis;
				maxDis = max(maxDis, dis);
			}
			sum *= 2;
			sum -= maxDis;

			if (Result.second > sum)
			{
				Result.second = sum;
				Result.first = { ax,ay };
			}
		}
	}

	cout << Result.second << endl;
	Debug(Result.first.first, Result.first.second);
}