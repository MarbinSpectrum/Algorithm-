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

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int A, B, N;
int Sum[1000005][3];
int S(int a, int b, int c)
{
	return ((b - 1 >= 0) ? Sum[b - 1][c] : 0) - ((a - 1 >= 0) ? Sum[a - 1][c] : 0);
}
int Arr[100005];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> A >> B >> N;
	N--;

	for (int i = 0; i < N; i++)
	{
		int a;
		std::cin >> a;
		Arr.push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		int add = (i % 2 == 0) ? Arr[i] : 0;
		if (i - 1 >= 0)
			Sum[i][0] = Sum[i - 1][0] + add;
		else
			Sum[i][0] = add;
	}
	for (int i = 0; i < N; i++)
	{
		int add = (i % 2 == 1) ? Arr[i] : 0;
		if (i - 1 >= 0)
			Sum[i][1] = Sum[i - 1][1] + add;
		else
			Sum[i][1] = add;
	}

	int ans = 0;

	vector<pair<int, int>> Flag;
	{
		int a = S(0, N, 1);
		int b = S(0, N, 0);
		int MinV = max(Arr[0], A - (a - b));
		int MaxV = min(INF, B - (a - b));

		int cnt = MaxV - MinV + 1;
		if (cnt > 0)
		{
			ans += cnt;
			Flag.push_back({ MaxV ,MinV });
		}
	}

	for (int i = 0; i < N; i++)
	{
		int a = S(0, i+1, 0) + S(i+1, N, 1);
		int b = S(0, i+1, 1) + S(i+1, N, 0);

		if (i % 2 == 1)
		{
			int MinV = max(i + 1 < N ? Arr[i + 1] : 1, A - (a - b));
			int MaxV = min(Arr[i], B - (a - b));

			int cnt = MaxV - MinV + 1;
			if (cnt > 0)
			{
				ans += cnt;
				Flag.push_back({ MaxV ,MinV });
			}
		}
		else
		{
			int MinV = max(i + 1 < N ? Arr[i + 1] : 1, (a - b) - B);
			int MaxV = min(Arr[i], (a - b) - A);

			int cnt = MaxV - MinV + 1;
			if (cnt > 0)
			{
				ans += cnt;
				Flag.push_back({ MaxV ,MinV });
			}
		}
	}
	for (int i = 0; i + 1 < Flag.size(); i++)
	{
		int a = Flag[i].second;
		int b = Flag[i+1].first;

		if (a == b)
			ans--;
	}

	cout << ans << endl;

}

