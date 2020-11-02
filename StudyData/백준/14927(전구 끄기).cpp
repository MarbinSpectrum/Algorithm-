#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>

#pragma warning(disable:4996)

using namespace std;

int N;
int Arr[18][18];
int Test[18][18];
int Result = 100000;
void Click(int r, int c)
{
    Test[r][c] = Test[r][c] == 0 ? 1 : 0;
    if (r - 1 >= 0)
        Test[r - 1][c] = Test[r - 1][c] == 0 ? 1 : 0;
    if (r + 1 < N)
        Test[r + 1][c] = Test[r + 1][c] == 0 ? 1 : 0;
    if (c - 1 >= 0)
        Test[r][c - 1] = Test[r][c - 1] == 0 ? 1 : 0;
    if (c + 1 < N)
        Test[r][c + 1] = Test[r][c + 1] == 0 ? 1 : 0;

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> Arr[r][c];

    for (int i = 0; i < (1 << N); i++)
    {

        int R = 0;
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                Test[r][c] = Arr[r][c];

        for (int c = 0; c < N; c++)
            if ((1 << c) & i)
            {
                Click(0, c);
                R++;
            }

        for (int r = 1; r < N; r++)
            for (int c = 0; c < N; c++)
                if (Test[r - 1][c] == 1)
                {
                    Click(r, c);
                    R++;
                }

        bool check = true;

        for (int c = 0; c < N; c++)
            if (Test[N - 1][c] == 1)
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