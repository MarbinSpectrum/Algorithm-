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

int T, N;

int B[2000];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;

        cout << floor((2 * N + 1) / 3) << endl;

        if (N <= 2)
            Debug(1, 1);
        else
        {
            int Result = 1;

            for (int i = 1; i <= floor((2 * N + 1) / 3); i++)
            {
                int a = i;
                int b = i;
                while (b != 0)
                {
                    B[b] = true;
                    a++;
                    b--;
                }

                bool flag = true;

                int c = i * 2;
                int d = i * 2 - 1;

                for (int j = 1; j <= floor((2 * N + 1) / 3) - i; j++)
                {
                    if (c > N || d < 0)
                    {
                        flag = false;
                        break;
                    }
                    if (B[d])
                    {
                        flag = false;
                        break;
                    }
                    c++;
                    d--;
                }

                if (flag)
                {
                    Result = i;
                    break;
                }

                a = i;
                b = i;
                while (b != 0)
                {
                    B[b] = false;
                    a++;
                    b--;
                }

                c = i * 2;
                d = i * 2 - 1;
            }

            int a = Result;
            int b = Result;
            while (b != 0)
            {
                Debug(a, b);
                a++;
                b--;
            }

            int c = Result * 2;
            int d = Result * 2 - 1;

            for (int j = 1; j <= floor((2 * N + 1) / 3) - Result; j++)
            {
                Debug(c, d);
                c++;
                d--;
            }

        }

    }

}
