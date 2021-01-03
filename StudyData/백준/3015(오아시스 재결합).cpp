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

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

stack<pair<int, int>> STACK;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int Result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (STACK.empty())
			STACK.push({ a,1 });
		else
		{
			int Check = 0;
			if (STACK.top().first == a)
			{
				Result += STACK.top().second;
				pair<int, int> temp = STACK.top();
				STACK.pop();
				if (!STACK.empty())
					Result += 1;
				STACK.push(temp);
				//Debug("!", STACK.top().second + (!STACK.empty() ? 1 : 0));
				STACK.top().second++;
			}
			else if (STACK.top().first < a)
			{
				while (!STACK.empty() && STACK.top().first < a)
				{
					Check += STACK.top().second;
					Result += STACK.top().second;
					STACK.pop();
				}

				if (!STACK.empty())
				{
					if (STACK.top().first == a)
					{
						Result += STACK.top().second;
						Check += STACK.top().second;
						pair<int, int> temp = STACK.top();
						STACK.pop();
						if (!STACK.empty())
							Result += 1;
						STACK.push(temp);
						//Debug("@", Check + (!STACK.empty() ? 1 : 0));
						STACK.top().second++;
					}
					else if (STACK.top().first > a)
					{
						//Debug("@", 1);
						Result += 1;
						STACK.push({ a,1 });
					}
				}
				else
					STACK.push({ a,1 });

			}
			else if (STACK.top().first > a)
			{
				STACK.push({ a,1 });
				//Debug("#", 1);
				Result += 1;
			}
		}
	}

	cout << Result << endl;

}
