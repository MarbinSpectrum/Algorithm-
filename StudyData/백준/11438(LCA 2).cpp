#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 100001

using namespace std;

int N, M;

int Depth[MAX];
int AC[MAX][20];

vector<int> Graph[MAX];

int maxLevel;

void MakeNode(int here, int parent)
{
	Depth[here] = Depth[parent] + 1;

	AC[here][0] = parent;

	maxLevel = (int)floor(log2(MAX));

	for (int i = 1; i <= maxLevel; i++)
	{
		int temp = AC[here][i - 1];
		AC[here][i] = AC[temp][i - 1];
	}

	int len = Graph[here].size();
	for (int i = 0; i < len; i++)
	{
		int there = Graph[here][i];
		if (there != parent)
			MakeNode(there, here);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i < N; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		Graph[from].push_back(to);
		Graph[to].push_back(from);
	}

	Depth[0] = -1;

	MakeNode(1, 0);

	scanf("%d", &M);

	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (Depth[a] != Depth[b])
		{
			if (Depth[a] > Depth[b])
				swap(a, b);

			for (int i = maxLevel; i >= 0; i--)
			{
				if (Depth[a] <= Depth[AC[b][i]])
					b = AC[b][i];
			}
		}

		int lca = a;

		if (a != b)
		{
			for (int i = maxLevel; i >= 0; i--)
			{
				if (AC[a][i] != AC[b][i])
				{
					a = AC[a][i];
					b = AC[b][i];
				}
				lca = AC[a][i];
			}
		}

		printf("%d\n", lca);
	}
}