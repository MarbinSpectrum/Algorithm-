#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

#pragma warning(disable:4996)

using namespace std;

int N;



int MoveNum(string s)
{
	int FNum = 0;
	for (int i = 0; i < 4; i++)
		if (s[i] == 'F')
			FNum++;
	if (FNum == 0)
		return 5;
	return FNum;
}

class Node
{
public:
	string now;
	string next[5];
	char object[4];

	Node(string z, string a, string b, string c, string d, string e)
	{
		now = z;
		next[0] = a;
		next[1] = b;
		next[2] = c;
		next[3] = d;
		next[4] = e;
		for (int i = 0; i < 4; i++)
			object[i] = '.';
	}
};

vector<Node> node;
vector<char> exitData;

string FindPos(char c)
{
	for (int i = 0; i < node.size(); i++)
		for (int j = 0; j < 4; j++)
			if (node[i].object[j] == c)
				return node[i].now;

	for (int i = 0; i < exitData.size(); i++)
		if (exitData[i] == c)
			return "탈출";
	return "날발";
}

int FindIndex(string s)
{
	for (int i = 0; i < node.size(); i++)
		if (node[i].now.compare(s) == 0)
			return i;
	return -1;
}

int FindIndex(char c)
{
	for (int i = 0; i < node.size(); i++)
		for (int j = 0; j < 4; j++)
			if (node[i].object[j] == c)
				return i;

	for (int i = 0; i < exitData.size(); i++)
		if (exitData[i] == c)
			return -1;
	return 0;
}


int NextIndex(int nowIndex, int n)
{
	string next = "";
	next = node[nowIndex].next[n - 1];
	for (int i = 0; i < node.size(); i++)
		if (node[i].now.compare(next) == 0)
			return i;
	return 0;
}

int NextIndex(string now, int n)
{
	string next = "";
	for (int i = 0; i < node.size(); i++)
		if (node[i].now.compare(now) == 0)
			next = node[i].next[n - 1];
	for (int i = 0; i < node.size(); i++)
		if (node[i].now.compare(next) == 0)
			return i;
	return 0;
}

string NextPos(int nowIndex, int n)
{
	return node[nowIndex].next[n - 1];
}

string NextPos(string now, int n)
{
	for (int i = 0; i < node.size(); i++)
		if (node[i].now.compare(now) == 0)
			return node[i].next[n - 1];
	return now;
}

void Move(char c, int n)
{
	string now = FindPos(c);
	int nowIndex = FindIndex(c);
	if (now == "탈출")
		return;
	int next = NextIndex(now, n);

	bool moveA, moveB, moveC, moveD;
	if ('a' <= c && c <= 'd')
	{
		moveA = (node[nowIndex].object[0] == 'a') || (c == 'a');
		moveB = (node[nowIndex].object[1] == 'b') || (c == 'b');
		moveC = (node[nowIndex].object[2] == 'c') || (c == 'c');
		moveD = (node[nowIndex].object[3] == 'd') || (c == 'd');
	}
	else
	{
		moveA = (node[nowIndex].object[0] == 'A') || (c == 'A');
		moveB = (node[nowIndex].object[1] == 'B') || (c == 'B');
		moveC = (node[nowIndex].object[2] == 'C') || (c == 'C');
		moveD = (node[nowIndex].object[3] == 'D') || (c == 'D');
	}
	//cout << moveA << moveB << moveC << moveD << endl;

	for (int i = 0; i < 4; i++)
		node[nowIndex].object[i] = '.';
	//cout << NextPos(nowIndex, n) << endl;
	if (NextPos(nowIndex, n).compare("탈출") == 0)
	{
		if ('a' <= c && c <= 'd')
		{
			if (moveA)
				exitData.push_back('a');
			if (moveB)
				exitData.push_back('b');
			if (moveC)
				exitData.push_back('c');
			if (moveD)
				exitData.push_back('d');
		}
		else
		{
			if (moveA)
				exitData.push_back('A');
			if (moveB)
				exitData.push_back('B');
			if (moveC)
				exitData.push_back('C');
			if (moveD)
				exitData.push_back('D');
		}
		return;
	}

	if ('a' <= c && c <= 'd')
	{
		if (node[next].object[0] == 'A' || node[next].object[1] == 'B' || node[next].object[2] == 'C' || node[next].object[3] == 'D')
		{
			for (int i = 0; i < 4; i++)
				node[next].object[i] = '.';
		}
		if (moveA)
			node[next].object[0] = 'a';
		if (moveB)
			node[next].object[1] = 'b';
		if (moveC)
			node[next].object[2] = 'c';
		if (moveD)
			node[next].object[3] = 'd';
	}
	else
	{
		if (node[next].object[0] == 'a' || node[next].object[1] == 'b' || node[next].object[2] == 'c' || node[next].object[3] == 'd')
		{
			for (int i = 0; i < 4; i++)
				node[next].object[i] = '.';
		}
		if (moveA)
			node[next].object[0] = 'A';
		if (moveB)
			node[next].object[1] = 'B';
		if (moveC)
			node[next].object[2] = 'C';
		if (moveD)
			node[next].object[3] = 'D';
	}

}

