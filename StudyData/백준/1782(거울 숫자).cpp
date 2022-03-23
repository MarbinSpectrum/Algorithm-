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

int DP[20];
int Dp(int a, int b = 0)
{
	if (a == 0)
		return 1;
	if (a == 1)
		return 3;
	return Dp(a - 2, 1) * (4 + b);
}
int DP1[20][2];
int baseNum = 0;
int Reverse[10] = { 0,1,5,-1,-1,2,-1,-1,8,-1 };
bool ReverseCC(int a)
{
	int b = a;
	int r = 0;
	while (a > 0)
	{
		int temp = Reverse[a % 10];
		if (temp == -1)
			return false;
		r *= 10;
		r += temp;
		a /= 10;
	}
	return b == r;
}
int CheckReverseNum(int a, int b)
{
	int sum = 0;
	for (int i = a; i <= b; i++)
	{
		if (ReverseCC(i))
		{
			//cout << i << endl;
			sum++;
		}
	}
	return sum;
	//cout << sum << endl;
}

int CheckCan(int center)
{
	int a = baseNum;
	bool odd = ((int)log10(baseNum) + 1) % 2 == 1;

	vector<int> arr;
	int tt = ((int)log10(baseNum) + 1) / 2;
	for (int i = 0; i < tt; i++)
	{
		int t = log10(a) - i;
		int f = a - (a / Pow(10, t + 1)) * Pow(10, t + 1) - a % Pow(10, t);
		f /= Pow(10, t);
		arr.push_back(f);
	}

	int result = 0;

	while (arr.size() < tt)
		arr.push_back(0);

	for (int i = 0; i < tt; i++)
	{
		result *= 10;
		result += arr[i];
	}
	if (odd)
	{
		result *= 10;
		result += center;
	}
	for (int i = tt - 1; i >= 0; i--)
	{
		result *= 10;
		result += Reverse[arr[i]];
	}

	//cout << "!!!";
	//Debug(baseNum, result);
	if (baseNum >= result)
		return 0;
	else
		return 1;
}
int Dp1(int a, int b, int aa, int c = 0)
{
	if (DP1[a][aa] != -1)
		return DP1[a][aa];

	int f = baseNum - (baseNum / Pow(10, b + 1)) * Pow(10, b + 1) - baseNum % Pow(10, b);
	f /= Pow(10, b);
	int bb = b - 1;

	if (a == 0)
	{
		if (aa == 0)
		{
			//cout << CheckCan(0) << endl;
			return CheckCan(0);
		}
	}
	else if (a == 1)
	{
		if (aa == 0)
		{
			if (f <= 0)
				return CheckCan(0) + 2;
			else if (f <= 1)
				return CheckCan(1) + 1;
			else if (f <= 8)
				return CheckCan(8);
		}
	}

	//cout << "!";
	//Debug(b, f);

	if (f <= 0)
	{
		if (aa == 1)
			return DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * (4 + c);
		else
			return DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * c + Dp1(a - 2, bb, 1, 1) * 4;
	}
	else if (f <= 1)
	{
		if (aa == 1)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * (4 + c);
		else
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) + Dp1(a - 2, bb, 1, 1) * 3;
	}
	else if (f <= 2)
	{
		if (aa == 1)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * (4 + c);
		else if (f < 2)
			return  DP1[a][aa] = Dp1(a - 2, bb, 1, 1) * 3;
		else if (f == 2)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) + Dp1(a - 2, bb, 1, 1) * 2;
	}
	else if (f <= 5)
	{
		if (aa == 1)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * (4 + c);
		else if (f < 5)
			return  DP1[a][aa] = Dp1(a - 2, bb, 1, 1) * 2;
		else if (f == 5)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) + Dp1(a - 2, bb, 1, 1);
	}
	else if (f <= 8)
	{
		if (aa == 1)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * (4 + c);
		else if (f < 8)
			return  DP1[a][aa] = Dp1(a - 2, bb, 1, 1);
		else if (f == 8)
			return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1);
	}
	else if (aa == 1)
	{
		return  DP1[a][aa] = Dp1(a - 2, bb, aa, 1) * (4 + c);
	}
	else
		return 0;
}
int F(int a)
{
	memset(DP1, -1, sizeof(DP1));
	DP1[0][1] = 1;
	DP1[1][1] = 3;

	baseNum = a;
	if (a == 0)
		return 1;
	if (a < 0)
		return 0;
	int result = 0;
	int t = log10(a);
	t++;

	for (int i = 1; i <= t; i++)
		result += Dp(i);
	//Debug(result, Dp1(t, t-1, 0));
	result -= Dp1(t, t - 1, 0);

	return result;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int AA, BB;
	std::cin >> AA >> BB;
	//cout << CheckReverseNum(AA,BB) << endl;
	cout << F(BB) - F(AA - 1) << endl;

	//for (int i = 0; i <= 10000; i++)
	//{
	//	for (int j = 0; j <= i; j++)
	//	{
	//		if (F(i) - F(j - 1) != CheckReverseNum(j, i))
	//		{
	//			Debug(j, i);
	//			return 0;
	//		}
	//	}

	//}
}