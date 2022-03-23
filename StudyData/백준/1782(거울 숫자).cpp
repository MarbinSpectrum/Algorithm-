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

int N, K; 

vector<int> A[20];
int B[4][2] = { {1,1},{2,5},{5,2},{8,8} };
int C[3] = { 0,1,8 };
vector<int> Arr;
int ReverseNum[10] = { 0,1,5,-1,-1,2,-1,-1,8,-1 };
int Reverse(int a)
{
	int b = 0;
	while (a > 0)
	{
		b *= 10;
		int ra = ReverseNum[a % 10];
		if (ra == -1)
			return -1;
		b += ra;
		a /= 10;
	}
	return b;
}

	int ans = 0;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int AA, BB;
	std::cin >> AA >> BB;

	for (int i = AA; i <= BB; i++)
	{
		if (i == Reverse(i))
		{
			cout << i << endl;
			ans++;
		}
	}
	cout << ans << endl;
	ans = 0;

	A[1].push_back(0);
	A[1].push_back(1);
	A[1].push_back(8);

	A[2].push_back(11);
	A[2].push_back(25);
	A[2].push_back(52);
	A[2].push_back(88);

	for (int i = 3; i <= 17; i++)
	{
		for (int l = 2; i - l >= 0; l += 2)
		{
			for (int j = 0; j < A[i - l].size(); j++)
			{
				int t = Pow(10, i - 1);
				{
					for (int k = 0; k < 4; k++)
					{
						int a0 = t * B[k][0] + A[i - l][j] * 10 + B[k][1];
						A[i].push_back(a0);

						if (A[i - l][j] != 0)
						{
							int a1 = t * B[k][0] + B[k][1];
							A[i].push_back(a1);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= 17; i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			Arr.push_back(A[i][j]);
		}
	}

	sort(Arr.begin(), Arr.end());

	for (int i = 0; i < Arr.size(); i++)
	{
		if (AA <= Arr[i] && Arr[i] <= BB)
		{
			ans++;
			cout << Arr[i] << endl;
		}
	}

	std::cout << ans << endl;
}