#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>

#pragma warning(disable:4996)

using namespace std;

bool Visit[20001];

void F(int N)
{
	queue<pair<long long, string>> Queue;
	Queue.push({ 1,"1" });
	while (!Queue.empty())
	{
		pair<long long, string> temp = Queue.front();
		Queue.pop();

		if (temp.first % N == 0)
			cout << temp.second << "\n";

		pair<long long, string> a = { (temp.first * (long long)10) % N, temp.second + "0" };
		pair<long long, string> b = { (temp.first * (long long)10 + (long long)1) % N,temp.second + "1" };

		if (!Visit[a.first])
		{
			Visit[a.first] = true;
			Queue.push(a);
		}
		if (!Visit[b.first])
		{
			Visit[b.first] = true;
			Queue.push(b);
		}
	}


}

int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		if (N == 1)
			cout << 1 << endl;
		else
		{
			memset(Visit, false, sizeof(Visit));
			F(N);
		}
	}

}