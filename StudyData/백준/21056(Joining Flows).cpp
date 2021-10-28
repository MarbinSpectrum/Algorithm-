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

////////////////////////////////////////////////////////////////////////

int k, r;
vector<tuple<int, int, int>> Arr0;
vector<tuple<int, int, int>> Arr1;
pair<int, int> minMax;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> k;
	while (k--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Arr0.push_back({ a,b,c });
		Arr1.push_back({ -a,b,c });
		minMax.first += b;
		minMax.second += c;
	}
	sort(Arr0.begin(), Arr0.end());
	sort(Arr1.begin(), Arr1.end());
	for (int i = 0; i < Arr1.size(); i++)
	{
		Arr1[i] = {
		-get<0>(Arr1[i]),
		get<1>(Arr1[i]),
		get<2>(Arr1[i]) };
	}
	cin >> r;
	while (r--)
	{
		int a, b;
		cin >> a >> b;
		if (minMax.first > b || minMax.second < b)
		{
			cout << "No" << endl;
			continue;
		}
		a *= b;
		int minV = 0;
		int tempB = b;
		for (int i = 0; i < Arr0.size(); i++)
		{
			minV += get<0>(Arr0[i]) * get<1>(Arr0[i]);
			tempB -= get<1>(Arr0[i]);
		}
		for (int i = 0; i < Arr0.size(); i++)
		{
			int va = min(tempB, get<2>(Arr0[i]) - get<1>(Arr0[i]));
			minV += get<0>(Arr0[i]) * va;
			tempB -= va;
		}

		int maxV = 0;
		tempB = b;
		for (int i = 0; i < Arr1.size(); i++)
		{
			maxV += get<0>(Arr1[i]) * get<1>(Arr1[i]);
			tempB -= get<1>(Arr1[i]);
		}
		for (int i = 0; i < Arr1.size(); i++)
		{
			int va = min(tempB, get<2>(Arr1[i]) - get<1>(Arr1[i]));
			maxV += get<0>(Arr1[i]) * va;
			tempB -= va;
		}
		if (minV <= a && a <= maxV)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

}