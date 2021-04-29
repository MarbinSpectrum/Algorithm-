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

int N;
int MAP[20][20];
bool Visit[20][20];

int fishLv = 2;
int fishExp = 0;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];

    int t = 0;
    while (true)
    {
        pair<int, int> FindShark;
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (MAP[i][j] == 9)
                        FindShark = { i,j };
        }

        vector<tuple<int, int, int>> FoodData; //°Å¸®//r//c
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    Visit[i][j] = false;

            queue<tuple<int, int, int>> Queue;
            Queue.push({ 0,FindShark.first,FindShark.second });
            Visit[FindShark.first][FindShark.second] = true;

            while (!Queue.empty())
            {
                tuple<int, int, int> temp = Queue.front();

                if (MAP[get<1>(temp)][get<2>(temp)] < fishLv && 1 <= MAP[get<1>(temp)][get<2>(temp)] && MAP[get<1>(temp)][get<2>(temp)] <= 6)
                {
                    int dis = get<0>(temp);
                    FoodData.push_back({ dis ,get<1>(temp),get<2>(temp) });
                }

                Queue.pop();

                for (int i = 0; i < 4; i++)
                {
                    int ar = get<1>(temp) + Dic[i][0];
                    int ac = get<2>(temp) + Dic[i][1];
                    if (ar < 0 || ac < 0 || ar >= N || ac >= N)
                        continue;
                    if (Visit[ar][ac])
                        continue;
                    if (MAP[ar][ac] > fishLv)
                        continue;

                    Queue.push({ get<0>(temp) + 1,ar,ac });
                    Visit[ar][ac] = true;
                }
            }
        }

        {
            if (FoodData.size() <= 0)
                break;
        }

        {
            sort(FoodData.begin(), FoodData.end());

            int ar = get<1>(FoodData[0]);
            int ac = get<2>(FoodData[0]);
            MAP[ar][ac] = 9;
            MAP[FindShark.first][FindShark.second] = 0;

            t += get<0>(FoodData[0]);

            fishExp++;
            while (fishExp >= fishLv)
            {
                fishExp -= fishLv;
                fishLv++;
            }
        }
    }

    cout << t << endl;

    return 0;
}