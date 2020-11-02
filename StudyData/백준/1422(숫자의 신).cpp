#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

#pragma warning(disable:4996)

using namespace std;

int N, K;
int maxIndex = 0;
vector<string> Arr;
long long int maxArr = -1;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main()
{

	cin >> K >> N;
	Arr.resize(K);
	for (int i = 0; i < K; i++)
		cin >> Arr[i];

	sort(Arr.begin(), Arr.end(), cmp);

	for (int i = 0; i < K; i++)
	{
		long long int emp = 0;
		for (int j = 0; j < Arr[i].length(); j++)
			emp += (Arr[i][Arr[i].length() - j - 1] - '0') * pow(10, j);

		if (maxArr < emp)
		{
			maxArr = emp;
			maxIndex = i;
		}
	}

	for (int i = 0; i < K; i++)
	{
		if (i == maxIndex)
			for (int j = 0; j < N - K; j++)
				cout << Arr[i];
		cout << Arr[i];
	}
	printf("\n");
}