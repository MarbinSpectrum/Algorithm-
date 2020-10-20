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

const int INF = 9999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int N;
int Result = 0;
int A = 0;
vector<int> Arr;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Arr.push_back(-temp);
	}
	sort(Arr.begin(), Arr.end());
	for (int i = 0; i < N; i++)
		Arr[i] = -Arr[i];

	for (int i = 0; i < N; i++)
	{
		if (Arr[i] - A <= 0)
			break;
		else
		{
			Result += Arr[i] - A;
			A++;
		}
	}

	cout << Result << endl;

}