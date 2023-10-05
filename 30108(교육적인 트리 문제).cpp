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
priority_queue<pair<int,int>> pq;
vector<int> V[500000];
int Arr[500000];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	std::cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int a;
		std::cin >> a;
		V[a].push_back(i);
	}
	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}

	int sum = 0;
	pq.push({ Arr[1],1 });
	for (int i = 0; i < N; i++)
	{
		pair<int,int> now = pq.top();
		pq.pop();

		sum += now.first;
		for (int j = 0; j < V[now.second].size(); j++)
		{
			int next = V[now.second][j];
			pq.push({ Arr[next],next });
		}

		std::cout << sum << endl;
	}

		
}