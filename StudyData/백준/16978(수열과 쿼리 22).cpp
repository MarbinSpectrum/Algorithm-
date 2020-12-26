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

int N, M;
vector<int> SegTree;
int Arr[100001];

void InitSeg(int node, int left, int right)
{
    //cout << node << endl;
    //Debug(left, right);
    if (left == right)
        SegTree[node] = Arr[left];
    else
    {
        int mid = (left + right) / 2;
        InitSeg(node * 2, left, mid);
        InitSeg(node * 2 + 1, mid + 1, right);
        SegTree[node] = SegTree[node * 2] + SegTree[node * 2 + 1];
    }
}

void Change(int node, int left, int right, int changeIndex, int diff)
{
    if (changeIndex < left || changeIndex > right)
        return;
    SegTree[node] += diff;
    if (left == right)
        Arr[left] += diff;
    else
    {
        int mid = (left + right) / 2;
        Change(node * 2, left, mid, changeIndex, diff);
        Change(node * 2 + 1, mid + 1, right, changeIndex, diff);
    }
}

int GetSum(int node, int left, int right, int s, int e)
{
    if (right < s || left > e)
        return 0;
    if (s <= left && right <= e)
        return  SegTree[node];
    int mid = (left + right) / 2;
    return GetSum(node * 2, left, mid, s, e) + GetSum(node * 2 + 1, mid + 1, right, s, e);
}
vector<pair<int, int>> Query1;
vector<pair<int, tuple<int, int, int>>> Query2;

bool Cmp(pair<int, tuple<int, int, int>> AA, pair<int, tuple<int, int, int>> BB)
{
    return (AA.first < BB.first);
}

int Result[100000];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> Arr[i];
    SegTree.resize(300000);
    InitSeg(1, 1, N);
    cin >> M;
    int qOrder = 0;

    for (int i = 0; i < M; i++)
    {
        int a, b, c, d;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            Query1.push_back({ b,c });
        }
        else
        {
            cin >> b >> c >> d;
            Query2.push_back({ b,{c,d,qOrder++} });
        }
    }

    sort(Query2.begin(), Query2.end(), Cmp);

    int q2 = 0;


    for (int i = 0; i <= Query1.size(); i++)
    {
        while (q2 < Query2.size() && Query2[q2].first == i)
        {
            int a = get<0>(Query2[q2].second);
            int b = get<1>(Query2[q2].second);
            int c = get<2>(Query2[q2].second);
            Result[c] = GetSum(1, 1, N, a, b);
            //cout << Query2[q2].first << endl;
            //Debug(get<0>(Query2[q2].second), get<1>(Query2[q2].second));
            //cout << Result[c] << endl;
            q2++;
        }

        if(i < Query1.size())
        {
            int a = Query1[i].first;
            int b = Query1[i].second;
            int diff = b - Arr[a];
            Change(1, 1, N, a, diff);
        }
    }

    for (int i = 0; i < q2; i++)
        cout << Result[i] << endl;

}

