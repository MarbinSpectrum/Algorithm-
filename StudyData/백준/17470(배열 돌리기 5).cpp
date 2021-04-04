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
int D[2][2];
int dir = 0;
bool ReverW = false;
bool ReverH = false;
void Fun1()
{
    swap(D[0][0], D[1][0]);
    swap(D[0][1], D[1][1]);

    ReverH = !ReverH;

}
void Fun2()
{
    swap(D[0][0], D[0][1]);
    swap(D[1][0], D[1][1]);

    ReverW = !ReverW;
}

void Fun5()
{
    swap(D[0][0], D[0][1]);
    swap(D[0][0], D[1][1]);
    swap(D[0][0], D[1][0]);
}

void Fun3()
{
    Fun5();
    if (ReverW == ReverH)
    {
        dir += 90;
        dir %= 360;
    }
    else
    {
        dir += 270;
        dir %= 360;
    }
}

void Fun6()
{
    swap(D[0][0], D[1][0]);
    swap(D[0][0], D[0][1]);
    swap(D[0][1], D[1][1]);
}

void Fun4()
{
    Fun6();
    if (ReverW == ReverH)
    {
        dir += 270;
        dir %= 360;
    }
    else
    {
        dir += 90;
        dir %= 360;
    }
}

int N, M, K;
int MAP[105][105];
vector<vector<int>> Piece[5];
int ResultMAP[105][105];
void Rotate(int n)
{
    int w, h;
    h = Piece[n].size();
    w = Piece[n][0].size();
    //Debug(h, w);
    vector<vector<int>> temp(w, vector<int>(h));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            temp[j][h - i - 1] = Piece[n][i][j];
    Piece[n] = temp;
}
void ReverseW(int n)
{
    int w, h;
    h = Piece[n].size();
    w = Piece[n][0].size();

    vector<vector<int>> temp(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            temp[i][w - j - 1] = Piece[n][i][j];
    Piece[n] = temp;
}

void ReverseH(int n)
{
    int w, h;
    h = Piece[n].size();
    w = Piece[n][0].size();

    vector<vector<int>> temp(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            temp[h - i - 1][j] = Piece[n][i][j];
    Piece[n] = temp;
}

void Show()
{
    int w = Piece[1][0].size();
    int h = Piece[1].size();

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int a = 0; a < h; a++)
                for (int b = 0; b < w; b++)
                    ResultMAP[i * h + a][j * w + b] = Piece[D[i][j]][a][b];

    for (int i = 0; i < h * 2; i++)
    {
        for (int j = 0; j < w * 2; j++)
            cout << ResultMAP[i][j] << " ";
        cout << endl;
    }
}

void ShowD()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    D[0][0] = 1;
    D[0][1] = 2;
    D[1][0] = 3;
    D[1][1] = 4;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAP[i][j];
    {
        vector<vector<int>> temp(N / 2, vector<int>(M / 2));
        for (int i = 0; i < N / 2; i++)
            for (int j = 0; j < M / 2; j++)
                temp[i][j] = MAP[i][j];
        Piece[1] = temp;
    }
    {
        vector<vector<int>> temp(N / 2, vector<int>(M / 2));
        for (int i = 0; i < N / 2; i++)
            for (int j = 0; j < M / 2; j++)
                temp[i][j] = MAP[i][j + M / 2];
        Piece[2] = temp;
    }
    {
        vector<vector<int>> temp(N / 2, vector<int>(M / 2));
        for (int i = 0; i < N / 2; i++)
            for (int j = 0; j < M / 2; j++)
                temp[i][j] = MAP[i + N / 2][j];
        Piece[3] = temp;
    }
    {
        vector<vector<int>> temp(N / 2, vector<int>(M / 2));
        for (int i = 0; i < N / 2; i++)
            for (int j = 0; j < M / 2; j++)
                temp[i][j] = MAP[i + N / 2][j + M / 2];
        Piece[4] = temp;
    }
    bool flagw = false;
    bool flagh = false;
    int flagr = 0;
    for (int i = 0; i < K; i++)
    {
        int a;
        cin >> a;

        if (a == 1)
            Fun1();
        else if (a == 2)
            Fun2();
        else if (a == 3)
            Fun3();
        else if (a == 4)
            Fun4();
        else if (a == 5)
            Fun5();
        else if (a == 6)
            Fun6();
    }

    for (int i = 0; i < dir; i += 90)
        for (int j = 1; j <= 4; j++)
            Rotate(j);

    if (ReverW)
        for (int j = 1; j <= 4; j++)
            ReverseW(j);
    if (ReverH)
        for (int j = 1; j <= 4; j++)         
            ReverseH(j);

    Show();
}