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

int N;
char MAP[25][25][3];
bool Visit[25][25][20000];
pair<int, int> Start;
int checkBit[9];
int Check[3][3];
bool isDraw(int bit, int r, int c)
{
	for (int i = 0; i < 9; i++)
		checkBit[i] = 0;

	int idx = 0;
	while (bit > 0)
	{
		checkBit[idx++] = bit % 3;
		bit /= 3;
	}
	int ar = (MAP[r][c][1] - '0') - 1;
	int ac = (MAP[r][c][2] - '0') - 1;
	return checkBit[ar * 3 + ac] != 0;
}
int Draw(int bit, int r, int c, int mo)
{
	for (int i = 0; i < 9; i++)
		checkBit[i] = 0;

	int idx = 0;
	while (bit > 0)
	{
		checkBit[idx++] = bit % 3;
		bit /= 3;
	}

	int ar = (MAP[r][c][1] - '0') - 1;
	int ac = (MAP[r][c][2] - '0') - 1;
	checkBit[ar * 3 + ac] = mo;
	int res = 0;
	for (int i = 0; i < 9; i++)
		res += pow(3, i) * checkBit[i];


	return res;
}

bool ansCheck(int bit)
{
	for (int i = 0; i < 9; i++)
		checkBit[i] = 0;

	int idx = 0;
	while (bit > 0)
	{
		checkBit[idx++] = bit % 3;
		bit /= 3;
	}
	for (int i = 0; i < 9; i++)
		Check[i / 3][i % 3] = checkBit[i];

	for (int i = 0; i < 3; i++)
		if (Check[i][0] == 2 && Check[i][1] == 1 && Check[i][2] == 1)
			return 1;
	for (int i = 0; i < 3; i++)
		if (Check[i][0] == 1 && Check[i][1] == 1 && Check[i][2] == 2)
			return 1;
	for (int i = 0; i < 3; i++)
		if (Check[0][i] == 2 && Check[1][i] == 1 && Check[2][i] == 1)
			return 1;
	for (int i = 0; i < 3; i++)
		if (Check[0][i] == 1 && Check[1][i] == 1 && Check[2][i] == 2)
			return 1;
	if (Check[0][0] == 1 && Check[1][1] == 1 && Check[2][2] == 2)
		return 1;
	if (Check[0][0] == 2 && Check[1][1] == 1 && Check[2][2] == 1)
		return 1;
	if (Check[0][2] == 1 && Check[1][1] == 1 && Check[2][0] == 2)
		return 1;
	if (Check[0][2] == 2 && Check[1][1] == 1 && Check[2][0] == 1)
		return 1;


	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < 3; k++)
			{
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 'B')
					Start = { i,j };
			}

	queue<tuple<int, int, int>> Q;
	Q.push({ Start.first,Start.second,0 });
	Visit[Start.first][Start.second][0] = true;
	while (!Q.empty())
	{
		tuple<int, int, int> qf = Q.front();
		Q.pop();
		int r = get<0>(qf);
		int c = get<1>(qf);
		int now = get<2>(qf);

		for (int i = 0; i < 4; i++)
		{
			int ar = r + Dic[i][0];
			int ac = c + Dic[i][1];
			if (ar < 0 || ac < 0 || ar >= N || ac >= N)
				continue;
			if (MAP[ar][ac][0] == '#')
				continue;

			if ((MAP[ar][ac][0] == '.' || MAP[ar][ac][0] == 'B') && !Visit[ar][ac][now])
			{
				Visit[ar][ac][now] = true;
				if (!ansCheck(now))
				Q.push({ ar,ac,now });
			}
			else if (MAP[ar][ac][0] == 'O')
			{
				if (!isDraw(now, ar, ac))
				{
					int next = Draw(now, ar, ac, 1);
					if (!Visit[ar][ac][next])
					{
						Visit[ar][ac][next] = true;
						if (!ansCheck(next))
						Q.push({ ar,ac,next });
					}
				}
				else if (!Visit[ar][ac][now])
				{
					Visit[ar][ac][now] = true;
					if (!ansCheck(now))
					Q.push({ ar,ac,now });
				}
			}
			else if (MAP[ar][ac][0] == 'M')
			{
				if (!isDraw(now, ar, ac))
				{
					int next = Draw(now, ar, ac, 2);
					if (!Visit[ar][ac][next])
					{
						Visit[ar][ac][next] = true;
						if (!ansCheck(next))
						Q.push({ ar,ac,next });
					}
				}
				else if (!Visit[ar][ac][now])
				{
					Visit[ar][ac][now] = true;
					if (!ansCheck(now))
					Q.push({ ar,ac,now });
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k < 20000; k++)
	{
		for (int i = 0; i < N * N; i++)
		{
			if (Visit[i / N][i % N][k])
			{
				int a = ansCheck(k);
				ans += a;
				break;
			}
		}
	}
	cout << ans << endl;


}