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

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int N, M;
int Flag[7][100001];
int A[100001];
int B[100001];

const int MOD = 1000000007;

bool AllRemove(int n)
{
	for (int i = 1; i < 7; i++)
		if (Flag[i][n])
			return false;
	return true;
}
vector<int> ans;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		std::cin >> A[i];
		int a = A[i] % 7;
		Flag[a][0] = A[i];
	}
	for (int i = 0; i < M; i++)
	{
		std::cin >> B[i];
	}

	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		//for (int j = 1; j <= 7; j++)
		//{
		//	cout << Flag[j % 7][i] << " ";
		//}
		//cout << endl;
		for (int j = 0; j < 7; j++)
		{
			int a = (Flag[j][i] + B[i]) % 7;
			if (Flag[j][i] == 0)
				Flag[j][i + 1] = 0;
			else if (a == 0)
				Flag[j][i + 1] = 0;
			else
				Flag[j][i + 1] = a;
		}

		if (AllRemove(i + 1))
		{
			for (int j = 0; j < 7; j++)
			{
				Flag[j][i + 1] = Flag[j][i];
			}
			continue;
		}
		sum = (sum + B[i]) % MOD;
	}
	//for (int j = 1; j <= 7; j++)
	//{
	//	cout << Flag[j % 7][M] << " ";
	//}
	//cout << endl;
	//cout << sum << endl;
	for (int i = 0; i < N; i++)
	{
		if (Flag[A[i] % 7][M])
		{
			int a = (A[i] + sum) % MOD;
			ans.push_back(a);
		}
	}

	std::cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i] << " ";
	}
}