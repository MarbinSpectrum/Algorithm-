#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <ctype.h>

#pragma warning(disable:4996)

using namespace std;

int N;
long long Block[50];
//i번째블록까지씀
//j만큼 두 탑의 크기가 차이가남
//만든 탑의높이
long long DP[50][500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, -1, sizeof(DP));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Block[i];
	sort(Block, Block + N);
	for (int i = 0; i < N; i++)
		DP[i][Block[i]] = Block[i];

	for (int i = 1; i < N; i++)
		for (int j = 0; j < 500001; j++)
			if (DP[i - 1][j] != -1)
			{
				//낮은쪽에 쌓아서 높이차를 줄임
				//1.낮은쪽에 블록을 쌓아서 낮은곳이 높아진경우
				if (j < Block[i])
				{
					long long temp = DP[i][abs(j - Block[i])];
					DP[i][abs(j - Block[i])] = max(temp, DP[i - 1][j] + abs(j - Block[i]));
				}
				//2.낮은쪽에 블록을 쌓앗지만 아직 낮은쪽의 높이가 더 낮은경우
				else
				{
					long long temp = DP[i][abs(j - Block[i])];
					DP[i][abs(j - Block[i])] = max(temp, DP[i - 1][j]);
				}

				//3.높은데에 블록을쌓은경우
				long long temp2 = DP[i][j + Block[i]];
				DP[i][j + Block[i]] = max(temp2, DP[i - 1][j] + Block[i]);

				//4.해당블록을 안쌓은경우
				temp2 = DP[i][j];
				DP[i][j] = max(temp2, DP[i - 1][j]);
			}

	long long result = -1;
	result = max(result, DP[N - 1][0]);
	cout << result << endl;


}