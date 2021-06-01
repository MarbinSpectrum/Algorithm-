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

int NextState(int n)
{
	if (n >= 10)
	{
		int a = 0;
		while (n > 0)
		{
			a += n % 10;
			n /= 10;
		}
		return NextState(a);
	}
	else
		return n;
}

void Sol()
{
	int K, M;
	cin >> K >> M;
	int N = 1;
	int NN = -1;
	map<int, int> MAP;
	int BACK = -1;
	while (MAP.find(NN) == MAP.end())
	{
		NN = NextState(N);
		if (BACK != -1)
		{
			//Debug(BACK, NN);
			MAP[BACK] = NN;
		}
		BACK = NN;
		N *= M;
	}

	vector<int> cycle;
	{
		int Start = BACK;
		while (true)
		{
			cycle.push_back(Start);
			int NEXT = MAP[Start];
			if (NEXT == BACK)
				break;
			Start = NEXT;
		}
	}

	{
		int Start = 1;
		int D = 0;
		int X = 0;
		int Y = 0;

		while (Start != BACK && K--)
		{
			int V = Start;
			if (D == 0)
				Y += V;
			else if (D == 1)
				X += V;
			else if (D == 2)
				Y -= V;
			else if (D == 3)
				X -= V;
			Start = MAP[Start];
			D++;
			D %= 4;
			if (Start == BACK)
				break;
		}

		vector<pair<char, int>> Cycle2;
		{
			int D2 = D;
			map<pair<char, int>, pair<char, int>> MAP2;
			pair<char, int> N2 = { D2 % 2 == 0 ? 'Y' : 'X',D2 < 2 ? cycle[0] : -cycle[0] };
			int t = 0;
			while (true)
			{
				D2++;
				D2 %= 4;
				t++;
				t %= cycle.size();
				pair<char, int> NN2 = { D2 % 2 == 0 ? 'Y' : 'X',D2 < 2 ? cycle[t] : -cycle[t] };
				//cout << N2.first << " " << N2.second << "---" << NN2.first << " " << NN2.second << endl;
				Cycle2.push_back(N2);
				if (MAP2.find(NN2) != MAP2.end())
					break;
				MAP2[N2] = NN2;
				N2 = NN2;
			}
		}

		if (K > 0)
		{
			for (int i = 0; i < Cycle2.size(); i++)
			{
				//Debug(Cycle2[i].first, Cycle2[i].second);
				int v = Cycle2[i].second * (K / Cycle2.size());
				if (i + 1 <= K % Cycle2.size())
					v += Cycle2[i].second;
				if (Cycle2[i].first == 'X')
					X += v;
				else
					Y += v;
			}
		}

		Debug(X, Y);
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
		Sol();
	



}