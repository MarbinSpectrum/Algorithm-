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
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M, K;

int MAP[100][100];
int temp[100][100];
int BaseMAP[100][100];
void InitMAP()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            MAP[i][j] = BaseMAP[i][j];
}

vector<tuple<int, int, int>> Arr;
vector<int> Order;
void Cycle(int sr, int sc, int er, int ec)
{
    if (sr > er || sc > ec)
        return;

    for (int i = sc; i < ec; i++)
        temp[sr][i + 1] = MAP[sr][i];
    for (int i = sr; i < er; i++)
        temp[i + 1][ec] = MAP[i][ec];
    for (int i = ec; i > sc; i--)
        temp[er][i - 1] = MAP[er][i];
    for (int i = er; i > sr; i--)
        temp[i - 1][sc] = MAP[i][sc];

    for (int i = sc; i < ec; i++)
        MAP[sr][i] = temp[sr][i];
    for (int i = sr; i < er; i++)
        MAP[i][ec] = temp[i][ec];
    for (int i = ec; i > sc; i--)
        MAP[er][i] = temp[er][i];
    for (int i = er; i > sr; i--)
        MAP[i][sc] = temp[i][sc];

    Cycle(sr + 1, sc + 1, er - 1, ec - 1); 
}




int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
            BaseMAP[i][j] = MAP[i][j];
        }

    for (int i = 0; i < K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;      
        Arr.push_back({ a,b,c });
        Order.push_back(i);
    }

    int Result = INF;

    do
    {
        InitMAP();

        for (int i = 0; i < Order.size(); i++)
        {
            int a, b, c;
            a = get<0>(Arr[Order[i]]);
            b = get<1>(Arr[Order[i]]);
            c = get<2>(Arr[Order[i]]);
            Cycle(a - c, b - c, a + c, b + c);
        }



        for (int i = 1; i <= N; i++)
        {
            int a = 0;
            for (int j = 1; j <= M; j++)
                a += MAP[i][j];
            Result = min(Result, a);
        }

    } while (next_permutation(Order.begin(), Order.end()));

    cout << Result << endl;

    return 0;
}