#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
//#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e10;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int F()
{
    int n, m;
    std::cin >> n >> m;
    vector<int> Price;
    vector<int> Pref;
    m /= 100;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a /= 100;
        Price.push_back(a);
        Pref.push_back(b);
    }

    vector<int> DP(201);

    int result = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n; j++)
            if (i - Price[j] >= 0)
            {
                DP[i % 201] = max(DP[i % 201], DP[(i - Price[j]) % 201] + Pref[j]);
                result = max(result,DP[i % 201]);
            }

    return result;
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
        std::cout << F() << endl;
    }

}