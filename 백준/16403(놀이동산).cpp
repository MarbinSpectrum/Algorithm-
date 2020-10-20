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

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

const int MAX = 500000;

int N;
int A, B;
vector<int> Citizen;
int DP[10001];
int GetDP(int i)
{
	if (10000 < i || i < 0)
		return 0;
	return DP[i];
}

int F(int a, int b)
{
	int center = (a + b) / 2;

	//모여서 버스타가 가자
	int case1 = 0;
	for (int i = a; i <= b; i++)
		case1 += abs(Citizen[i] - Citizen[center]);
	case1 *= A;
	case1 += B;

	//각자 택시타고 가자
	int case2 = 0;
	for (int i = a; i <= b; i++)
		case2 += Citizen[i];
	case2 *= A;

	return min(case1, case2);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력부
	cin >> N;
	cin >> A >> B;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Citizen.push_back(temp);
	}
	sort(Citizen.begin(), Citizen.end());

	int front = 0;

	for (int i = 0; i < Citizen.size(); i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (i - j < 0)
				break;
			if (j == 0)
				DP[i] = GetDP(i - j - 1) + F(i - j, i);
			else
				DP[i] = min(DP[i], GetDP(i - j - 1) + F(i - j, i));
		}
	}

	cout << DP[Citizen.size() - 1] << endl;

}