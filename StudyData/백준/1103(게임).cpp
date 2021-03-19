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
#define Init(a,b) memset(a,b,sizeof(a))

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
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M;
char MAP[50][50];
vector<int> V[2500];

bool Visit[2500];
bool Finish[2500];
bool Cycle = false;

int VisitValue[2500];

void DFS(int n)
{
    Visit[n] = true;
    for (int i = 0; i < V[n].size(); i++)
    {
        int v = V[n][i];
        if (!Visit[v])
            DFS(v);
        else if (!Finish[v])
            Cycle = true;
    }
    Finish[n] = true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAP[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (MAP[i][j] != 'H')
            {
                int moveValue = MAP[i][j] - '0';

                for(int k = 0; k < 4; k++)
                {
                    int ai = i + Dic[k][0] * moveValue;
                    int aj = j + Dic[k][1] * moveValue;
                    if (0 <= ai && ai < N && 0 <= aj && aj < M)
                        if (MAP[ai][aj] != 'H')
                            V[i * M + j].push_back(ai * M + aj);
                }
            }

    pair<int, int> Start = { 0,1 };
    int result = 0;

    DFS(0);

    if (Cycle)
    {
        cout << -1 << endl;
        return 0;
    }

    queue<pair<int, int>> Queue;
    Queue.push(Start);
    VisitValue[Start.first] = 0;

    while (!Queue.empty())
    {
        pair<int, int> Now = Queue.front();
        Queue.pop();

        result = max(result,Now.second);
        for (int i = 0; i < V[Now.first].size(); i++)
        {
            pair<int, int> Next = { V[Now.first][i],Now.second + 1 };
            if (VisitValue[Next.first] >= Now.second + 1)
                continue;
            Queue.push(Next);
            VisitValue[Next.first] = Now.second + 1;
        }
    }

    cout << result << endl;


}