string Field[32] =
{
	"..----..----..----..----..----..",
	"..    ..    ..    ..    ..    ..",
	"| \\                          / |",
	"|  \\                        /  |",
	"|   \\                      /   |",
	"|    ..                  ..    |",
	"..   ..                  ..   ..",
	"..     \\                /     ..",
	"|       \\              /       |",
	"|        \\            /        |",
	"|         ..        ..         |",
	"|         ..        ..         |",
	"..          \\      /          ..",
	"..           \\    /           ..",
	"|             \\  /             |",
	"|              ..              |",
	"|              ..              |",
	"|             /  \\             |",
	"..           /    \\           ..",
	"..          /      \\          ..",
	"|         ..        ..         |",
	"|         ..        ..         |",
	"|        /            \\        |",
	"|       /              \\       |",
	"..     /                \\     ..",
	"..   ..                  ..   ..",
	"|    ..                  ..    |",
	"|   /                      \\   |",
	"|  /                        \\  |",
	"| /                          \\ |",
	"..    ..    ..    ..    ..    ..",
	"..----..----..----..----..----..",
};

void Print()
{
	//cout << node[0].object[0] << node[0].object[1] << endl;
	//cout << node[0].object[2] << node[0].object[3] << endl;

	Field[0][0] = node[FindIndex("뒷발")].object[0]; Field[0][1] = node[FindIndex("뒷발")].object[1];
	Field[1][0] = node[FindIndex("뒷발")].object[2]; Field[1][1] = node[FindIndex("뒷발")].object[3];

	Field[0][6] = node[FindIndex("뒷윷")].object[0]; Field[0][7] = node[FindIndex("뒷윷")].object[1];
	Field[1][6] = node[FindIndex("뒷윷")].object[2]; Field[1][7] = node[FindIndex("뒷윷")].object[3];

	Field[0][12] = node[FindIndex("뒷걸")].object[0]; Field[0][13] = node[FindIndex("뒷걸")].object[1];
	Field[1][12] = node[FindIndex("뒷걸")].object[2]; Field[1][13] = node[FindIndex("뒷걸")].object[3];

	Field[0][18] = node[FindIndex("뒷개")].object[0]; Field[0][19] = node[FindIndex("뒷개")].object[1];
	Field[1][18] = node[FindIndex("뒷개")].object[2]; Field[1][19] = node[FindIndex("뒷개")].object[3];

	Field[0][24] = node[FindIndex("뒷도")].object[0]; Field[0][25] = node[FindIndex("뒷도")].object[1];
	Field[1][24] = node[FindIndex("뒷도")].object[2]; Field[1][25] = node[FindIndex("뒷도")].object[3];

	Field[0][30] = node[FindIndex("모")].object[0]; Field[0][31] = node[FindIndex("모")].object[1];
	Field[1][30] = node[FindIndex("모")].object[2]; Field[1][31] = node[FindIndex("모")].object[3];


	Field[6][0] = node[FindIndex("찌도")].object[0]; Field[6][1] = node[FindIndex("찌도")].object[1];
	Field[7][0] = node[FindIndex("찌도")].object[2]; Field[7][1] = node[FindIndex("찌도")].object[3];

	Field[5][5] = node[FindIndex("뒷모도")].object[0]; Field[5][6] = node[FindIndex("뒷모도")].object[1];
	Field[6][5] = node[FindIndex("뒷모도")].object[2]; Field[6][6] = node[FindIndex("뒷모도")].object[3];

	Field[5][25] = node[FindIndex("앞모도")].object[0]; Field[5][26] = node[FindIndex("앞모도")].object[1];
	Field[6][25] = node[FindIndex("앞모도")].object[2]; Field[6][26] = node[FindIndex("앞모도")].object[3];

	Field[6][30] = node[FindIndex("윷")].object[0]; Field[6][31] = node[FindIndex("윷")].object[1];
	Field[7][30] = node[FindIndex("윷")].object[2]; Field[7][31] = node[FindIndex("윷")].object[3];


	Field[12][0] = node[FindIndex("찌개")].object[0]; Field[12][1] = node[FindIndex("찌개")].object[1];
	Field[13][0] = node[FindIndex("찌개")].object[2]; Field[13][1] = node[FindIndex("찌개")].object[3];

	Field[10][10] = node[FindIndex("뒷모개")].object[0]; Field[10][11] = node[FindIndex("뒷모개")].object[1];
	Field[11][11] = node[FindIndex("뒷모개")].object[2]; Field[11][11] = node[FindIndex("뒷모개")].object[3];

	Field[15][15] = node[FindIndex("방")].object[0]; Field[15][16] = node[FindIndex("방")].object[1];
	Field[16][15] = node[FindIndex("방")].object[2]; Field[16][16] = node[FindIndex("방")].object[3];

	Field[10][20] = node[FindIndex("앞모개")].object[0]; Field[10][21] = node[FindIndex("앞모개")].object[1];
	Field[11][20] = node[FindIndex("앞모개")].object[2]; Field[11][21] = node[FindIndex("앞모개")].object[3];

	Field[12][30] = node[FindIndex("걸")].object[0]; Field[12][31] = node[FindIndex("걸")].object[1];
	Field[13][30] = node[FindIndex("걸")].object[2]; Field[13][31] = node[FindIndex("걸")].object[3];


	Field[18][0] = node[FindIndex("찌걸")].object[0]; Field[18][1] = node[FindIndex("찌걸")].object[1];
	Field[19][0] = node[FindIndex("찌걸")].object[2]; Field[19][1] = node[FindIndex("찌걸")].object[3];

	Field[20][10] = node[FindIndex("속윷")].object[0]; Field[20][11] = node[FindIndex("속윷")].object[1];
	Field[21][10] = node[FindIndex("속윷")].object[2]; Field[21][11] = node[FindIndex("속윷")].object[3];

	Field[20][20] = node[FindIndex("사려")].object[0]; Field[20][21] = node[FindIndex("사려")].object[1];
	Field[21][20] = node[FindIndex("사려")].object[2]; Field[21][21] = node[FindIndex("사려")].object[3];

	Field[18][30] = node[FindIndex("개")].object[0]; Field[18][31] = node[FindIndex("개")].object[1];
	Field[19][30] = node[FindIndex("개")].object[2]; Field[19][31] = node[FindIndex("개")].object[3];


	Field[24][0] = node[FindIndex("찌윷")].object[0]; Field[24][1] = node[FindIndex("찌윷")].object[1];
	Field[25][0] = node[FindIndex("찌윷")].object[2]; Field[25][1] = node[FindIndex("찌윷")].object[3];

	Field[25][5] = node[FindIndex("속모")].object[0]; Field[25][6] = node[FindIndex("속모")].object[1];
	Field[26][5] = node[FindIndex("속모")].object[2]; Field[26][6] = node[FindIndex("속모")].object[3];

	Field[25][25] = node[FindIndex("안찌")].object[0]; Field[25][26] = node[FindIndex("안찌")].object[1];
	Field[26][25] = node[FindIndex("안찌")].object[2]; Field[26][26] = node[FindIndex("안찌")].object[3];

	Field[24][30] = node[FindIndex("도")].object[0]; Field[24][31] = node[FindIndex("도")].object[1];
	Field[25][30] = node[FindIndex("도")].object[2]; Field[25][31] = node[FindIndex("도")].object[3];


	Field[30][0] = node[FindIndex("찔발")].object[0]; Field[30][1] = node[FindIndex("찔발")].object[1];
	Field[31][0] = node[FindIndex("찔발")].object[2]; Field[31][1] = node[FindIndex("찔발")].object[3];

	Field[30][6] = node[FindIndex("날도")].object[0]; Field[30][7] = node[FindIndex("날도")].object[1];
	Field[31][6] = node[FindIndex("날도")].object[2]; Field[31][7] = node[FindIndex("날도")].object[3];

	Field[30][12] = node[FindIndex("날개")].object[0]; Field[30][13] = node[FindIndex("날개")].object[1];
	Field[31][12] = node[FindIndex("날개")].object[2]; Field[31][13] = node[FindIndex("날개")].object[3];

	Field[30][18] = node[FindIndex("날걸")].object[0]; Field[30][19] = node[FindIndex("날걸")].object[1];
	Field[31][18] = node[FindIndex("날걸")].object[2]; Field[31][19] = node[FindIndex("날걸")].object[3];

	Field[30][24] = node[FindIndex("날윷")].object[0]; Field[30][25] = node[FindIndex("날윷")].object[1];
	Field[31][24] = node[FindIndex("날윷")].object[2]; Field[31][25] = node[FindIndex("날윷")].object[3];

	Field[30][30] = node[FindIndex("끝")].object[0]; Field[30][31] = node[FindIndex("끝")].object[1];
	Field[31][30] = node[FindIndex("끝")].object[2]; Field[31][31] = node[FindIndex("끝")].object[3];

	for (int i = 0; i < 32; i++)
		cout << Field[i] << endl;
}

