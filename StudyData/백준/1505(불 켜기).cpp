#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>

#pragma warning(disable:4996)

using namespace std;

int N, M;
char Arr[8][8];
char Test[8][8];
int Result = 100000;
void Click(int r, int c)
{
    Test[r][c] = Test[r][c] == '*' ? '.' : '*';
    if (r - 1 >= 0)
        Test[r - 1][c] = Test[r - 1][c] == '*' ? '.' : '*';
    if (r - 1 >= 0 && c - 1 >= 0)
        Test[r - 1][c - 1] = Test[r - 1][c - 1] == '*' ? '.' : '*';
    if (r - 1 >= 0 && c + 1 < M)
        Test[r - 1][c + 1] = Test[r - 1][c + 1] == '*' ? '.' : '*';
    if (r + 1 < N)
        Test[r + 1][c] = Test[r + 1][c] == '*' ? '.' : '*';
    if (r + 1 < N && c - 1 >= 0)
        Test[r + 1][c - 1] = Test[r + 1][c - 1] == '*' ? '.' : '*';
    if (r + 1 < N && c + 1 < M)
        Test[r + 1][c + 1] = Test[r + 1][c + 1] == '*' ? '.' : '*';
    if (c - 1 >= 0)
        Test[r][c - 1] = Test[r][c - 1] == '*' ? '.' : '*';
    if (c + 1 < M)
        Test[r][c + 1] = Test[r][c + 1] == '*' ? '.' : '*';

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> Arr[r][c];

    for (int i = 0; i < (1 << M); i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            int R = 0;
            for (int r = 0; r < N; r++)
                for (int c = 0; c < M; c++)
                    Test[r][c] = Arr[r][c];

            for (int c = 0; c < M; c++)
            {
                if ((1 << c) & i)
                {
                    Click(0, c);
                    R++;
                }
            }

            for (int c = 0; c < N; c++)
            {
                if ((1 << c) & j)
                {
                    Click(c, 0);
                    R++;
                }
            }

            for (int r = 1; r < N; r++)
                for (int c = 1; c < M; c++)
                    if (Test[r - 1][c - 1] == '.')
                    {
                        Click(r, c);
                        R++;
                    }

            bool check = true;

            for (int r = 0; r < N; r++)
                for (int c = 0; c < M; c++)
                    if (Test[r][c] == '.')
                    {
                        check = false;
                        break;
                    }

            if (check)
                Result = min(Result, R);
        }
    }

    if (Result != 100000)
        cout << Result << endl;
    else
        cout << -1 << endl;

    return 0;
}