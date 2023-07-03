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

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		int Q;
		priority_queue<int> pq0;
		priority_queue<int> pq1;
		map<int, int> map0;
		map<int, int> map1;

		std::cin >> Q;
		for (int i = 0; i < Q; i++)
		{
			string s;
			int a;
			std::cin >> s >> a;
			if (s[0] == 'I')
			{
				pq0.push(a);
				pq1.push(-a);
			}
			else
			{
				if (a == 1)
				{
					while (true)
					{
						if (pq0.empty())
							break;
						int temp = pq0.top();
						if (map0[temp])
						{
							map0[temp]--;
							pq0.pop();
						}
						else
						{
							pq0.pop();
							map1[-temp]++;
							break;
						}
					}
				}
				else
				{
					while (true)
					{
						if (pq1.empty())
							break;
						int temp = pq1.top();
						if (map1[temp])
						{
							map1[temp]--;
							pq1.pop();
						}
						else
						{
							pq1.pop();
							map0[-temp]++;
							break;
						}
					}
				}
			}
		}
		bool check = true;

		while (true)
		{
			if (pq0.empty())
				break;
			int temp = pq0.top();
			if (map0[temp])
			{
				map0[temp]--;
				pq0.pop();
			}
			else
			{
				if (pq0.empty() == false)
				{
					std::cout << pq0.top() << " ";
					check = false;
					break;
				}
			}
		}

		while (true)
		{
			if (pq1.empty())
				break;
			int temp = pq1.top();
			if (map1[temp])
			{
				map1[temp]--;
				pq1.pop();
			}
			else
			{
				if (pq1.empty() == false)
				{
					std::cout << -pq1.top() << endl;
					check = false;
					break;
				}
			}
		}

		if (check)
		{
			std::cout << "EMPTY" << endl;
		}
	}
}