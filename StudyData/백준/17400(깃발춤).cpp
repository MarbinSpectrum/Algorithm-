#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include <string.h>

#pragma warning(disable:4996)

using namespace std;

int N, Q;

class Data
{
public:
	long long StartEven_EvenSum, StartEven_OddSum;
	long long StartOdd_EvenSum, StartOdd_OddSum;
	Data()
	{
		StartEven_EvenSum = 0;
		StartOdd_EvenSum = 0;
		StartEven_OddSum = 0;
		StartOdd_OddSum = 0;
	}
};



vector<Data> Tree;
vector<long long > A;
void TreeInit(int Left, int Right, bool startEven, int TreeNum)
{
	for (int i = Left; i <= Right; i++)
	{
		if (startEven)
		{
			if (i % 2 == 0)
				Tree[TreeNum].StartEven_EvenSum += A[i];
			else
				Tree[TreeNum].StartEven_OddSum += A[i];
		}
		else
		{
			if (i % 2 == 0)
				Tree[TreeNum].StartOdd_EvenSum += A[i];
			else
				Tree[TreeNum].StartOdd_OddSum += A[i];
		}
	}

	if (Left >= Right)
		return;
	int Mid = (Left + Right) / 2;
	TreeInit(Left, Mid, startEven, TreeNum * 2);
	TreeInit(Mid + 1, Right, startEven, TreeNum * 2 + 1);
}

Data TreeAdd(int Left, int Right, int Start, int End, int TreeNum)
{
	if (Left > End || Right < Start)
	{
		Data temp;
		return temp;
	}

	if (Left <= Start && Right >= End || Start == End)
		return Tree[TreeNum];

	int Mid = (Start + End) / 2;

	Data A = TreeAdd(Left, Right, Start, Mid, TreeNum * 2);
	Data B = TreeAdd(Left, Right, Mid + 1, End, TreeNum * 2 + 1);

	Data temp;
	temp.StartEven_EvenSum = A.StartEven_EvenSum + B.StartEven_EvenSum;
	temp.StartOdd_EvenSum = A.StartOdd_EvenSum + B.StartOdd_EvenSum;
	temp.StartEven_OddSum = A.StartEven_OddSum + B.StartEven_OddSum;
	temp.StartOdd_OddSum = A.StartOdd_OddSum + B.StartOdd_OddSum;

	return temp;
}

void TreeUpdate(int Left, int Right, int UpdatePoint, int diff, int TreeNum)
{
	if (Left > Right)
		return;

	if (Left <= UpdatePoint && UpdatePoint <= Right)
	{
		if (UpdatePoint % 2 == 0)
			Tree[TreeNum].StartEven_EvenSum += diff;
		else
			Tree[TreeNum].StartEven_OddSum += diff;

		if (UpdatePoint % 2 == 0)
			Tree[TreeNum].StartOdd_EvenSum += diff;
		else
			Tree[TreeNum].StartOdd_OddSum += diff;
	}
	else
		return;

	if (Left == Right)
	{
		A[Left] += diff;
		return;
	}

	int Mid = (Left + Right) / 2;

	TreeUpdate(Left, Mid, UpdatePoint, diff, TreeNum * 2);
	TreeUpdate(Mid + 1, Right, UpdatePoint, diff, TreeNum * 2 + 1);

	return;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	int tree_high = (int)ceil(log2(N));
	int tree_size = (1 << (tree_high + 1));
	Tree.resize(tree_size);

	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	TreeInit(0, N - 1, false, 1);
	TreeInit(0, N - 1, true, 1);

	for (int q = 0; q < Q; q++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			Data temp = TreeAdd(b - 1, c - 1, 0, N - 1, 1);

			if (b % 2 == 0)
				cout << abs(temp.StartEven_EvenSum - temp.StartEven_OddSum) << "\n";
			else
				cout << abs(temp.StartOdd_EvenSum - temp.StartOdd_OddSum) << "\n";
		}
		else
		{
			TreeUpdate(0, N - 1, b - 1, c, 1);
		}


	}
}