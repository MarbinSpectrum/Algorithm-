#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e10;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N;
void F()
{
    std::cin >> N;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++)
        std::cin >> A[i].second;
    for (int i = 0; i < N; i++)
        std::cin >> A[i].first;
   
    for (int i = 0; i < N; i++)
        A[i].first = -A[i].first;
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++)
        A[i].first = -A[i].first;

    int t = 0;
    int et = 0;
    for(int i = 0; i < N; i++)
    {
        t += A[i].second;
        et = max(et, t + A[i].first);
    }

    std::cout << et << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    std::cin >> C;
    while (C--)
    {
        F();
    }

}