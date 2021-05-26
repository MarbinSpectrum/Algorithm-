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
#define float long double
#define Debug(a,b) cout << a << " " << b << endl


int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
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
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	int temp = Pow(a, b / 2);

	return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int n;
void Sol(int N)
{
	vector<int> Arr(N);
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	sort(Arr.begin(), Arr.end());

	int last = Arr[0];
	vector<pair<int, int>> Check;
	Check.push_back({ last,1 });
	for (int i = 1; i < N; i++)
		if (last != Arr[i])
		{
			last = Arr[i];
			Check.push_back({ last,1 });
		}
		else
			Check[Check.size() - 1].second++;

	int lastN = INF;
	for (int i = 0; i < Check.size(); i++)
	{
		if (i == Check.size() - 2)
		{
			if (lastN + 1 == Check[i].first)
			{
				if (Check[i].first + 1 == Check[i + 1].first)
				{
					for (int j = 0; j < Check[i + 1].second; j++)
						cout << Check[i + 1].first << " ";
					for (int j = 0; j < Check[i].second; j++)
						cout << Check[i].first << " ";
				}
				else
				{
					cout << Check[i + 1].first << " ";
					for (int j = 0; j < Check[i].second; j++)
						cout << Check[i].first << " ";
					for (int j = 1; j < Check[i + 1].second; j++)
						cout << Check[i + 1].first << " ";

				}
			}
			else 
			{
				if (Check[i].first + 1 == Check[i+1].first)
				{
					for (int j = 0; j < Check[i + 1].second; j++)
						cout << Check[i + 1].first << " ";
					for (int j = 0; j < Check[i].second; j++)
						cout << Check[i].first << " ";
				}
				else
				{
					for (int j = 0; j < Check[i].second; j++)
						cout << Check[i].first << " ";
					for (int j = 0; j < Check[i + 1].second; j++)
						cout << Check[i + 1].first << " ";
				}
			}
			break;
		}
		else
		{
			if (lastN + 1 == Check[i].first && Check[i].second > 0)
			{
				cout << Check[i + 1].first << " ";
				Check[i + 1].second--;
				lastN = Check[i + 1].first;
			}
			for (int j = 0; j < Check[i].second; j++)
			{
				cout << Check[i].first << " ";
				lastN = Check[i].first;
			}
		}
	}

	cout << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		Sol(n);
	}


}