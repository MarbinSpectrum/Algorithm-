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

const int INF = 8999999999999999999;

////////////////////////////////////////////////////////////////////////

using namespace std;

int T;
int ans = 0;
string s;
int idx = 0;

class Trie
{
public:
	Trie* next[26];
	//unordered_map<char, Trie*> next;
	bool EndPos;
	int size;
	Trie()
	{
		EndPos = false;
		size = 0;
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void Add()
	{
		if (idx < s.length())
		{
			char nowC = s[idx];
			int nowIdx = nowC - 'a';

			if (!next[nowIdx])
			{
				next[nowIdx] = new Trie();
				size++;
			}
			if (idx + 1 == s.length())
				next[nowIdx]->EndPos = true;
			idx++;
			next[nowIdx]->Add();
		}
	}
	void Find()
	{
		if (idx < s.length())
		{
			char nowC = s[idx];
			int nowIdx = nowC - 'a';

			if (next[nowIdx]->EndPos)
				ans++;
			else if (idx + 1 < s.length() && next[nowIdx]->size > 1)
				ans++;

			idx++;
			next[nowIdx]->Find();
		}
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cout << fixed;
	cout.precision(2);

	int N;
	while (cin >> N)
	{
		Trie trie;
		vector<string> Arr;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			idx = 0;
			trie.Add();
			Arr.push_back(s);
		}
		float sum = 0;
		for (int i = 0; i < N; i++)
		{
			s = Arr[i];
			ans = 0;
			idx = 0;

			trie.Find();
			sum += ans;
		}
		cout << sum / N << endl;
	}


}