#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>

#pragma warning(disable:4996)

using namespace std;

int N, S;
int A[101];
bool Visit[1001][51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 1; i <= 50; i++)
		A[i] = i * (i + 1) / 2;
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 51; j++)
			Visit[i][j] = false;
	if (N - 2 <= S && S <= (N - 1) * (N - 2) / 2)
	{
		queue<pair<int, int>> Queue;
		Queue.push({ S,N - 2 });
		Visit[S][N] = true;
		while (!Queue.empty())
		{
			pair<int, int> temp = Queue.front();
			//cout << temp.first << "," << temp.second << "\n";
			Queue.pop();
			for (int i = 1; i <= 50; i++)
			{
				if (temp.first - A[i] < 0)
					break;
				if (temp.second - i < 0)
					break;
				if (Visit[temp.first - A[i]][temp.second - i])
					continue;
				Queue.push({ temp.first - A[i],temp.second - i });
				Visit[temp.first - A[i]][temp.second - i] = true;
				if (temp.first - A[i] == 0 && temp.second - i == 0)
				{
					cout << 1 << endl;
					return 0;
				}
			}

		}
	}
	cout << 0 << endl;
}