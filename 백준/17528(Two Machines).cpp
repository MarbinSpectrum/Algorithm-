#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <map>

#pragma warning(disable:4996)

using namespace std;

int T;

//순서 //0왼쪽이 높음 1오른쪽이 높음  //시간차이 //높은시간
long long DP[2][2][100001];

const int INF = 9876543210;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int j = 0; j < 100001; j++)
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++)
				DP[a][b][j] = INF;
	int N;
	cin >> N;
	vector<pair<long long, long long>> Cookie(N);
	long long result = INF;

	for (int i = 0; i < N; i++)
		cin >> Cookie[i].first >> Cookie[i].second;
	DP[1][0][Cookie[0].first] = Cookie[0].first;
	DP[1][1][Cookie[0].second] = Cookie[0].second;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 100001; j++)
			for (int a = 0; a < 2; a++)
				DP[(i + 1) % 2][a][j] = INF;

		for (int a = 0; a < 2; a++)
			for (int j = 0; j < 100001; j++)
			{
				if (DP[i % 2][a][j] != INF)
				{
					//cout << "[" << i << " " << a << " " << j << " = " << DP[i % 2][a][j] << "]" << endl;
					if (a == 0)
					{
						//왼쪽이 더 높은데 왼쪽에 쌓음

						DP[(i + 1) % 2][0][j + Cookie[i].first] = min(DP[(i + 1) % 2][0][j + Cookie[i].first], DP[i % 2][a][j] + Cookie[i].first);

						//cout << i + 1 << " " << a << " " << j + Cookie[i].first << " = " << DP[(i + 1) % 2][0][j + Cookie[i].first] << endl;

						if (j < Cookie[i].second)
						{
							//왼쪽이 더 높아서 오른쪽에 쌓아서 오른쪽이 높음
							int temp = abs(j - Cookie[i].second);
							DP[(i + 1) % 2][1][temp] = min(DP[(i + 1) % 2][1][temp], DP[i % 2][a][j] - j + Cookie[i].second);

							//cout << i + 1 << " " << 1 << " " << temp << " = " << DP[(i + 1) % 2][1][temp] << endl;

						}
						else
						{
							//왼쪽이 더 높아서 오른쪽에 쌓았는데 아직도 왼쪽이 높음
							DP[(i + 1) % 2][0][j - Cookie[i].second] = min(DP[(i + 1) % 2][0][j - Cookie[i].second], DP[i % 2][0][j]);
							//cout << i + 1 << " " << 0 << " " << j - Cookie[i].second << " = " << DP[(i + 1) % 2][0][j - Cookie[i].second] << endl;
						}
					}
					else if (a == 1)
					{
						//오른쪽이 더 높은데 오른쪽에 쌓음
						DP[(i + 1) % 2][1][j + Cookie[i].second] = min(DP[(i + 1) % 2][1][j + Cookie[i].second], DP[i % 2][1][j] + Cookie[i].second);
						//cout << i + 1 << " " << 1 << " " << j + Cookie[i].second << " = " << DP[(i + 1) % 2][1][j + Cookie[i].second] << endl;
						if (j < Cookie[i].first)
						{
							//오른쪽이 더 높아서 왼쪽에 쌓아서 왼쪽이 높음
							int temp = abs(j - Cookie[i].first);
							DP[(i + 1) % 2][0][temp] = min(DP[(i + 1) % 2][0][temp], DP[i % 2][1][j] - j + Cookie[i].first);

							//cout << i + 1 << " " << 0 << " " << temp << " = " << DP[(i + 1) % 2][0][temp] << endl;
						}
						else
						{
							//오른쪽이 더 높아서 왼쪽에 쌓았는데 아직도 오른쪽이 높음
							DP[(i + 1) % 2][1][j - Cookie[i].first] = min(DP[(i + 1) % 2][1][j - Cookie[i].first], DP[i % 2][a][j]);

							//cout << i + 1 << " " << 1 << " " << j - Cookie[i].first << " = " << DP[i % 2][a][j] << endl;
						}
					}

				}
			}
	}

	for (int j = 0; j < 100001; j++)
		for (int a = 0; a < 2; a++)
			result = min(result, DP[(N) % 2][a][j]);

	cout << result << "\n";



}