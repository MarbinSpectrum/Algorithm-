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

int N, M;
int Arr[1000][1000];
int DP[1000][1000];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    std::cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> Arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0)
            {
                DP[i][j] = Arr[i][j];
            }
            else
            {
                int v = INF;
                for (int k = 0; k < M; k++)
                {
                    if (k == j)
                        continue;
                    v = min(v, DP[i - 1][k]);
                }
                DP[i][j] = v + Arr[i][j];
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < M; i++)
        ans = min(ans, DP[N - 1][i]);
    std::cout << ans << endl;
}