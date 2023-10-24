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

int N, K;
int  Arr[300000];
bool Flag[300000];
int ans = 0;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}
	
	for (int i = 20; i >= 0; i--)
	{
		int check = 0;
		for (int j = 0; j < N; j++)
		{
			if (Flag[j])
				continue;

			if ((Arr[j] & (1 << i)) > 0)
				check++;
		}

		if (check >= K)
		{
			for (int j = 0; j < N; j++)
				if ((Arr[j] & (1 << i)) == 0)
					Flag[j] = true;
			ans += (1 << i);
		}
	}

	std::cout << ans << endl;	
}