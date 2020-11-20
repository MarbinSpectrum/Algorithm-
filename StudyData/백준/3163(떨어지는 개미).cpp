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

int T;
int N, L, k;
vector<pair<int, int>> Ant;
vector<pair<int, int>> FallData;
vector<int> Result;

//bool cmp(const pair<int, int> A, const pair<int, int> B)
//{
//    if (A.first == B.first)
//        return abs(A.second) < abs(B.second);
//    else
//        return A.first < B.first;
//}

int Sign(int n)
{
    if (n < 0)
        return -1;
    else if (n > 0)
        return +1;
    else
        return +0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> N >> L >> k;
        Ant.clear();
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            Ant.push_back({ a,b });
        }

        FallData.clear();
        for (int i = 0; i < Ant.size(); i++)
        {
            if (Ant[i].second > 0)
                FallData.push_back({ abs(L - Ant[i].first) + 1,Sign(Ant[i].second) });
            else
                FallData.push_back({ abs(0 - Ant[i].first) + 1,Sign(Ant[i].second) });
        }
        sort(FallData.begin(), FallData.end());

        //for (int i = 0; i < N; i++)
        //{
        //    cout << "[ ";
        //    Debug(FallData[i].first, FallData[i].second);
        //}

        Result.clear();
        int a = 0;
        int b = Ant.size() - 1;

        for (int i = 0; i < FallData.size(); i++)
        {
            if (i + 1 < N && FallData[i].first == FallData[i + 1].first)
            {
                if (Ant[a].second < Ant[b].second)
                {
                    Result.push_back(Ant[a++].second);
                    Result.push_back(Ant[b--].second);
                }
                else
                {
                    Result.push_back(Ant[b--].second);
                    Result.push_back(Ant[a++].second);
                }
                i++;
            }
            else if (FallData[i].second < 0)
                Result.push_back(Ant[a++].second);
            else
                Result.push_back(Ant[b--].second);
        }
        //for (int i = 0; i < Result.size(); i++)
        //    cout << Result[i] << endl;
        cout << Result[k - 1] << endl;

    }

}
