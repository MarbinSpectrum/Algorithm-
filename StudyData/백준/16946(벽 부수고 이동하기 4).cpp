#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e18;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N, M;
int MAP[1005][1005];
int Visit[1005][1005];
int Cnt[1005][1005];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			MAP[i][j] = (c - '0');
			if (MAP[i][j] == 1)
				Visit[i][j] = 2121212121;
			else
				Visit[i][j] = 0;
		}

	int groupNum = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Visit[i][j] == 0)
			{
				vector<pair<int, int>> nums;
				queue<pair<int, int>> Q;

				Q.push({ i,j });
				nums.push_back({ i,j });
				Visit[i][j] = groupNum;

				while (Q.empty() == false)
				{
					pair<int, int> now = Q.front();
					Q.pop();

					for (int k = 0; k < 4; k++)
					{
						int ai = now.first + Dic[k][0];
						int aj = now.second + Dic[k][1];
						if (ai < 0 || ai >= N || aj < 0 || aj >= M)
							continue;
						if (Visit[ai][aj] > 0)
							continue;
						Q.push({ ai,aj });
						nums.push_back({ ai,aj });
						Visit[ai][aj] = groupNum;
					}
				}

				for (int k = 0; k < nums.size(); k++)
				{
					Cnt[nums[k].first][nums[k].second] = nums.size();
				}

				groupNum++;
			}
		}
	}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (MAP[i][j] == 0)
				{
					std::cout << 0;
				}
				else
				{
					set<int> hasGroup;

					int sum = 1;
					for (int k = 0; k < 4; k++)
					{
						int ai = i + Dic[k][0];
						int aj = j + Dic[k][1];
						if (ai < 0 || ai >= N || aj < 0 || aj >= M)
							continue;
						if (MAP[ai][aj] == 1)
							continue;
						int isGroup = Visit[ai][aj];
						if (hasGroup.find(isGroup) != hasGroup.end())
							continue;
						hasGroup.insert(isGroup);
						sum += Cnt[ai][aj];
					}
					std::cout << sum % 10;
				}
			}
			std::cout << endl;
		}
	
}