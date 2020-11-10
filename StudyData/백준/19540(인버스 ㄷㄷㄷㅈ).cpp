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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 6)
    {
        Debug(1, 2);
        Debug(2, 3);
        Debug(3, 4);
        Debug(4, 5);
        Debug(4, 6);
    }
    else if (N == 7)
    {
        Debug(1, 2);
        Debug(2, 3);
        Debug(2, 4);
        Debug(4, 5);
        Debug(4, 7);
        Debug(5, 6);
    }
    else if (N == 8)
    {
        Debug(1, 2);
        Debug(2, 3);
        Debug(2, 4);
        Debug(3, 7);
        Debug(4, 5);
        Debug(5, 6);
        Debug(5, 8);
    }
    else if (N % 6 == 3)
    {
        Debug(1, 2);
        Debug(2, 3);
        Debug(3, 4);
        Debug(3, 6);
        Debug(3, 8);
        Debug(4, 5);
        Debug(6, 7);
        Debug(8, 9);
        for (int i = 1; i < N / 6; i++)
        {
            int a = i * 6;
            Debug(3 + a, 4 + a);
            Debug(4 + a, 5 + a);
            Debug(3 + a, 8 + a);
            Debug(8 + a, 9 + a);
            Debug(3 + a, 6 + a);
            Debug(6 + a, 7 + a);
        }
    }
    else if (N % 6 == 4)
    {
        Debug(1, 2);
        Debug(2, N);
        Debug(2, 3);
        Debug(3, 4);
        Debug(3, 6);
        Debug(3, 8);
        Debug(4, 5);
        Debug(6, 7);
        Debug(8, 9);
        for (int i = 1; i < N / 6; i++)
        {
            int a = i * 6;
            Debug(3 + a, 4 + a);
            Debug(4 + a, 5 + a);
            Debug(3 + a, 8 + a);
            Debug(8 + a, 9 + a);
            Debug(3 + a, 6 + a);
            Debug(6 + a, 7 + a);
        }
    }
    else if (N % 6 == 5)
    {
        Debug(1, 2);
        Debug(2, N - 1);
        Debug(4, N);
        Debug(2, 3);
        Debug(3, 4);
        Debug(3, 6);
        Debug(3, 8);
        Debug(4, 5);
        Debug(6, 7);
        Debug(8, 9);
        for (int i = 1; i < N / 6; i++)
        {
            int a = i * 6;
            Debug(3 + a, 4 + a);
            Debug(4 + a, 5 + a);
            Debug(3 + a, 8 + a);
            Debug(8 + a, 9 + a);
            Debug(3 + a, 6 + a);
            Debug(6 + a, 7 + a);
        }
    }
    else if (N % 6 == 0)
    {
        Debug(1, 2);
        Debug(2, N - 2);
        Debug(4, N - 1);
        Debug(2, 3);
        Debug(3, 4);
        Debug(3, 6);
        Debug(3, 8);
        Debug(4, 5);
        Debug(6, 7);
        Debug(6, N);
        Debug(8, 9);
        for (int i = 1; i < N / 6 - 1; i++)
        {
            int a = i * 6;
            Debug(3 + a, 4 + a);
            Debug(4 + a, 5 + a);
            Debug(3 + a, 8 + a);
            Debug(8 + a, 9 + a);
            Debug(3 + a, 6 + a);
            Debug(6 + a, 7 + a);
        }
    }
    else if (N % 6 == 1)
    {
        Debug(1, 2);
        Debug(2, N - 3);
        Debug(4, N - 2);
        Debug(2, 3);
        Debug(3, 4);
        Debug(3, 6);
        Debug(3, 8);
        Debug(4, 5);
        Debug(6, 7);
        Debug(6, N - 1);
        Debug(8, 9);
        for (int i = 1; i < N / 6 - 1; i++)
        {
            int a = i * 6;
            Debug(3 + a, 4 + a);
            Debug(4 + a, 5 + a);
            Debug(3 + a, 8 + a);
            Debug(8 + a, 9 + a);
            Debug(3 + a, 6 + a);
            Debug(6 + a, 7 + a);

        }
        Debug(8 + (N / 6 - 2) * 6, N);
    }
    else if (N % 6 == 2)
    {
        Debug(1, N);
        Debug(1, N - 1);
        Debug(N, N - 2);
        Debug(N - 2, N - 3);
        Debug(N - 2, N - 4);
        Debug(1, 2);
        Debug(2, 3);
        Debug(3, 4);
        Debug(3, 6);
        Debug(3, 8);
        Debug(4, 5);
        Debug(6, 7);
        Debug(8, 9);
        for (int i = 1; i < N / 6 - 1; i++)
        {
            int a = i * 6;
            Debug(3 + a, 4 + a);
            Debug(4 + a, 5 + a);
            Debug(3 + a, 8 + a);
            Debug(8 + a, 9 + a);
            Debug(3 + a, 6 + a);
            Debug(6 + a, 7 + a);
        }
    }

    return 0;
}
