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

int N, M;
bool Visit[100001];
vector<int> A[100001];
vector<int> B[100001];
stack<int> STACK;
vector<vector<int>> Group;

int P[100001];
int FindP(int a)
{
	if (P[a] == a)
		return a;
	else
	{
		int emp = FindP(P[a]);
		P[a] = emp;
		return emp;
	}
}

void Union(int a, int b)
{
	P[FindP(b)] = P[FindP(a)];
}

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
		if (Visit[next])
			continue;
		DFS_B(next, SCC);
	}
}

void DFS(int n)
{
	n = FindP(n);
	Visit[n] = true;
	for (int i = 0; i < A[n].size(); i++)
	{
		int next = A[n][i];
		next = FindP(next);
		if (Visit[next])
			continue;
		DFS_A(next);
	}
}

bool ComeNode[100001];

void Sol()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		A[i].clear();
		B[i].clear();
	}
	memset(Visit, false, sizeof(Visit));
	memset(ComeNode, false, sizeof(Visit));
	Group.clear();

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		B[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
		P[i] = i;

	for (int i = 0; i < N; i++)
		if (!Visit[i])
			DFS_A(i);

	memset(Visit, false, sizeof(Visit));

	while (!STACK.empty())
	{
		vector<int> temp;
		int next = STACK.top();
		STACK.pop();
		if (Visit[next])
			continue;
		DFS_B(next, temp);
		Group.push_back(temp);
	}

	for (int i = 0; i < Group.size(); i++)
		for (int j = 1; j < Group[i].size(); j++)
			Union(Group[i][0], Group[i][j]);

	int check = -1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < A[i].size(); j++)
		{
			int a = FindP(i);
			int b = FindP(A[i][j]);
			if (a != b)
				ComeNode[b] = true;
		}

	memset(Visit, false, sizeof(Visit));

	for (int i = 0; i < N; i++)
	{
		int a = FindP(i);
		if (!Visit[a] && !ComeNode[a])
		{
			if (check == -1)
			{
				check = a;
				DFS(a);
			}
			else
			{
				cout << "Confused" << endl;
				return;
			}
		}
	}

	if (check == -1)
	{
		cout << "Confused" << endl;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		int a = FindP(i);
		if (check == a)
			cout << i << endl;
	}

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		Sol();
		cout << endl;
	}
}