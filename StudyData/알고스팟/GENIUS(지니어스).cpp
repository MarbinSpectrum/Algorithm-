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

int N, K, M;
int L[50];
float T[50][50];
int likeSong[50];
float W[205][205];
float MultiTemp[205][205];

void MultiMatrix(float A[205][205], float B[205][205], float Result[205][205])
{
    for (int i = 0; i < N * 4; i++)
        for (int j = 0; j < N * 4; j++)
        {
            MultiTemp[i][j] = 0;
            for (int k = 0; k < N * 4; k++)
                MultiTemp[i][j] += A[i][k] * B[k][j];


        }

    for (int i = 0; i < N * 4; i++)
        for (int j = 0; j < N * 4; j++)
            Result[i][j] = MultiTemp[i][j];
}

float PowTemp[205][205];
void PowMatrix(float A[205][205], int n)
{
    if (n == 0)
    {
        return;
    }
    else if (n == 1)
    {
        for (int i = 0; i < N * 4; i++)
            for (int j = 0; j < N * 4; j++)
                PowTemp[i][j] = A[i][j];
    }
    else
    {
        PowMatrix(A, n / 2);
        MultiMatrix(PowTemp, PowTemp, PowTemp);

        if (n % 2 != 0)
            MultiMatrix(A, PowTemp, PowTemp);
    }
}

void F()
{
    for (int i = 0; i < N * 4; i++)
    {
        for (int j = 0; j < N * 4; j++)
        {
            W[i][j] = 0;
            MultiTemp[i][j] = 0;
        }
    }

    std::cin >> N >> K >> M;
    for (int i = 0; i < N; i++)
        std::cin >> L[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> T[i][j];
    for (int i = 0; i < M; i++)
        std::cin >> likeSong[i];

    for (int i = 0; i < 3 * N; i++)
        W[i][i + N] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            W[3 * N + i][(4 - L[j]) * N + j] = T[j][i];

    PowMatrix(W, K);

    for (int i = 0; i < M; i++)
    {
        float sum = 0;
        for (int j = 0; j < L[likeSong[i]]; j++)
            sum += PowTemp[N * (3 - j) + likeSong[i]][3 * N];
        std::cout << sum << " ";
    }
    std::cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(8);

    int C;
    std::cin >> C;
    while (C--)
    {
        F();
    }

}