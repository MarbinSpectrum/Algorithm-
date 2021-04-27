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

////////////////////////////////////////////////////////////////////////

using namespace std;

int N, M;

int MAP[20][20];
bool Visit[20][20];

void Print()
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << MAP[i][j] << " ";
        cout << endl;
    }
}

void Rotation(int angle)
{
    for (int i = 0; i < angle; i++)
    {
        vector < vector<int>> temp(N, vector<int>(N));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                int ai = j;
                int aj = -i + N - 1;
                temp[ai][aj] = MAP[i][j];
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                MAP[i][j] = temp[i][j];
    }
}

void Gravity()
{

    for (int j = 0; j < N; j++)
        for (int i = N - 2; i >= 0; i--)
            if (MAP[i][j] >= 0 && MAP[i + 1][j] == -2)
            {
                MAP[i + 1][j] = MAP[i][j];
                MAP[i][j] = -2;
                i = N - 1;
            }
}

int RemoveBlock()
{
    vector < pair<pair<int, int>, pair<int, int>>> Block;
    for (int a = 1; a <= M; a++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Visit[i][j] = false;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (MAP[i][j] == a)
                {
                    bool flag = true;
                    for (int k = 0; k < 4; k++)
                    {
                        int ai = i + Dic[k][0];
                        int aj = j + Dic[k][1];
                        if (0 > ai || ai >= N || 0 > aj || aj >= N)
                            continue;
                        if (MAP[ai][aj] == a || MAP[ai][aj] == 0)
                        {
                            flag = false;
                            break;
                       }
                    }

                    if (flag)
                        continue;

                    int size = 0;
                    int rainBlock = 0;
                    queue<pair<int, int>> Queue;
                    Queue.push({ i,j });
                    Visit[i][j] = true;
                    size++;

                    while (!Queue.empty())
                    {
                        pair<int, int> now = Queue.front();
                        Queue.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int ai = now.first + Dic[k][0];
                            int aj = now.second + Dic[k][1];
                            if (0 > ai || ai >= N || 0 > aj || aj >= N)
                                continue;
                            if (Visit[ai][aj])
                                continue;
                            if (MAP[ai][aj] == a || MAP[ai][aj] == 0)
                            {
                                if (MAP[ai][aj] == 0)
                                    rainBlock++;
                                Queue.push({ ai,aj });
                                Visit[ai][aj] = true;
                                size++;
                            }
                        }
                    }

                    Block.push_back({ {size,rainBlock },{i,j} });
                }
    }

    sort(Block.begin(), Block.end());

    int point = 0;

    if(Block.size() > 0)
    {

        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    Visit[i][j] = false;
        }

        int i = Block[Block.size() - 1].second.first;
        int j = Block[Block.size() - 1].second.second;
        int a = MAP[i][j];

        queue<pair<int, int>> Queue;
        Queue.push({ i,j });
        Visit[i][j] = true;
        MAP[i][j] = -2;
        point++;
        while (!Queue.empty())
        {
            pair<int, int> now = Queue.front();
            Queue.pop();

            for (int k = 0; k < 4; k++)
            {
                int ai = now.first + Dic[k][0];
                int aj = now.second + Dic[k][1];
                if (0 > ai || ai >= N || 0 > aj || aj >= N)
                    continue;
                if (Visit[ai][aj])
                    continue;
                if (MAP[ai][aj] == a || MAP[ai][aj] == 0)
                {
                    Queue.push({ ai,aj });
                    Visit[ai][aj] = true;
                    MAP[ai][aj] = -2;
                    point++;
                }
            }
        }
    }

    return point * point;
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

    int result = 0;

    while (true)
    {
        int add = RemoveBlock();
        if (add == 0)
            break;
        result += add;

        Gravity();

        Rotation(3);

        Gravity();

       // cout << result << endl;
    }

    cout << result << endl;

    return 0;
}