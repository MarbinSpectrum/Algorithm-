#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int N, K;
vector<pair<char, int>> SetList;
map<pair<int, int>, int> MAP;
map<char, int> DicValue;
vector<int> Road;
int Seed[2000000];

void Init()
{
	{
		int x = 0;
		int y = 0;
		int t = 0;
		for (int i = 0; i < N; i++)
		{
			int a = DicValue[SetList[i].first];
			int b = SetList[i].second;
			for (int j = 0; j < b; j++)
			{
				x += Dic[a][0];
				y += Dic[a][1];

				if (MAP.find({ x, y }) == MAP.end())
				{
					MAP[{x, y}] = t++;
				}
			}
		}
	}

	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < N; i++)
		{
			int a = DicValue[SetList[i].first];
			int b = SetList[i].second;
			for (int j = 0; j < b; j++)
			{
				x += Dic[a][0];
				y += Dic[a][1];

				int idx = MAP[{x, y}];
				Road.push_back(idx);
			}
		}
	}
}
bool Check(int V)
{
	for (int i = 0; i < 2000000; i++)
		Seed[i] = -1;

	int G = 0;
	for (int t = 0; t < Road.size(); t++)
	{
		int idx = Road[t];
		
		if (Seed[idx] == -1)
		{
			Seed[idx] = t;
		}
		else
		{
			int seedT = t - Seed[idx];
			if (seedT >= V)
			{
				Seed[idx] = t;
				G++;
			}
		}
	}
	return G >= K;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	DicValue['N'] = 0;
	DicValue['S'] = 1;
	DicValue['W'] = 3;
	DicValue['E'] = 2;

	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		char a;
		int b;
		std::cin >> a >> b;
		SetList.push_back({ a,b });
	}

	Init();

	int left = 0;
	int right = INF;
	int result = -1;

	while (left + 1 < right)
	{
		int mid = (right + left) / 2;

		if (Check(mid))
		{
			result = max(result, mid);
			left = mid;
		}
		else
			right = mid;

	}

	std::cout << result << endl;
}