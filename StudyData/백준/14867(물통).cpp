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

int a, b, c, d;
set<int> Visit[100001];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> a >> b >> c >> d;
    
    queue<pair<pair<int, int>, int>> Q;
    Q.push({ { 0,0 }, 0 });
    Visit[0].insert(0);

    while (Q.empty() == false)
    {
        pair<pair<int, int>, int> now = Q.front();
        Q.pop();

        int nowA = now.first.first;
        int nowB = now.first.second;
        int nowT = now.second;

        if (nowA == c && nowB == d)
        {
            std::cout << nowT << endl;
            return 0;
        }

        if(Visit[a].find(nowB) == Visit[a].end())
        {
            Q.push({ {a,nowB},nowT + 1 });
            Visit[a].insert(nowB);
        }

        if (Visit[nowA].find(b) == Visit[nowA].end())
        {
            Q.push({ {nowA,b},nowT + 1 });
            Visit[nowA].insert(b);
        }

        if (Visit[0].find(nowB) == Visit[0].end())
        {
            Q.push({ {0,nowB},nowT + 1 });
            Visit[0].insert(nowB);
        }

        if (Visit[nowA].find(0) == Visit[nowA].end())
        {
            Q.push({ {nowA,0},nowT + 1 });
            Visit[nowA].insert(0);
        }

        {
            int emptySpace = b - nowB;
            if (emptySpace >= nowA)
            {
                if (Visit[0].find(nowB + nowA) == Visit[0].end())
                {
                    Q.push({ {0,nowB + nowA},nowT + 1 });
                    Visit[0].insert(nowB + nowA);
                }
            }
            else
            {
                int nextA = nowA - emptySpace;
                if (Visit[nextA].find(b) == Visit[nextA].end())
                {
                    Q.push({ {nextA,b},nowT + 1 });
                    Visit[nextA].insert(b);
                }
            }
        }

        {
            int emptySpace = a - nowA;
            if (emptySpace >= nowB)
            {
                if (Visit[nowA + nowB].find(0) == Visit[nowA + nowB].end())
                {
                    Q.push({ {nowA + nowB,0},nowT + 1 });
                    Visit[nowA + nowB].insert(0);
                }
            }
            else
            {
                int nextB = nowB - emptySpace;
                if (Visit[a].find(nextB) == Visit[a].end())
                {
                    Q.push({ {a,nextB},nowT + 1 });
                    Visit[a].insert(nextB);
                }
            }
        }
    }

    std::cout << -1 << endl;
    return 0;
}