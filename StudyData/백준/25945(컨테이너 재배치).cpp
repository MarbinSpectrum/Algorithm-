#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int Ceil(float f)
{
	if (f == (int)f)
		return (int)f;
	else
		return (int)f + 1;
}

//////////////////////////////////////////////////////////////////////// 

int n;
vector<int> Arr;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int sum = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		Arr.push_back(a);
		sum += a;
	}

	int A = sum / n;
	int B = Ceil((float)sum / (float)n);

	sort(Arr.begin(), Arr.end());

	int cnt = 0;
	if (A != B)
		cnt = (sum - B * n) / (A - B);
	else
		cnt = n;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < cnt)
		{
			if (Arr[i] > A)
				ans += Arr[i] - A;
		}
		else
		{
			if (Arr[i] > B)
				ans += Arr[i] - B;
		}
	}

	std::cout << ans << endl;
}