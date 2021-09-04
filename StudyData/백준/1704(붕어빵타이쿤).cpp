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

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M;
int MAP[20][20];
int MAP2[20][20];
bool Anstemp[20][20];
int ansCount = INF;
int cnt = 0;
vector<string> ansVec;
string s = "";
void R(int r, int c)
{
	cnt++;
	Anstemp[r][c] = true;
	MAP2[r][c] = !MAP2[r][c];
	for (int i = 0; i < 4; i++)
	{
		int ar = r + Dic[i][0];
		int ac = c + Dic[i][1];
		if (ar < 0 || ac < 0 || ar >= N || ac >= M)
			continue;
		MAP2[ar][ac] = !MAP2[ar][ac];
	}
}

void DFS(int a, int startBit)
{	
	if (a == 0)
	{
		memcpy(MAP2, MAP, sizeof(MAP));
		memset(Anstemp, false, sizeof(Anstemp));

		cnt = 0;

		for (int i = 0; i < M; i++)
			if (startBit & (1 << i))
				R(0, i);

		DFS(a + 1, startBit);
	}
	else if (a < N)
	{
		for (int i = 0; i < M; i++)
			if (MAP2[a - 1][i])
				R(a, i);

		DFS(a + 1, startBit);
	}
	else
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (MAP2[i][j])
					cnt = INF;

		if (cnt != INF)
		{
			s = "";
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					if (Anstemp[i][j])
						s += "1";
					else
						s += "0";

		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];

	for (int bit = 0; bit < (1 << M); bit++)
	{
		DFS(0, bit);

		if (ansCount >= cnt)
		{
			if (ansCount > cnt)
			{
				ansVec.clear();
				ansCount = cnt;
			}
			ansVec.push_back(s);
		}
	}

	sort(ansVec.begin(), ansVec.end());


	if (ansCount == INF)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << ansVec[0][i * M + j] << " ";
			cout << endl;
		}
	}

}