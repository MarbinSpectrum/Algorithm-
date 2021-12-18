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

int MAP[6][6];

vector<pair<int, int>> Arr;
void Rotate()
{
	for (int i = 0; i < Arr.size(); i++)
	{
		int r = Arr[i].first;
		int c = Arr[i].second;
		Arr[i].first = -c;
		Arr[i].second = r;
	}
}
bool Check(int r,int c)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		int ar = Arr[i].first + r;
		int ac = Arr[i].second + c;
		if (0 <= ar && ar < 6 && 0 <= ac && ac < 6)
		{
			if (MAP[ar][ac] == 0)
				return false;
		}
		else
			return false;
	}
	return true;
}
int A[6];
bool ans = false;
void F(int r, int c)
{
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 3,1 });
		A[0] = 2;
		A[2] = 0;
		A[1] = 4;
		A[4] = 1;
		A[3] = 5;
		A[5] = 3;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 4)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 2,0 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 0,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 2,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		A[0] = 4;
		A[4] = 0;
		A[1] = 2;
		A[2] = 1;
		A[3] = 5;
		A[5] = 3;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 2,1 });
		A[0] = 2;
		A[2] = 0;
		A[1] = 3;
		A[3] = 1;
		A[4] = 5;
		A[5] = 4;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 2,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 0,3 });
		A[0] = 4;
		A[4] = 0;
		A[2] = 5;
		A[5] = 2;
		A[1] = 3;
		A[3] = 1;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 2,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		A[0] = 4;
		A[4] = 0;
		A[2] = 5;
		A[5] = 2;
		A[1] = 3;
		A[3] = 1;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 0,3 });
		Arr.push_back({ 0,4 });
		A[0] = 3;
		A[3] = 0;
		A[2] = 5;
		A[5] = 2;
		A[1] = 4;
		A[4] = 1;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		A[0] = 4;
		A[4] = 0;
		A[1] = 3;
		A[3] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 2,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 0,3 });
		Arr.push_back({ 1,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 2,2 });
		Arr.push_back({ 2,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 2,2 });
		Arr.push_back({ 2,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 2,2 });
		Arr.push_back({ 2,3 });
		A[0] = 4;
		A[4] = 0;
		A[1] = 3;
		A[3] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 2,2 });
		Arr.push_back({ 1,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		A[0] = 3;
		A[3] = 0;
		A[1] = 4;
		A[4] = 1;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 2,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		A[1] = 3;
		A[3] = 1;
		A[0] = 4;
		A[4] = 0;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 0,1 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		Arr.push_back({ 1,4 });
		A[1] = 4;
		A[4] = 1;
		A[0] = 2;
		A[2] = 0;
		A[3] = 5;
		A[5] = 3;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 2,2 });
		Arr.push_back({ 1,3 });
		A[1] = 3;
		A[3] = 1;
		A[0] = 4;
		A[4] = 0;
		A[2] = 5;
		A[5] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 2,1 });
		Arr.push_back({ 0,2 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 0,3 });
		A[1] = 5;
		A[5] = 1;
		A[0] = 4;
		A[4] = 0;
		A[2] = 3;
		A[3] = 2;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
	{
		Arr.clear();
		Arr.push_back({ 0,0 });
		Arr.push_back({ 1,0 });
		Arr.push_back({ 1,1 });
		Arr.push_back({ 1,2 });
		Arr.push_back({ 1,3 });
		Arr.push_back({ 2,3 });
		A[1] = 3;
		A[3] = 1;
		A[2] = 4;
		A[4] = 2;
		A[0] = 5;
		A[5] = 0;
		for (int i = 0; i < 4; i++)
		{
			Rotate();

			if (Check(r, c))
				for (int j = 0; j < 6; j++)
					if (MAP[Arr[j].first + r][Arr[j].second + c] == 1)
					{
						cout << MAP[Arr[A[j]].first + r][Arr[A[j]].second + c] << endl;
						ans = true;
						return;
					}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			cin >> MAP[i][j];

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (ans == false)
				F(i, j);
	if (!ans)
		cout << 0 << endl;
}