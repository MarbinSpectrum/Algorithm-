#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int T, N, K;
struct Equip
{
	int r[5];
	Equip(int a, int b, int c, int d, int e)
	{
		r[0] = a;
		r[1] = b;
		r[2] = c;
		r[3] = d;
		r[4] = e;
	}
	int Get(int bit)
	{
		int result = 0;
		for (int i = 0; i < 5; i++)
			if (bit & (1 << i))
				result += r[i];
		return result;
	}
};
vector<Equip> Equips;
int BitValue[1 << 5];
int F(int bit, int deep)
{
	if (deep == K)
		return 0;

	int result = 0;
	for (int i = 1; i < (1 << 5); i++)
		if ((bit & i) == 0)
			result = max(result, BitValue[i] + F(bit | i, deep + 1));
	return result;
}

void Sol()
{
	for (int i = 1; i < (1 << 5); i++)
		BitValue[i] = 0;
	Equips.clear();

	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d, e;
		std::cin >> a >> b >> c >> d >> e;
		Equips.emplace_back(a, b, c, d, e);
		for (int j = 1; j < (1 << 5); j++)
			BitValue[j] = max(BitValue[j], Equips[i].Get(j));
	}

	std::cout << F(0, 0) << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;
	while (T--)
		Sol();
}