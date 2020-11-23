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

int N, M;
char MAP[30][30];

//현재 X //현재 4판 //현재점수
bool DP[26][1024][1001];
int Result = 0;
int GetBit(int b)
{
    return 1 << b;
}
void D(int r, int nowBit,int nowP)
{
    //cout << r << " = ";
    //Debug(nowBit, nowP);
    if (r >= M)
    {
        Result = max(Result, nowP);
        return;
    }

    if (DP[r][nowBit][nowP])
        return;
    DP[r][nowBit][nowP] = true;

    for (int bit = 0; bit < (1 << N); bit++)
    {
        bool flag = false;
        int Point1 = 0;
        int Point4 = 0;
        int Defalut_Point4 = 0;
        for (int b = 0; b < N; b++)
        {
            //위 아래를 확인해서 4를 배치할수있는지 검사
            if ((bit & GetBit(b)) && ((b > 0 && (bit & GetBit(b - 1))) || (b < N - 1 && (bit & GetBit(b + 1)))))
            {
                flag = true;
                break;
            }
            //전 상태를 확인해서 4를 배치할수있는지 검사
            if ((bit & GetBit(b)) && ((b > 0 && (nowBit & GetBit(b - 1))) || (nowBit & GetBit(b)) || (b < N - 1 && (nowBit & GetBit(b + 1)))))
            {
                flag = true;
                break;
            }
            //이미 깔려진 1을 확인해서 4를 4를 배치할수있는지 검사
            if ((bit & GetBit(b)) && (MAP[b][r] == '1' || MAP[b][r + 1] == '1' || MAP[b + 1][r] == '1' || MAP[b + 1][r + 1] == '1'))
            {
                flag = true;
                break;
            }

            if (MAP[b][r] == '1')
                Defalut_Point4 += 1;
            else if (bit & GetBit(b))
                Point4 += 16;
            else
            {
                if (b > 0)
                {
                    if (bit & GetBit(b - 1))
                        continue;
                    if (nowBit & GetBit(b - 1))
                        continue;
                }
                if (nowBit & GetBit(b))
                    continue;
                Point1 += 1;
            }
            //if (bit == 8)
            //{

            //    cout << "8 : " << Defalut_Point4 << " ";
            //    Debug(Point1, Point4);
            //}
        }
        if (flag)
            continue;
        //cout << "P : " << Defalut_Point4 << " ";
        //Debug(Point1, Point4);

        D(r + 1, bit, nowP + Point1 + Point4 + Defalut_Point4);
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int r = 0; r < 30; r++)
        for (int c = 0; c < 30; c++)
            MAP[r][c] = '1';
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> MAP[r][c];

    for (int bit = 0; bit < (1 << N); bit++)
    {
        bool flag = false;
        int Point = 0;
        for (int b = 0; b < N; b++)
        {
            if ((bit & GetBit(b)) && ((b > 0 && (bit & GetBit(b - 1))) || (b < N - 1 && (bit & GetBit(b + 1)))))
            {
                flag = true;
                break;
            }
            if ((bit & GetBit(b)) && (MAP[b][0] == '1' || MAP[b][1] == '1' || MAP[b + 1][0] == '1' || MAP[b + 1][1] == '1'))
            {
                flag = true;
                break;
            }

            if(MAP[b][0] == '1')
                Point += 1;
            else if (bit & GetBit(b))
                Point += 16;
            else if (!(bit & GetBit(b)) && !(bit & GetBit(b - 1)))
                Point += 1;
        }

        if (flag)
            continue;
        D(1, bit, Point);

    }

    cout << Result << endl;

}
