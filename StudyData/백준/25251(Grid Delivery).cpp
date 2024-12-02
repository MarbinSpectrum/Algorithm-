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

int h, w;
char M[3000][3000];
vector<int> tree[3000];

void update(int i,int x,int v)
{
    while (x < tree[i].size())
    {
        tree[i][x] += v;
        x += (x & -x);
	}
}

int sum(int i, int x) 
{
    int ans = 0;
    while (x > 0) {
        ans += tree[i][x];
        x -= (x & -x);
    }
    return ans;
}

void printM()
{
    std::cout << endl;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            std::cout << M[i][j];
        }
        std::cout << endl;
    }
    std::cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> h >> w;
    for (int i = 1; i <= w; i++)
        tree[i].resize(h + 1);

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char a;
            std::cin >> a;
            M[i][j] = a;
            if (a == 'C')
                update(j, i, 1);
        }
    }

    int res = 0;

    for (int i = 1; i <= w; i++)
    {
        bool useLine = false;
        int x = i;
        int y = 1;

        while (x <= w && y <= h)
        {
            int tempA = sum(x, h);
            int tempB = sum(x, y - 1);
            int countC = tempA - tempB;
            if (countC == 0)
            {
                if (x < w)
                    x++;
                else if (y < h)
                    y++;
                else
                    break;
            }

            while (countC > 0)
            {
                if (M[y][x] == 'C')
                {
                    useLine = true;
                    M[y][x] = '_';
                    countC--;
                    update(x, y, -1);
                }

                if (countC == 0)
                {
                    x++;
                    break;
                }
                else
                    y++;
            }
        }

        if (useLine)
            res++;
    }

    std::cout << res << endl;
}
