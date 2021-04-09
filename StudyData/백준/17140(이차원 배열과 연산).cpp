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
const int Dic[5][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{0,0} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int W = 3;
int H = 3;
vector<vector<int>> Arr(H,vector<int>(W));
int MAP[101];

void MAP_Init()
{
    for (int i = 0; i <= 100; i++)
        MAP[i] = 0;
}

vector<pair<int, int>> MAP_Arr()
{
    vector<pair<int, int>> temp;
    for (int i = 1; i <= 100; i++)
        if (MAP[i] != 0)
            temp.push_back({ MAP[i],i });
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
        swap(temp[i].first, temp[i].second);
    return temp;
}

void Print()
{
    cout << "-----------------" << endl;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << Arr[i][j] << " ";
        cout << endl;
    }
}

void R_Fun()
{
    for (int i = 0; i < H; i++)
    {
        MAP_Init();
        for (int j = 0; j < W; j++)
            MAP[Arr[i][j]]++;
        vector<pair<int, int>> temp = MAP_Arr();
        Arr[i].clear();
        for (int j = 0; j < temp.size(); j++)
        {
            Arr[i].push_back(temp[j].first);
            Arr[i].push_back(temp[j].second);
        }
    }
    int MAX_W = 0;
    for (int i = 0; i < H; i++)
        MAX_W = max(MAX_W, (int)Arr[i].size());
    W = MAX_W;

    for (int i = 0; i < H; i++)
        while (Arr[i].size() < W)
            Arr[i].push_back(0);
}

void C_Fun()
{
    for (int i = 0; i < W; i++)
    {
        MAP_Init();
        for (int j = 0; j < H; j++)
            MAP[Arr[j][i]]++;
        vector<pair<int, int>> temp = MAP_Arr();
        
        for (int j = 0; j < Arr.size(); j++)
            Arr[j][i] = 0;

        int hh = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            if (Arr.size() <= hh)
                Arr.push_back(vector<int>(W, 0));
            Arr[hh][i] = temp[j].first;
            hh++;
            if (Arr.size() <= hh)
                Arr.push_back(vector<int>(W, 0));
            Arr[hh][i] = temp[j].second;
            hh++;
            
        }
    }

    H = max((int)Arr.size(), H);
}

void ReSize()
{
    H = min((int)100, H);
    W = min((int)100, W);
    vector<vector<int>> temp(H, vector<int>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            temp[i][j] = Arr[i][j];

    Arr = temp;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;
    r--;
    c--;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> Arr[i][j];

    int T = 0;
    do
    {
        if(r < H && c < W)
            if (Arr[r][c] == k)
            {
                cout << T << endl;
                return 0;
            }


        if (H >= W)
            R_Fun();
        else
            C_Fun();

       // Print();
        ReSize();
        T++;
    }     
    while (T <= 100);

    cout << -1 << endl;
}