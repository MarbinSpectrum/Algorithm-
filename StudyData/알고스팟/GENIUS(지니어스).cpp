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
float IMatrix[205][205];
float W[205][205];
float BaseMat[205][205];
float MultiTemp[205][205];
float ansDP[205][205];

void MultiMatrix(float A[205][205], float B[205][205], float Result[205][205])
{
    for (int i = 0; i < 205; i++)
        for (int j = 0; j < 205; j++)
            MultiTemp[i][j] = 0;

    for (int i = 0; i < 205; i++)
        for (int j = 0; j < 205; j++)
            for (int k = 0; k < 205; k++)
                MultiTemp[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < 205; i++)
        for (int j = 0; j < 205; j++)
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
        for (int i = 0; i < 205; i++)
            for (int j = 0; j < 205; j++)
                PowTemp[i][j] = A[i][j];
    }
    else if (n % 2 == 0)
    {
        PowMatrix(A, n / 2);
        MultiMatrix(PowTemp, PowTemp, PowTemp);
    }
    else
    {
        PowMatrix(A, n / 2);
        MultiMatrix(PowTemp, PowTemp, PowTemp);
        MultiMatrix(A, PowTemp, PowTemp);
    }
}

void F()
{ 
    for (int i = 0; i < 205; i++)
    {
        for (int j = 0; j < 205; j++)
        {
            IMatrix[i][j] = 0;
            W[i][j] = 0;
            BaseMat[i][j] = 0;
            MultiTemp[i][j] = 0;
            ansDP[i][j] = 0;
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

    for (int i = 0; i < N * 4; i++)
        IMatrix[i][i] = 1;

    for (int i = 0; i < 3 * N; i++)
        W[i][i + N] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            W[3 * N + i][(4 - L[j]) * N + j] = T[j][i];

    BaseMat[3 * N][0] = 1;

    PowMatrix(W, K);
    MultiMatrix(PowTemp, BaseMat, ansDP);

    for (int i = 0; i < M; i++)
    {
        float sum = 0;
        for (int j = 0; j < L[likeSong[i]]; j++)
        {
            sum += ansDP[N * (3 - j) + likeSong[i]][0];
        }
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