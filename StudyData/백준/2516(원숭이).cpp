//#ifndef _GLIBCXX_NO_ASSERT 
//#include <cassert> 
//#endif #include <cctype>
//#include <cerrno> 
//#include <cfloat> 
//#include <ciso646> 
//#include <climits> 
//#include <clocale> 
//#include <cmath> 
//#include <csetjmp> 
//#include <csignal>
//#include <cstdarg> 
//#include <cstddef>
//#include <cstdio> 
//#include <cstdlib> 
//#include <cstring> 
//#include <ctime> 
//
//#if __cplusplus >= 201103L 
//#include <ccomplex> 
//#include <cfenv> 
//#include <cinttypes> 
//#include <cstdalign> 
//#include <cstdbool>
//#include <cstdint> 
//#include <ctgmath>
//#include <cwchar> 
//#include <cwctype>
//#endif 
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
//#if __cplusplus >= 201103L 
//#include <array> 
//#include <atomic> 
//#include <chrono> 
//#include <condition_variable> 
//#include <forward_list> 
//#include <future> 
//#include <initializer_list> 
//#include <mutex> 
//#include <random> 
//#include <ratio>
//#include <regex> 
//#include <scoped_allocator> 
//#include <system_error> 
//#include <thread> 
//#include <tuple> 
//#include <typeindex> 
//#include <type_traits> 
//#include <unordered_map> 
//#include <unordered_set> 
//#endif

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

int Ceil(double n)
{
    if (n - (int)(n) > 0)
        return (int)n + 1;
    else
        return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
vector<int> V[100001];
//0 1번우리
//1 2번우리
int State[100001];


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            V[i].push_back(b);
        }
    }

    while (true)
    {
        bool Flag = true;

        for (int i = 1; i <= N; i++)
        {
            if (State[i] == 0)
            {
                int C = 0;
                for (int j = 0; j < V[i].size(); j++)
                    if (State[V[i][j]] == 0)
                        C++;

                if (C >= 2)
                {
                    Flag = false;
                    State[i] = 1;
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            if (State[i] == 1)
            {
                int C = 0;
                for (int j = 0; j < V[i].size(); j++)
                    if (State[V[i][j]] == 1)
                        C++;

                if (C >= 2)
                {
                    Flag = false;
                    State[i] = 0;
                }
            }
        }

        if (Flag)
            break;
    }

    vector<int> A;
    for (int i = 1; i <= N; i++)
        if (State[i] == 0)
            A.push_back(i);

    vector<int> B;
    for (int i = 1; i <= N; i++)
        if (State[i] == 1)
            B.push_back(i);

    cout << A.size() << " ";
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    cout << B.size() << " ";
    for (int i = 0; i < B.size(); i++)
        cout << B[i] << " ";
    cout << endl;
}