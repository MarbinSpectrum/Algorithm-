#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <map>

#pragma warning(disable:4996)

using namespace std;

int T;

set<long long> SET[50000];
vector<pair<int, int>> Point;

bool Check(pair<int, int> p)
{
	if (p.first < 15000 || p.first > 35000 || p.second < 15000 || p.second > 35000)
		return false;
	return SET[p.first].count(p.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		long long N;
		cin >> N;
		for (int i = 0; i < 50000; i++)
			SET[i].clear();
		Point.clear();
		while (N--)
		{
			long long a, b;
			cin >> a >> b;
			a += 25000;
			b += 25000;
			SET[a].insert(b);
			Point.push_back({ a,b });
		}
		long long r = 0;
		for (int i = 0; i < Point.size(); i++)
		{
			for (int j = i + 1; j < Point.size(); j++)
			{
				long long w = abs(Point[i].first - Point[j].first);
				long long h = abs(Point[i].second - Point[j].second);
				if (w * w + h * h < r)
					continue;
				pair<int, int> check1;
				pair<int, int> check2;
				if ((Point[i].first <= Point[j].first && Point[i].second >= Point[j].second) || (Point[i].first >= Point[j].first && Point[i].second <= Point[j].second))
				{
					check1 = { Point[i].first + h,Point[i].second + w };
					check2 = { Point[j].first + h,Point[j].second + w };
					if (Check(check1) && Check(check2))
					{
						r = w * w + h * h;
						continue;
					}
					check1 = { Point[i].first - h,Point[i].second - w };
					check2 = { Point[j].first - h,Point[j].second - w };
					if (Check(check1) && Check(check2))
					{
						r = w * w + h * h;
						continue;
					}
				}
				else if ((Point[i].first <= Point[j].first && Point[i].second <= Point[j].second) || (Point[i].first >= Point[j].first && Point[i].second >= Point[j].second))
				{
					check1 = { Point[i].first + h,Point[i].second - w };
					check2 = { Point[j].first + h,Point[j].second - w };
					if (Check(check1) && Check(check2))
					{
						r = w * w + h * h;
						continue;
					}
					check1 = { Point[i].first - h,Point[i].second + w };
					check2 = { Point[j].first - h,Point[j].second + w };
					if (Check(check1) && Check(check2))
					{
						r = w * w + h * h;
						continue;
					}
				}
			}
		}
		cout << r << endl;

	}

}