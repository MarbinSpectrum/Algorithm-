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

////////////////////////////////////////////////////////////////////////

using namespace std;

set<int> EASY[105];
set<int> HARD[105];
map<int, pair<int,int>> Problem;
set<pair<int, int>> EASY_ClASS[105];
set<pair<int, int>> HARD_ClASS[105];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Problem[a] = { b,c };
		HARD[b].insert(-a);
		EASY[b].insert(a);
		HARD_ClASS[c].insert({ -b,-a });
		EASY_ClASS[c].insert({ b,a });
		Problem[a] = { b,c };
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (s.compare("add") == 0)
		{
			int a, b, c;
			cin >> a >> b >> c;
			Problem[a] = { b,c };
			HARD[b].insert(-a);
			EASY[b].insert(a);
			HARD_ClASS[c].insert({ -b,-a });
			EASY_ClASS[c].insert({ b,a });
			Problem[a] = { b,c };
		}
		else if (s.compare("recommend") == 0)
		{
			int a, b;
			cin >> a >> b;
			if (b == 1)
			{
				set<pair<int, int>>::iterator iter = HARD_ClASS[a].begin();
				cout << -iter->second << endl;
			}
			else if (b == -1)
			{
				set<pair<int, int>>::iterator iter = EASY_ClASS[a].begin();
				cout << iter->second << endl;
			}
		}
		else if (s.compare("recommend2") == 0)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				for (int i = 100; i >= 1; i--)
					if (!HARD[i].empty())
					{
						set<int>::iterator iter = HARD[i].begin();
						cout << -*iter << endl;
						break;
					}
			}
			else if (a == -1)
			{
				for (int i = 1; i <= 100; i++)
					if (!EASY[i].empty())
					{
						set<int>::iterator iter = EASY[i].begin();
						cout << *iter << endl;
						break;
					}
			}
		}
		else if (s.compare("recommend3") == 0)
		{
			int a,b;
			cin >> a >> b;
			bool findFlag = false;
			if (a == 1)
			{
				for (int i = b; i <= 100; i++)
					if (!EASY[i].empty())
					{
						set<int>::iterator iter = EASY[i].begin();
						cout << *iter << endl;
						findFlag = true;
						break;
					}
			}
			else if (a == -1)
			{
				for (int i = b - 1; i >= 1; i--)
					if (!HARD[i].empty())
					{
						set<int>::iterator iter = HARD[i].begin();
						cout << -*iter << endl;
						findFlag = true;
						break;
					}
			}
			if (!findFlag)
				cout << -1 << endl;
		}
		else if (s.compare("solved") == 0)
		{
			int a;
			cin >> a;
			pair<int, int> V0 = { Problem[a].first,a };
			pair<int, int> V1 = { -Problem[a].first,-a };


			for (int i = 1; i <= 100; i++)
			{
				if (HARD[i].find(-a) != HARD[i].end())
					HARD[i].erase(-a);
				if (EASY[i].find(a) != EASY[i].end())
					EASY[i].erase(a);
				if (EASY_ClASS[i].find(V0) != EASY_ClASS[i].end())
					EASY_ClASS[i].erase(V0);
				if (HARD_ClASS[i].find(V1) != HARD_ClASS[i].end())
					HARD_ClASS[i].erase(V1);
			}
		}
	}
	
}