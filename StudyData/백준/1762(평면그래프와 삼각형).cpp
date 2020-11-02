#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <tuple>
#include <list>
#include <map>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int N, M;
vector<int> Link[500000];
int Result = 0;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Link[a].push_back(b);
		Link[b].push_back(a);
	}

	for (int i = 0; i < 500000; i++)
		sort(Link[i].begin(), Link[i].end());

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < Link[i].size(); j++)
		{
			int a = i;
			int b = Link[a][j];

			if (a > b)
				continue;
			if (Link[a].size() > Link[b].size())
				swap(a, b);

			for (int k = 0; k < Link[a].size(); k++)
			{
				int c = Link[a][k];

				if (binary_search(Link[b].begin(), Link[b].end(), c))
					Result++;
			}
		}
	}

	cout << Result / 3 << endl;


}
