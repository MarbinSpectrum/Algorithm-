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

int N, M, K;
vector<pair<int, int>> Dragon[301];
vector<int> City[301];
bool Visit[301];
bool Check[301];
bool HuntDragon(int n,int w)
{
    Init(Visit, false);
    int S = w;

    queue<int> Queue;
    Queue.push(n);
    Visit[n] = true;
    while (!Queue.empty())
    {
        int now = Queue.front();
        Queue.pop();
        for (int j = 0; j < Dragon[now].size(); j++)
        {
            if (S <= Dragon[now][j].second)
                w -= Dragon[now][j].first;
        }

        for (int j = 0; j < City[now].size(); j++)
        {
            int next = City[now][j];
            if (Visit[next])
                continue;
            Queue.push(next);
            Visit[next] = true;
        }
    }
    if (w < 0)
        return false;
    return true;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {

        cin >> N >> M >> K;
        
        if (N == M && M == K && N == 0)
            break;

        for (int i = 0; i < 301; i++)
        {
            Dragon[i].clear();
            City[i].clear();
        }

        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            City[a].push_back(b);
            City[b].push_back(a);              
        }
        for (int i = 0; i < K; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            Dragon[a].push_back({ b,c });
        }

        int Solution = 0;

        Init(Check, false);

        for (int i = 1; i <= N; i++)
        {
            if (Check[i])
                continue;

            queue<int> Queue;
            Queue.push(i);
            Check[i] = true;
            while (!Queue.empty())
            {
                int now = Queue.front();
                Queue.pop();

                for (int j = 0; j < City[now].size(); j++)
                {
                    int next = City[now][j];
                    if (Check[next])
                        continue;
                    Queue.push(next);
                    Check[next] = true;
                }
            }

            int R = 100000000;
            int L = 0;
            int Result = 100000000;

            while (L <= R)
            {
                int Mid = (L + R) / 2;
                if (HuntDragon(i,Mid))
                {
                    Result = min(Mid, Result);
                    R = Mid - 1;
                }
                else
                    L = Mid + 1;
            }
            Solution += Result;

        }
        cout << Solution << endl;
    }
   
    return 0;
}


