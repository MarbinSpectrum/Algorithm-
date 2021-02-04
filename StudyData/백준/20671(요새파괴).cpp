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
		return n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N;

vector<tuple<int, int, int>> Pos;
//좌표 //올라가는여부(1,-1) //높이

int Next[200001];
int Par[200001];
const int GROUND = 150001;
int Find(int a)
{
	if (Par[a] == a)
		return a;
	else
		return Par[a] = Find(Par[a]);
}
void Uni(int a, int b)
{
	int A = Find(a);
	int B = Find(b);
	Par[A] = B;
}

int Q;
stack<int> STACK;
stack<int> STACK2;
vector<int> Result;
vector<pair<int, int>> Arr;
vector<int> Arr2;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int H, L, R;
		cin >> H >> L >> R;
		Pos.push_back(make_tuple(L - 1, +H, i));
		Pos.push_back(make_tuple(R, -H, i));
		Par[i] = i;
	}
	Par[GROUND] = GROUND;

	sort(Pos.begin(), Pos.end());

	for (int i = 0; i < Pos.size(); i++)
	{
		int pos = get<0>(Pos[i]);
		int h = get<1>(Pos[i]);
		int num = get<2>(Pos[i]);

		if (h > 0)
			STACK.push(num);
		else if (h < 0)
		{
			if (!STACK.empty())
				STACK.pop();
			if (STACK.empty())
				Next[num] = GROUND;
			else
				Next[num] = STACK.top();
		}
	}
	Next[GROUND] = GROUND;

	int lastPos = GROUND;

	for (int i = 0; i < Pos.size(); i++)
	{
		int pos = get<0>(Pos[i]);
		int h = get<1>(Pos[i]);
		int num = get<2>(Pos[i]);

		if (lastPos != pos && h > 0)
		{
			Arr.push_back({ pos,STACK2.empty() ? GROUND : STACK2.top() });
			lastPos = pos;
			STACK2.push(num);
		}
		else if (lastPos == pos && h > 0)
		{
			STACK2.push(num);
			//Arr.back().second = STACK2.empty() ? GROUND : STACK2.top();
		}
		else if (lastPos != pos && h < 0)
		{
			Arr.push_back({ pos,STACK2.empty() ? GROUND : STACK2.top() });
			lastPos = pos;
			STACK2.pop();
		}
		else if (lastPos == pos && h < 0)
		{
			STACK2.pop();
		}
	}
	Arr.push_back({ 20000000000 ,GROUND });

	for (int i = 0; i < Arr.size(); i++)
		Arr2.push_back(Arr[i].first);

	for (int i = 0; i < Arr.size(); i++)
		cout << "[ " << Arr[i].first << " " << Arr[i].second << endl;

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int result = 0;
		int X, P;
		cin >> X >> P;

		int index = (lower_bound(Arr2.begin(), Arr2.end(), X) - Arr2.begin());

		if (index >= Arr.size() || index < 0)
		{
			Result.push_back(0);
			continue;
		}

		int A = Arr[index].second;
		while (P--)
		{
			A = Find(A);
			if (A == GROUND)
				break;
			int B = Next[A];
			B = Find(B);
			result++;
			Uni(A, B);

		}
		Result.push_back(result);
	}

	for (int i = 0; i < Result.size(); i++)
		cout << Result[i] << " ";
	cout << endl;


}