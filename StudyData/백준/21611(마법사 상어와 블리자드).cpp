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

    int v = temp * temp;
    if (b % 2 == 1)
        v *= a;
    return v;
}

const int INF = 8999999999999999999;
const int Dic[5][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{0,0} };
const int Dic8[8][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1},{+1,+1},{-1,-1} ,{+1,-1}, {-1,+1} };
////////////////////////////////////////////////////////////////////////

using namespace std;

int N,M;
int MAP[50][50];
pair<int,int> Next[50][50];
int Marble[4];

void Fun1(int d,int s)
{
    pair<int, int> now = { N / 2, N / 2 };
    if (d == 1)
    {
        for (int j = 0; j < s; j++)
        {
            pair<int, int> temp = { now.first - 1,now.second };
            //Marble[MAP[temp.first][temp.second]]++;
            MAP[temp.first][temp.second] = 0;
            now = temp;
        }
    }
    else if (d == 2)
    {
        for (int j = 0; j < s; j++)
        {
            pair<int, int> temp = { now.first + 1,now.second };
            //Marble[MAP[temp.first][temp.second]]++;
            MAP[temp.first][temp.second] = 0;
            now = temp;
        }
    }
    else if (d == 3)
    {
        for (int j = 0; j < s; j++)
        {
            pair<int, int> temp = { now.first,now.second - 1 };
            //Marble[MAP[temp.first][temp.second]]++;
            MAP[temp.first][temp.second] = 0;
            now = temp;
        }
    }
    else if (d == 4)
    {
        for (int j = 0; j < s; j++)
        {
            pair<int, int> temp = { now.first,now.second + 1 };
            //Marble[MAP[temp.first][temp.second]]++;
            MAP[temp.first][temp.second] = 0;
            now = temp;
        }
    }
}

void Fun2()
{
    while (true)
    {
        vector<pair<int, int>> Marbles;
        int lastM = -1;
        pair<int, int> now = { N / 2, N / 2 - 1 };
        bool flag = true;
        while (now != Next[now.first][now.second])
        {
            if (lastM != MAP[now.first][now.second] && MAP[now.first][now.second] != 0)
            {
                if (Marbles.size() >= 4)
                {
                    for (int i = 0; i < Marbles.size(); i++)
                    {
                        Marble[MAP[Marbles[i].first][Marbles[i].second]]++;
                        MAP[Marbles[i].first][Marbles[i].second] = 0;
                    }
                    flag = false;
                }
                Marbles.clear();
                lastM = MAP[now.first][now.second];
            }

            if(MAP[now.first][now.second] != 0)
                Marbles.push_back(now);

            now = Next[now.first][now.second];
        }

        if (Marbles.size() >= 4)
        {
            for (int i = 0; i < Marbles.size(); i++)
            {
                Marble[MAP[Marbles[i].first][Marbles[i].second]]++;
                MAP[Marbles[i].first][Marbles[i].second] = 0;
            }
            flag = false;
        }
        Marbles.clear();

        if (flag)
            break;
    }

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        cout << MAP[i][j] << " ";
    //    cout << endl;
    //}
    //cout << endl;

    {
        vector<pair<int, int>> Marbles;

        pair<int, int> now = { N / 2, N / 2 - 1 };
        pair<int, int> nowState = { 0,0 };
        while (now != Next[now.first][now.second])
        {
            if (MAP[now.first][now.second] != nowState.first && MAP[now.first][now.second] != 0)
            {
                if (nowState.first != 0)
                    Marbles.push_back(nowState);
                nowState.first = MAP[now.first][now.second];
                nowState.second = 1;
            }
            else if (MAP[now.first][now.second] == nowState.first)
                nowState.second++;

            now = Next[now.first][now.second];
        }
        if (nowState.first != 0)
            Marbles.push_back(nowState);


        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                MAP[i][j] = 0;

        now = { N / 2, N / 2 - 1 };

        for(int i = 0; i < Marbles.size(); i++)
            {
                MAP[now.first][now.second] = Marbles[i].second;
                if (now.first == 0 && now.second == 0 && now == Next[now.first][now.second])
                {
                    i = Marbles.size();
                    break;
                }
                now = Next[now.first][now.second];
                MAP[now.first][now.second] = Marbles[i].first;
                if (now.first == 0 && now.second == 0 && now == Next[now.first][now.second])
                {
                    i = Marbles.size();
                    break;
                }
                now = Next[now.first][now.second];
            }
    }

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        cout << MAP[i][j] << " ";
    //    cout << endl;
    //}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];

    {
        pair<int, int> now = { N / 2, N / 2 };
        for (int i = 1; i <= N; i++)
        {
            if (i % 2 == 1)
            {
                for (int j = 0; j < i; j++)
                {
                    pair<int, int> temp = { now.first,now.second - 1 };
                    if (temp.first < 0 || temp.second < 0 || temp.first >= N || temp.second >= N)
                        break;
                    Next[now.first][now.second] = temp;
                    now = temp;
                }
                for (int j = 0; j < i; j++)
                {
                    pair<int, int> temp = { now.first + 1,now.second };
                    if (temp.first < 0 || temp.second < 0 || temp.first >= N || temp.second >= N)
                        break;
                    Next[now.first][now.second] = temp;
                    now = temp;
                }
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    pair<int, int> temp = { now.first,now.second + 1 };
                    if (temp.first < 0 || temp.second < 0 || temp.first >= N || temp.second >= N)
                        break;
                    Next[now.first][now.second] = temp;
                    now = temp;
                }
                for (int j = 0; j < i; j++)
                {
                    pair<int, int> temp = { now.first - 1,now.second };
                    if (temp.first < 0 || temp.second < 0 || temp.first >= N || temp.second >= N)
                        break;
                    Next[now.first][now.second] = temp;
                    now = temp;
                }
            }
        }
    }
    Next[0][0] = { 0,0 };



    for (int i = 0; i < M; i++)
    {
        int d, s;
        cin >> d >> s;
        Fun1(d, s);
        Fun2();

    }

    cout << Marble[1] + Marble[2] * 2 + Marble[3] * 3 << endl;
    

    return 0;
}