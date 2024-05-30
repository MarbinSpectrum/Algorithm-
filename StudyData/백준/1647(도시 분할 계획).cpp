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
vector<tuple<int, int, int>> edge;
int P[200000];
int Find(int a)
{
	if (a == P[a])
		return a;
	return P[a] = Find(P[a]);
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 200000; i++)
		P[i] = i;

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		edge.emplace_back(c, a, b);
	}

	sort(edge.begin(), edge.end());

	int sum = 0;
	int maxValue = -1;
	int cnt = 0;

	for (int i = 0; i < M; i++)
	{
		int a = std::get<1>(edge[i]);
		int b = std::get<2>(edge[i]);
		int c = std::get<0>(edge[i]);

		int pA = Find(a);
		int pB = Find(b);
		if (pA != pB)
		{
			if (pA < pB)
				P[pB] = pA;
			else
				P[pA] = pB;
			cnt++;
			sum += c;
			maxValue = max(maxValue, c);
				
		}

		if (cnt == N - 1)
			break;
	}

	std::cout << sum - maxValue << endl;
}