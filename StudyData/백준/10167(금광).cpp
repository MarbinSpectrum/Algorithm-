#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

int N;
struct Mine
{
	int x, y, w;
	Mine(int ax, int ay, int aw)
	: x(ax)
	, y(ay)
	, w(aw)
	{
	}
};
vector<Mine> mine;
map<int, int> x;
map<int, int> y;
int xSize;
int ySize;
vector<Mine> yMine[3001];
struct Seg
{
	int sum;
	int lmax;
	int rmax;
	int tmax;

	void Init()
	{
		sum = lmax = rmax = tmax = 0;
	}
};
const int treeSize = 20000;
Seg seg[treeSize];

void Update(int n, int l, int r, int idx, int v)
{
	if (r < idx || idx < l)
		return;
	if (l == r && r == idx)
	{
		seg[n].sum += v;
		seg[n].lmax += v;
		seg[n].rmax += v;
		seg[n].tmax += v;
		return;
	}

	int m = (l + r) / 2;
	Update(n * 2, l, m, idx, v);
	Update(n * 2 + 1, m + 1, r, idx, v);

	seg[n].sum = seg[n * 2].sum + seg[n * 2 + 1].sum;
	seg[n].lmax = max(seg[n * 2].lmax, seg[n * 2].sum + seg[n * 2 + 1].lmax);
	seg[n].rmax = max(seg[n * 2 + 1].rmax, seg[n * 2 + 1].sum + seg[n * 2].rmax);
	seg[n].tmax = max({ seg[n * 2].tmax,seg[n * 2 + 1].tmax,seg[n * 2].rmax + seg[n * 2 + 1].lmax });
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	vector<int> tempX;
	vector<int> tempY;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		mine.emplace_back(a, b, c);
		tempX.push_back(a);
		tempY.push_back(b);
	}

	{
		sort(tempX.begin(), tempX.end());
		x[tempX[0]] = 0;
		int idx = 1;
		int backX = tempX[0];
		for (int i = 1; i < tempX.size(); i++)
			if (backX != tempX[i])
			{
				backX = tempX[i];
				x[tempX[i]] = idx++;
			}
		xSize = idx;
	}
	{
		sort(tempY.begin(), tempY.end());
		y[tempY[0]] = 0;
		int idx = 1;
		int backY = tempY[0];
		for (int i = 1; i < tempY.size(); i++)
			if (backY != tempY[i])
			{
				backY = tempY[i];
				y[tempY[i]] = idx++;
			}
		ySize = idx;
	}

	for (int i = 0; i < N; i++)
	{
		yMine[y[mine[i].y]].emplace_back(mine[i]);
	}

	int result = 0;
	for (int s = 0; s < ySize; s++)
	{
		for (int i = 0; i < treeSize; i++)
		{
			seg[i].Init();
		}

		for (int e = s; e < ySize; e++)
		{
			for (int i = 0; i < yMine[e].size(); i++)
			{
				int idx = x[yMine[e][i].x];
				int w = yMine[e][i].w;
				Update(1, 0, xSize - 1, idx, w);
			}
			result = max(result, seg[1].tmax);
		}
	}

	std::cout << result << endl;
}