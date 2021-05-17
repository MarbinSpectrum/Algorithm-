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


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed;
	cout.precision(4);

	int T;
	cin >> T;
	while (T--)
	{
		float A, B, C, D;
		cin >> A >> B >> C >> D;
		vector<float> ans;
		for (int i = 0; i <= 1000000; i++)
		{
			if (i == 0)
			{
				if (D == 0)
				{
					ans.push_back(i);
					break;
				}
			}
			else
			{
				if ((int)D % i != 0)
					continue;
				{
					int x2 = i * i;
					int x = i;
					if (A * x2 + B * x + C + D / i == 0)
					{
						ans.push_back(i);
						break;
					}
				}
				i = -i;
				{
					int x2 = i * i;
					int x = i;
					if (A * x2 + B * x + C + D / i == 0)
					{
						ans.push_back(i);
						break;
					}
				}
				i = -i;
			}
		}

		{
			float a = A;
			float b = B + ans[0] * a;
			float c = C + ans[0] * b;
			if (a == 0)
			{
				sort(ans.begin(), ans.end());
				ans.erase(unique(ans.begin(), ans.end()), ans.end());
				for (int i = 0; i < ans.size(); i++)
					cout << ans[i] << " ";
				cout << endl;
				continue;
			}

			float temp = b * b - (float)4 * a * c;
			if (temp > 0)
			{
				double ans1, ans2;
				ans1 = (-1 * b + sqrt(temp)) / (2 * a);
				ans2 = (-1 * b - sqrt(temp)) / (2 * a);
				ans.push_back(ans1);
				ans.push_back(ans2);
				sort(ans.begin(), ans.end());
				ans.erase(unique(ans.begin(), ans.end()), ans.end());
				for (int i = 0; i < ans.size(); i++)
					cout << ans[i] << " ";
				cout << endl;
			}
			else if (temp == 0)
			{
				double ans1, ans2;
				ans1 = (-1 * b + sqrt(temp)) / (2 * a);
				ans.push_back(ans1);
				sort(ans.begin(), ans.end());
				ans.erase(unique(ans.begin(), ans.end()), ans.end());
				for (int i = 0; i < ans.size(); i++)
					cout << ans[i] << " ";
				cout << endl;
			}
			else
			{
				sort(ans.begin(), ans.end());
				ans.erase(unique(ans.begin(), ans.end()), ans.end());
				for (int i = 0; i < ans.size(); i++)
					cout << ans[i] << " ";
				cout << endl;
			}
		}


	}

}