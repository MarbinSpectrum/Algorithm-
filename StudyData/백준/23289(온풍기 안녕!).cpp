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

int R, C, K, W;
int MAP[30][30];
int HitterMAP[30][30];
bool Wall[30][30][30][30];
vector<pair<pair<int, int>,int>> Hitter;

void Print()
{
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cout << MAP[r][c] << " ";
		}
		cout << endl;
	}
}

bool Availability_Area(int r, int c)
{
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	return false;
}
bool WallCheck(int ar, int ac, int br, int bc)
{
	if (Availability_Area(ar, ac) && Availability_Area(br, bc))
		return Wall[ar][ac][br][bc];
	return false;
}
void Test1()
{
	for (int i = 0; i < Hitter.size(); i++)
	{
		memset(HitterMAP, 0, sizeof(HitterMAP));
		int r, c, dic;
		r = Hitter[i].first.first;
		c = Hitter[i].first.second;
		dic = Hitter[i].second;
		if (dic == 1)
		{
			queue<pair<int, int>> Q;
			if (Availability_Area(r, c + 1))
			{
				HitterMAP[r][c + 1] = 5;
				Q.push({ r,c + 1 });
			}
			while (!Q.empty())
			{
				pair<int, int> temp = Q.front();
				int x = temp.first;
				int y = temp.second;
				int now = HitterMAP[x][y];
				Q.pop();
				if (now == 0)
					continue;

				if (Availability_Area(x - 1, y + 1))
				{
					if (HitterMAP[x - 1][y + 1] == 0)
					{
						if (!WallCheck(x,y,x - 1,y) && !WallCheck(x - 1,y,x - 1,y + 1))
						{
							HitterMAP[x - 1][y + 1] = now - 1;
							Q.push({ x-1,y + 1 });
						}
					}
				}
				if (Availability_Area(x, y + 1))
				{
					if (HitterMAP[x][y + 1] == 0)
					{
						if (!WallCheck(x, y, x, y + 1))
						{
							HitterMAP[x][y + 1] = now - 1;
							Q.push({ x,y + 1 });
						}
					}
				}
				if (Availability_Area(x+1, y + 1))
				{
					if (HitterMAP[x + 1][y + 1] == 0)
					{
						if (!WallCheck(x, y, x + 1, y) && !WallCheck(x + 1, y, x + 1, y + 1))
						{
							HitterMAP[x + 1][y + 1] = now - 1;
							Q.push({ x + 1,y + 1 });
						}
					}
				}
			}
		}
		else if (dic == 2)
		{
			queue<pair<int, int>> Q;
			if (Availability_Area(r, c - 1))
			{
				HitterMAP[r][c - 1] = 5;
				Q.push({ r,c - 1 });
			}
			while (!Q.empty())
			{
				pair<int, int> temp = Q.front();
				int x = temp.first;
				int y = temp.second;
				int now = HitterMAP[x][y];
				Q.pop();
				if (now == 0)
					continue;

				if (Availability_Area(x - 1, y - 1))
				{
					if (HitterMAP[x - 1][y - 1] == 0)
					{
						if (!WallCheck(x, y, x - 1, y) && !WallCheck(x - 1, y, x - 1, y - 1))
						{
							HitterMAP[x - 1][y - 1] = now - 1;
							Q.push({ x - 1,y - 1 });
						}
					}
				}
				if (Availability_Area(x, y - 1))
				{
					if (HitterMAP[x][y - 1] == 0)
					{
						if (!WallCheck(x, y, x, y - 1))
						{
							HitterMAP[x][y - 1] = now - 1;
							Q.push({ x,y - 1 });
						}
					}
				}
				if (Availability_Area(x + 1, y - 1))
				{
					if (HitterMAP[x + 1][y - 1] == 0)
					{
						if (!WallCheck(x, y, x + 1, y) && !WallCheck(x + 1, y, x + 1, y - 1))
						{
							HitterMAP[x + 1][y - 1] = now - 1;
							Q.push({ x + 1,y - 1 });
						}
					}
				}
			}
		}
		else if (dic == 3)
		{
		queue<pair<int, int>> Q;
		if (Availability_Area(r - 1, c))
		{
			HitterMAP[r - 1][c] = 5;
			Q.push({ r - 1,c });
		}
		while (!Q.empty())
		{
			pair<int, int> temp = Q.front();
			int x = temp.first;
			int y = temp.second;
			int now = HitterMAP[x][y];
			Q.pop();
			if (now == 0)
				continue;

			if (Availability_Area(x - 1, y - 1))
			{
				if (HitterMAP[x - 1][y - 1] == 0)
				{
					if (!WallCheck(x, y, x, y - 1) && !WallCheck(x, y - 1, x - 1, y - 1))
					{
						HitterMAP[x - 1][y - 1] = now - 1;
						Q.push({ x - 1,y - 1 });
					}
				}
			}
			if (Availability_Area(x - 1, y))
			{
				if (HitterMAP[x - 1][y] == 0)
				{
					if (!WallCheck(x, y, x - 1, y))
					{
						HitterMAP[x - 1][y] = now - 1;
						Q.push({ x - 1,y });
					}
				}
			}
			if (Availability_Area(x - 1, y + 1))
			{
				if (HitterMAP[x - 1][y + 1] == 0)
				{
					if (!WallCheck(x, y, x, y + 1) && !WallCheck(x, y + 1, x - 1, y + 1))
					{
						HitterMAP[x - 1][y + 1] = now - 1;
						Q.push({ x - 1,y + 1 });
					}
				}
			}
		}
		}
		else if (dic == 4)
		{
		queue<pair<int, int>> Q;
		if (Availability_Area(r + 1, c))
		{
			HitterMAP[r + 1][c] = 5;
			Q.push({ r + 1,c });
		}
		while (!Q.empty())
		{
			pair<int, int> temp = Q.front();
			int x = temp.first;
			int y = temp.second;
			int now = HitterMAP[x][y];
			Q.pop();
			if (now == 0)
				continue;

			if (Availability_Area(x + 1, y - 1))
			{
				if (HitterMAP[x + 1][y - 1] == 0)
				{
					if (!WallCheck(x, y, x, y - 1) && !WallCheck(x, y - 1, x + 1, y - 1))
					{
						HitterMAP[x + 1][y - 1] = now - 1;
						Q.push({ x + 1,y - 1 });
					}
				}
			}
			if (Availability_Area(x + 1, y))
			{
				if (HitterMAP[x + 1][y] == 0)
				{
					if (!WallCheck(x, y, x + 1, y))
					{
						HitterMAP[x + 1][y] = now - 1;
						Q.push({ x + 1,y });
					}
				}
			}
			if (Availability_Area(x + 1, y + 1))
			{
				if (HitterMAP[x + 1][y + 1] == 0)
				{
					if (!WallCheck(x, y, x, y + 1) && !WallCheck(x, y + 1, x + 1, y + 1))
					{
						HitterMAP[x + 1][y + 1] = now - 1;
						Q.push({ x + 1,y + 1 });
					}
				}
			}
		}
		}

		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				MAP[r][c] += HitterMAP[r][c];
			}
		}
	}
}

