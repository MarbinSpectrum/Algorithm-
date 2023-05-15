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

int N,K;
vector<pair<int, int>> Arr;
int ans = 0;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        std::cin >> x >> y;
        Arr.push_back({ x,y });
    }
    int s = 1;
    int e = 30000000000;
    while (s <= e)
    {
        int m = (s + e) / 2;
        bool find = false;
        for (int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int sx = Arr[i].first - 1;
                int sy = Arr[j].second - 1;
                int ex = Arr[i].first + m - 1;
                int ey = Arr[j].second + m - 1;
                int point = 0;

                for (int k = 0; k < N; k++)
                {
                    if ((sx < Arr[k].first && Arr[k].first < ex) && (sy < Arr[k].second && Arr[k].second < ey))
                    {
                        point++;
                    }
                }

                if (point >= K)
                    find = true;

                if (find)
                {
                    break;
                }
            }

            if (find)
            {
                break;
            }
        }

        if (find)
        {
            ans = m * m;
            e = m-1;
        }
        else
        {
            s = m+1;
        }
    }

    std::cout << ans << endl;
    
}