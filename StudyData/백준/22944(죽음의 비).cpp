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

bool Visit[1<<11][500][500];
char MAP[500][500];
int N, H, D;
pair<int, int> S;
pair<int, int> E;
int U_Idx[500][500];
int u = 0;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N >> H >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> MAP[i][j];
            if (MAP[i][j] == 'S')
                S = { i,j };
            else if (MAP[i][j] == 'E')
                E = { i,j };
            else if (MAP[i][j] == 'U')
                U_Idx[i][j] = u++;
        }
    }
    
    queue<pair<int, pair< pair<int, pair<int, int>>, pair<int, int>>>> Q;
    Q.push({ 0,{{0,S},{0,H } } });
    Visit[0][S.first][S.second] = true;
    while (Q.empty() == false)
    {
        pair<int, pair< pair<int, pair<int, int>>, pair<int, int>>> nowState = Q.front();
        Q.pop();

        int len = nowState.first;
        int VisitBit = nowState.second.first.first;
        pair<int, int> nowPos = nowState.second.first.second;
        int Hp = nowState.second.second.second;
        int Umbrella = nowState.second.second.first;

        for (int i = 0; i < 4; i++)
        {
            int ax = nowPos.first + Dic[i][0];
            int ay = nowPos.second + Dic[i][1];
            if (ax < 0 || ay < 0 || ax >= N || ay >= N)
                continue;
            if (MAP[ax][ay] == 'E')
            {
                std::cout << len + 1 << endl;
                return 0;
            }
            else if (MAP[ax][ay] == 'U')
            {
                int idx = U_Idx[ax][ay];
                if (!(VisitBit | (1 << idx)))
                    continue;

                int newLen = len + 1;
                int newVisitBit = VisitBit | (1 << idx);
                pair<int, int> newPos = { ax,ay };
                int newHp = Hp;
                int newUmbrella = D;
                newUmbrella--;

                if (Visit[newVisitBit][newPos.first][newPos.second])
                    continue;
                Q.push({ newLen,{{newVisitBit,newPos},{newUmbrella,newHp } } });
                Visit[newVisitBit][newPos.first][newPos.second] = true;
            }
            else
            {
                int newLen = len + 1;
                int newVisitBit = VisitBit;
                pair<int, int> newPos = { ax,ay };
                int newHp = Hp;
                int newUmbrella = Umbrella;

                if (newUmbrella > 0)
                    newUmbrella--;
                else if (newHp > 0)
                    newHp--;

                if(newHp == 0)
                    continue;

                if (Visit[newVisitBit][newPos.first][newPos.second])
                    continue;
                Q.push({ newLen,{{newVisitBit,newPos},{newUmbrella,newHp } } });
                Visit[newVisitBit][newPos.first][newPos.second] = true;
            }
        }

    }

    std::cout << -1 << endl;
}