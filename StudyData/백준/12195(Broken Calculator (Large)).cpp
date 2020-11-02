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

////////////////////////////////////////////////////////////////////////

int T, N;
int Num[10];
int Result;
int MAP[1000001];
vector<int> CheckArr;
int makeCheck(int n)
{
	int temp = 0;
	while (n > 0)
	{
		if (Num[n % 10] == 0)
			return -1;
		temp++;
		n /= 10;
	}
	return temp;
}

void DFS(int n,int deep)
{
	int check = makeCheck(n);
	if (check != -1)
		Result = min(Result, deep == 0 ? check : deep + 1 + check);
	for (int i = 0; i < CheckArr.size(); i++)
		if (n >= CheckArr[i])
		{
			int len = makeCheck(CheckArr[i]);
			if (len != -1 && n % CheckArr[i] == 0 && deep + 1 + len < Result)
				DFS(n / CheckArr[i], deep == 0 ? len : deep + 1 + len);
		}
}

void MakeNum(int deep,int end,int v)
{
	if (deep == end)
	{
		if(v <= N && v > 1)
			CheckArr.push_back(v);
		return;
	}
	for (int i = 0; i <= 9; i++)
		if (Num[i] == 1)
			MakeNum(deep + 1,end, v * 10 + i);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	cin >> T;

	while (T--)
	{
		for (int i = 0; i <= 9; i++)
			cin >> Num[i];
		cin >> N;
		Result = INF;
		CheckArr.clear();
		for (int i = 1; i <= 6; i++)
			MakeNum(0, i, 0);
		DFS(N, 0);

		t++;
		if (Result == INF)
			cout << "Case #" << t << ": " << "Impossible\n";
		else
			cout << "Case #" << t << ": " << Result + 1 << endl;

	}
}
