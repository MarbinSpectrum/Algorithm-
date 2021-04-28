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

int N, L;
int MAP[100][100];
int MAPtemp[100][100];
int A[100][100];


void S()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            MAPtemp[j][i] = MAP[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            MAP[i][j] = MAPtemp[i][j];

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        cout << MAP[i][j] << " ";
    //    cout << endl;
    //}
}


int GetData()
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int f = MAP[i][0];
        bool flag = true;
        for (int j = 0; j < N; j++)
            A[i][j] = false;

        for (int j = 1; j < N; j++)
        {
            if (f == MAP[i][j])
                continue;
            if (abs(f - MAP[i][j]) > 1)
            {
                flag = false;
                break;
            }

            if (f > MAP[i][j])
            {
                for (int k = j; k < j + L; k++)
                    if (MAP[i][j] != MAP[i][k] || A[i][k])
                    {
                        flag = false;
                        break;
                    }

                if (flag)
                    for (int k = j; k < j + L; k++)
                        A[i][k] = true;

                f = MAP[i][j];
            }
            else if (f < MAP[i][j])
            {
                for (int k = j - 1; k > j - 1 - L; k--)
                    if (k < 0 || MAP[i][j - 1] != MAP[i][k] || A[i][k])
                    {
                        flag = false;
                        break;
                    }

                if (flag)
                    for (int k = j - 1; k > j - 1 - L; k--)
                        A[i][k] = true;

                f = MAP[i][j];
            }

            if (!flag)
                break;
        }
        if (flag)
        {
            //cout << i << endl;
            result++;
        }


    }

    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];

    int a = GetData();
    S();
    int b = GetData();
    //Debug(a, b);
    cout << a + b << endl;



    return 0;
}