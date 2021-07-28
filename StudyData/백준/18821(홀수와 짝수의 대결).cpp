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

	return temp * temp * ((b % 2) ? a : 1);
}

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int Arr[137][2] = {
			{906150257 ,906150258},
{906150259 ,906150293},
{906150295 ,906150307},
{906150311 ,906150313},
{906150315 ,906151515},
{906151517 ,906151575},
{906154583 ,906154585},
{906154605 ,906154605},
{906154609 ,906154757},
{906154763 ,906154763},
{906154769 ,906154769},
{906154789 ,906154789},
{906154791 ,906154791},
{906154793 ,906154793},
{906154825 ,906154825},
{906154829 ,906154829},
{906154837 ,906154837},
{906154857 ,906154857},
{906154865 ,906154881},
{906154885 ,906154885},
{906154887 ,906154887},
{906154889 ,906154889},
{906154891 ,906154891},
{906154893 ,906154893},
{906154895 ,906154907},
{906154909 ,906154911},
{906154915 ,906154927},
{906154947 ,906154949},
{906180359 ,906180361},
{906180363 ,906180363},
{906180365 ,906180365},
{906180367 ,906180369},
{906180371 ,906180373},
{906180375 ,906180375},
{906180391 ,906180517},
{906180519 ,906180519},
{906180525 ,906180533},
{906180537 ,906180553},
{906180555 ,906192697},
{906192847 ,906192865},
{906192867 ,906192903},
{906192905 ,906192905},
{906192907 ,906192965},
{906192971 ,906192971},
{906192979 ,906192983},
{906192985 ,906193227},
{906193229 ,906193233},
{906193245 ,906193245},
{906193247 ,906193247},
{906193303 ,906193303},
{906193419 ,906193419},
{906193465 ,906193465},
{906193475 ,906193475},
{906193477 ,906193477},
{906194931 ,906194931},
{906194933 ,906194945},
{906194949 ,906194949},
{906194951 ,906194967},
{906194979 ,906194979},
{906195099 ,906195099},
{906195109 ,906195149},
{906195151 ,906195151},
{906195297 ,906195297},
{906195299 ,906195985},
{906195989 ,906195989},
{906196009 ,906196009},
{906196011 ,906196013},
{906196015 ,906196015},
{906196045 ,906196051},
{906196053 ,906196055},
{906196057 ,906196071},
{906196077 ,906196079},
{906196081 ,906196081},
{906196083 ,906196091},
{906196099 ,906208711},
{906208713 ,906208713},
{906208731 ,906208731},
{906209041 ,906209063},
{906209067 ,906209067},
{906209069 ,906209069},
{906209071 ,906209223},
{906209227 ,906209227},
{906209233 ,906209235},
{906209237 ,906209237},
{906209241 ,906209241},
{906209243 ,906209271},
{906209283 ,906209283},
{906209285 ,906477701},
{906477735 ,906477811},
{906477867 ,906477867},
{906477869 ,906477869},
{906477871 ,906477899},
{906477901 ,906477901},
{906477903 ,906477905},
{906477929 ,906477931},
{906477933 ,906477933},
{906477935 ,906477935},
{906477937 ,906486639},
{906486805 ,906486805},
{906486807 ,906486807},
{906486817 ,906486817},
{906486819 ,906486819},
{906486821 ,906486831},
{906486843 ,906486853},
{906486855 ,906486855},
{906486909 ,906486913},
{906486917 ,906486973},
{906486975 ,906487001},
{906487005 ,906487063},
{906487065 ,906487065},
{906487069 ,906487069},
{906487071 ,906487071},
{906487073 ,906487077},
{906487085 ,906487085},
{906487087 ,906487101},
{906487185 ,906487185},
{906487187 ,906487189},
{906487191 ,906487191},
{906487193 ,906487193},
{906487195 ,906487203},
{906487205 ,906487205},
{906487259 ,906487259},
{906487261 ,906487261},
{906487263 ,906487263},
{906487271 ,906487287},
{906487933 ,906487933},
{906487937 ,906487937},
{906487949 ,906487973},
{906487975 ,906487993},
{906487995 ,906488001},
{906488003 ,906488003},
{906488007 ,906488007},
{906488009 ,906488009},
{906488023 ,906488025},
{906488027 ,906488065},
{906488067 ,906488067},
{906488077 ,906488079} };
void Sol()
{
	int a;
	cin >> a;
	if (a == 1)
	{
		cout << "E" << endl;
		return;
	}
	for (int i = 0; i < 137; i++)
		if (Arr[i][0] <= a && a <= Arr[i][1])
		{
			cout << "E" << endl;
			return;
		}
	cout << "O" << endl;
	return;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
		Sol();
}