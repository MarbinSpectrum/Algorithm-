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

// C++ 
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
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };
const int Prime[] =
{
	2 ,3 ,5 ,7 ,11 ,13 ,17, 19 ,23 ,29,
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
	73 ,79 ,83 ,89 ,97 ,101 ,103 ,107 ,109 ,113,
	127 ,131, 137, 139 ,149 ,151, 157 ,163 ,167 ,173,
	179 ,181, 191, 193, 197, 199, 211, 223 ,227 ,229,
	233 ,239 ,241 ,251 ,257 ,263 ,269 ,271 ,277 ,281,
	283 ,293 ,307 ,311 ,313 ,317 ,331 ,337 ,347 ,349,
	353 ,359 ,367 ,373 ,379 ,383 ,389 ,397 ,401 ,409,
	419 ,421 ,431 ,433 ,439 ,443 ,449 ,457 ,461 ,463,
	467 ,479 ,487 ,491 ,499 ,503 ,509 ,521 ,523 ,541
};

////////////////////////////////////////////////////////////////////////

int Dist[10][10];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)
		return 1;
	else if (op == 0)
		return 0;
	else
		return -1;
}


bool Contact(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0)
	{
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

pair<double, double> ContactPoint(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
	double A, B, E; // ax + by = e
	double C, D, F; // cx + dy = f

	A = (double)b.second - (double)a.second;
	B = (double)a.first - (double)b.first;
	E = ((double)b.second - (double)a.second) * (double)a.first + ((double)a.first - (double)b.first) * (double)a.second;

	C = (double)d.second - (double)c.second;
	D = (double)c.first - (double)d.first;
	F = ((double)d.second - (double)c.second) * (double)c.first + ((double)c.first - (double)d.first) * (double)c.second;

	double DE = (A * D) - (B * C);
	return { ((E * D) - (B * F)) / DE, ((A * F) - (E * C)) / DE };
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;

	while (true)
	{
		t++;
		int N, C;
		cin >> N >> C;
		if (N == 0 && C == 0)
			break;

		vector<int> BaseArr;
		vector<vector<int>> Arr;
		for (int i = 1; i <= N; i++)
			BaseArr.push_back(i);
		do
		{
			vector<int> tempArr;
			for (int i = 0; i < BaseArr.size(); i++)
				tempArr.push_back(BaseArr[i]);
			Arr.push_back(tempArr);

		} while (next_permutation(BaseArr.begin(), BaseArr.end()));


		vector<pair<int, int>> Point(N + 1);
		for (int i = 1; i <= N; i++)
		{
			int a, b;
			cin >> a >> b;
			Point[i] = { a,b };
		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> Dist[i][j];

		int Result = INF;
		for(int num = 0; num < Arr.size(); num++)
		{
			int temp = 0;
			if (Arr[num][0] != 1)
				continue;
			//for (int i = 0; i < Arr[num].size(); i++)
			//	cout << Arr[num][i] << " ";
			//cout << endl;
			vector<pair<double, double>> pArr;

			for (int i = 0; i < Arr[num].size(); i++)
			{
				int a = Arr[num][i];
				int b = Arr[num][(i + 1) % N];
				vector<pair<double, double>> checkArr;
				for (int j = 0; j < Arr[num].size(); j++)
				{
					int c = Arr[num][j];
					int d = Arr[num][(j + 1) % N];
					if (a == c || a == d || b == c || b == d)
						continue;
					if (Contact(Point[a], Point[b], Point[c], Point[d]))
					{
						//Debug(a, b);
						//Debug(c, d);
						pair<double, double> p = ContactPoint(Point[a], Point[b], Point[c], Point[d]);
						bool flag = true;
						for(int k = 0; k < checkArr.size(); k++)
							if (checkArr[k].first == p.first && checkArr[k].second == p.second)
							{
								flag = false;
								break;
							}

						if (flag)
						{
							pArr.push_back(p);
							checkArr.push_back(p);
						}
					}
				}

				temp += Dist[a][b];
			}

			sort(pArr.begin(), pArr.end());
			if (pArr.size() > 0)
			{
				pair<double, double> f = { -99999,-99999 };
				int c = 0;
				for (int i = 0; i < pArr.size(); i++)
				{
					if (f.first != pArr[i].first || f.second != pArr[i].second)
					{
						temp += c * (c - 1) * C / 2;
						f = pArr[i];
						c = 1;
					}
					else
						c++;
				}
				temp += c * (c - 1) * C / 2;
			}
			//cout << temp << endl;
			Result = min(Result, temp);
		}

		cout << t << ". " << Result << endl;

	}


}
