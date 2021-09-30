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
#define float double
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

const long long INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, K;
int d;
int mod = 100000007;
vector<vector<int>> matrix;
vector<vector<int>> Identity;
vector<vector<int>> Mul(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> temp(d);
	for (int i = 0; i < d; i++)
		temp[i].resize(d);
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
		{
			int value = 0;
			for (int k = 0; k < d; k++)
				value += (A[k][i] * B[j][k]) % mod;
			value %= mod;
			temp[j][i] = value;
		}

	return temp;
}
vector<int> Mul(vector<vector<int>>& A, vector<int>& B)
{
	vector<int> temp(d);

	for (int i = 0; i < d; i++)
	{
		int value = 0;
		for (int j = 0; j < d; j++)
		{
			value += (A[i][j] * B[j]) % mod;
			value %= mod;
		}
		temp[i] = value;
	}

	return temp;
}
vector<vector<int>> Power(vector<vector<int>>& A, int B)
{
	if (B == 0)
		return Identity;
	if (B == 1)
		return A;
	vector<vector<int>> v = Power(A, B / 2);
	vector<vector<int>> mul = Mul(v, v);
	if (B & 1)
		return Mul(A, mul);
	else
		return mul;
}


void Sol()
{
	cin >> K >> N;

	if (K == 0)
	{
		cout << Pow(2, N, mod) << endl;
		return;
	}

	matrix.clear();
	Identity.clear();

	K--;
	d = (K + 1) * 2;
	matrix.resize(d);
	for (int i = 0; i < d; i++)
	{
		matrix[i].resize(d);
	}
	for (int i = 0; i < d; i++)
	{
		if (i < K)
		{
			matrix[0][i] = 0;
		}
		else
		{
			matrix[0][i] = 1;
		}
	}
	for (int i = 1; i < d; i++)
	{
		matrix[i][i - 1] = 1;
	}


	Identity.resize(d);
	for (int i = 0; i < d; i++)
		Identity[i].resize(d);
	for (int i = 0; i < d; i++)
		Identity[i][i] = 1;


	vector<vector<int>> p = Power(matrix, N);
	vector<int> Arr(d);
	for (int i = 0; i < d; i++)
	{
		if (i < K)
		{
			Arr[d - 1 - i] = 0;
		}
		else
		{
			Arr[d - 1 - i] = 1;
		}
	}
	vector<int> Result = Mul(p, Arr);
	cout << Result[K+1] << endl;

}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	cin >> T;
	while(T--)
		Sol();
}