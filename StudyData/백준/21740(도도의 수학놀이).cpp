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
#define float double
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

    return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int n;
int maxIndex = 0;
int maxArr = -1;
bool cmp(string a, string b) {
    return a + b > b + a;
}

char Swap(char n)
{
    if (n == '0')
        return '0';
    if (n == '1')
        return '1';
    if (n == '2')
        return '2';
    if (n == '5')
        return '5';
    if (n == '6')
        return '9';
    if (n == '8')
        return '8';
    if (n == '9')
        return '6';
}

string Reverse(string s)
{
    string temp = "";
    int v = 0;
    for (int i = 0; i < s.size(); i++)
        temp += Swap(s[i]);
    reverse(temp.begin(), temp.end());
    return temp;
}
vector<string> Arr;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        Arr.push_back(Reverse(a));
    }

    sort(Arr.begin(), Arr.end(), cmp);

    string cc = Arr[0];

    for (int i = 0; i < n; i++)
    {
        if (cc.length() < Arr[i].length())
        {
            cc = Arr[i];
            maxIndex = i;
        }
        else if (cc.length() == Arr[i].length())
        {
            if (cc < Arr[i])
            {
                cc = Arr[i];
                maxIndex = i;
            }
        }

    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == maxIndex)
            cout << Reverse(Arr[i]);
        cout << Reverse(Arr[i]);
    }
    cout << endl;
}