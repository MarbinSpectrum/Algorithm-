#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>

#pragma warning(disable:4996)

using namespace std;

#define MAX 1000

class Pos
{
public:
	int x;
	int y;
	Pos(int ax, int ay)
	{
		x = ax;
		y = ay;
	}

	friend bool operator ==(const Pos& other1, const Pos& other2)
	{
		return other1.x == other2.x && other1.y == other2.y;
	}

	friend bool operator !=(const Pos& other1, const Pos& other2)
	{
		return other1.x != other2.x || other1.y != other2.y;
	}
};

int field[MAX][MAX];
bool check[MAX][MAX];

int R, C;

int Dic[4][2] = { {-1,0},{0,-1},{1,0},{0,+1} };

bool Get(int x, int y)
{
	//printf("%d %d\n", x, y);

	if (x < 0 || x >= C || y < 0 || y >= R)
		return false;

	return check[x][y];
}

int Around(int x, int y)
{
	int block = 0;
	for (int i = 0; i < 4; i++)
	{
		int ax = x + Dic[i][0];
		int ay = y + Dic[i][1];
		if (!Get(ax, ay))
			block++;
	}

	return block;
}

void DicPrint(int i)
{
	switch (i)
	{
	case 0:
		printf("L");
		break;
	case 1:
		printf("U");
		break;
	case 2:
		printf("R");
		break;
	case 3:
		printf("D");
		break;
	}
	//	printf("\n");
}

int main()
{

	cin >> R >> C;

	for (int j = 0; j < R; j++)
		for (int i = 0; i < C; i++)
			scanf("%d", &field[i][j]);

	//R = 4;
	//C = 4;

	//for (int i = 0; i < C; i++)
	//	for (int j = 0; j < R; j++)
	//		field[i][j] = 2;

	//field[2][3] = 1;

	if ((C % 2 == 1 && R % 2 == 1) || (C % 2 == 0 && R % 2 == 1))
	{
		bool flag = false;

		for (int j = 0; j < R; j++)
		{
			if (!flag)
			{
				for (int j = 0; j < C - 1; j++)
					printf("R");
			}
			else
			{
				for (int j = 0; j < C - 1; j++)
					printf("L");
			}

			if (j != R - 1)
				printf("D");
			else
				printf("\n");

			flag = !flag;
		}
	}
	///////////////////////////////////////////////////////////////////////
	else if (C % 2 == 1 && R % 2 == 0)
	{
		bool flag = false;

		for (int i = 0; i < C; i++)
		{
			if (!flag)
			{
				for (int j = 0; j < R - 1; j++)
					printf("D");
			}
			else
			{
				for (int j = 0; j < R - 1; j++)
					printf("U");
			}

			if (i != C - 1)
				printf("R");
			else
				printf("\n");

			flag = !flag;
		}
	}
	///////////////////////////////////////////////////////////////////////
	else if (R % 2 == 0 && R % 2 == 0)
	{
		Pos minPos(1, 0);
		int minV = 10000;

		for (int j = 0; j < R; j++)
			for (int i = 0; i < C; i++)
			{
				if ((i + j) % 2 == 1 && field[i][j] <= minV)
				{
					minV = field[i][j];
					minPos.x = i;
					minPos.y = j;
					//cout << "minPos <" << minPos.x << "," << minPos.y << "> = " << field[i][j] << endl;
				}
				check[i][j] = true;
			}

		check[minPos.x][minPos.y] = false;

		//cout << "minPos <" << minPos.x << "," << minPos.y << ">" << endl;

		///////////////////////////////////////////////////////////////////////

		bool flag = false;

		Pos StartPos(0, 0);
		Pos EndPos(C - 1, R - 1);

		check[0][0] = false;

		while (StartPos != EndPos)
		{
			bool move = false;

			if (!move)
			{
				for (int i = 0; i < 4; i++)
				{
					Pos emp(StartPos.x + Dic[i][0], StartPos.y + Dic[i][1]);
					if (Get(emp.x, emp.y) && Around(emp.x, emp.y) == 3 && emp != EndPos)
					{
						//	cout << "Case1 <" << emp.x << "," << emp.y << "> = " << Get(emp.x, emp.y) << endl;

						move = true;
						StartPos.x = StartPos.x + Dic[i][0];
						StartPos.y = StartPos.y + Dic[i][1];
						check[emp.x][emp.y] = false;
						DicPrint(i);
						break;
					}
				}
			}

			if (!move)
			{
				for (int i = 0; i < 4; i++)
				{

					Pos emp(StartPos.x + Dic[i][0], StartPos.y + Dic[i][1]);
					if (Get(emp.x, emp.y))
					{
						//	cout << "Case2 <" << emp.x << "," << emp.y << "> = " << Get(emp.x, emp.y) << endl;

						move = true;
						StartPos.x = StartPos.x + Dic[i][0];
						StartPos.y = StartPos.y + Dic[i][1];
						check[emp.x][emp.y] = false;
						DicPrint(i);
						break;
					}
				}
			}
		}


	}

	return 0;

}