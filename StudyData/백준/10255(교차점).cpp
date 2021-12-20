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

#define x first
#define y second
typedef pair<float, float> Pos;

int CCW(Pos& p1, Pos& p2, Pos& p3)
{
	float op = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	op -= (p1.x * p3.y + p2.x * p1.y + p3.x * p2.y);

	if (op > 0) 
		return 1;
	else if (op == 0) 
		return 0;
	else 
		return -1;
}

bool CheckIntersect(Pos p1, Pos p2,Pos p3,Pos p4)
{
	int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if (line1_2 == 0 && line2_1 == 0)
	{
		if (p1 > p2) 
			swap(p1, p2);
		if (p3 > p4) 
			swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}
	return line1_2 <= 0 && line2_1 <= 0;
}


void Sol()
{
	Pos minP, maxP;
	Pos a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> minP.x >> maxP.y >> maxP.x >> minP.y;
	int minX = min(minP.x, maxP.x);
	int maxX = max(minP.x, maxP.x);
	int minY = min(minP.y, maxP.y);
	int maxY = max(minP.y, maxP.y);
	minP.x = minX;
	maxP.x = maxX;
	minP.y = minY;
	maxP.y = maxY;
	if (minP.x <= a.x && a.x <= maxP.x && minP.y <= a.y && a.y <= maxP.y &&
		minP.x <= b.x && b.x <= maxP.x && minP.y <= b.y && b.y <= maxP.y)
	{
		cout << "T" << endl;
	}
	else if (CheckIntersect(minP, { minP.x,maxP.y }, a, b) ||
		CheckIntersect(minP, { maxP.x,minP.y }, a, b) ||
		CheckIntersect({ minP.x,maxP.y }, maxP, a, b) ||
		CheckIntersect({ maxP.x,minP.y }, maxP, a, b))
	{
		cout << "T" << endl;
	}
	else
	{
		cout << "F" << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		Sol();
	}
}