#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int WinPoint[4] = { 0, };
float Rate[4];
float W[4][4];
float D[4][4];
float L[4][4];

map<string, int> Idx;
vector<pair<int, int>> battle;

void DFS(int d, float per)
{
	if (per == 0)
		return;

	if (d < 6)
	{
		int idxA = battle[d].first;
		int idxB = battle[d].second;

		WinPoint[idxA] += 3;
		DFS(d + 1, per * W[idxA][idxB]);
		WinPoint[idxA] -= 3;

		WinPoint[idxA] += 1;
		WinPoint[idxB] += 1;
		DFS(d + 1, per * D[idxA][idxB]);
		WinPoint[idxA] -= 1;
		WinPoint[idxB] -= 1;

		WinPoint[idxB] += 3;
		DFS(d + 1, per * L[idxA][idxB]);
		WinPoint[idxB] -= 3;
	}
	else
	{
		vector<pair<int, int>> Arr;
		for (int i = 0; i < 4; i++)
			Arr.emplace_back(-WinPoint[i], i);

		sort(Arr.begin(), Arr.end());

		int maxPoint = Arr[0].first;
		vector<int> maxIdx;

		for (int i = 0; i < 4; i++)
			if (Arr[i].first == maxPoint)
				maxIdx.push_back(Arr[i].second);

		int maxIdxLen = maxIdx.size();
	
		if (maxIdxLen == 1)
		{
			//가장 높은 점수를 가진사람이 1명
			Rate[maxIdx[0]] += per;

			//두번째로 높은 점수를 가진사람중 1명을 랜덤으로 뽑는다.
			maxIdx.clear();
			maxPoint = Arr[1].first;
			for (int i = 1; i < 4; i++)
				if (Arr[i].first == maxPoint)
					maxIdx.push_back(Arr[i].second);

			maxIdxLen = maxIdx.size();
			for (int i = 0; i < maxIdxLen; i++)
			{
				float v = per / (float)maxIdxLen;
				Rate[maxIdx[i]] += v;
			}
		}
		else if (maxIdxLen == 2)
		{
			//가장 높은 점수를 가진사람이 2명
			Rate[maxIdx[0]] += per;
			Rate[maxIdx[1]] += per;
		}
		else if (maxIdxLen == 3)
		{
			//가장 높은 점수를 가진사람이 3명
			Rate[maxIdx[0]] += (per * 2) / (float)3;
			Rate[maxIdx[1]] += (per * 2) / (float)3;
			Rate[maxIdx[2]] += (per * 2) / (float)3;
		}
		else if (maxIdxLen == 4)
		{
			//가장 높은 점수를 가진사람이 4명
			Rate[maxIdx[0]] += per / (float)2;
			Rate[maxIdx[1]] += per / (float)2;
			Rate[maxIdx[2]] += per / (float)2;
			Rate[maxIdx[3]] += per / (float)2;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cout << fixed;
	cout.precision(10);

	for (int i = 0; i < 4; i++)
	{
		string s;
		std::cin >> s;
		Idx[s] = i;
	}

	for (int i = 0; i < 6; i++)
	{
		string a, b;
		std::cin >> a >> b;
		int idxA = Idx[a];
		int idxB = Idx[b];
		battle.emplace_back(idxA, idxB);
	
		std::cin >> W[idxA][idxB] >> D[idxA][idxB] >> L[idxA][idxB];
		W[idxA][idxB] *= 1000;
		D[idxA][idxB] *= 1000;
		L[idxA][idxB] *= 1000;
	}

	DFS(0, 1);

	for (int i = 0; i < 4; i++)
	{
		std::cout << Rate[i] /(float)1000000000000000000 << endl;
	}
}