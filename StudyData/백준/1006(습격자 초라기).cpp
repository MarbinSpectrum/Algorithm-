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
#include <unordered_map> 
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

int Mul(int x, int y, int mod)
{
	return x * y % mod;
}

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}
int Ceil(int a, int b)
{
	return (a % b == 0) ? (a / b) : (a / b + 1);
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
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		b = b >> 1;
		a = (a * a);
	}
	return res;
}
int Pow(int a, int b, int p)
{
	int res = 1;
	a = a % p;
	while (b > 0)
	{
		if (b & 1)
			res = Mul(res, a, p);
		b = b >> 1;
		a = Mul(a, a, p);
	}
	return res;
}

vector<string> split(string input, vector<char> check)
{
	vector<string> answer;
	input += check[0];
	string temp = "";
	for (int i = 0; i < input.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < check.size(); j++)
			if (input[i] == check[j])
			{
				flag = true;
				break;
			}

		if (flag && temp.size() == 0)
			continue;
		if (flag && temp.size() > 0)
		{
			answer.push_back(temp);
			temp = "";
		}
		else
		{
			temp += input[i];
		}
	}
	return answer;
}

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

////////////////////////////////////////////////////////////////////////

int T;
int N, W;
int DP[4][3][10001];
int A[2][10001];
vector<int> AnsList;
int Dp(int a, int b, int c)
{
	if (c == N)
		return 0;
	if (DP[a][b][c] != -1)
		return DP[a][b][c];
	int &ref = DP[a][b][c];
	ref = INF;
	//XX
	if (b == 0)
	{
		if (c == N - 1)
		{
			if (a == 0)
			{
				if(A[0][c] + A[1][c] <= W)
					ref = min(ref, Dp(a, 0, c + 1) + 1);
				else
					ref = min(ref, Dp(a, 0, c + 1) + 2);
			}
			else if (a == 3)
			{
				ref = min(ref, Dp(a, 0, c + 1));
			}
			else 
			{
				ref = min(ref, Dp(a, 0, c + 1) + 1);
			}
		}
		else
		{
			if (A[0][c] + A[1][c] <= W)
			{
				ref = min(ref, Dp(a, 0, c + 1) + 1);
			}
			if (A[0][c] + A[0][c + 1] <= W)
			{
				if(c + 1 == N - 1 && a != 1 && a != 3)
					ref = min(ref, Dp(a, 1, c + 1) + 2);
				else if (c + 1 != N - 1)
					ref = min(ref, Dp(a, 1, c + 1) + 2);
			}
			if (A[1][c] + A[1][c + 1] <= W)
			{
				if (c + 1 == N - 1 && a != 2 && a != 3)
					ref = min(ref, Dp(a, 2, c + 1) + 2);
				else if (c + 1 != N - 1)
					ref = min(ref, Dp(a, 2, c + 1) + 2);
			}
			if (A[0][c] + A[0][c + 1] <= W && A[1][c] + A[1][c + 1] <= W)
			{
				if (a == 0 && c + 2 <= N)
					ref = min(ref, Dp(a, 0, c + 2) + 2);
				else if (a != 0 && c + 2 <= N - 1)
					ref = min(ref, Dp(a, 0, c + 2) + 2);
			}
			if(A[0][c] <= W && A[1][c] <= W)
				ref = min(ref, Dp(a, 0, c + 1) + 2);
		}
	}
	//OX
	else if (b == 1)
	{
		if (c == N - 1)
		{
			if (a == 2)
			{
				ref = min(ref, Dp(a, 0, c + 1));
			}
			else
			{
				ref = min(ref, Dp(a, 0, c + 1) + 1);
			}
		}
		else
		{
			if (A[1][c] <= W)
			{
				ref = min(ref, Dp(a, 0, c + 1) + 1);
			}
			if (A[1][c] + A[1][c + 1] <= W)
			{
				if (c + 1 == N - 1 && a != 2 && a != 3)
					ref = min(ref, Dp(a, 2, c + 1) + 1);
				else if (c + 1 != N - 1)
					ref = min(ref, Dp(a, 2, c + 1) + 1);
			}
		}
	}
	//XO
	else if (b == 2)
	{
		if (c == N - 1)
		{
			if (a == 1)
			{
				ref = min(ref, Dp(a, 0, c + 1));
			}
			else
			{
				ref = min(ref, Dp(a, 0, c + 1) + 1);
			}
		}
		else
		{
			if (A[0][c] <= W)
			{
				ref = min(ref, Dp(a, 0, c + 1) + 1);
			}
			if (A[0][c] + A[0][c + 1] <= W)
			{
				if (c + 1 == N - 1 && a != 1 && a != 3)
					ref = min(ref, Dp(a, 1, c + 1) + 1);
				else if (c + 1 != N - 1)
					ref = min(ref, Dp(a, 1, c + 1) + 1);
			}
		}
	}

	return ref;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;
	while (T--)
	{
		memset(DP, -1, sizeof(DP));
		std::cin >> N >> W;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				std::cin >> A[i][j];
			}
		}
		int ans = INF;
		ans = min(ans, Dp(0, 0, 0));

		if (A[0][0] + A[0][N - 1] <= W)
		{
			ans = min(ans, Dp(1, 1, 0) + 1);
		}
		if (A[1][0] + A[1][N - 1] <= W)
		{
			ans = min(ans, Dp(2, 2, 0) + 1);
		}
		if (A[0][0] + A[0][N - 1] <= W && A[1][0] + A[1][N - 1] <= W)
		{
			ans = min(ans, Dp(3, 0, 1) + 2);
		}
		AnsList.push_back(ans);
	}
	for (int i = 0; i < AnsList.size(); i++)
		cout << AnsList[i] << endl;
}