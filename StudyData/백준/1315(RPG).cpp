#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

#pragma warning(disable:4996)

using namespace std;

int K;

class Quest
{
public:
	int STR;
	int INT;
	int P;
	bool c;
	Quest(int as, int ai, int ap)
	{
		STR = as;
		INT = ai;
		P = ap;
		c = false;
	}
};
vector<Quest> questList;

int DP[1001][1001];

int V(int STR, int INT)
{
	if (DP[STR][INT] != -1)
		return DP[STR][INT];

	int point = 0;
	int n = 0;

	vector<int> clearData;
	for (int i = 0; i < K; i++)
	{
		if (questList[i].STR <= STR || questList[i].INT <= INT)
		{
			if (!questList[i].c)
			{
				questList[i].c = true;
				clearData.push_back(i);
				point += questList[i].P;
			}
			n++;
		}
	}

	DP[STR][INT] = n;

	for (int i = STR; i <= min(1000, STR + point); i++)
		DP[STR][INT] = max(V(i, min(1000, INT + (point - (i - STR)))), DP[STR][INT]);

	for (int i = 0; i < clearData.size(); i++)
		questList[clearData[i]].c = false;

	return DP[STR][INT];
}


int main()
{

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		questList.push_back(Quest(a, b, c));
	}

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			DP[i][j] = -1;

	cout << V(1, 1) << "\n";

}
