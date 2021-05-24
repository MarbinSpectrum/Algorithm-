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

	return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M;
map<int, vector<int>> A;
map<int, vector<int>> B;
map<int, bool> Visit;
stack<int> STACK;

void DFS_A(int n)
{
	Visit[n] = true;
	for (int i = 0; i < A[n].size(); i++)
	{
		int next = A[n][i];

		if (Visit[next])
			continue;
		DFS_A(next);
	}
	STACK.push(n);
}

void DFS_B(int n, vector<int>& SCC)
{
	Visit[n] = true;
	SCC.push_back(n);
	for (int i = 0; i < B[n].size(); i++)
	{
		int next = B[n][i];
		if (Visit[next]) continue;
		DFS_B(next, SCC);
	}
}
bool cmp(int a, int b)
{
	return abs(a) < abs(b);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < 0 && b > 0)
		{
			A[abs(a)].push_back(b);
			A[-b].push_back(a);

			B[b].push_back(abs(a));
			B[a].push_back(-b);
		}
		else if (a > 0 && b > 0)
		{
			A[-a].push_back(b);
			A[-b].push_back(a);

			B[b].push_back(-a);
			B[a].push_back(-b);
		}
		else if (a > 0 && b < 0)
		{
			A[-a].push_back(b);
			A[abs(b)].push_back(a);

			B[b].push_back(-a);
			B[a].push_back(abs(b));
		}
		else if (a < 0 && b < 0)
		{
			A[abs(a)].push_back(-abs(b));
			A[abs(b)].push_back(-abs(a));

			B[-abs(b)].push_back(abs(a));
			B[-abs(a)].push_back(abs(b));
		}
	}

	for (map<int, vector<int>>::iterator iter = A.begin(); iter != A.end(); iter++)
	{
		if (!Visit[iter->first])
			DFS_A(iter->first);
	}

	for (map<int, vector<int>>::iterator iter = A.begin(); iter != A.end(); iter++)
		Visit[iter->first] = false;

	while (!STACK.empty())
	{
		vector<int> temp;
		int next = STACK.top();
		STACK.pop();
		if (Visit[next])
			continue;
		DFS_B(next, temp);
		sort(temp.begin(), temp.end(), cmp);
		for (int i = 0; i < temp.size() - 1; i++)
			if (abs(temp[i]) == abs(temp[i + 1]))
			{
				cout << "OTL" << endl;
				return 0;
			}
	}

	cout << "^_^" << endl;
	return 0;
}