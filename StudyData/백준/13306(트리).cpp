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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, Q;
int Join[200001];
vector<tuple<int, int, int>> Order;
int Par[200001];
vector<string> Result;

int Find(int a)
{
    if (a != Par[a])
        return Par[a] = Find(Par[a]);
    return Par[a];
}


void Uni(int a, int b)
{
    int A = Find(a);
    int B = Find(b);
    Par[A] = B;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    for (int i = 2; i <= N; i++)
        cin >> Join[i];

    for (int i = 0; i < N + Q - 1; i++)
    {
        int x, a, b;
        cin >> x;
        if (x == 0)
        {
            cin >> a;
            b = 0;
        }
        else
        {
            cin >> a;
            cin >> b;
        }
        Order.push_back(make_tuple(x, a, b));
    }

    reverse(Order.begin(), Order.end());

    for (int i = 1; i <= 200000; i++)
        Par[i] = i;

    for (int i = 0; i < Order.size(); i++)
    {
        int x = get<0>(Order[i]);
        int a = get<1>(Order[i]);
        int b = get<2>(Order[i]);
        if (x == 0)
        {
            int b = Join[a];
            Uni(a, b);
        }
        else
        {
            if (Find(a) == Find(b))
                Result.push_back("YES");
            else
                Result.push_back("NO");
        }
    }
    
    reverse(Result.begin(), Result.end());

    for (int i = 0; i < Result.size(); i++)
        cout << Result[i] << endl;

}

