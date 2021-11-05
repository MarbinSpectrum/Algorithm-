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

int Cube[30];
bool nowAnswer()
{
	for (int i = 0; i <= 6; i++)
		if (Cube[i * 4 + 1] != Cube[i * 4 + 2] || Cube[i * 4 + 1] != Cube[i * 4 + 3] || Cube[i * 4 + 1] != Cube[i * 4 + 4])
			return false;
	return true;
}
void Turn0()
{
	int temp = Cube[3];
	Cube[3] = Cube[4];
	Cube[4] = Cube[2];
	Cube[2] = Cube[1];
	Cube[1] = temp;

	int temp0 = Cube[5];
	int temp1 = Cube[6];
	Cube[5] = Cube[17];
	Cube[6] = Cube[18];
	Cube[17] = Cube[21];
	Cube[18] = Cube[22];
	Cube[21] = Cube[13];
	Cube[22] = Cube[14];
	Cube[13] = temp0;
	Cube[14] = temp1;
}
void Turn1()
{
	int temp = Cube[7];
	Cube[7] = Cube[8];
	Cube[8] = Cube[6];
	Cube[6] = Cube[5];
	Cube[5] = temp;

	int temp0 = Cube[9];
	int temp1 = Cube[10];
	Cube[9] = Cube[19];
	Cube[10] = Cube[17];
	Cube[19] = Cube[4];
	Cube[17] = Cube[3];
	Cube[4] = Cube[14];
	Cube[3] = Cube[16];
	Cube[14] = temp0;
	Cube[16] = temp1;
}
void Turn2()
{
	int temp = Cube[15];
	Cube[15] = Cube[16];
	Cube[16] = Cube[14];
	Cube[14] = Cube[13];
	Cube[13] = temp;

	int temp0 = Cube[11];
	int temp1 = Cube[9];
	Cube[11] = Cube[7];
	Cube[9] = Cube[5];
	Cube[7] = Cube[3];
	Cube[5] = Cube[1];
	Cube[3] = Cube[22];
	Cube[1] = Cube[24];
	Cube[22] = temp0;
	Cube[24] = temp1;
}
void Turn3()
{
	int temp = Cube[11];
	Cube[11] = Cube[12];
	Cube[12] = Cube[10];
	Cube[10] = Cube[9];
	Cube[9] = temp;

	int temp0 = Cube[1];
	int temp1 = Cube[2];
	Cube[1] = Cube[20];
	Cube[2] = Cube[19];
	Cube[20] = Cube[8];
	Cube[19] = Cube[7];
	Cube[8] = Cube[16];
	Cube[7] = Cube[15];
	Cube[16] = temp0;
	Cube[15] = temp1;
}
void Turn4()
{
	int temp = Cube[19];
	Cube[19] = Cube[20];
	Cube[20] = Cube[18];
	Cube[18] = Cube[17];
	Cube[17] = temp;

	int temp0 = Cube[10];
	int temp1 = Cube[12];
	Cube[10] = Cube[23];
	Cube[12] = Cube[21];
	Cube[23] = Cube[2];
	Cube[21] = Cube[4];
	Cube[2] = Cube[6];
	Cube[4] = Cube[8];
	Cube[6] = temp0;
	Cube[8] = temp1;
}
void Turn5()
{
	int temp = Cube[23];
	Cube[23] = Cube[24];
	Cube[24] = Cube[22];
	Cube[22] = Cube[21];
	Cube[21] = temp;

	int temp0 = Cube[12];
	int temp1 = Cube[11];
	Cube[12] = Cube[15];
	Cube[11] = Cube[13];
	Cube[15] = Cube[1];
	Cube[13] = Cube[2];
	Cube[1] = Cube[18];
	Cube[2] = Cube[20];
	Cube[18] = temp0;
	Cube[20] = temp1;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 1; i <= 24; i++)
		cin >> Cube[i];

	Turn0();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn0();
	Turn0();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn0();


	Turn1();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn1();
	Turn1();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn1();

	Turn2();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn2();
	Turn2();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn2();

	Turn3();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn3();
	Turn3();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn3();

	Turn4();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;;
	}
	Turn4();
	Turn4();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn4();

	Turn5();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn5();
	Turn5();
	if (nowAnswer())
	{
		cout << 1 << endl;
		return 0;
	}
	Turn5();

	cout << 0 << endl;
}