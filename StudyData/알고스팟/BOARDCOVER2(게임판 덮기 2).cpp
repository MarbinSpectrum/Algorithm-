#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e15;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

char MAP[22][22];
vector<vector<pair<int, int>>> Block;
int H, W, R, C;
int ans = 0;
int emptySize = 0;
int blockCnt = 0;
bool Paint(int x, int y, int t, bool state)
{
    for (int i = 0; i < Block[t].size(); i++)
    {
        int ax = Block[t][i].second + x;
        int ay = Block[t][i].first + y;
        if (0 <= ax && ax < W && 0 <= ay && ay < H)
            if (state ? MAP[ay][ax] == '.' : MAP[ay][ax] == '#')
                continue;
        return false;
    }

    for (int i = 0; i < Block[t].size(); i++)
    {
        int ax = Block[t][i].second + x;
        int ay = Block[t][i].first + y;
        MAP[ay][ax] = state ? '#' : '.';
    }

    return true;
}
void DFS(int cnt)
{
    int cantBlock = emptySize / blockCnt;
    if (cnt + cantBlock <= ans)
        return;

    int x = -1;
    int y = -1;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (MAP[i][j] == '.')
            {
                x = j;
                y = i;
                break;
            }
        }
        if (y != -1)
            break;
    }

    if (x >= W || x < 0 || y >= H || y < 0)
    {
        ans = max(ans, cnt);
        return;
    }

    for (int i = 0; i < Block.size(); i++)
    {
        if (Paint(x, y, i, true))
        {
            emptySize -= blockCnt;

            DFS(cnt + 1);
            emptySize += blockCnt;
            Paint(x, y, i, false);
        }
    }

    MAP[y][x] = '#';
    emptySize--;
    DFS(cnt);
    MAP[y][x] = '.';
    emptySize++;
}

void F()
{
    ans = 0;
    for (int i = 0; i < 22; i++)
        for (int j = 0; j < 22; j++)
            MAP[i][j] = '.';
    Block.clear();
    emptySize = 0;
    blockCnt = 0;

    std::cin >> H >> W >> R >> C;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            std::cin >> MAP[i][j];
            if (MAP[i][j] == '.')
                emptySize++;
        }

    int aR = R;
    int aC = C;
    vector<vector<char>> btemp(aR, vector<char>(aC));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            std::cin >> btemp[i][j];
            if (btemp[i][j] == '#')
                blockCnt++;
        }

    for (int t = 0; t < 4; t++)
    {
        swap(aR, aC);
        vector<vector<char>> temp(aR, vector<char>(aC));
        for (int i = 0; i < aC; i++)
            for (int j = 0; j < aR; j++)
                temp[j][aC - i - 1] = btemp[i][j];
        btemp.clear();
        btemp.resize(aR, vector<char>(aC));
        for (int i = 0; i < aR; i++)
            for (int j = 0; j < aC; j++)
                btemp[i][j] = temp[i][j];

        vector<pair<int, int>> newList;
        for (int i = 0; i < aR; i++)
            for (int j = 0; j < aC; j++)
                if (btemp[i][j] == '#')
                    newList.emplace_back(i, j);

        bool skip = false;
        for (int i = 0; i < Block.size(); i++)
        {
            bool c = false;
            for (int j = 0; j < blockCnt; j++)
            {
                if (newList[j] == Block[i][j])
                    continue;
                c = true;
            }
            if (c == false)
            {
                skip = true;
                break;
            }
        }

        if (skip == false)
        {
            Block.push_back(newList);
        }
    }

    for (int i = 0; i < Block.size(); i++)
    {
        pair<int, int> firstPos = Block[i][0];
        pair<int, int> pivot = { -firstPos.first,-firstPos.second };
        for (int j = 0; j < Block[i].size(); j++)
        {
            Block[i][j] = { Block[i][j].first + pivot.first, Block[i][j].second + pivot.second };
        }
    }

    DFS(0);

    std::cout << ans << endl;
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
        F();
    }

}