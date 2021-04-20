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
const int Dic[5][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{0,0} };

////////////////////////////////////////////////////////////////////////

using namespace std;

bool Prime[3000];
int N;
int Arr[55];
vector<int> Pair[55];

vector<int> A;
vector<int> B;

bool Check[55];
int Link[55];
bool DFS(int n)
{
    for (int i = 0; i < Pair[n].size(); i++)
    {
        int idx = Pair[n][i];
        if (Check[idx])
            continue;
        Check[idx] = true;
        if (Link[idx] == 0 || DFS(Link[idx]))
        {
            Link[idx] = n;
            return true;
        }
    }
    return false;
}
vector<int> ans;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i <= 3000; i++)
    {
        bool flag = false;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            Prime[i] = true;
    }

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
        if (Arr[i] % 2 == 0)
            B.push_back(Arr[i]);
        else
            A.push_back(Arr[i]);
    }

    if (A.size() != B.size())
    {
        puts("-1");
        return 0;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j)
                if (Prime[Arr[i] + Arr[j]])
                    Pair[i].push_back(j);

    for (int j = 0; j < Pair[1].size(); j++)
    {
        memset(Link, 0, sizeof(Link));
        Link[1] = Pair[1][j];
        Link[Pair[1][j]] = 1;
        int flag = 2;
        for (int i = 1; i <= N; i++)
        {
            if (i == 1)
                continue;
            if (i == Pair[1][j])
                continue;
            memset(Check, false, sizeof(Check));
            Check[1] = true;
            Check[Pair[1][j]] = true;
            if (DFS(i))
                flag++;
        }

        if (flag == N)
            ans.push_back(Arr[Link[1]]);
    }

    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

}