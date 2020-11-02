#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<deque>

#pragma warning(disable:4996)

using namespace std;

int N, L;
//숫자, 삭제번호
deque<pair<int, int>> Deque;

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int emp;
		scanf("%d", &emp);

		while (!Deque.empty() && Deque.back().first >= emp)
			Deque.pop_back();

		if (!Deque.empty())
		{
			pair<int, int> temp = Deque.front();
			if (temp.second == i)
				Deque.pop_front();
		}

		Deque.push_back(make_pair(emp, i + L));
		printf("%d ", Deque.front().first);
	}

}