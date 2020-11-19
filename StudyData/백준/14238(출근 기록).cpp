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

string S;
int a, b, c;
bool Visit[50][50][50][10];
char Result[31];
bool endGame = false;
void Solution(int a, int b, int c, int n, int k)
{
    if (endGame)
        return;
    if (Visit[a][b][c][k])
        return;
    if (a == b && b == c && c == 0)
    {
        endGame = true;
        for (int i = 0; i < S.length(); i++)
            cout << Result[i];
        cout << endl;
        return;
    }

    Visit[a][b][c][k] = true;

    if (a > 0)
    {
        Result[n] = 'A';
        if (k == 0 || k == 3 || k == 6)
            Solution(a - 1, b, c, n + 1, 0);
        else if (k == 1 || k == 4 || k == 7)
            Solution(a - 1, b, c, n + 1, 3);
        else if (k == 2 || k == 5 || k == 8)
            Solution(a - 1, b, c, n + 1, 6);
    }

    if (b > 0)
    {
        Result[n] = 'B';
        if (k == 0 || k == 3 || k == 6)
            Solution(a, b - 1, c, n + 1, 1);
        //else if (k == 1 || k == 4 || k == 7)
        //    Solution(a, b - 1, c, n + 1, 4);
        else if (k == 2 || k == 5 || k == 8)
            Solution(a, b - 1, c, n + 1, 7);
    }

    if (c > 0)
    {
        Result[n] = 'C';
        if (k == 0 || k == 3 /*|| k == 6*/)
            Solution(a, b, c - 1, n + 1, 2);
        else if (k == 1 || k == 4 /*|| k == 7*/)
            Solution(a, b, c - 1, n + 1, 5);
        //else if (k == 2 || k == 5/* || k == 8*/)
        //    Solution(a, b, c - 1, n + 1, 8);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == 'A')
            a++;
        else if (S[i] == 'B')
            b++;
        else if (S[i] == 'C')
            c++;
    }

    Init(Visit, false);

    Solution(a, b, c, 0, 0);



    if (!endGame)
        cout << -1 << endl;
}
