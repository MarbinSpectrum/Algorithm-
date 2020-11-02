#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>

#pragma warning(disable:4996)

using namespace std;

int N, M;
//숫자, 삭제번호
deque<pair<int, int>> Deque;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int emp;
		cin >> emp;

		while (!Deque.empty() && Deque.back().first <= emp)
			Deque.pop_back();

		if (!Deque.empty())
		{
			pair<int, int> temp = Deque.front();
			if (temp.second == i)
				Deque.pop_front();
		}

		Deque.push_back(make_pair(emp, i + (M - 1) * 2 + 1));
		if (i >= (M - 1) * 2)
			printf("%d ", Deque.front().first);
	}
}