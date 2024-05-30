#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double


#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))
const int INF = 1e15;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N, M;
priority_queue<int> pq;
set<int> solved;
vector<int> V[40000];
int InValue[40000];
vector<int> ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		V[a].push_back(b);
		InValue[b]++;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if(InValue[i] == 0)
			pq.push(-i);
	}

	while (pq.empty() == false)
	{
		int a = -pq.top();
		pq.pop();

		if (solved.find(a) != solved.end())
			continue;
		solved.insert(a);
		ans.push_back(a);

		for (int i = 0; i < V[a].size(); i++)
		{
			int b = V[a][i];
			InValue[b]--;
			if(InValue[b] == 0)
				pq.push(-b);
		}
	}

	for (int i = 0; i < ans.size(); i++)
		std::cout << ans[i] << " ";
	std::cout << endl;
}