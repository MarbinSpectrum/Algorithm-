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

int N;
vector<long long> Arr;

bool Check(long long n)
{
	vector<long long> temp;
	for (int i = 0; i < N; i++)
	{
		long long t = Arr[i] / n;
		if (t * n == Arr[i])
			temp.push_back(t);
		else
			temp.push_back(t + 1);
	}

	int a = 0;
	int b = 0;
	for (int i = 0; i < N; i++)
	{
		if (temp[i] == 1)
			a++;
		else if (b == 0)
			b = temp[i] - 1;
		else
			b += temp[i] - 2;
	}
	return (a >= b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	Arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	sort(Arr.begin(), Arr.end());
	long long left = 1;
	long long right = 1000000000;
	long long Result = 1000000000;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (Check(mid))
		{
			Result = min(Result, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << Result << endl;

}