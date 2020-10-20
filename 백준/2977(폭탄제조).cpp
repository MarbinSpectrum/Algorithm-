#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <tuple>
#include <list>
#include <map>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int N, M;
class Part
{
public:
	int a, b, c, d, e, f;
	Part(int aa, int ab, int ac, int ad, int ae, int af)
	{
		a = aa;
		b = ab;
		c = ac;
		d = ad;
		e = ae;
		f = af;
	}
	Part()
	{

	}
};

Part part[100];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		part[i] = Part(a, b, c, d, e, f);
	}

	int l, r;
	l = 0;
	r = 100000;
	int result = 0;
	while (l <= r)
	{
		int money = M;
		int m = (l + r) / 2;

		bool flag = false;

		for (int i = 0; i < N; i++)
		{
			int cost_m = INF;
			int a = ceil((part[i].a * m - part[i].b) / (float)part[i].c);
			int b = 0;
			while (a >= 0)
			{
				//if (m == 5)
				//	Debug(a, b);
				cost_m = min(cost_m, part[i].d * a + part[i].f * b);
				a--;
				int temp = (part[i].a * m - part[i].b) - a * part[i].c;
				b = ceil(temp / (float)part[i].e);
			}

			if (money - cost_m < 0)
			{
				flag = true;
				break;
			}
			else
			{
				money -= cost_m;
			}

		}


		if (flag)
			r = m - 1;
		else
		{
			result = max(result, m);
			l = m + 1;
		}
	}
	cout << result << endl;
}
