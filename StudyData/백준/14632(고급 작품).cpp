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

int N, M;
int K;
int Q;
char DrawingPaper[1000][1000];
char Stamp[501][1000][1000];
pair<int, int> StampHW[501];
void Print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << DrawingPaper[i][j];
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int H, W;
        cin >> H >> W;
        StampHW[i].first = H;
        StampHW[i].second = W;
        for (int j = 0; j < H; j++)
            for (int k = 0; k < W; k++)
                cin >> Stamp[i][j][k];

    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            DrawingPaper[i][j] = '.';

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int T, Y, X;
        cin >> T >> Y >> X;
        for (int j = Y; j < min(N, (int)(Y + StampHW[T].first)); j++)
            for (int k = X; k < min(M, (int)(X + StampHW[T].second)); k++)
                DrawingPaper[j][k] = Stamp[T][j - Y][k - X];
    }

    Print();
    

}

