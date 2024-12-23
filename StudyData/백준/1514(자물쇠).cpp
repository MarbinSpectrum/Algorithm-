﻿#ifndef _GLIBCXX_NO_ASSERT 
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

int N;
int A[105];
int B[105];
//현재 P //1번째번호 //2번째번호 //3번째번호 //회전방향
int DP[100][10][10][10][2];
int Result = INF;
int Digit(int n)
{
    while (n < 0)
        n += 10;
    n %= 10;
    return n;
}

int D(int p, int a, int b, int c, int f)
{
    if (p == N) 
        return 0;
    if (DP[p][a][b][c][f] != -1)
        return DP[p][a][b][c][f];
    DP[p][a][b][c][f] = INF;

    if (a == B[p])
        return DP[p][a][b][c][f] = min(D(p + 1, b, c, A[p + 3], 0), D(p + 1, b, c, A[p + 3], 1));
    int flag = (f == 1) ? 1 : -1;
    for (int z = 1; z <= 3; z++)
    {
        DP[p][a][b][c][f] = min(DP[p][a][b][c][f], 1 + D(p, Digit(a + z * flag), b, c, f));
        DP[p][a][b][c][f] = min(DP[p][a][b][c][f], 1 + D(p, Digit(a + z * flag), Digit(b + z * flag), c, f));
        DP[p][a][b][c][f] = min(DP[p][a][b][c][f], 1 + D(p, Digit(a + z * flag), Digit(b + z * flag), Digit(c + z * flag), f));
    }

    return  DP[p][a][b][c][f];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init(DP, -1);
    cin >> N;
    string temp;
    cin >> temp;
    for (int i = 0; i < N; i++)
        A[i] = temp[i] - '0';
    cin >> temp;
    for (int i = 0; i < N; i++)
        B[i] = temp[i] - '0';

    cout << min(D(0, A[0], A[1], A[2], 0), D(0, A[0], A[1], A[2], 1)) << endl;
}
