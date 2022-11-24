#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int a, b, c;
int DP[40][101][101][101];
//char State(int pT, int pA, int pB, int pC)
//{
//	int A = DP[pT][pA][pB][pC];
//	int B = a + b + c - A;
//	if (A > B)
//		return 'F';
//	else if (A < B)
//		return 'S';
//	else
//		return 'D';
//}
int Dp(int pT, int pA, int pB, int pC)
{
	int& ref = DP[pT][pA][pB][pC];

	if (ref != -1)
		return ref;

	if (pA == 0 && pA == pB && pB == pC)
	{
		ref = 0;
	}
	else if (pT % 2 == 0)
	{
		ref = INF;
		if (pA > 0)
		{
			if (pT > pA)
				ref = min(ref, Dp(pT + 1, 0, pB, pC));
			else
				ref = min(ref, Dp(pT + 1, pA - pT, pB, pC));
		}

		if (pB > 0)
		{
			if (pT > pB)
				ref = min(ref, Dp(pT + 1, pA, 0, pC));
			else
				ref = min(ref, Dp(pT + 1, pA, pB - pT, pC));
		}

		if (pC > 0)
		{
			if (pT > pC)
				ref = min(ref, Dp(pT + 1, pA, pB, 0));
			else
				ref = min(ref, Dp(pT + 1, pA, pB, pC - pT));
		}
	}
	else
	{
		ref = 0;
		if (pA > 0)
		{
			if (pT > pA)
				ref = max(ref, Dp(pT + 1, 0, pB, pC) + pA);
			else
				ref = max(ref, Dp(pT + 1, pA - pT, pB, pC) + pT);
		}

		if (pB > 0)
		{
			if (pT > pB)
				ref = max(ref, Dp(pT + 1, pA, 0, pC) + pB);
			else
				ref = max(ref, Dp(pT + 1, pA, pB - pT, pC) + pT);
		}
		
		if (pC > 0)
		{
			if (pT > pC)
				ref = max(ref, Dp(pT + 1, pA, pB, 0) + pC);
			else
				ref = max(ref, Dp(pT + 1, pA, pB, pC - pT) + pT);
		}
	}
	return ref;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				for (int l = 0; l < 101; l++)
					DP[i][j][k][l] = -1;

	std::cin >> a >> b >> c;

	int cnt = Dp(1, a, b, c);

	if (cnt == a + b + c - cnt)
		std::cout << "D" << endl;
	else 	if (cnt > a + b + c - cnt)
		std::cout << "F" << endl;
	else
		std::cout << "S" << endl;
}