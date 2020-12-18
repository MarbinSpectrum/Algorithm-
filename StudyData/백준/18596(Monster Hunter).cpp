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

const int MAX_N = 100001;

int T;
int N;
vector<int> V[MAX_N];
int Parent[MAX_N];
int P[MAX_N];

class QueueData
{
public:
    int a;
    int b;
    int index;
}Monster[MAX_N];

struct cmp
{
    bool operator()(QueueData A, QueueData B)
    {
        int Aa = A.a;
        int Ab = A.b;
        int Ba = B.a;
        int Bb = B.b;

        if (Ab - Aa >= 0 && Bb - Ba < 0)
            return 0;
        else if (Ab - Aa < 0 && Bb - Ba >= 0)
            return 1;
        if (Ab - Aa < 0)
            return Ab < Bb;
        return Aa > Ba;
    }
};
priority_queue< QueueData, vector<QueueData>, cmp > Queue;
bool Check[MAX_N];

void Reset()
{
    for (int i = 0; i < MAX_N; i++)
        V[i].clear();
    for (int i = 0; i < MAX_N; i++)
    {
        Monster[i].a = 0;
        Monster[i].b = 0;
        Monster[i].index = i;
    }
    for (int i = 1; i < MAX_N; i++)
        P[i] = i;
    for (int i = 0; i < MAX_N; i++)
        Check[i] = false;
}

void MakeTree(int parent, int now)
{
    Parent[now] = parent;
    for (int i = 0; i < V[now].size(); i++)
    {
        int next = V[now][i];
        if (next == parent)
            continue;
        MakeTree(now, next);
    }
}

int Find(int n)
{
    if (n == P[n])
        return n;
    return P[n] = Find(P[n]);
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        Reset();

        cin >> N;

        for (int i = 2; i <= N; i++)
        {
            int a, b;
            cin >> Monster[i].a >> Monster[i].b;
            Queue.push(Monster[i]);
        }

        for (int i = 0; i < N - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            V[a].push_back(b);
            V[b].push_back(a);
        }

        MakeTree(-1, 1);

        //cout << "--------------------" << endl;

        while (!Queue.empty())
        {
            int index = Queue.top().index;
            Queue.pop();

            if (Check[index])
                continue;
            Check[index] = true;

            int p = Find(Parent[index]);

            int a = min(-Monster[p].a, Monster[p].b - (Monster[p].a + Monster[index].a));
            int b = Monster[p].b + Monster[index].b - (Monster[p].a + Monster[index].a) - a;
            Monster[p].a = -a;
            Monster[p].b = b;

            P[index] = p;

            if (p != 1)
                Queue.push(Monster[p]);
        }

        cout << Monster[1].a << endl;

    }

}

