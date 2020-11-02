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

vector<long long> Tree;
long long Arr[1000001];
int N, M, K;
long long Init(int node, int start, int end)
{
	//Tree[node]는 Start ~ End까지의 합을 의미
	if (start == end)
		Tree[node] = Arr[start];
	else
		Tree[node] = Init(node * 2, start, (start + end) / 2) + Init(node * 2 + 1, (start + end) / 2 + 1, end);

	return Tree[node];
}

long long Sum(int node, int start, int end, int left, int right)
{
	//탐색범위에 내가 구할려는 범위가 없는경우
	if (left > end || right < start)
		return 0;

	//탐색범위에 내가 구할려는 범위보다 클경우
	if (left <= start && end <= right)
		return Tree[node];

	//탐색범위에 내가 구할려는 범위안에 있을경우
	//자식노드들을 탐색
	return Sum(node * 2, start, (start + end) / 2, left, right) + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

//index : 바꾼 숫자의 인덱스번호
//diff : 바뀐수치
void Update(int node, int start, int end, int index, long long diff)
{
	if (start == end && end == index)
	{
		Arr[index] += diff;
		Tree[node] += diff;
		return;
	}
	if (start > index || end < index)
		return;
	Tree[node] += diff;
	Update(node * 2, start, (start + end) / 2, index, diff);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	int H = ceil(log2f(N));
	Tree.resize(pow(2, H + 1));
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	Init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			b--;
			Update(1, 0, N - 1, b, c - Arr[b]);
		}
		else if (a == 2)
		{
			b--;
			c--;
			cout << Sum(1, 0, N - 1, b, c) << endl;
		}


	}
}