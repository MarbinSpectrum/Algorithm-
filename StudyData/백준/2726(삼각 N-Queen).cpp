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

int T,N;

bool Check[1001][1001];
bool A[1001];
bool B[1001];
bool C[1001];

vector<pair<int, int>> Result;

void DFS(int ar,int num)
{
    if (num == floor((2 * N + 1) / 3))
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j <= i; j++)
                if (Check[i][j])
                    Result.push_back({ i + 1,j + 1 });

        return;
    }


    for (int r = ar; r < N; r++)
        for (int c = 0; c <= r; c++)
            if (!A[r] && !B[c] && !C[r - c])
            {
                Check[r][c] = true;
                A[r] = true;
                B[c] = true;
                C[r - c] = true;
                if (Result.size() <= 0)
                    DFS(r + 1, num + 1);
                Check[r][c] = false;
                A[r] = false;
                B[c] = false;
                C[r - c] = false;
            }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;

        Result.clear();
        DFS(0, 0);

        cout << Result.size() << endl;
        for (int i = 0; i < Result.size(); i++)
            Debug(Result[i].first, Result[i].second);

    }

}
