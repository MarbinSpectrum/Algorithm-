#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const float INF = 1e10;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int GCD(int pA, int pB)
{
	if (pB == 0) 
		return pA;
	else return GCD(pB, pA % pB);
}
int N;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	while(N--)
	{
		int X, Y;
		std::cin >> X >> Y;
		int K;
		std::cin >> K;
		vector<int> A(K);
		for (int i = 0; i < K; i++)
		{
			std::cin >> A[i];
		}

		int v = A[0];
		for (int i = 1; i < K; i++)
		{
			v = GCD(v, A[i]);
		}

		if (X % v == 0 && Y % v == 0)
		{
			std::cout << "Ta-da" << endl;
		}
		else
		{
			std::cout << "Gave up" << endl;
		}
	}
}