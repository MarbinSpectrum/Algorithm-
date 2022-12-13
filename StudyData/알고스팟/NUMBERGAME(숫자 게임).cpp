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
int Arr[50];
int DP[50][50][2];
int Dp(int l, int r,int t)
{
    if (l > r)
    {
        return 0;
    }

    int& ret = DP[l][r][t];
    if (ret != INF)
    {
        return ret;
    }

    if (l == r)
    {
        ret = 0;
        if (t == 0)
            ret += Arr[l];
        else
            ret -= Arr[l];
    }
    else if (r - l >= 1)
    {
        if (t == 0)
        {
            ret = -INF;
            ret = max(ret, Dp(l, r - 1, 1) + Arr[r]);
            ret = max(ret, Dp(l + 1, r, 1) + Arr[l]);
            ret = max(ret, Dp(l + 2, r, 1));
            ret = max(ret, Dp(l, r - 2, 1));
        }
        else
        {
            ret = INF;
            ret = min(ret, Dp(l, r - 1, 0) - Arr[r]);
            ret = min(ret, Dp(l + 1, r, 0) - Arr[l]);
            ret = min(ret, Dp(l + 2, r, 0));
            ret = min(ret, Dp(l, r - 2, 0));
        }
    }

    return ret;
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
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                DP[i][j][0] = INF;
                DP[i][j][1] = INF;
            }
        }

        std::cin >> N;
        for (int i = 0; i < N; i++)
        {
            std::cin >> Arr[i];
        }

        std::cout << Dp(0, N - 1, 0) << endl;
    }

}