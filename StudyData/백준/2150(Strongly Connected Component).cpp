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
bool Visit[10001];
vector<int> A[10001];
vector<int> B[10001];
stack<int> STACK;
vector<vector<int>> Result;

void DFS_A(int n)
{
    Visit[n] = true;
    for (int i = 0; i < A[n].size(); i++)
    {
        int next = A[n][i];
        if (Visit[next]) continue;
        DFS_A(next);
    }
    STACK.push(n);
}

void DFS_B(int n, vector<int>& SCC)
{
    Visit[n] = true;
    SCC.push_back(n);
    for (int i = 0; i < B[n].size(); i++)
    {
        int next = B[n][i];
        if (Visit[next]) continue;
        DFS_B(next, SCC);
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
        B[b].push_back(a);
    }

    for (int i = 1; i <= V; i++)
        if (!Visit[i])
            DFS_A(i);

    Init(Visit, false);

    while (!STACK.empty())
    {
        vector<int> temp;
        int next = STACK.top();
        STACK.pop();
        if (Visit[next]) continue;
        DFS_B(next, temp);
        sort(temp.begin(), temp.end());
        Result.push_back(temp);
    }

    sort(Result.begin(), Result.end());

    cout << Result.size() << endl;
    for (int i = 0; i < Result.size(); i++)
    {
        for (int j = 0; j < Result[i].size(); j++)
            cout << Result[i][j] << " ";
        cout << "-1\n";
    }
}
