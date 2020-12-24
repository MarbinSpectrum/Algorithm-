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

int Dice[4][6];
char Color[4] = { 'R','G','B','Y' };
set<int> Pillar;
int DiceData[4][6][4][4];
int DiceD(int n, int face, int t,int a)
{
    if (DiceData[n][face][t][a] != -1)
        return DiceData[n][face][t][a];
    DiceData[n][face][t][a] = 0;
    if (face == 0)
    {
        if ((a + t) % 4 == 0)
            return DiceData[n][face][t][a] = Dice[n][5];
        if ((a + t) % 4 == 1)
            return DiceData[n][face][t][a] = Dice[n][1];
        if ((a + t) % 4 == 2)
            return DiceData[n][face][t][a] = Dice[n][4];
        if ((a + t) % 4 == 3)
            return DiceData[n][face][t][a] = Dice[n][3];
    }
    if (face == 1)
    {
        if ((a + t) % 4 == 0)
            return DiceData[n][face][t][a] = Dice[n][5];
        if ((a + t) % 4 == 1)
            return DiceData[n][face][t][a] = Dice[n][2];
        if ((a + t) % 4 == 2)
            return DiceData[n][face][t][a] = Dice[n][4];
        if ((a + t) % 4 == 3)
            return DiceData[n][face][t][a] = Dice[n][0];
    }
    if (face == 2)
    {
        if ((a + t) % 4 == 0)
            return DiceData[n][face][t][a] = Dice[n][4];
        if ((a + t) % 4 == 1)
            return DiceData[n][face][t][a] = Dice[n][1];
        if ((a + t) % 4 == 2)
            return DiceData[n][face][t][a] = Dice[n][5];
        if ((a + t) % 4 == 3)
            return DiceData[n][face][t][a] = Dice[n][3];
    }
    if (face == 3)
    {
        if ((a + t) % 4 == 0)
            return DiceData[n][face][t][a] = Dice[n][0];
        if ((a + t) % 4 == 1)
            return DiceData[n][face][t][a] = Dice[n][4];
        if ((a + t) % 4 == 2)
            return DiceData[n][face][t][a] = Dice[n][2];
        if ((a + t) % 4 == 3)
            return DiceData[n][face][t][a] = Dice[n][5];
    }
    if (face == 4)
    {
        if ((a + t) % 4 == 0)
            return DiceData[n][face][t][a] = Dice[n][0];
        if ((a + t) % 4 == 1)
            return DiceData[n][face][t][a] = Dice[n][1];
        if ((a + t) % 4 == 2)
            return DiceData[n][face][t][a] = Dice[n][2];
        if ((a + t) % 4 == 3)
            return DiceData[n][face][t][a] = Dice[n][3];
    }
    if (face == 5)
    {
        if ((a + t) % 4 == 0)
            return DiceData[n][face][t][a] = Dice[n][2];
        if ((a + t) % 4 == 1)
            return DiceData[n][face][t][a] = Dice[n][1];
        if ((a + t) % 4 == 2)
            return DiceData[n][face][t][a] = Dice[n][0];
        if ((a + t) % 4 == 3)
            return DiceData[n][face][t][a] = Dice[n][3];
    }
}

int topColor;

bool flag[4][4];
int num = 0;

void DataAdd(int AA, int a, int b, int BB, int c, int d, int CC, int e, int f, int DD, int g, int h)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            flag[i][j] = false;

    for (int i = 0; i < 4; i++)
    {
        flag[i][DiceD(AA, a, b, i) - 1] = true;
        flag[i][DiceD(BB, c, d, i) - 1] = true;
        flag[i][DiceD(CC, e, f, i) - 1] = true;
        flag[i][DiceD(DD, g, h, i) - 1] = true;
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (!flag[i][j])
                return;

    //돌리기
    for (int k = 0; k < 4; k++)
    {
        int temp = 0;
        int ten = 1;
        for (int i = 0; i < 4; i++)
        {
            temp += DiceD(AA, a, b, (i + k) % 4) * ten;
            ten *= 10;
            temp += DiceD(BB, c, d, (i + k) % 4) * ten;
            ten *= 10;
            temp += DiceD(CC, e, f, (i + k) % 4) * ten;
            ten *= 10;
            temp += DiceD(DD, g, h, (i + k) % 4) * ten;
            ten *= 10;
        }

        temp += topColor * ten;

        if (Pillar.find(temp) != Pillar.end())
            return;
        if (k == 3)
            Pillar.insert(temp);
    }

    num++;

}

void Solution()
{
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            for (int c = 0; c < 6; c++)
            {
                for (int d = 0; d < 4; d++)
                {
                    for (int e = 0; e < 6; e++)
                    {
                        for (int f = 0; f < 4; f++)
                        {
                            for (int g = 0; g < 6; g++)
                            {
                                for (int h = 0; h < 4; h++)
                                {
                                    topColor = Dice[3][g];
                                    DataAdd(0, a, b, 1, c, d, 2, e, f, 3, g, h);
                                }
                            }
                        }
                    }

                }
            }

        }
    }
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init(DiceData, -1);

    for (int i = 0; i < 4; i++)
    {
        string c;
        cin >> c;
        for (int j = 0; j < 6; j++)
            for (int k = 1; k <= 4; k++)
            {
                if (c[j] == Color[k - 1])
                {
                    Dice[i][j] = k;
                    break;
                }
            }
    }

    Solution();

    cout << num << endl;



    

}

