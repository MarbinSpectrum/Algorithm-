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

bool Alpha[28];
vector<int> A;
string a, b, c;
int Value[28];
bool Check = false;
bool UseNum[11];
void DFS(int alphaNum)
{
	if (Check)
		return;
	if (alphaNum < A.size())
	{
		for (int i = 0; i < 10; i++)
		{
			if (UseNum[i])
				continue;
			UseNum[i] = true;
			Value[A[alphaNum]] = i;
			DFS(alphaNum + 1);
			UseNum[i] = false;
		}
	}
	else
	{
		int aValue = 0;
		for (int i = 0; i < a.size(); i++)
		{
			aValue *= 10;
			aValue += Value[a[i] - 'A'];
		}
		int bValue = 0;
		for (int i = 0; i < b.size(); i++)
		{
			bValue *= 10;
			bValue += Value[b[i] - 'A'];
		}
		int cValue = 0;
		for (int i = 0; i < c.size(); i++)
		{
			cValue *= 10;
			cValue += Value[c[i] - 'A'];
		}
		//cout << aValue << " + " << bValue << " = " << cValue << endl;
		if (aValue + bValue == cValue)
			Check = true;
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	for (int i = 0; i < a.size(); i++)
		Alpha[a[i] - 'A'] = true;
	for (int i = 0; i < b.size(); i++)
		Alpha[b[i] - 'A'] = true;
	for (int i = 0; i < c.size(); i++)
		Alpha[c[i] - 'A'] = true;
	for (int i = 0; i < 28; i++)
		if (Alpha[i])
			A.push_back(i);

	//for (int i = 0; i < A.size(); i++)
	//	cout << (char)(A[i] + 'A') << " ";
	//cout << endl;

	DFS(0);

	if (Check)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
