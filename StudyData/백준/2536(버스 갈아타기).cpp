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
//#define int long long
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

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

////////////////////////////////////////////////////////////////////////

int N, M, K;

struct SE
{
	int startX, startY, endX, endY;

	int GetXY()
	{
		if (startX == endX)
			return -1;
		if (startY == endY)
			return +1;
		return 0;
	}
	int maxX()
	{
		return max(startX, endX);
	}
	int maxY()
	{
		return max(startY, endY);
	}
	int minX()
	{
		return min(startX, endX);
	}
	int minY()
	{
		return min(startY, endY);
	}
};
vector<SE> bus;
vector<int> V[5001];
int Visit[5001];
int busType[5001];

bool Cross(int a, int b)
{
	int axy = bus[a].GetXY();
	int bxy = bus[b].GetXY();
	if (axy == bxy)
	{
		if (axy == -1)
		{
			return ((bus[a].startX == bus[b].startX && bus[a].minY() <= bus[b].minY() && bus[b].minY() <= bus[a].maxY()) ||
				(bus[a].startX == bus[b].startX && bus[b].minY() <= bus[a].minY() && bus[a].minY() <= bus[b].maxY()));
		}
		else if (axy == +1)
		{
			return ((bus[a].startY == bus[b].startY && bus[a].minX() <= bus[b].minX() && bus[b].minX() <= bus[a].maxX()) ||
				(bus[a].startY == bus[b].startY && bus[b].minX() <= bus[a].minX() && bus[a].minX() <= bus[b].maxX()));
		}
	}
	else
	{
		if (axy == -1 && bxy == +1)
		{
			pair<int, int> crossPoint = { bus[a].startX,bus[b].startY };
			return bus[a].minY() <= crossPoint.second && crossPoint.second <= bus[a].maxY()
				&& bus[b].minX() <= crossPoint.first && crossPoint.first <= bus[b].maxX();
		}
		else
		{
			pair<int, int> crossPoint = { bus[b].startX,bus[a].startY };
			return bus[b].minY() <= crossPoint.second && crossPoint.second <= bus[b].maxY()
				&& bus[a].minX() <= crossPoint.first && crossPoint.first <= bus[a].maxX();
		}
	}
}

bool Cross(pair<int, int> pos, int a)
{
	int xy = bus[a].GetXY();
	if (xy == -1)
	{
		return (pos.first == bus[a].startX && bus[a].minY() <= pos.second && pos.second <= bus[a].maxY());
	}
	else
	{
		return (pos.second == bus[a].startY && bus[a].minX() <= pos.first && pos.first <= bus[a].maxX());
	}
}
int ans = -1;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	memset(Visit, -1, sizeof(Visit));
	std::cin >> N >> M;
	std::cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d, e;
		std::cin >> a >> b >> c >> d >> e;
		bus.push_back({ b,c,d,e });

		for (int j = 0; j < i; j++)
		{
			if (Cross(i, j))
			{
				V[i].push_back(j);
				V[j].push_back(i);
			}
		}
	}
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		for (int i = 0; i < K; i++)
		{
			if (Cross({ a,b }, i))
			{
				//출발지와 연결된 버스
				busType[i] = 1;
			}
			if (Cross({ c,d }, i))
			{
				//도착지와 연결된 버스
				if (busType[i] == 1)
				{
					cout << 1 << endl;
					return 0;
				}
				busType[i] = 2;
			}
		}
	}

	queue<int> Q;
	for (int i = 0; i < K; i++)
		if (busType[i] == 1)
		{
			Q.push(i);
			Visit[i] = 1;
		}

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		if (busType[now] == 2)
		{
			ans = Visit[now];
			break;
		}
		for (int i = 0; i < V[now].size(); i++)
		{
			int next = V[now][i];
			if (Visit[next] != -1)
				continue;
			Q.push(next);
			Visit[next] = Visit[now] + 1;
		}
	}

	cout << ans << endl;
}