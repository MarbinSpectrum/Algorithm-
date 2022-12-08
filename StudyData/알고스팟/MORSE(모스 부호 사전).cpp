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

int bino[205][205];
int C;

void Fun(int n, int m, int k)
{
    if (n == 0 && m == 0)
        return;

    int pBino = bino[n + m - 1][m];
    if (k > pBino)
    {
        std::cout << "o";
        Fun(n, m - 1, k - pBino);
    }
    else
    {
        std::cout << "-";
        Fun(n - 1, m, k);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bino[0][0] = 1;
    for (int i = 1; i <= 204; i++)
        for (int j = 0; j <= i; j++)
        {
            bino[i][j] = bino[i-1][j] + ((j - 1 >= 0) ? bino[i - 1][j - 1] : 0);
            bino[i][j] = min(bino[i][j], (int)1000000000+100); //어차피 k보다 큰지만 확인하면된다.
        }

    std::cin >> C;
    while (C--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;
        Fun(n, m, k);
        std::cout << endl;
    }
}