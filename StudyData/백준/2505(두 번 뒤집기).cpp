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

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
int Arr[10001];
int Arr2[10001];
int a, b;
vector<pair<int, int>> Result;

bool IndexCheck(int n)
{
    return (Arr[n] != n);
}

bool Check()
{
    for (int i = 0; i < 10001; i++)
        if (Arr[i] != i)
            return false;
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
        Arr2[i] = Arr[i];
    }
    a = -1;

    for (int i = 1; i <= N; i++)
    {
        if (Arr[i] != i && a == -1)
            a = i;
        else if (Arr[i] == a)
        {
            b = i;
            Result.push_back({ a,b });
            reverse(Arr + a, Arr + b + 1);
            a = -1;
            b = -1;
            i = 1;
        }
    }

    if (Result.size() > 2)
    {
        Result.clear();
        for(int i = N; i >= 1; i--)
        {
            if (Arr2[i] != i && b == -1)
                b = i;
            else if (Arr2[i] == b)
            {
                a = i;
                Result.push_back({ a,b });
                reverse(Arr2 + a, Arr2 + b + 1);
                a = -1;
                b = -1;
                i = N;
            }
        }
    }
    
    if (Result.size() == 2)
    {
        Debug(Result[0].first, Result[0].second);
        Debug(Result[1].first, Result[1].second);
    }
    else if (Result.size() == 1)
    {
        Debug(Result[0].first, Result[0].second);
        Debug(1, 1);
    }
    else if (Result.size() == 0)
    {
        Debug(1, 1);
        Debug(1, 1);
    }
}
