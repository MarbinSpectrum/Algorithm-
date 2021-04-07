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

struct Data
{
    string name;
    int a, b;
    float c;
    Data(string aname, int aa, int ab, float ac) : name(aname), a(aa), b(ab), c(ac) {};
};
int P;
float V;
vector<Data> Arr0;

float FA = 253;
vector<Data> Arr1;

bool cmp(pair<string, int> A, pair<string, int> B)
{
    if (A.second != B.second)
        return A.second > B.second;
    else
        return A.first.compare(B.first) < 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> P >> V;
    for (int i = 0; i < P; i++)
    {
        string a;
        float b;
        float c;
        cin >> a >> b >> c;   
        FA -= b;
        Arr0.push_back(Data(a, b, c, 0));
    }
    
    float Sum = 0;
    int R = FA;
    for (int i = 0; i < Arr0.size(); i++)
        Sum += Arr0[i].b;
    for (int i = 0; i < Arr0.size(); i++)
        Arr0[i].c = Arr0[i].b / Sum;
    for (int i = 0; i < Arr0.size(); i++)
        if (Arr0[i].a >= 5 || Arr0[i].c >= 0.03f)
            Arr1.push_back(Arr0[i]);
        else
            R += Arr0[i].a;

    Sum = 0;
    for (int i = 0; i < Arr1.size(); i++)
        Sum += Arr1[i].b;
    for (int i = 0; i < Arr1.size(); i++)
        Arr1[i].c = Arr1[i].b / Sum;

    Sum = 0;
    vector<int> S1(Arr1.size());
    for (int i = 0; i < Arr1.size(); i++)
    {
        float s = ((300 - R) * Arr1[i].c - Arr1[i].a) / (float)2;
        S1[i] = max((int)0, (int)round(s));
        Sum += S1[i];
    }

    vector<int> S2(Arr1.size());
    {
        int a = 30;
        vector<pair<float, int>> b;
        if (Sum < 30)
        {
            for (int i = 0; i < Arr1.size(); i++)
            {
                float temp = (float)S1[i] + ((float)30 - (float)Sum) * Arr1[i].c;
                b.push_back({ temp,i });
                a -= (int)temp;
                S2[i] = (int)temp;
            }
        }
        else if (Sum > 30)
        {
            for (int i = 0; i < Arr1.size(); i++)
            {
                float temp = (float)30 * (float)S1[i] / (float)(Sum);
                b.push_back({ temp,i });
                a -= (int)temp;
                S2[i] = (int)temp;
            }     
        }

        while (a > 0)
        {
            for (int i = 0; i < b.size(); i++)
                b[i].first -= (int)b[i].first;
            for (int i = 0; i < b.size(); i++)
                b[i].first *= -10;
            sort(b.begin(), b.end());
            for (int i = 0; i < b.size(); i++)
                b[i].first *= -1;
            for (int i = 0; i < b.size(); i++)
            {
                if (a > 0)
                {
                    S2[b[i].second]++;
                    a--;
                }
                else
                    break;
            }
        }
    }

    vector<int> P3(Arr1.size());
    {
        int a = 17;
        vector<pair<float, int>> b;
        for (int i = 0; i < Arr1.size(); i++)
        {
            float temp = (float)17 * (float)Arr1[i].c;
            b.push_back({ temp,i });
            a -= (int)temp;
            P3[i] = (int)temp;
        }
        
        while (a > 0)
        {
            for (int i = 0; i < b.size(); i++)
                b[i].first -= (int)b[i].first;
            for (int i = 0; i < b.size(); i++)
                b[i].first *= -10;
            sort(b.begin(), b.end());
            for (int i = 0; i < b.size(); i++)
                b[i].first *= -1;
            for (int i = 0; i < b.size(); i++)
            {
                if (a > 0)
                {
                    P3[b[i].second]++;
                    a--;
                }
                else
                    break;
            }
        }
    }

    vector<pair<string, int>> Result;
    for (int i = 0; i < Arr0.size(); i++)
        Result.push_back({ Arr0[i].name, Arr0[i].a });

    for (int i = 0; i < Result.size(); i++)
    {
        int a = -1;
        for(int j = 0; j < Arr1.size(); j++)
            if (Arr1[j].name.compare(Result[i].first) == 0)
            {
                a = j;
                break;
            }
        if (a == -1)
            continue;
        Result[i].second += S2[a] + P3[a];
    }

    sort(Result.begin(), Result.end(), cmp);

    for (int i = 0; i < Result.size(); i++)
        Debug(Result[i].first, Result[i].second);



}