#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <ctype.h>

#pragma warning(disable:4996)

using namespace std;

long long d, t;
long long mod = 31991;
vector<vector<long long>> matrix;
vector<vector<long long>> Identity;
vector<vector<long long>> Mul(vector<vector<long long>> A, vector<vector<long long>> B)
{
	vector<vector<long long>> temp(d);
	for (int i = 0; i < d; i++)
		temp[i].resize(d);
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
		{
			long long value = 0;
			for (int k = 0; k < d; k++)
				value += (A[k][i] * B[j][k]) % mod;
			value %= mod;
			temp[j][i] = value;
		}

	return temp;
}

vector<vector<long long>> Pow(vector<vector<long long>> A, long long B)
{
	if (B == 0)
		return Identity;
	if (B == 1)
		return A;
	vector<vector<long long>> v = Pow(A, B / 2);
	if (B & 1)
		return Mul(A, Mul(v, v));
	else
		return Mul(v, v);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> d >> t;
	matrix.resize(d);
	for (int i = 0; i < d; i++)
		matrix[i].resize(d);

	Identity.resize(d);
	for (int i = 0; i < d; i++)
		Identity[i].resize(d);
	for (int i = 0; i < d; i++)
		Identity[i][i] = 1;

	for (int i = 0; i < d; i++)
		matrix[0][i] = 1;
	for (int i = 1; i < d; i++)
		matrix[i][i - 1] = 1;

	vector<vector<long long>> Result = Pow(matrix, t);

	cout << Result[0][0] << endl;

}