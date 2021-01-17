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

const int MOD = 20150523;

//자리수
//맨앞의숫자
//자릿수의합을3으로나눴을때나머지
//369보유여부
int DP[100006][10][3][2];
string Number;

//n자리면서 맨앞의숫자숫자가 Num인 경우의수
int Get(int n, int Num)
{
	return (((DP[n][Num][0][0] + DP[n][Num][0][1]) % MOD + DP[n][Num][1][1]) % MOD + DP[n][Num][2][1]) % MOD;
}

//(n자리면서 맨앞의숫자숫자가 Num인 경우의수) + (n자리보다 작은 경우의수)
int Get2(int n, int Num)
{
	int Result = 0;
	int t = n;
	while (t >= 1)
	{
		int count = 9;
		if (t == n)
			count = Num;
		for (int i = 1; i <= count; i++)
		{
			Result += Get(t, i) % MOD;
			Result %= MOD;
		}
		t--;
	}

	return Result % MOD;
}
//Number이랑 같은자리수면서 Number보다큰 경우의수를 모두구함
int Get3(int n, bool flag, int frontNum)
{
	if (Number.length() - n <= 0)
		return 0;
	int count = Number[n] - '0';
	int result = 0;
	for (int i = 9; i > count; i--)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
				if (flag || (j + frontNum) % 3 == 0 || k == 1)
				{
					result += DP[(Number.length() - n)][i][j][k] % MOD;
					result %= MOD;
				}
	//Debug(n, count);
	//cout << result << endl;
	return (result + Get3(n + 1, flag || (count != 0 && count % 3 == 0), frontNum + count)) % MOD;
}

//num에 1을뺀숫자를 만들어줌
string Sub(string num)
{
	for (int i = num.length() - 1; i >= 0; i--)
	{
		int nowNum = num[i] - '0';
		if (nowNum == 0)
			num[i] = '9';
		else
		{
			num[i] = ((nowNum - 1) + '0');
			break;
		}
	}

	string temp = "";
	bool flag = false;
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] == '0' && flag)
			temp += num[i];
		if (num[i] != '0')
		{
			temp += num[i];
			flag = true;
		}
	}
	return temp;

}

bool Num369(int n)
{
	int r = 0;
	while (n > 0)
	{
		int a = n % 10;
		if (a != 0 && a % 3 == 0)
			return true;
		r += a;
		n /= 10;
	}
	return (r % 3 == 0);
}

void Debuging(int a, int b)
{
	int num = 0;
	for (int i = a; i <= b; i++)
		if (Num369(i))
			num++;
	
	cout << "[" << num << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//Debuging(200, 999);

	string num1, num2;
	cin >> num1 >> num2;
	num1 = Sub(num1);

	//DP값을 만들어줌
	for (int i = 0; i <= 9; i++)
		DP[1][i][i % 3][(i != 0 && i % 3 == 0) ? 1 : 0] = 1;
	for (int i = 2; i <= 100005; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				for (int t = 0; t < 3; t++)
					for (int a = 0; a < 2; a++)
					{
						int b = max(a, (int)((j != 0 && j % 3 == 0) ? 1 : 0));
						DP[i][j][(t + j) % 3][b] += DP[i - 1][k][t][a] % MOD;
						DP[i][j][(t + j) % 3][b] %= MOD;
					}

	//(num1 - 1)까지의 경우의수
	Number = num1;
	int A = (Get2(Number.length(), 9) - Get3(0, false, 0) + MOD) % MOD;

	//num2까지의 경우의수
	Number = num2;
	int B = (Get2(Number.length(), 9) - Get3(0, false, 0) + MOD) % MOD;
	//Debug(A, B);
	cout << (B - A + MOD) % MOD << endl;
}
