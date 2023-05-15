#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e18;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N, Q;
int T[1000001];
int V[1000001];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int S, E;
        std::cin >> S >> E;
        T[S]++;
        T[E+1]--;
    }
    for (int i = 1; i <= 1000000; i++)
    {
        V[i] = V[i - 1];
        V[i] += T[i];
    }
    std::cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int a;
        std::cin >> a;
        std::cout << V[a] << endl;
    }
}