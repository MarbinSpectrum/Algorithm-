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

int N, K;
vector<pair<int, int>> user;

int DP[300000];
int GetValue(int l, int r)
{
    if (l < 0 || r > N)
        return 0;
    int res = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            for (int k = j + 1; k <= r; k++)
            {
                int minRequire = min({ user[i].second, user[j].second, user[k].second});
                int maxRequire = max({ user[i].second, user[j].second, user[k].second });

                if (abs(minRequire - maxRequire) > K)
                    continue;
                res = max(res, user[i].first + user[j].first + user[k].first);
            }
        }
    }

    return res;
}
int Dp(int i)
{
    if (i < 0)
        return 0;
    if (DP[i] != -1)
        return DP[i];
    DP[i] = 0;
    for (int j = i - 6; j <= i - 3; j++)
        DP[i] = max(DP[i], Dp(j) + GetValue(j + 1, i));
    return DP[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        user.push_back({ b,a });
        DP[i] = -1;
    }

    sort(user.begin(), user.end());
    for (int i = 0; i < N; i++)
        swap(user[i].first, user[i].second);

    std::cout << Dp(N - 1) << endl;
}