int ChangeMAP1[30][30];
int ChangeMAP2[30][30];
void Test2()
{
	memset(ChangeMAP1, 0, sizeof(ChangeMAP1));
	memset(ChangeMAP2, 0, sizeof(ChangeMAP2));
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (MAP[r][c] > 0)
			{
				int a = MAP[r][c] / 4;
				if (Availability_Area(r + 1, c) && !Wall[r][c][r + 1][c] && MAP[r][c] > MAP[r + 1][c])
				{
					int a = (MAP[r][c] - MAP[r + 1][c])/ 4;
					ChangeMAP1[r][c] -= a;
					ChangeMAP2[r + 1][c] += a;

				}
				if (Availability_Area(r - 1, c) && !Wall[r][c][r - 1][c] && MAP[r][c] > MAP[r - 1][c])
				{
					int a = (MAP[r][c] - MAP[r - 1][c]) / 4;
					ChangeMAP1[r][c] -= a;
					ChangeMAP2[r - 1][c] += a;
				}
				if (Availability_Area(r, c + 1) && !Wall[r][c][r][c + 1] && MAP[r][c] > MAP[r][c + 1])
				{
					int a = (MAP[r][c] - MAP[r][c + 1]) / 4;
					ChangeMAP1[r][c] -= a;
					ChangeMAP2[r][c + 1] += a;
				}
				if (Availability_Area(r, c - 1) && !Wall[r][c][r][c - 1] && MAP[r][c] > MAP[r][c - 1])
				{
					int a = (MAP[r][c] - MAP[r][c - 1]) / 4;
					ChangeMAP1[r][c] -= a;
					ChangeMAP2[r][c - 1] += a;
				}
			}
		}
	}
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			MAP[r][c] += ChangeMAP1[r][c];
			MAP[r][c] += ChangeMAP2[r][c];
		}
	}
}
void Test3()
{
	for (int r = 1; r < R; r++)
	{
		if (MAP[r][0] > 0)
		{
			MAP[r][0]--;
		}
	}
	for (int r = 0; r < R-1; r++)
	{
		if (MAP[r][C - 1] > 0)
		{
			MAP[r][C - 1]--;
		}
	}
	for (int c = 0; c < C - 1; c++)
	{
		if (MAP[0][c] > 0)
		{
			MAP[0][c]--;
		}
	}
	for (int c = 1; c < C; c++)
	{
		if (MAP[R - 1][c] > 0)
		{
			MAP[R - 1][c]--;
		}
	}
}

int chocolate = 0;
void Test4()
{
	chocolate++;
}

vector<pair<int, int>> TestArea;
bool Test5()
{
	for (int i = 0; i < TestArea.size(); i++)
	{
		int r = TestArea[i].first;
		int c = TestArea[i].second;
		if (MAP[r][c] < K)
		{
			return true;
		}
	}
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> R >> C >> K;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			int a;
			std::cin >> a;

			if (1 <= a && a <= 4)
				Hitter.push_back({ { r,c }, a });
			else if (a == 5)
				TestArea.push_back({ r,c });
		}
	}
	std::cin >> W;
	for (int i = 0; i < W; i++)
	{
		int x, y, t;
		std::cin >> x >> y >> t;
		x--;
		y--;
		if (t == 0)
		{
			Wall[x][y][x - 1][y] = true;
			Wall[x - 1][y][x][y] = true;
		}
		else if (t == 1)
		{
			Wall[x][y][x][y + 1] = true;
			Wall[x][y + 1][x][y] = true;
		}
	}

	do
	{
		Test1();
		Test2();
		Test3();
		Test4();
		if (chocolate > 100)
		{
			cout << 101 << endl;
			return 0;
		}
	} while (Test5());
	//Print();
	cout << chocolate << endl;
}