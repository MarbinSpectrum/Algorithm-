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

int N;
vector<pair<int,int>> Arr;
vector<int> Pos;
pair<int, int> Result[1000001];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1000001; i++)
        Result[i] = { -1,-1 };

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        Arr.push_back({ a, -1 });
        Arr.push_back({ b, +1 });
    }

    sort(Arr.begin(), Arr.end());

    for (int i = 0; i < Arr.size(); i++)
    {
        if (Pos.size() > 0 && Pos[Pos.size() - 1] == Arr[i].first)
            continue;     
        Pos.push_back(Arr[i].first);
    }

    int c = 0;
    int f = 0;
    int index = 0;

    for (int i = 0; i < Pos.size(); i++)
    {
        if (Result[c].first == -1)
            Result[c] = { f,Pos[i] };
        else if(Result[c].second == f)
            Result[c] = { Result[c].first,Pos[i] };

        //cout << c << endl;
        //Debug(Result[c].first, Result[c].second);

        while (index < Arr.size() && Pos[i] == Arr[index].first)
        {
            if (Arr[index].second == -1)
                c++;
            else if (Arr[index].second == +1)
                c--;
            index++;
        }

        f = Pos[i];
    }

    for(int i = N; i >= 0; i--)
        if (Result[i].first != -1)
        {
            cout << i << endl;
            Debug(Result[i].first, Result[i].second);
            return 0;
        }



}

