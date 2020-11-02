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

int N, A, B;

int Get(int n,int a,int b)
{
	if (a % n == 0)
		a--;
	a = a / n;
	b = b / n;
	return (b - a);
}

int Bit_Count(int n)
{
	int temp = 0;
	while (n > 0)
	{
		if (n % 2 != 0)
			temp++;
		n /= 2;
	}
	return temp;
}

int GCD(int a, int b) 
{
	if (b == 0) 		
		return a;
	else		
		return GCD(b, a % b);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> A >> B;
	int Result = 0;
	vector<int> Arr;

	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		Arr.push_back(a);
		if (a == 1)
			flag = true;
	}

	if (flag)
	{
		cout << B - A + 1 << endl;
		return 0;
	}

	for (int i = 0; i < Arr.size(); i++)
		for (int bit = 1; bit < (1 << Arr.size()); bit++)
			if (Bit_Count(bit) == i + 1)
			{
				bool flag = false;
				int mul = 1;
				for (int j = 0; j < Arr.size(); j++)
					if (bit & (1 << j))
					{
						mul = (mul * Arr[j]) / GCD(mul, Arr[j]);
						if (B < mul)
						{
							flag = true;
							break;
						}
					}
				//cout << mul << endl;
				if (!flag)
				{
					if ((i + 1) % 2 == 0)
						Result -= Get(mul, A, B);
					else
						Result += Get(mul, A, B);
				}
			}

	cout << Result << endl;
}
