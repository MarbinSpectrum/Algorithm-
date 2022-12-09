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

const int MOD = 1000000007;
string numSort;
string num = "2023";

int n, m;
int DP[1<<16][2][21];
int Ans(int bit, bool less, int mod)
{
    if (DP[bit][less][mod] != -1)
        return DP[bit][less][mod];

    int& ret = DP[bit][less][mod];
    ret = 0;

    int oneCnt = 0;
    for (int i = 0; i < n; i++)
        if ((bit & (1 << i)))
            oneCnt++;

    if (oneCnt == n)
    {
        if (mod == 0 && less)
            return ret = 1;
        else
            return ret = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if ((bit & (1 << i)))
            continue;
        if (i == 0 || numSort[i] != numSort[i - 1] || (bit & (1 << (i - 1))))
        {
            int newMod = (mod * 10 + (numSort[i] - '0')) % m;
            if (num[oneCnt] > numSort[i] || less)
                ret = (ret + Ans(bit | (1 << i), true, newMod)) % MOD;
            else  if (num[oneCnt] == numSort[i])
                ret = (ret + Ans(bit | (1 << i), false, newMod)) % MOD;
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
        std::cin >> num;
        numSort = num;
        sort(numSort.begin(), numSort.end());
        n = num.length();

        std::cin >> m;

        for(int i = 0; i < (1<<16); i++)
            for (int j = 0; j < 21; j++)
            {
                DP[i][0][j] = -1;
                DP[i][1][j] = -1;
            }

        std::cout << Ans(0, false, 0) << endl;
    }
    
}