#ifndef _GLIBCXX_NO_ASSERT 
#include <cassert> 
#endif #include <cctype>
#include <cerrno> 
#include <cfloat> 
#include <ciso646> 
#include <climits> 
#include <clocale> 
#include <cmath> 
#include <csetjmp> 
#include <csignal>
#include <cstdarg> 
#include <cstddef>
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#if __cplusplus >= 201103L 
#include <ccomplex> 
#include <cfenv> 
#include <cinttypes> 
#include <cstdalign> 
#include <cstdbool>
#include <cstdint> 
#include <ctgmath>
#include <cwchar> 
#include <cwctype>
#endif 

// C++ 
#include <algorithm> 
#include <bitset> 
#include <complex> 
#include <deque> 
#include <exception> 
#include <fstream> 
#include <functional> 
#include <iomanip> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <iterator> 
#include <limits> 
#include <list> 
#include <locale> 
#include <map> 
#include <memory> 
#include <new> 
#include <numeric>
#include <ostream> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <stdexcept> 
#include <streambuf> 
#include <string> 
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <vector> 

#if __cplusplus >= 201103L 
#include <array> 
#include <atomic> 
#include <chrono> 
#include <condition_variable> 
#include <forward_list> 
#include <future> 
#include <initializer_list> 
#include <mutex> 
#include <random> 
#include <ratio>
#include <regex> 
#include <scoped_allocator> 
#include <system_error> 
#include <thread> 
#include <tuple> 
#include <typeindex> 
#include <type_traits> 
#include <unordered_map> 
#include <unordered_set> 
#endif

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int H, W;
int t = 0;
vector<vector<int>> Board;

void FloodFill(int r,int c,int value,int change)
{
	if (Board[r][c] != value)
		return;

	queue <pair<int, int>> Queue;
	Queue.push({ r,c });
	Board[r][c] = change;
	while (!Queue.empty())
	{
		pair<int, int> temp = Queue.front();
		Queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int ar = temp.first + Dic[i][0];
			int ac = temp.second + Dic[i][1];
			if (ar < 0 || ac < 0 || ar >= H || ac >= W * 4)
				continue;
			if (Board[ar][ac] != value)
				continue;
			Queue.push({ ar,ac });
			Board[ar][ac] = change;
		}
	}
}

char Get(int r, int c)
{
	queue <pair<int, int>> Queue;
	Queue.push({ r,c });
	Board[r][c] = -1;
	int check = 0;
	while (!Queue.empty())
	{
		pair<int, int> temp = Queue.front();
		Queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int ar = temp.first + Dic[i][0];
			int ac = temp.second + Dic[i][1];
			if (ar < 0 || ac < 0 || ar >= H || ac >= W*4)
				continue;
			if (Board[ar][ac] == -1)
				continue;
			if (Board[ar][ac] == 1)
			{
				Queue.push({ ar,ac });
				Board[ar][ac] = -1;
			}
			else if (Board[ar][ac] == 0)
			{
				FloodFill(ar, ac, 0, -1);
				check++;
			}
		}
	}

	if (check == 1)
		return 'A';
	else if (check == 3)
		return 'J';
	else if (check == 5)
		return 'D';
	else if (check == 4)
		return 'S';
	else if (check == 0)
		return 'W';
	else if (check == 2)
		return 'K';
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		Board.clear();

		cin >> H >> W;

		if (H == 0 && H == W)
			break;
		t++;
		for (int i = 0; i < H; i++)
		{
			vector<int> temp(W*4);
			Board.push_back(temp);
		}

		//for (int r = 0; r < H; r++)
		//	for (int c = 0; c < W; c++)
		//	{
		//		char temp;
		//		cin >> temp;
		//		if (temp - '0' == 0)
		//			Board[r][c] = 0;
		//		else
		//			Board[r][c] = 1;
		//	}


		for (int r = 0; r < H; r++)
		{
			string temp;
			cin >> temp;
			int j = temp.length() - 1;
			for (int c = W*4 - 1; c >= 0; c -= 4)
			{
				for (int i = c; i >= c - 3; i--)
				{
					if (i < 0)
						break;
					int a = c - i;
					if ('a' <= temp[j] && temp[j] <= 'f')
					{
						if ((1 << a) & (temp[j] - 'a' + 10))
							Board[r][i] = 1;
					}
					else if ((1 << a) & (temp[j] - '0'))
						Board[r][i] = 1;
				}
				j--;
			}
		}

		for (int r = 0; r < H; r++)
		{
			FloodFill(r, 0, 0, -1);
			FloodFill(r, W*4 - 1, 0, -1);
		}
		for (int c = 0; c < W*4; c++)
		{
			FloodFill(0, c, 0, -1);
			FloodFill(H - 1, c, 0, -1);
		}
	
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W*4; c++)
				if (Board[r][c] == 1)
					cout << "■";
				else if (Board[r][c] == -1)
					cout << "XX";
				else
					cout << "□";
			cout << endl;
		}

		string Result = "";

		for (int c = 0; c < W*4; c++)
			for (int r = 0; r < H; r++)
				if (Board[r][c] == 1)
					Result += Get(r, c);
		sort(Result.begin(), Result.end());
		cout << "Case " << t << ": " << Result << endl;
	}
}
