#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double


#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))
const float INF = 1e15;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N;
set<int> hasValue;
vector<int> Arr;
vector<int> CheckValue;
vector<int> ans;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		std::cin >> a;
		hasValue.insert(a);
		Arr.push_back(a);
	}

	for (int i = 1; i < N; i++)
	{
		int dis = Arr[i] - Arr[0];
		CheckValue.push_back(dis);
	}

	for (int i = 0; i < CheckValue.size(); i++)
	{
		int cnt = 0;
		set<int> flag;

		for (int j = 0; j < N; j++)
		{
			int nowValue = Arr[j];
			int nextValue = nowValue + CheckValue[i];
			if (hasValue.find(nextValue) != hasValue.end())
			{
				if (flag.find(nowValue) == flag.end())
				{
					cnt++;
					flag.insert(nowValue);
				}
				if (flag.find(nextValue) == flag.end())
				{
					cnt++;
					flag.insert(nextValue);
				}
			}
		}

		if (cnt == N)
			ans.push_back(CheckValue[i]);
	}

	std::cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i] << " ";
	}
	std::cout << endl;
	
}