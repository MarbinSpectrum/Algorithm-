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

int DP[10001][2][2];
int A[10001];
vector<int> tempV[10001];
vector<int> V[10001];
void MakeTree(int now, int par)
{
	for (int i = 0; i < tempV[now].size(); i++)
	{
		int next = tempV[now][i];
		if (next == par)
			continue;
		MakeTree(next, now);
		V[now].push_back(next);
	}
}
//now : 현재마을 //state : 우수마을 여부 //state2 : 전마을의 우수마을 여부
int D(int now, int state1, int state2)
{
	if (DP[now][state1][state2] != -1)
		return DP[now][state1][state2];
	DP[now][state1][state2] = (state1 == 1 ? A[now] : 0);
	if (state1 == 1)
	{
		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i];
			DP[now][state1][state2] += D(next, 0, 1);
		}
	}
	else if(state1 == 0 && state2 == 1)
	{
		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i];
			if(V[next].size() == 0)
				DP[now][state1][state2] += D(next, 1, 0);
			else
				DP[now][state1][state2] += max(D(next, 0, 0), D(next, 1, 0));
		}
	}
	else if (state1 == 0 && state2 == 0)
	{
		int temp = 0;
		bool flag = false;
		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i];
			if (V[next].size() == 0)
			{
				flag = true;
				temp += D(next, 1, 0);
			}
			else
			{
				int a = D(next, 0, 0);
				int b = D(next, 1, 0);
				if (a <= b)
				{
					flag = true;
					temp += b;
				}
				else
				{
					temp += a;
				}
			}
		}

		if (flag)
			DP[now][state1][state2] += temp;
		else
		{
			int AA = 0;

			for (int i = 0; i < V[now].size(); i++)
			{
				int next = V[now][i];

				{
					int Check = temp;
					int a = D(next, 0, 0);
					int b = D(next, 1, 0);
					Check -= a;
					Check += b;
					AA = max(AA, Check);
				}
			}

			DP[now][state1][state2] += AA;
		}
	}
	return DP[now][state1][state2];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init(DP, -1);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tempV[a].push_back(b);
		tempV[b].push_back(a);
	}

	MakeTree(1, -1);

	cout << max(D(1, 0, 0), D(1, 1, 0));
}
