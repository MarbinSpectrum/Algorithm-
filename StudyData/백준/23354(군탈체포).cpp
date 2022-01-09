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

const int INF = 1000000000;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int N;
int MAP[1005][1005];
int Dist1[6][1005][1005];
int Dist2[1 << 6][6];
vector<pair<int, int>> A;
typedef pair<int, int> POS;
typedef priority_queue< pair<int, POS>, vector< pair<int, POS>>, greater< pair<int, POS>>> PQ;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> MAP[i][j];
			if (MAP[i][j] <= 0)
			{
				A.push_back({ i,j });
			}
			for (int k = 0; k < 6; k++)
			{
				Dist1[k][i][j] = INF;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < (1 << 6); j++)
		{
			Dist2[j][i] = INF;
		}
	}

	for (int i = 0; i < A.size(); i++)
	{
		PQ pq;
		pq.push({ 0,A[i] });
		Dist1[i][A[i].first][A[i].second] = 0;
		while (!pq.empty())
		{
			POS temp0 = pq.top().second;
			int temp1 = pq.top().first;
			pq.pop();

			if (Dist1[i][temp0.first][temp0.second] < temp1)
				continue;
			for (int j = 0; j < 4; j++)
			{
				int ar = temp0.first + Dic[j][0];
				int ac = temp0.second + Dic[j][1];
				if (ar < 0 || ar >= N || ac < 0 || ac >= N)
					continue;

				int add = MAP[ar][ac] == -1 ? 0 : MAP[ar][ac];

				if (Dist1[i][ar][ac] > Dist1[i][temp0.first][temp0.second] + add)
				{
					Dist1[i][ar][ac] = Dist1[i][temp0.first][temp0.second] + add;
					pq.push({ Dist1[i][ar][ac],{ar,ac} });
				}
			}
		}
	}

	//for (int i = 0; i < A.size(); i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		for (int k = 0; k < N; k++)
	//		{
	//			cout << Dist[i][j][k] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

	{
		PQ pq;
		pq.push({ 0,{0,0} });
		Dist2[0][0] = 0;
		while (!pq.empty())
		{
			int bit = pq.top().second.first;
			int pos = pq.top().second.second;
			int cost = pq.top().first;
			pq.pop();

			if (Dist2[bit][pos] < cost)
				continue;

			for (int j = 0; j < A.size(); j++)
			{
				int add = Dist1[pos][A[j].first][A[j].second];
				int nb = bit | (1 << j);

				if (Dist2[nb][j] > Dist2[bit][pos] + add)
				{
					Dist2[nb][j] = Dist2[bit][pos] + add;
					pq.push({ Dist2[nb][j],{nb,j} });
				}
			}
		}
	}

	cout << Dist2[(1 << A.size()) - 1][0] << endl;
}