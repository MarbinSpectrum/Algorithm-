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

int N, M;
int Map[100][100];
bool BackVisit[100][100];
int Visit[100][100];
int ans = 0;
bool isEdge(int r, int c)
{
	return r == 0 || c == 0 || r == N - 1 || c == M - 1;
}
void Save()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			BackVisit[i][j] = Visit[i][j];
}
void Load()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			Visit[i][j] = BackVisit[i][j];
}
int Color(int r, int c)
{
	if (isEdge(r, c))
	{
		return 0;
	}

	for (int h = 9; h >= 0; h--)
	{
		bool hasWall = false;
		bool escape = false;
		Save();
		queue<pair<int, int>> Q;
		if (h <= Map[r][c])
			continue;
		if (Visit[r][c] == 2)
			continue;
		Q.push({ r,c });
		Visit[r][c] = 2;

		while (!Q.empty())
		{
			pair<int, int> now = Q.front();
			Q.pop();
			if (isEdge(now.first, now.second))
			{
				//Debug(r, c);
				//Debug(h, "?");
				escape = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				pair<int, int> next = { now.first + Dic[i][0],now.second + Dic[i][1] };
				if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)
					continue;
				if (h <= Map[next.first][next.second])
					continue;
				if (Visit[next.first][next.second] == 2)
					continue;
				Q.push({ next.first,next.second });
				Visit[next.first][next.second] = 2;
			}
		}


		if (escape == false)
		{
			int sum = 0;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					if (Visit[i][j] == 2)
					{
						Visit[i][j] = 1;
						sum += h - Map[i][j];
					}

			//Debug(r,c);
			//Debug(h, sum);

			return sum;
		}
		else
			Load();
	}
	
	return 0;
		
}
void Check()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Visit[i][j] == 0)
			{
				cnt += Color(i, j);
			}
	ans = max(ans, cnt);
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			char a;
			std::cin >> a;
			Map[i][j] = a - '0';
		}

	Check();
	std::cout << ans << endl;
}