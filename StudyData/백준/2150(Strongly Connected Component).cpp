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

int V, E;
vector<int> A[10001];
int N[10001];
int L[10001];
bool Visit[10001];
int cnt = 0;
stack<int> STACK;
vector<vector<int>> Result;
void DFS(int n)
{
    cnt++;
    STACK.push(n);
    N[n] = cnt;
    L[n] = cnt;
    Visit[n] = true;
    for (int i = 0; i < A[n].size(); i++)
    {
        int next = A[n][i];
        if (!N[next])
        {
            DFS(next);
            L[n] = min(L[n], L[next]);
        }
        else if (Visit[next])
            L[n] = min(L[n], N[next]);
    }

    if (L[n] == N[n])
    {
        vector<int> Arr;
        while (!STACK.empty())
        {
            int p = STACK.top();
            STACK.pop();
            Arr.push_back(p);
            Visit[p] = false;
            if (n == p)
                break;
        }
        sort(Arr.begin(), Arr.end());
        Result.push_back(Arr);
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
    }

    for (int i = 1; i <= V; i++)
        if (!N[i])
            DFS(i);

    sort(Result.begin(), Result.end());

    cout << Result.size() << endl;
    for (int i = 0; i < Result.size(); i++)
    {
        for (int j = 0; j < Result[i].size(); j++)
            cout << Result[i][j] << " ";
        cout << "-1\n";
    }
}


