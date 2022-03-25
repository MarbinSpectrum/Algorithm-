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
#include <unordered_map> 
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
#define float double
#define Debug(a,b) cout << a << " " << b << endl

int Mul(int x, int y, int mod)
{
	return x * y % mod;
}

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
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
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		b = b >> 1;
		a = (a * a);
	}
	return res;
}
int Pow(int a, int b, int p)
{
	int res = 1;
	a = a % p;
	while (b > 0)
	{
		if (b & 1)
			res = Mul(res, a, p);
		b = b >> 1;
		a = Mul(a, a, p);
	}
	return res;
}

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

const float PI = acos(-1);

void fft(vector<complex<float>>& a, bool inv = false)
{
	int n = a.size();
	int j = 0;

	vector<complex<float>> roots(n / 2);
	for (int i = 1; i < n; i++) 
	{
		int bit = (n >> 1);
		while (j >= bit)
		{
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) 
			swap(a[i], a[j]);
	}
	double ang = 2 * PI / n * (inv ? -1 : 1);
	for (int i = 0; i < n / 2; i++) 
		roots[i] = complex<float>(cos(ang * i), sin(ang * i));
	
	for (int i = 2; i <= n; i <<= 1)
	{
		int step = n / i;
		for (int j = 0; j < n; j += i)
		{
			for (int k = 0; k < i / 2; k++)
			{
				complex<float> u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) 
		for (int i = 0; i < n; i++) 
			a[i] /= n;
}

vector<int> multiply(vector<int>& v, vector<int>& w)
{
	vector<complex<float>> fv(v.begin(), v.end());
	vector<complex<float>> fw(w.begin(), w.end());
	// n이 무조건 2^n 이여야 하기 때문에 변환!
	int n = 2;
	while (n < v.size() + w.size())
		n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);

	for (int i = 0; i < n; i++) 
		fv[i] *= fw[i];
	fft(fv, 1);
	vector<int> ret(n);
	for (int i = 0; i < n; i++) 
		ret[i] = (int)round(fv[i].real());
	return ret;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> a(N * 2);
	vector<int> b(N * 2);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		a[i + N] = a[i];
	for (int i = 0; i < N; i++)
		cin >> b[N - i - 1];

	vector<int> res = multiply(a, b);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

}