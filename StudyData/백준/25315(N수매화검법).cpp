#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

////////////////////////////////////////////////////////////////////////

const int MAX = 3000;
int N;
pair<float, float> S[MAX];
pair<float, float> E[MAX];
std::vector<pair<int, int>> A;

int CCW(pair<float, float>& p1, pair<float, float>& p2, pair<float, float>& p3)
{
	float op = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	op -= (p1.first * p3.second + p2.first * p1.second + p3.first * p2.second);

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}
bool CheckIntersect(int line1, int line2)
{
	pair<float, float> p1 = S[line1];
	pair<float, float> p2 = E[line1];
	pair<float, float> p3 = S[line2];
	pair<float, float> p4 = E[line2];

	int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if (line1_2 == 0 && line2_1 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}
	return line1_2 <= 0 && line2_1 <= 0;
}
int ans = 0;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d, e;
		std::cin >> a >> b >> c >> d >> e;
		S[i] = { a,b };
		E[i] = { c,d };
		A.push_back({ e,i });
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++)
	{
		int a = A[i].first;
		int cnt = 0;
		for (int j = i + 1; j < N; j++)
		{
			int b = A[i].second;
			int c = A[j].second;
			cnt += CheckIntersect(b, c);
		}
		ans += (cnt + 1) * a;
	}
	std::cout << ans << endl;

}