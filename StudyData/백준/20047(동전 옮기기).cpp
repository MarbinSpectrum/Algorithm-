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

int n;
string S;
string new_S;
string T;
bool Diff[10000];
int DiffNum = 0;
int a, b;
vector<char> A;
vector<char> B;
bool Result = false;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> S >> T;
	cin >> a >> b;

	string temp = "";
	for (int j = 0; j < n; j++)
		if (a != j && b != j)
			temp += S[j];
	new_S = temp;

	int i = 0;
	for (int j = 0; j < n; j++)
	{
		if (new_S.length() > i&& new_S[i] == T[j])
			i++;
		else
			A.push_back(T[j]);
	}


	if (A.size() == 0)
		Result = Result || true;
	else if (A.size() == 1)
		Result = Result || false;
	else if (A.size() == 2)
	{
		if (A[0] == S[a] && A[1] == S[b])
			Result = Result || true;
		else
			Result = Result || false;
	}
	else
		Result = Result || false;

	i = new_S.length() - 1;
	for (int j = n - 1; j >= 0; j--)
	{
		if (i >= 0 && new_S[i] == T[j])
			i--;
		else
			B.push_back(T[j]);
	}

	if (B.size() == 0)
		Result = Result || true;
	else if (B.size() == 1)
		Result = Result || false;
	else if (B.size() == 2)
	{
		if (B[0] == S[b] && B[1] == S[a])
			Result = Result || true;
		else
			Result = Result || false;
	}
	else
		Result = Result || false;

	if (Result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}
