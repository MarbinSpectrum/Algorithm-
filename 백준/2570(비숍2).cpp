#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include <string.h>

#pragma warning(disable:4996)

using namespace std;

const int MAX = 5002;

int N, M;
vector<int> Case1[MAX];
int Result1 = 0;
vector<int> Case2[MAX];
int Result2 = 0;
int Map[101][101];
bool Check[MAX];
int Link[MAX];

//왼쪽위에서 오른쪽아래
int A_Map[101][101];
//오른쪽위에서 왼쪽아래
int B_Map[101][101];



bool DFS(int n, vector<int> arr[MAX])
{
	for (int i = 0; i < arr[n].size(); i++)
	{
		int idx = arr[n][i];
		if (Check[idx])
			continue;
		Check[idx] = true;
		if (Link[idx] == 0 || DFS(Link[idx], arr))
		{
			Link[idx] = n;
			return true;
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Map[a][b] = 2;
	}

	int a = 0;
	bool flag = false;
	int r = 1;
	int c = 1;
	for (int t = 0; t <= 1; t++)
	{
		for (int i = 0; i <= N; i++)
		{
			if (t == 1 && i == 0)
				continue;
			bool indexOut = false;
			int ar = r + (t == 0 ? i * 2 : 0);
			int ac = c + (t == 1 ? i * 2 : 0);
			if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
				indexOut = true;
			if (indexOut)
				continue;
			flag = false;
			if (Map[ar][ac] == 2)
				flag = false;
			else
			{
				if (!flag)
				{
					flag = true;
					a++;
				}
				A_Map[ar][ac] = a;
			}

			for (int j = 0; j < N; j++)
			{
				ar += 1;
				ac += 1;
				if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
					indexOut = true;
				if (indexOut)
					break;
				if (Map[ar][ac] == 2)
					flag = false;
				else
				{
					if (!flag)
					{
						flag = true;
						a++;
					}
					A_Map[ar][ac] = a;
				}
			}

			if (indexOut)
				continue;
		}
		flag = false;
	}

	int b = 0;
	r = 1;
	c = N;

	if (N % 2 == 0)
	{
		b = 0;
		r = 1;
		c = N;
		for (int t = 0; t <= 1; t++)
		{
			for (int i = 0; i <= N; i++)
			{
				bool indexOut = false;
				int ar = r + (t == 0 ? i * 2 + 1 : 0);
				int ac = c - (t == 1 ? i * 2 + 1 : 0);
				if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
					indexOut = true;
				if (indexOut)
					continue;
				//cout << ar << " " << ac << "\n";
				flag = false;
				if (Map[ar][ac] == 2)
					flag = false;
				else
				{
					if (!flag)
					{
						flag = true;
						b++;
					}
					B_Map[ar][ac] = b;
				}

				for (int j = 0; j < N; j++)
				{
					ar += 1;
					ac -= 1;
					if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
						indexOut = true;
					if (indexOut)
						break;
					if (Map[ar][ac] == 2)
						flag = false;
					else
					{
						if (!flag)
						{
							flag = true;
							b++;
						}
						B_Map[ar][ac] = b;
					}
				}

				if (indexOut)
					continue;
			}
			flag = false;
		}
	}
	else
	{
		b = 0;
		r = 1;
		c = N;
		for (int t = 0; t <= 1; t++)
		{
			for (int i = 0; i <= N; i++)
			{
				if (t == 1 && i == 0)
					continue;
				bool indexOut = false;
				int ar = r + (t == 0 ? i * 2 : 0);
				int ac = c - (t == 1 ? i * 2 : 0);
				if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
					indexOut = true;
				if (indexOut)
					continue;
				//cout << ar << " " << ac << "\n";
				flag = false;
				if (Map[ar][ac] == 2)
					flag = false;
				else
				{
					if (!flag)
					{
						flag = true;
						b++;
					}
					B_Map[ar][ac] = b;
				}

				for (int j = 0; j < N; j++)
				{
					ar += 1;
					ac -= 1;
					if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
						indexOut = true;
					if (indexOut)
						break;
					if (Map[ar][ac] == 2)
						flag = false;
					else
					{
						if (!flag)
						{
							flag = true;
							b++;
						}
						B_Map[ar][ac] = b;
					}
				}

				if (indexOut)
					continue;
			}
			flag = false;
		}
	}

	//cout << "-----------------------------------------\n";

	//for (int r = 1; r <= N; r++)
	//{
	//	for (int c = 1; c <= N; c++)
	//		cout << A_Map[r][c] << " ";
	//	cout << "\n";
	//}

	//cout << "-----------------------------------------\n";

	//for (int r = 1; r <= N; r++)
	//{
	//	for (int c = 1; c <= N; c++)
	//		cout << B_Map[r][c] << " ";
	//	cout << "\n";
	//}

	//cout << "-----------------------------------------\n";

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			if (Map[r][c] != 2)
			{
				int aa = A_Map[r][c];
				int bb = B_Map[r][c];
				if (aa == 0 || bb == 0)
					continue;
				Case1[aa].push_back(bb);
			}

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			A_Map[r][c] = 0;
			B_Map[r][c] = 0;
		}

	for (int i = 0; i < MAX; i++)
	{
		memset(Check, false, sizeof(Check));
		Result1 += DFS(i, Case1);
	}

	a = 0;
	flag = false;
	r = 1;
	c = 1;
	for (int t = 0; t <= 1; t++)
	{
		for (int i = 0; i <= N; i++)
		{
			bool indexOut = false;
			int ar = r + (t == 0 ? i * 2 + 1 : 0);
			int ac = c + (t == 1 ? i * 2 + 1 : 0);
			if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
				indexOut = true;
			if (indexOut)
				continue;
			flag = false;
			if (Map[ar][ac] == 2)
				flag = false;
			else
			{
				if (!flag)
				{
					flag = true;
					a++;
				}
				A_Map[ar][ac] = a;
			}

			for (int j = 0; j < N; j++)
			{
				ar += 1;
				ac += 1;
				if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
					indexOut = true;
				if (indexOut)
					break;
				if (Map[ar][ac] == 2)
					flag = false;
				else
				{
					if (!flag)
					{
						flag = true;
						a++;
					}
					A_Map[ar][ac] = a;
				}
			}

			if (indexOut)
				continue;
		}
		flag = false;
	}

	if (N % 2 != 0)
	{
		b = 0;
		r = 1;
		c = N;
		for (int t = 0; t <= 1; t++)
		{
			for (int i = 0; i <= N; i++)
			{
				bool indexOut = false;
				int ar = r + (t == 0 ? i * 2 + 1 : 0);
				int ac = c - (t == 1 ? i * 2 + 1 : 0);
				if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
					indexOut = true;
				if (indexOut)
					continue;
				//cout << ar << " " << ac << "\n";
				flag = false;
				if (Map[ar][ac] == 2)
					flag = false;
				else
				{
					if (!flag)
					{
						flag = true;
						b++;
					}
					B_Map[ar][ac] = b;
				}

				for (int j = 0; j < N; j++)
				{
					ar += 1;
					ac -= 1;
					if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
						indexOut = true;
					if (indexOut)
						break;
					if (Map[ar][ac] == 2)
						flag = false;
					else
					{
						if (!flag)
						{
							flag = true;
							b++;
						}
						B_Map[ar][ac] = b;
					}
				}

				if (indexOut)
					continue;
			}
			flag = false;
		}
	}
	else
	{
		b = 0;
		r = 1;
		c = N;
		for (int t = 0; t <= 1; t++)
		{
			for (int i = 0; i <= N; i++)
			{
				if (t == 1 && i == 0)
					continue;
				bool indexOut = false;
				int ar = r + (t == 0 ? i * 2 : 0);
				int ac = c - (t == 1 ? i * 2 : 0);
				if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
					indexOut = true;
				if (indexOut)
					continue;
				//cout << ar << " " << ac << "\n";
				flag = false;
				if (Map[ar][ac] == 2)
					flag = false;
				else
				{
					if (!flag)
					{
						flag = true;
						b++;
					}
					B_Map[ar][ac] = b;
				}

				for (int j = 0; j < N; j++)
				{
					ar += 1;
					ac -= 1;
					if (!(1 <= ar && ar <= N && 1 <= ac && ac <= N))
						indexOut = true;
					if (indexOut)
						break;
					if (Map[ar][ac] == 2)
						flag = false;
					else
					{
						if (!flag)
						{
							flag = true;
							b++;
						}
						B_Map[ar][ac] = b;
					}
				}

				if (indexOut)
					continue;
			}
			flag = false;
		}
	}

	//for (int r = 1; r <= N; r++)
	//{
	//	for (int c = 1; c <= N; c++)
	//		cout << A_Map[r][c] << " ";
	//	cout << "\n";
	//}

	//cout << "-----------------------------------------\n";

	//for (int r = 1; r <= N; r++)
	//{
	//	for (int c = 1; c <= N; c++)
	//		cout << B_Map[r][c] << " ";
	//	cout << "\n";
	//}

	//cout << "-----------------------------------------\n";

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			if (Map[r][c] != 2)
			{
				int aa = A_Map[r][c];
				int bb = B_Map[r][c];
				if (aa == 0 || bb == 0)
					continue;
				Case2[aa].push_back(bb);
			}

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			A_Map[r][c] = 0;
			B_Map[r][c] = 0;
		}

	memset(Link, 0, sizeof(Link));
	for (int i = 0; i < MAX; i++)
	{
		memset(Check, false, sizeof(Check));
		Result2 += DFS(i, Case2);
	}

	cout << Result1 + Result2 << "\n";

}