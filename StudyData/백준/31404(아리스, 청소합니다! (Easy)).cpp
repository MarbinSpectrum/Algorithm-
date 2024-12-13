#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e18;
const int Dic[8][2] = { {0,-1},{1,0},{0,1},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int H, W;
int R, C, D;
bool MAP[100][100];
int A[100][100];
int B[100][100];
bool Visit[100][100][4];
vector<tuple<int, int,int>> visitList;
int res = 0;

void Print()
{
    return;
    std::cout << endl;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == R && j == C)
                std::cout << "#";
            else
            std::cout << MAP[i][j] ? "0" : "1";
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

    std::cin >> H >> W;
    std::cin >> R >> C >> D;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            char c;
            std::cin >> c;
            A[i][j] = c - '0';
        }
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            char c;
            std::cin >> c;
            B[i][j] = c - '0';
        }

    int turn = 0;
    while (true)
    {
        turn++;
        Print();
        if (MAP[R][C])
        {
            if (Visit[R][C][D])
                break;
            Visit[R][C][D] = true;
            visitList.push_back({ R,C,D });
            D = (D + B[R][C]) % 4;
        }
        else
        {
            for(tuple<int, int,int> pos : visitList)
                Visit[std::get<0>(pos)][std::get<1>(pos)][std::get<2>(pos)] = false;
            visitList.clear();
            MAP[R][C] = true;
            D = (D + A[R][C]) % 4;
            res = max(turn, res);
        }
        R += Dic[D][1];
        C += Dic[D][0];

        if (R < 0 || C < 0 || R >= H || C >= W)
        {
            //res = max(turn, res);
            break;
        }
    }

    std::cout << res << endl;
}
