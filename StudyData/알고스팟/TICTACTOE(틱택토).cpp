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

int N;

map<string, string> DP;
string Dp(string board)
{
    if (DP.find(board) != DP.end())
    {
        return DP[board];
    }

    for (int i = 0; i < 2; i++)
    {
        char c = (i == 0) ? 'o' : 'x';
        for (int j = 0; j < 3; j++)
        {
            if (board[j * 3 + 0] == c &&
                board[j * 3 + 0] == board[j * 3 + 1] &&
                board[j * 3 + 1] == board[j * 3 + 2])
            {
                return DP[board] = c;
            }
        }

        for (int j = 0; j < 3; j++)
        {
            if (board[0 + j] == c &&
                board[0 + j] == board[3 + j] &&
                board[3 + j] == board[6 + j])
            {
                return DP[board] = c;
            }
        }

        if (board[0] == c &&
            board[0] == board[4] &&
            board[4] == board[8])
        {
            return DP[board] = c;
        }

        if (board[2] == c &&
            board[2] == board[4] &&
            board[4] == board[6])
        {
            return DP[board] = c;
        }
    }

    int cnt = 0;
    for (int i = 0; i < board.size(); i++)
        if (board[i] != '.')
            cnt++;

    if (cnt == 9)
    {
        return DP[board] = "TIE";
    }

    char cChar0 = cnt % 2 ? 'o' : 'x';
    char cChar1 = cnt % 2 ? 'x' : 'o';
    int cCnt0 = 0;
    int cCnt1 = 0;
    for (int i = 0; i < board.length(); i++)
    {
        if (board[i] != '.')
            continue;

        string newBoard = board;
        newBoard[i] = cChar0;

        string res = Dp(newBoard);
        if (res[0] == cChar0)
        {
            return DP[board] = cChar0;
        }
        else if (res[0] == cChar1)
        {
            cCnt0++;
        }
        cCnt1++;
    }   


    if (cCnt0 == cCnt1)
    {
        return DP[board] = cChar1;
    }

    return DP[board] = "TIE";
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
        string s;
        for (int i = 0; i < 9; i++)
        {
            char c;
            std::cin >> c;
            s += c;
        }

        std::cout << Dp(s) << endl;
    }

}