#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int l;
int r;
int N;
string str;
int s = 0;
int k = 0;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> str;
	r = N / 2;
	l = 0;

	for (int i = 0; i < N; i++)
	{
		if (i >= N / 2)
		{
			if (s == N / 4 && k == N / 4)
			{
				if (l == 0)
				{
					std::cout << 1 << endl;
					std::cout << r << endl;
				}
				else
				{
					std::cout << 2 << endl;
					std::cout << l << " " << r << endl;
				}
				return 0;
			}

			if (str[l] == 's')
				s--;
			else
				k--;
			l++;
			r++;
		}

		if (str[i] == 's')
			s++;
		else
			k++;
	}
}