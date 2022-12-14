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

int N;
char DP[1 << 25];

int BlockDic[4][3][2] =
{
    {{1,0},{0,1},{1,1}} ,
    {{0,0},{1,0},{1,1}} ,
    {{0,0},{1,0},{0,1}} ,
    {{0,0},{0,1},{1,1}}
};

vector<int> checkArr;

int GetBit(int r, int c)
{
    return 1 << (r * 5 + c);
}

void MakeCheckList()
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            vector<int> Bits;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Bits.push_back(GetBit(r + i, c + j));
                }
            }
            int sumBits = Bits[0] + Bits[1] + Bits[2] + Bits[3];
            for (int i = 0; i < 4; i++)
            {
                checkArr.push_back(sumBits - Bits[i]);
            }
        }
    }

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            checkArr.push_back(GetBit(r, c) + GetBit(r, c + 1));
            checkArr.push_back(GetBit(c, r) + GetBit(c + 1, r));
        }
    }
}

char Dp(int board)
{
    char& ret = DP[board];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;

    for (int i = 0; i < checkArr.size(); i++)
    {
        if (board & checkArr[i])
            continue;
        if (Dp(board | checkArr[i]) == 0)
            return ret = 1;
    }

    return ret;
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < (1 << 25); i++)
        DP[i] = -1;

    MakeCheckList();
    int C;
    std::cin >> C;
    while (C--)
    {

        int bit = 0;
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                char t;
                std::cin >> t;
                if (t != '.')
                {
                    bit |= GetBit(r, c);
                }
            }
        }

        int result = Dp(bit);
        if (result == 0)
        {
            std::cout << "LOSING" << endl;
        }
        else
        {
            std::cout << "WINNING" << endl;
        }
    }

}