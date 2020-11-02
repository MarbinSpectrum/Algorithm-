#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>

#pragma warning(disable:4996)

using namespace std;

char Arr[10][10];
char Test[10][10];
int Result = 100000;
void Click(int r, int c)
{
    Test[r][c] = Test[r][c] == '#' ? 'O' : '#';
    if (r - 1 >= 0)
        Test[r - 1][c] = Test[r - 1][c] == '#' ? 'O' : '#';
    if (r + 1 < 10)
        Test[r + 1][c] = Test[r + 1][c] == '#' ? 'O' : '#';
    if (c - 1 >= 0)
        Test[r][c - 1] = Test[r][c - 1] == '#' ? 'O' : '#';
    if (c + 1 < 10)
        Test[r][c + 1] = Test[r][c + 1] == '#' ? 'O' : '#';

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            cin >> Arr[r][c];

    for (int i = 0; i < (1 << 10); i++)
    {

        int R = 0;
        for (int r = 0; r < 10; r++)
            for (int c = 0; c < 10; c++)
                Test[r][c] = Arr[r][c];

        for (int c = 0; c < 10; c++)
            if ((1 << c) & i)
            {
                Click(0, c);
                R++;
            }

        for (int r = 1; r < 10; r++)
            for (int c = 0; c < 10; c++)
                if (Test[r - 1][c] == 'O')
                {
                    Click(r, c);
                    R++;
                }

        bool check = true;

        for (int c = 0; c < 10; c++)
            if (Test[9][c] == 'O')
            {
                check = false;
                break;
            }

        if (check)
            Result = min(Result, R);
    }

    if (Result != 100000)
        cout << Result << endl;
    else
        cout << -1 << endl;




    return 0;
}