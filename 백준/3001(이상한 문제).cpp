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

//맨앞자리숫자 //자리수 //합
int DP[10][16][151];

int Sum(int n)
{
	int temp = 0;
	while (n > 0)
	{
		temp += n % 10;
		n /= 10;
	}
	return temp;
}

int F(int n,int s)
{
	int digit = (int)log10(n) + 1;
	int temp = 0;
	for (int i = 1; i <= digit; i++)
		for (int a = 1; a <= 9; a++)
			temp += DP[a][i][s];
	int sub = Sum(n);
	for(int i = 1; i <= digit; i++)
	{
		int b = n % 10;
		sub -= b;
		for (int a = b + 1; a <= 9; a++)
			if (s - sub >= 0)
				temp -= DP[a][i][s - sub];
		n /= 10;
	}
	return temp;

}
int Arr[16];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init(DP, 0);
	for (int i = 0; i <= 9; i++)
		DP[i][1][i] = 1;

	for (int i = 2; i <= 15; i++)
		for (int j = 0; j <= 150; j++)
			for (int k = 0; k <= 9; k++)
				for (int a = 0; a <= 9; a++)
					if (j - k >= 0)
						DP[k][i][j] += DP[a][i - 1][j - k];

	int A, B ,S;
	cin >> A >> B >> S;
	cout << F(B,S) - F(A - 1, S) << endl;

	while (Sum(A) != S)
	{
		if (Sum(A) < S)
		{
			int can = 0;
			int tempA = A;
			int p = 1;
			while (tempA > 0)
			{
				Arr[p] = 9 - (tempA % 10);
				can += 9 - (tempA % 10);
				tempA /= 10;
				p++;
			}
			int A_Sum = Sum(A);
			if (abs(A_Sum - S) > can)
			{
				A = pow(10, (int)log10(A) + 1);
				continue;
			}
			for (int i = 1; i <= 15; i++)
			{
				while (Arr[i] > 0)
				{
					int t = pow(10, i - 1);
					A += t;
					A_Sum++;
					if (A_Sum == S)
						break;
				}
				if (A_Sum == S)
					break;
			}
		}
		else if (Sum(A) > S)
		{
			int can = 0;
			int tempA = A;
			int p = 1;
			while (tempA > 0)
			{
				Arr[p] = (tempA % 10);
				can += (tempA % 10);
				tempA /= 10;
				p++;
			}
			int A_Sum = Sum(A);
			if (abs(A_Sum - S) > can)
			{
				A = pow(10, (int)log10(A) + 1);
				continue;
			}
			for (int i = 1; i <= 15; i++)
			{
				while (Arr[i] > 0)
				{
					int t = pow(10, i - 1);
					A -= t;
					A_Sum--;
					if (A_Sum == S)
						break;
				}
				if (A_Sum == S)
					break;
			}
		}
	}

	cout << A << endl;


}