int main()
{

	node.push_back(Node("날발", "도", "개", "걸", "윷", "모"));					//0
	node.push_back(Node("도", "개", "걸", "윷", "모", "뒷도"));					//1
	node.push_back(Node("개", "걸", "윷", "모", "뒷도", "뒷개"));				//2
	node.push_back(Node("걸", "윷", "모", "뒷도", "뒷개", "뒷걸"));				//3
	node.push_back(Node("윷", "모", "뒷도", "뒷개", "뒷걸", "뒷윷"));			//4
	node.push_back(Node("모", "앞모도", "앞모개", "방", "속윷", "속모"));		//5
	node.push_back(Node("뒷도", "뒷개", "뒷걸", "뒷윷", "뒷발", "찌도"));		//6
	node.push_back(Node("뒷개", "뒷걸", "뒷윷", "뒷발", "찌도", "찌개"));		//7
	node.push_back(Node("뒷걸", "뒷윷", "뒷발", "찌도", "찌개", "찌걸"));		//8
	node.push_back(Node("뒷윷", "뒷발", "찌도", "찌개", "찌걸", "찌윷"));		//9
	node.push_back(Node("뒷발", "뒷모도", "뒷모개", "방", "사려", "안찌"));		//10
	node.push_back(Node("찌도", "찌개", "찌걸", "찌윷", "찔발", "날도"));		//11
	node.push_back(Node("찌개", "찌걸", "찌윷", "찔발", "날도", "날개"));		//12
	node.push_back(Node("찌걸", "찌윷", "찔발", "날도", "날개", "날걸"));		//13
	node.push_back(Node("찌윷", "찔발", "날도", "날개", "날걸", "날윷"));		//14
	node.push_back(Node("찔발", "날도", "날개", "날걸", "날윷", "끝"));			//15
	node.push_back(Node("날도", "날개", "날걸", "날윷", "끝", "탈출"));			//16
	node.push_back(Node("날개", "날걸", "날윷", "끝", "탈출", "탈출"));			//17
	node.push_back(Node("날걸", "날윷", "끝", "탈출", "탈출", "탈출"));			//18
	node.push_back(Node("날윷", "끝", "탈출", "탈출", "탈출", "탈출"));			//19
	node.push_back(Node("끝", "탈출", "탈출", "탈출", "탈출", "탈출"));			//20
	node.push_back(Node("앞모도", "앞모개", "방", "속윷", "속모", "찔발"));		//21
	node.push_back(Node("앞모개", "방", "속윷", "속모", "찔발", "날도"));		//22
	node.push_back(Node("방", "사려", "안찌", "끝", "탈출", "탈출"));			//23
	node.push_back(Node("속윷", "속모", "찔발", "날도", "날개", "날걸"));		//24
	node.push_back(Node("속모", "찔발", "날도", "날개", "날걸", "날윷"));		//25
	node.push_back(Node("뒷모도", "뒷모개", "방", "사려", "안찌", "끝"));		//26
	node.push_back(Node("뒷모개", "방", "사려", "안찌", "끝", "탈출"));			//27
	node.push_back(Node("사려", "안찌", "끝", "탈출", "탈출", "탈출"));			//28
	node.push_back(Node("안찌", "끝", "탈출", "탈출", "탈출", "탈출"));			//29
	cin >> N;
	while (N--)
	{
		char temp;
		string numTemp;
		cin >> temp >> numTemp;
		Move(temp, MoveNum(numTemp));
		//Print();

	}

	Print();
}