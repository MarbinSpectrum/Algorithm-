#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

#pragma warning(disable:4996)

using namespace std;

int R, C, N;
char Data[30000][30];

char Get(int r, int c)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
		return 'X';
	return Data[r][c];
}

class Pos
{
public:
	stack<pair<int, int>> st;
	void Update()
	{
		int ar = st.top().first;
		int ac = st.top().second;
		while (true)
		{
			if (Get(ar, ac) != '.')
			{
				st.pop();
				ar = st.top().first;
				ac = st.top().second;
			}
			else if (Get(ar - 1, ac) == '.')
			{
				ar--;
				st.push(make_pair(ar, ac));
			}
			else if (Get(ar - 1, ac) == 'X')
				break;
			else  if (Get(ar - 1, ac) == 'O')
			{
				if (Get(ar, ac - 1) == '.' && Get(ar - 1, ac - 1) == '.')
				{
					ac--;
					ar--;
					st.push(make_pair(ar, ac));
				}
				else if (Get(ar, ac + 1) == '.' && Get(ar - 1, ac + 1) == '.')
				{
					ac++;
					ar--;
					st.push(make_pair(ar, ac));
				}
				else
					break;
			}
		}
	}
};

Pos pos[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int r = R - 1; r >= 0; r--)
		for (int c = 0; c < C; c++)
			cin >> Data[r][c];

	for (int i = 0; i < C; i++)
		pos[i].st.push(make_pair(R - 1, i));

	cin >> N;

	while (N--)
	{
		int K;
		cin >> K;
		K -= 1;
		pos[K].Update();
		Data[pos[K].st.top().first][pos[K].st.top().second] = 'O';
		pos[K].st.pop();
	}

	for (int r = R - 1; r >= 0; r--)
	{
		for (int c = 0; c < C; c++)
			cout << Data[r][c];
		cout << "\n";
	}
}