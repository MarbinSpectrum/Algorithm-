//#ifndef _GLIBCXX_NO_ASSERT 
//#include <cassert> 
//#endif #include <cctype>
//#include <cerrno> 
//#include <cfloat> 
//#include <ciso646> 
//#include <climits> 
//#include <clocale> 
//#include <cmath> 
//#include <csetjmp> 
//#include <csignal>
//#include <cstdarg> 
//#include <cstddef>
//#include <cstdio> 
//#include <cstdlib> 
//#include <cstring> 
//#include <ctime> 
//
//#if __cplusplus >= 201103L 
//#include <ccomplex> 
//#include <cfenv> 
//#include <cinttypes> 
//#include <cstdalign> 
//#include <cstdbool>
//#include <cstdint> 
//#include <ctgmath>
//#include <cwchar> 
//#include <cwctype>
//#endif 
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
//#if __cplusplus >= 201103L 
//#include <array> 
//#include <atomic> 
//#include <chrono> 
//#include <condition_variable> 
//#include <forward_list> 
//#include <future> 
//#include <initializer_list> 
//#include <mutex> 
//#include <random> 
//#include <ratio>
//#include <regex> 
//#include <scoped_allocator> 
//#include <system_error> 
//#include <thread> 
//#include <tuple> 
//#include <typeindex> 
//#include <type_traits> 
//#include <unordered_map> 
//#include <unordered_set> 
//#endif

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float double
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int Ceil(double n)
{
    if (n - (int)(n) > 0)
        return (int)n + 1;
    else
        return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

vector<pair<int, int>> Arr;
deque<pair<pair<int, int>,pair<int,int>>> Pos;
bool Cmp1(pair<int, int> A, pair<int, int> B)
{
    if (A.second != B.second)
        return A.second < B.second;
    return A.first < B.first;
}

bool Cmp2(pair<pair<int, int>, pair<int, int>> A, pair<pair<int, int>, pair<int, int>> B)
{
    pair<int, int> A_Pos = A.first;
    pair<int,int> A_Angle = A.second;

    pair<int, int> B_Pos = B.first;
    pair<int, int> B_Angle = B.second;
    if (A_Angle.second * B_Angle.first != A_Angle.first * B_Angle.second)
        return A_Angle.second * B_Angle.first < A_Angle.first * B_Angle.second;

    if (A_Pos.second != B_Pos.second)
        return A_Pos.second < B_Pos.second;

    return A_Pos.first < B_Pos.first;

}

int CCW(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    return A.first * B.second + B.first * C.second + C.first * A.second - B.first * A.second - C.first * B.second - A.first * C.second;
}

int N;

float Distance(pair<int, int> A, pair<int, int> B)
{
    return sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        Arr.push_back({ a,b });
    }

    sort(Arr.begin(), Arr.end(), Cmp1);

    for (int i = 1; i < N; i++)
        Pos.push_back({ Arr[i],{ Arr[i].first - Arr[0].first, Arr[i].second - Arr[0].second} });

    sort(Pos.begin(), Pos.end(), Cmp2);
    Pos.push_front({ Arr[0],{0,0} });

    stack<int> OutLine;

    for (int i = 0; i < Pos.size(); i++)
    {
        while (OutLine.size() >= 2)
        {
            int B = OutLine.top();
            OutLine.pop();
            int A = OutLine.top();

            if (CCW(Pos[A].first, Pos[B].first, Pos[i].first) > 0)
            {
                OutLine.push(B);
                break;
            }
        }
        OutLine.push(i);
    }

    vector<pair<int, int>> Result_Arr;
    while (OutLine.size())
    {
        pair<int, int> A = Pos[OutLine.top()].first;
        OutLine.pop();
        Result_Arr.push_back(A);
    }

    float Result = 0;
    for (int i = 0; i < Result_Arr.size(); i++)
        for (int j = 0; j < Result_Arr.size(); j++)
            Result = max(Result, Distance(Result_Arr[i], Result_Arr[j]));
    cout << fixed;
    cout.precision(8);
    cout << Result << endl;

}