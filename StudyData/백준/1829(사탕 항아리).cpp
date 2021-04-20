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

int N , M;
vector < pair<int, vector<int>>> ans1;
vector < pair<int, vector<int>>> ans2;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> Arr(N);

    {
        {
            vector<int> temp;
            for (int i = 0; i < N; i++)
                temp.push_back(i);
            ans1.push_back({ M,temp });
        }
        for (int i = 0; i < N; i++)
            Arr[i] = i;


        while (true)
        {
            int maxV = -1;

            for (int i = 0; i < N; i++)
                maxV = max(maxV, Arr[i]);

            if (maxV == 0)
                break;

            maxV = Pow(2, (int)log2(maxV));
            vector<int> temp;
            for (int i = 0; i < N; i++)
                if (Arr[i] >= maxV)
                {
                    Arr[i] -= maxV;
                    temp.push_back(i);
                }
            ans1.push_back({ maxV,temp });
        }
    }

    {
        for (int i = 0; i < N; i++)
            Arr[i] = M + i;

        while (true)
        {
            int maxV = -1;

            for (int i = 0; i < N; i++)
                maxV = max(maxV, Arr[i]);

            if (maxV == 0)
                break;

            maxV = Pow(2, (int)log2(maxV));
            vector<int> temp;
            for (int i = 0; i < N; i++)
                if (Arr[i] >= maxV)
                {
                    Arr[i] -= maxV;
                    temp.push_back(i);
                }
            ans2.push_back({ maxV,temp });
        }

    }

    if (ans1.size() > ans2.size())
        swap(ans1, ans2);

    cout << ans1.size() << endl;
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i].second.size() << " " << ans1[i].first << endl;
        for (int j = 0; j < ans1[i].second.size(); j++)
            cout << ans1[i].second[j] + 1 << " ";
        cout << endl;
    }

}