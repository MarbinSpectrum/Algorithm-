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

    int v = temp * temp;
    if (b % 2 == 1)
        v *= a;
    return v;
}

const int INF = 8999999999999999999;
const int Dic[5][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{0,0} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int n;
vector<int> S;
vector<pair<int, pair<int, int>>> Arr;
int result = -INF;

bool cmp(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B)
{
    return A.first < B.first;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        Arr.clear();
        S.clear();
        S.resize(n);
        result = -INF;

        for (int i = 0; i < n; i++)
            cin >> S[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    Arr.push_back({ S[i] - S[j] ,{i,j} });

        sort(Arr.begin(), Arr.end(), cmp);

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                int sum = S[i] + S[j];
                pair<int, pair<int, int>> v = { sum,{0,0} };
                int s = (lower_bound(Arr.begin(), Arr.end(), v, cmp) - Arr.begin());
                int e = (upper_bound(Arr.begin(), Arr.end(), v, cmp) - Arr.begin());

                if (0 > s || s >= Arr.size())
                    continue;
                if (Arr[s].first != sum)
                    continue;
                if (0 > e - 1 || e - 1 >= Arr.size())
                    continue;
                if (Arr[e - 1].first != sum)
                    continue;

                for (int k = s; k <= e - 1; k++)
                {
                    if (Arr[k].second.first == i || Arr[k].second.first == j || Arr[k].second.second == i || Arr[k].second.second == j)
                        continue;
                    result = max(result, S[Arr[k].second.first]);
                }
            }

        if (result == -INF)
            cout << "no solution" << endl;
        else
            cout << result << endl;
    }

    return 0;
}