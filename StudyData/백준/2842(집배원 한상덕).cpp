#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>
#include <map>

#pragma warning(disable:4996)

using namespace std;

int Dic[8][2] = { {+1,0},{-1,0} ,{0,+1} ,{0,-1},{+1,1},{-1,-1} ,{-1,+1} ,{+1,-1} };

int N;

///////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> Field_Height;
int Get_Field_Height(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 9876543210;
	return Field_Height[x][y];
}

///////////////////////////////////////////////////////////////////////////////////

vector<vector<char>> Field_Data;
char Get_Field_Data(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return '#';
	return Field_Data[x][y];
}

///////////////////////////////////////////////////////////////////////////////////

vector<vector<bool>> Visit;
bool Get_Visit(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	return Visit[x][y];
}
void Init_Visit()
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			Visit[x][y] = false;
}

///////////////////////////////////////////////////////////////////////////////////

pair<int, int> StartPos;
int HomeNum = 0;
// A미만은 무시 B초과는 무시
//pair<bool,pair<int,int>> 통과성공 , 최소 , 최고
pair<bool, pair<int, int>> Check(int A, int B)
{
	Init_Visit();
	int RemainHome = HomeNum;
	int minH = 9876543210;
	int maxH = 0;
	queue <pair<int, int>> Queue;
	Queue.push(StartPos);
	int startH = Get_Field_Height(StartPos.first, StartPos.second);
	Visit[StartPos.first][StartPos.second] = true;
	if (Get_Field_Data(startH, startH) == 'K')
		RemainHome--;
	minH = min(minH, startH);
	maxH = max(maxH, startH);

	if (A <= startH && startH <= B)
	{
		while (!Queue.empty())
		{
			pair<int, int> temp = Queue.front();
			Queue.pop();

			for (int i = 0; i < 8; i++)
			{
				int ax = temp.first + Dic[i][0];
				int ay = temp.second + Dic[i][1];
				int ah = Get_Field_Height(ax, ay);
				if (!Get_Visit(ax, ay) && A <= ah && ah <= B)
				{
					Queue.push(make_pair(ax, ay));
					Visit[ax][ay] = true;
					if (Get_Field_Data(ax, ay) == 'K')
						RemainHome--;
					minH = min(minH, ah);
					maxH = max(maxH, ah);
				}
			}
		}
		pair<bool, pair<int, int>> Result = make_pair((RemainHome == 0), make_pair(minH, maxH));
		return Result;
	}
	else
	{
		pair<bool, pair<int, int>> Result = make_pair(false, make_pair(minH, maxH));
		return Result;
	}
}

///////////////////////////////////////////////////////////////////////////////////

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Field_Height.resize(N);
	Field_Data.resize(N);
	Visit.resize(N);
	for (int i = 0; i < N; i++)
	{
		Field_Height[i].resize(N);
		Field_Data[i].resize(N);
		Visit[i].resize(N);
	}

	int startPosHeight = 0;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			cin >> Field_Data[x][y];
			if (Field_Data[x][y] == 'P')
			{
				StartPos.first = x;
				StartPos.second = y;
			}
			else if (Field_Data[x][y] == 'K')
				HomeNum++;
		}

	set<int> height_Data;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			cin >> Field_Height[x][y];
			if (Field_Data[x][y] == 'P')
				startPosHeight = Field_Height[x][y];
			if (height_Data.find(Field_Height[x][y]) == height_Data.end())
				height_Data.insert(Field_Height[x][y]);
		}

	vector<int> height_Data_vector;

	for (set<int> ::iterator iter = height_Data.begin(); iter != height_Data.end(); iter++)
		height_Data_vector.push_back(*iter);

	int center = 0;
	int right = 0;
	for (int i = 0; i < height_Data_vector.size(); i++)
		if (startPosHeight == height_Data_vector[i])
			center = i;
	right = center;

	int result_Value = 987654321;
	while (right < height_Data_vector.size())
	{
		int Cleft = 0;
		int Cright = center;
		while (Cleft <= Cright)
		{
			int Cmid = (Cleft + Cright) / 2;
			pair<bool, pair<int, int>> CResult = Check(height_Data_vector[Cmid], height_Data_vector[right]);
			if (CResult.first)
			{
				Cleft = Cmid + 1;
				result_Value = min(result_Value, abs(CResult.second.first - CResult.second.second));
			}
			else
				Cright = Cmid - 1;
		}

		right++;
	}

	cout << result_Value << endl;

	return 0;

}