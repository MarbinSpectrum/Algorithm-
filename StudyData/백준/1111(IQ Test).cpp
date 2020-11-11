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
int Arr[200];

bool Check(int a, int b)
{
    for (int i = 0; i < N - 1; i++)
        if (Arr[i] * a + b != Arr[i + 1])
            return false;
    return true;
}

vector<pair<int, int>> Result;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    if (N == 1)
        cout << "A" << endl;
    else if (N == 2)
    {
        if (Arr[0] == Arr[1])
            cout << Arr[0] << endl;
        else
            cout << "A" << endl;
    }
    else
    {
        for (int i = 0; i < N - 2; i++)
        {
            int x1 = Arr[i];
            int x2 = Arr[i + 1];
            int x3 = Arr[i + 2];

            int a = (x2 - x1 == 0) ? 0 : (x3 - x2) / (x2 - x1);
            int b = x2 - (x1 * a);

            if (Check(a, b))
            {
                Result.push_back({ a,b });
                break;
            }
        }

         if (Result.size() == 0)
            cout << "B" << endl;
         else if (Result.size() == 1)
            cout << Arr[N - 1] * Result[0].first + Result[0].second << endl;
         else
            cout << "A" << endl;



    }


    return 0;
}
