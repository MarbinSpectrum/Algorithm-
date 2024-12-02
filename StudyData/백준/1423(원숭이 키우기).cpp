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

int N, D;
vector<int> Arr;
vector<int> P;
vector<int> NewArr;
int DP[200][70000];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        std::cin >> a;
        Arr.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        std::cin >> a;
        P.push_back(a);
    }
    std::cin >> D;

    for (int i = 0; i < N; i++)
    {
        int a = min(Arr[i], D);
        for (int j = 0; j < a; j++)
            NewArr.push_back(i);
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += Arr[i] * P[i];

    for (int i = 0; i < 70000; i++)
        for (int j = 0; j < 200; j++)
            DP[j][i] = sum;

    int res = DP[0][0];
    for (int day = 0; day < D; day++)
    {
        for (int i = NewArr.size() - 1; i >= 0; i--)
        {
            for (int j = NewArr[i]; j < N; j++)
            {
                int useDay = j - NewArr[i];
                if (day + useDay > D)
                    continue;
                DP[day + useDay][i] = max(DP[day + useDay][i], DP[day][i + 1] + P[j] - P[NewArr[i]]);
                res = max(res, DP[day + useDay][i]);
            }
        }
    }

    std::cout << res << endl;
}
