#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>

#pragma warning(disable:4996)

using namespace std;

int S = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;

	int N = 1;
	while (S - N * (N - 1) >= 0)
	{
		if (1 + 2 * N + S - N * (N - 1) <= 500)
		{
			cout << 1 + 2 * N + S - N * (N - 1) << "\n";
			for (int i = 1; i <= N; i++)
				cout << 0 << " " << i << "\n";
			for (int i = 1; i <= N; i++)
				cout << i << " " << i + N << "\n";

			int c = S - N * (N - 1);
			int a = 2 * N;
			for (int i = 0; i < c; i++)
				cout << a + i << " " << a + 1 + i << "\n";

			return 0;
		}
		N++;
	}

}