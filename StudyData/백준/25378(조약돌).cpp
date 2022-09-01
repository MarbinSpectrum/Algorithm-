#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int N;
vector<int> Arr;
map<int,int> DP[2502];
int D(int a,int b)
{
	if (DP[a].find(b) != DP[a].end())
		return DP[a][b];
	DP[a][b] = INF;
	int& ret = DP[a][b];
	if (a + 1 < N)
	{
		if (b == 0)
		{
			ret = min(ret, D(a + 1, Arr[a + 1]));
		}
		else if (b > Arr[a+1])
		{
			ret = min(ret, D(a + 1, Arr[a + 1]) + 1);
		}
		else
		{
			ret = min(ret, D(a + 1, Arr[a + 1]) + 1);
			ret = min(ret, D(a + 1, Arr[a + 1] - b) + 1);
		}
	}
	else
	{
		if (b == 0)
			ret = min(ret, (int)0);
		else
			ret = min(ret, (int)1);
	}

	return ret;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		std::cin >> a;
		Arr.push_back(a);
	}

	std::cout << D(0, Arr[0]) << endl;
}