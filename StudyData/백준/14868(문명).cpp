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
#define float double
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return (int)n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N,K;
int World[2000][2000];
int Par[100001];
int Find(int a)
{
	if (a == Par[a])
		return a;
	else
		return Par[a] = Find(Par[a]);
}

int UnionNum = 0;

void Uni(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
	{
		Par[b] = a;
		UnionNum++;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	queue< tuple<int, int, int>> Queue;
	queue< pair<int, int>> UniQueue;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		World[x - 1][y - 1] = i + 1;
		Queue.push({ x - 1,y - 1 ,0 });
		UniQueue.push({ x - 1,y - 1 });
		Par[i + 1] = i + 1;
	}

	int time = -1;

	while (!Queue.empty())
	{
		int r = get<0>(Queue.front());
		int c = get<1>(Queue.front());
		int t = get<2>(Queue.front());
		Queue.pop();

		if (t != time)
		{
			time = t;

			while (!UniQueue.empty())
			{
				int uni_r = UniQueue.front().first;
				int uni_c = UniQueue.front().second;
				UniQueue.pop();

				for (int i = 0; i < 4; i++)
				{
					int uni_ar = uni_r + Dic[i][0];
					int uni_ac = uni_c + Dic[i][1];
					if (0 <= uni_ar && uni_ar < N && 0 <= uni_ac && uni_ac < N)
						if (World[uni_r][uni_c] != 0 && World[uni_ar][uni_ac] != 0)
							Uni(Find(World[uni_r][uni_c]), Find(World[uni_ar][uni_ac]));
				}
			}
		}

		if (UnionNum >= K - 1)
		{
			cout << t << endl;

			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ar = r + Dic[i][0];
			int ac = c + Dic[i][1];
			if (0 <= ar && ar < N && 0 <= ac && ac < N)
				if (World[r][c] != 0 && World[ar][ac] == 0)
				{
					World[ar][ac] = World[r][c];
					Queue.push({ ar,ac,t + 1 });
					UniQueue.push({ ar,ac });
				}
		}
	}


}