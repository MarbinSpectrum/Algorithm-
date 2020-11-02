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

int T;
int N, M;
class Cell
{
public:
	vector<pair<int, int>> child;
	long long value = 0;
	Cell(int v)
	{
		value = v;
	}
	Cell() {}
	void Clear()
	{
		value = -1;
		child.clear();
	}
};

vector<vector<Cell>> cell;
int GetCell(int r, int c)
{
	if (cell[r][c].value != -1)
		return cell[r][c].value;

	cell[r][c].value = 0;
	for (int i = 0; i < cell[r][c].child.size(); i++)
	{
		pair<int, int> temp = cell[r][c].child[i];
		cell[r][c].value += GetCell(temp.first, temp.second);
	}
	return cell[r][c].value;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		cell.clear();
		cell.resize(N);
		for (int i = 0; i < N; i++)
			cell[i].resize(M);

		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
				cell[n][m].Clear();

		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
			{
				string temp;
				cin >> temp;
				if (temp[0] != '=')
				{
					cell[n][m].value = stoi(temp);
				}
				else
				{
					int c_num = 0;
					int r_num = 0;
					string c = "";
					string r = "";
					for (int i = 1; i < temp.length(); i++)
					{
						if (temp[i] == '+')
						{
							c_num = 0;
							for (int j = 0; j < c.length(); j++)
								c_num += (c[j] - 'A' + 1) * pow(26, c.length() - j - 1);
							r_num = stoi(r);
							//cout << c_num  - 1 << " , " << r_num - 1 << "\n";
							cell[n][m].child.push_back({ c_num - 1,r_num - 1 });
							r = "";
							c = "";
						}
						else if ('A' <= temp[i] && temp[i] <= 'Z')
							c += temp[i];
						else if ('0' <= temp[i] && temp[i] <= '9')
							r += temp[i];
					}
					c_num = 0;
					for (int j = 0; j < c.length(); j++)
						c_num += (c[j] - 'A' + 1) * pow(26, c.length() - j - 1);
					r_num = stoi(r);
					cell[n][m].child.push_back({ c_num - 1,r_num - 1 });
					//cout << c_num - 1 << " , " << r_num - 1 << "\n";
					r = "";
					c = "";
				}
			}

		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
			{
				if (cell[n][m].value != -1)
					continue;
				cell[n][m] = GetCell(n, m);
			}

		for (int m = 0; m < M; m++)
		{
			for (int n = 0; n < N; n++)
				cout << cell[n][m].value << " ";
			cout << "\n";
		}

	}

}