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

int B, E;
int StringToBit(string s)
{
	int v = 0;
	int m = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		v += (int)(s[i] - '0') * m;
		m *= 2;
	}
	return v;
}
string BitToString(int bit)
{
	string v = "";
	for (int i = 0; i < B; i++)
		v += "0";
	int m = B - 1;
	while (bit > 0)
	{
		v[m] = (char)(bit % 2 + '0');
		bit /= 2;
		m--;
	}
	return v;
}
int Offset(int a, int b)
{
	int v = 0;
	while (a > 0 || b > 0)
	{
		int aa = a % 2;
		int bb = b % 2;
		if (aa != bb)
			v++;
		a /= 2;
		b /= 2;
	}
	return v;
}
int Target;
int Arr[101];
int D[1 << 16];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> B >> E;
	{
		string s;
		cin >> s;
		Target = StringToBit(s);
	}
	{
		for (int i = 1; i <= E; i++)
		{
			string s;
			cin >> s;
			Arr[i] = StringToBit(s);
		}
	}

	
	queue<int> Q;
	for (int i = 1; i <= E; i++)
		for (int j = 1; j <= E; j++)
		{
			int a = Arr[i] ^ Arr[j];
			if (D[a] == 0)
			{
				D[a] = 1;
				Q.push(a);
			}
		}

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (int i = 1; i <= E; i++)
		{
			int next = Arr[i] ^ now;
			if (D[next] == 0)
			{
				D[next] = D[now]+1;
				Q.push(next);
			}
		}
	}

	vector<tuple<int, int, string>> Ans;

	for (int j = 0; j < (1 << B); j++)
		if (D[j] != 0)
		{
			tuple<int, int, string> temp = { Offset(Target,j),D[j],BitToString(j) };
			Ans.push_back(temp);
		}

	sort(Ans.begin(), Ans.end());

	cout << get<1>(Ans[0]) << endl;
	cout << get<2>(Ans[0]) << endl;
}