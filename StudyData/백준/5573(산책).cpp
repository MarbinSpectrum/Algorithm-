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

int R, C, N;
int A[1000][1000];
int B[1000][1000];

void DFS(int r, int c, int stack)
{
	if (r < 0 || r >= R || c < 0 || c >= C || stack <= 0)
		return;
	B[r][c] += stack;
	if (stack % 2 == 0)
	{
		DFS(r + 1, c, stack / 2);
		DFS(r, c + 1, stack / 2);
	}
	else if(A[r][c] == 0)
	{
		DFS(r, c + 1, stack / 2);
		DFS(r + 1, c, stack / 2 + 1);
	}
	else if (A[r][c] == 1)
	{
		DFS(r, c + 1, stack / 2 + 1);
		DFS(r + 1, c, stack / 2);
	}
}

void Seek(int r, int c)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
	{
		Debug(r + 1, c + 1);
		return;
	}
	if (A[r][c] == 1)
	{
		if (B[r][c] % 2 == 1)
			Seek(r, c + 1);
		else
			Seek(r + 1, c);
	}
	else
	{
		if (B[r][c] % 2 == 1)
			Seek(r + 1, c);
		else
			Seek(r, c + 1);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> A[i][j];

	DFS(0, 0, N);

	B[0][0] = N;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] == 1)
			{
				B[i][j + 1] += B[i][j] / 2;
				B[i][j + 1] += (B[i][j] % 2 == 0 ? 0 : 1);
				B[i + 1][j] += B[i][j] / 2;
			}
			else
			{
				B[i][j + 1] += B[i][j] / 2;
				B[i + 1][j] += B[i][j] / 2;
				B[i + 1][j] += (B[i][j] % 2 == 0 ? 0 : 1);
			}

		}

	Seek(0, 0);

}
