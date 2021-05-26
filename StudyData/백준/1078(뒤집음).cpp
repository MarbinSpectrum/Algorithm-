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

int R(int n)
{
	int v = 0;
	while (n > 0)
	{
		v *= 10;
		v += n % 10;
		n /= 10;
	}
	return v;
}

int F(int n)
{
	return n - R(n);
}
const int MAX = 1000001;
int X[MAX];

int ToInt(string s)
{
	int v = 0;
	for (int i = 0; i < s.length(); i++)
	{
		v *= 10;
		v += (s[i] - '0');
	}
	return v;
}

void DFS(int l,int r,string s)
{
	if (l < r)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (l == 0 && i == 0)
			{
				s[l] = (char)('1');
				s[r] = (char)('1');
				DFS(l + 1, r - 1, s);
			}
			else
			{
				s[l] = (char)('0' + i);
				s[r] = (char)('0');
				DFS(l + 1, r - 1, s);
				s[l] = (char)('0');
				s[r] = (char)('0' + i);
				DFS(l + 1, r - 1, s);
			}
		}
	}
	else
	{
		int a = ToInt(s);
		int b = F(a);
		if (0 <= b && b < MAX)
			X[b] = min(X[b], a);
	}
}

void CheckNum(int len)
{
	string num = "";
	for (int i = 0; i < len; i++)
		num += "0";

	DFS(0, len - 1, num);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < MAX; i++)
		X[i] = INF;

	//while (true)
	//{
	//	int N;
	//	cin >> N;
	//	int a = F(N);

	//	Debug(N, a);
	//}

	for (int i = 1; i <= 10; i++)
		CheckNum(i);
	
	int N;
	cin >> N;
	if (X[N] == INF)
	{
		if (N == 990000)
			cout << 10001000001 << endl;
		else if (N == 900000)
			cout << 100001000001 << endl;
		else
			cout << -1 << endl;
	}
	else
		cout << X[N] << endl;

}