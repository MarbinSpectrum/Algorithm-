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
int A = 1;
vector<int> Arr;
int OneN = 0;
bool flag = true;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        Arr.push_back(a);
        if (i == 0)
            A = a;
        else
            A ^= a;
        if (a == 1)
            OneN++;
        else
            flag = false;
    }

    if (flag)
    {
        if (N & 1)
        {
            cout << "cubelover" << endl;
            return 0;
        }
        else
        {
            cout << "koosaga" << endl;
            return 0;
        }
    }


    if (OneN == 0 || OneN & 1)
    {
        if (A != 0)
            cout << "koosaga" << endl;
        else
            cout << "cubelover" << endl;
    }
    else
    {

        for (int i = 0; i < N; i++)
        {
            if (Arr[i] == 1)
                continue;
            Arr[i] = 1;
            break;
        }

        A = 0;
        for (int i = 0; i < N; i++)
            A ^= Arr[i];

        for (int i = 0; i < N; i++)
        {
            if (Arr[i] == 1)
                continue;
            A ^= Arr[i];
        }

        if (A != 0)
            cout << "koosaga" << endl;
        else
            cout << "cubelover" << endl;
    }
}
