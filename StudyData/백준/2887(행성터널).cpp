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

int N;
vector<tuple<int, int, int>> V;
map<pair<int, int>,int> MoveCost;
int P[1000000];
vector<tuple<int, int, int>> Edge;

int FindP(int a)
{
	if (P[a] == a)
		return a;
	return P[a] = FindP(P[a]);
}

bool Bind(int a, int b)
{
	a = FindP(a);
	b = FindP(b);

	if (a == b)
		return true;

	if (a < b)
		swap(a, b);
	P[b] = a;

	return false;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 1000000; i++)
		P[i] = i;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		V.emplace_back(a, b, c);
	}

	vector<pair<int, int>> X_Value;
	for (int i = 0; i < N; i++)
	{
		int x = get<0>(V[i]);
		X_Value.emplace_back(x, i);
	}
	sort(X_Value.begin(), X_Value.end());
	for (int i = 0; i < N - 1; i++)
	{
		int aValue = X_Value[i].first;
		int aPos = X_Value[i].second;
		int bValue = X_Value[i + 1].first;
		int bPos = X_Value[i + 1].second;
		int dis = abs(aValue - bValue);

		if (aPos > bPos)
			swap(aPos, bPos);

		pair<int, int> key = { aPos,bPos };
		if (MoveCost.find(key) == MoveCost.end())
			MoveCost[key] = dis;
		else
			MoveCost[key] = min(MoveCost[key], dis);
	}

	vector<pair<int, int>> Y_Value;
	for (int i = 0; i < N; i++)
	{
		int y = get<1>(V[i]);
		Y_Value.emplace_back(y, i);
	}
	sort(Y_Value.begin(), Y_Value.end());
	for (int i = 0; i < N - 1; i++)
	{
		int aValue = Y_Value[i].first;
		int aPos = Y_Value[i].second;
		int bValue = Y_Value[i + 1].first;
		int bPos = Y_Value[i + 1].second;
		int dis = abs(aValue - bValue);

		if (aPos > bPos)
			swap(aPos, bPos);

		pair<int, int> key = { aPos,bPos };
		if (MoveCost.find(key) == MoveCost.end())
			MoveCost[key] = dis;
		else
			MoveCost[key] = min(MoveCost[key], dis);
	}

	vector<pair<int, int>> Z_Value;
	for (int i = 0; i < N; i++)
	{
		int z = get<2>(V[i]);
		Z_Value.emplace_back(z, i);
	}
	sort(Z_Value.begin(), Z_Value.end());
	for (int i = 0; i < N - 1; i++)
	{
		int aValue = Z_Value[i].first;
		int aPos = Z_Value[i].second;
		int bValue = Z_Value[i + 1].first;
		int bPos = Z_Value[i + 1].second;
		int dis = abs(aValue - bValue);

		if (aPos > bPos)
			swap(aPos, bPos);

		pair<int, int> key = { aPos,bPos };
		if (MoveCost.find(key) == MoveCost.end())
			MoveCost[key] = dis;
		else
			MoveCost[key] = min(MoveCost[key], dis);
	}

	for (map<pair<int, int>, int>::iterator iter = MoveCost.begin(); iter != MoveCost.end(); iter++)
	{
		Edge.emplace_back(iter->second, iter->first.first, iter->first.second);
	}

	sort(Edge.begin(), Edge.end());

	int ans = 0;
	for (int i = 0; i < Edge.size(); i++)
	{
		int a = get<1>(Edge[i]);
		int b = get<2>(Edge[i]);
		int c = get<0>(Edge[i]);
		
		if (Bind(a, b))
			continue;
		else
		{
			ans += c;
		}
	}

	std::cout << ans << endl;
}