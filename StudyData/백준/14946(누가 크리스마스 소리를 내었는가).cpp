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

int V, Q, K;
vector<int> A[1001];
int R[1001];
int G[1001];
int B[1001];
bool nowChild[1001][4];
vector<int> ChildK[1001][4];

vector<int> Sum(vector<int> temp0, vector<int> temp1)
{
    vector<int> temp(10);
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            if (temp0[a] > 0 && temp1[b] > 0)
                temp[(a + b) % K] += (temp0[a] * temp1[b])%Q;
    return temp;
}

vector<int> Add(vector<int> temp0, vector<int> temp1)
{
    for (int a = 0; a < 10; a++)
    {
        temp0[a] += temp1[a];
        temp0[a] %= Q;
    }
    return temp0;
}

vector<int> CK(int par, int now,int color)
{
    if (nowChild[now][color] != false)
        return ChildK[now][color];
    nowChild[now][color] = true;
    vector<int> temp(10);

    bool flag = false;
    bool emp = true;
    for (int i = 0; i < A[now].size(); i++)
    {
        int next = A[now][i];
        if (par == next)
            continue;
        flag = true;
        vector<int> temp2(10);
        if (color == 0)
        {
            temp2 = CK(now, next, 0);
            vector<int> temp1 = CK(now, next, 1);
            temp2 = Add(temp2, temp1);

        }
        else  if (color == 1)
        {
            temp2 = CK(now, next, 0);
            vector<int> temp1 = CK(now, next, 2);
            temp2 = Add(temp2, temp1);
        }
        else  if (color == 2)
        {
            temp2 = CK(now, next, 1);
        }

        if (emp)
        {
            emp = false;
            temp = temp2;
        }
        else
        {
            temp = Sum(temp, temp2);
        }
    }

    if (emp)
    {
        //빨강
        if (color == 0)
            temp[R[now] % K] += 1;
        //초록
        else if (color == 1)
            temp[G[now] % K] += 1;
        //파랑
        else if (color == 2)
            temp[B[now] % K] += 1;
    }
    else
    {
        vector<int> temp1(10);
        for (int i = 0; i < 10; i++)
            if (temp[i] > 0)
            {
                //빨강
                if (color == 0)
                    temp1[(R[now] + i) % K] = temp[i];
                //초록
                else if (color == 1)
                    temp1[(G[now] + i) % K] = temp[i];
                //파랑
                else if (color == 2)
                    temp1[(B[now] + i) % K] = temp[i];

            }

        for (int i = 0; i < 10; i++)
            temp[i] = temp1[i];

    }

    ChildK[now][color] = temp;

    return temp;
}

int D(int now, int color)
{
    vector<int> temp = CK(0, now, color);  
    return temp[0];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> Q >> K;
    for (int i = 0; i < V - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    for (int i = 1; i <= V; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        R[i] = a;
        G[i] = b;
        B[i] = c;
    }

    cout << ((D(1, 0) + D(1, 1)) % Q + D(1, 2)) % Q << endl;

}