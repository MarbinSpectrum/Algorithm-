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

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, W;

pair<int,int> A[1100];
pair<int, int> B[1100];

int DP[1100][1100];
pair<int, int> Child[1100][1100];
int Flag[1100][1100];

int A_Distance(int a, int b)
{
    return abs(A[a].first - A[b].first) + abs(A[a].second - A[b].second);
}
int B_Distance(int a, int b)
{
    return abs(B[a].first - B[b].first) + abs(B[a].second - B[b].second);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int a = 0; a <= 1000; a++)
        for (int b = 0; b <= 1000; b++)
            DP[a][b] = INF;

    cin >> N >> W;
    for (int w = 1; w <= W; w++)
    {
        int a, b;
        cin >> a >> b;
        A[w] = { a,b };
        B[w] = { a,b };
    }
    A[0] = { 1,1 };
    B[0] = { N,N };

    DP[0][0] = 0;
    Flag[0][0] = true; 

    for (int a = 0; a <= 1000; a++)
    {
        for (int b = 0; b <= 1000; b++)
        {
            if (Flag[a][b])
            {
                Flag[a + 1][b] = true;
                if (DP[a + 1][b] > DP[a][b] + A_Distance(a, a + 1))
                {
                    DP[a + 1][b] = DP[a][b] + A_Distance(a, a + 1);
                    Child[a + 1][b] = { a,b };
                }

                Flag[a][a + 1] = true;
                if (DP[a][a + 1] > DP[a][b] + B_Distance(b, a + 1))
                {
                    DP[a][a + 1] = DP[a][b] + B_Distance(b, a + 1);
                    Child[a][a + 1] = { a,b };
                }
            }

            if (Flag[b][a])
            {
                Flag[b][a + 1] = true;
                if (DP[b][a + 1] > DP[b][a] + B_Distance(a, a + 1))
                {
                    DP[b][a + 1] = DP[b][a] + B_Distance(a, a + 1);
                    Child[b][a + 1] = { b,a };
                }

                Flag[a + 1][a] = true;
                if (DP[a + 1][a] > DP[b][a] + A_Distance(b, a + 1))
                {
                    DP[a + 1][a] = DP[b][a] + A_Distance(b, a + 1);
                    Child[a + 1][a] = { b,a };
                }
            }
        }
    }

    int ResultMin = INF;
    int ResultA = 0;
    int ResultB = 0;
    for (int i = 0; i <= 1000; i++)
    {
        if (ResultMin > DP[W][i])
        {
            ResultMin = DP[W][i];
            ResultA = W;
            ResultB = i;
        }
        if (ResultMin > DP[i][W])
        {
            ResultMin = DP[i][W];
            ResultA = i;
            ResultB = W;
        }
    }

    cout << ResultMin << endl;
    vector<int> ResultArr;
    pair<int, int> Check = { ResultA,ResultB };
    while(Check.first != 0 || Check.second != 0)
    {
        //Debug(Check.first, Check.second);
        int nextA = Child[Check.first][Check.second].first;
        int nextB = Child[Check.first][Check.second].second;
        if (nextA < Check.first)
            ResultArr.push_back(1);
        else if (nextB < Check.second)
            ResultArr.push_back(2);
        Check = { nextA ,nextB };
    }
    for (int i = ResultArr.size() - 1; i >= 0; i--)
        cout << ResultArr[i] << endl;

}
