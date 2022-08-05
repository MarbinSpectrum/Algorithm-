#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

map<int,int> Map;
int size = 0;

void D(const string& s, int d)
{
	int st = 0;
	int p = -1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
			st++;
		else if (s[i] == ']')
			st--;
        
        	if (s[i] == ',' && st == 1)
		{
			p = i;
			break;
		}
	}

	if (p == -1)
	{
		int num = stol(s);
        	size++;
		Map[num<<d]++;
	}
	else
	{
		D(s.substr(1, p - 1), d + 1);
		D(s.substr(p + 1, s.length() - p - 2), d + 1);
	}
}
void F()
{
    	Map.clear();
    	size = 0;
	std::string s;
	std::cin >> s;

	D(s, 0);

	int ans = INF;
	for (auto mp : Map)
	{
		ans = min(ans,size - mp.second);
	}

	std::cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		F();
	}
}
