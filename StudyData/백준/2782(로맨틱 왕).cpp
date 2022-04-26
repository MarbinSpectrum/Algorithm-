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


int R, C, Time;
char MAP[51][51];
int Dist[51][51][51][51];
int TreeNum = 0;
pair<int, int> TreePos[51];
pair<int, int> King;
pair<int, int> Queen;
int DP[20][1 << 18];

int CountBit(int n)
{
	int i;
	for (i = 0; n != 0; i++)
	{
		n &= (n - 1);
	}
	return i;
}
int Dp(int now, int bit)
{
	int& ret = DP[now][bit];
	if (ret != -1)
		return ret;
	ret = INF;

	int nowGift = CountBit(bit);
	int nextBit = bit - (1 << (now - 1));

	bool flag = true;
	for (int i = 1; i < TreeNum; i++)
	{
		if (i == now)
			continue;

		if (bit & (1 << (i - 1)))
		{		
			pair<int, int> start = TreePos[i];
			pair<int, int> end = TreePos[now];
			int dis = Dist[start.first][start.second][end.first][end.second];
			if (dis == -1)
				continue;
			flag = false;
			ret = min(ret, Dp(i, nextBit) + dis * nowGift);
		}
	}

	if (flag && bit == (1 << (now - 1)))
	{
		int dis = Dist[King.first][King.second][TreePos[now].first][TreePos[now].second];
		if(dis != -1)
			ret = dis;
	}

	return ret;
}
int Ans()
{
	int ans = 0;
	for (int i = 1; i < TreeNum; i++)
	{
		for (int j = 0; j < (1 << (TreeNum - 1)); j++)
		{
			if (j & (1 << (i - 1)))
			{
				pair<int, int> start = TreePos[i];
				pair<int, int> end = Queen;
				int nowGift = CountBit(j);
				int a = Dp(i, j);
				int b = Dist[start.first][start.second][end.first][end.second];
				if (b == -1)
					continue;
				b *= (nowGift + 1);
				//Debug(i, j);
				//Debug(a, b);
				//cout << endl;
				if (a + b <= Time)
				{
					ans = max(ans, nowGift);
				}
			}
		}
	}
	return ans;
}

void Input()
{
	std::cin >> R >> C >> Time;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			std::cin >> MAP[r][c];
		}
	}
}
void Sol()
{
	TreeNum = 1;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (MAP[r][c] == 'G')
			{
				TreePos[TreeNum++] = { r,c };
			}
			else if (MAP[r][c] == 'K')
			{
				King = { r,c };
			}
			else if (MAP[r][c] == 'Q')
			{
				Queen = { r,c };
			}
		}
	}

	for (int r = 0; r < 51; r++)
		for (int c = 0; c < 51; c++)
			for (int i = 0; i < 51; i++)
				for (int j = 0; j < 51; j++)
					Dist[r][c][i][j] = -1;

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (MAP[r][c] == '#')
				continue;
			queue<pair<int, int>> Q;
			Q.push({ r,c });
			Dist[r][c][r][c] = 0;

			while (!Q.empty())
			{
				pair<int, int> Now = Q.front();
				int Cost = Dist[r][c][Now.first][Now.second];

				Q.pop();	

				for (int i = 0; i < 4; i++)
				{
					pair<int, int> Next = { Now.first + Dic[i][0],Now.second + Dic[i][1] };

					if (Next.first < 0 || Next.first >= R || Next.second < 0 || Next.second >= C)
						continue;
					if (MAP[Next.first][Next.second] == '#')
						continue;
					if(Dist[r][c][Next.first][Next.second] == -1)
					{
						Dist[r][c][Next.first][Next.second] = Cost + 1;
						Q.push(Next);
					}
				}
			}
		}
	}
	
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1 << 18); j++)
			DP[i][j] = -1;

	std::cout << Ans() << endl;

}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		Input();
		Sol();
	}
}

