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
const int Prime[] =
{
	2 ,3 ,5 ,7 ,11 ,13 ,17, 19 ,23 ,29,
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
	73 ,79 ,83 ,89 ,97 ,101 ,103 ,107 ,109 ,113,
	127 ,131, 137, 139 ,149 ,151, 157 ,163 ,167 ,173,
	179 ,181, 191, 193, 197, 199, 211, 223 ,227 ,229,
	233 ,239 ,241 ,251 ,257 ,263 ,269 ,271 ,277 ,281,
	283 ,293 ,307 ,311 ,313 ,317 ,331 ,337 ,347 ,349,
	353 ,359 ,367 ,373 ,379 ,383 ,389 ,397 ,401 ,409,
	419 ,421 ,431 ,433 ,439 ,443 ,449 ,457 ,461 ,463,
	467 ,479 ,487 ,491 ,499 ,503 ,509 ,521 ,523 ,541
};

////////////////////////////////////////////////////////////////////////

int N;

int Result = 0;

vector<vector<int>> Move(vector<vector<int>> NowMap, int dic)
{
	vector<vector<int>> Map;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp(N);
		Map.push_back(temp);
	}

	vector<vector<int>> NewMap;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp(N);
		NewMap.push_back(temp);
	}

	//왼쪽으로 밀음
	if (dic == 0)
	{
		for (int r = 0; r < N; r++)
		{
			queue<int> tempQueue;
			for (int c = 0; c < N; c++)
				if (NowMap[r][c] != 0)
					tempQueue.push(NowMap[r][c]);

			int q = 0;

			while (!tempQueue.empty())
			{
				NewMap[r][q] = tempQueue.front();
				tempQueue.pop();
				q++;
			}
		}

		for (int r = 0; r < N; r++)
		{
			queue<int> tempQueue;
			for (int c = 0; c < N; c++)
			{
				if (NewMap[r][c] != 0)
				{
					if (c + 1 < N && NewMap[r][c] == NewMap[r][c + 1])
					{
						tempQueue.push(NewMap[r][c] * 2);
						NewMap[r][c] = 0;
						NewMap[r][c + 1] = 0;
					}
					else
					{
						tempQueue.push(NewMap[r][c]);
						NewMap[r][c] = 0;
					}
				}
			}

			int q = 0;

			while (!tempQueue.empty())
			{
				Map[r][q] = tempQueue.front();
				tempQueue.pop();
				q++;
			}
		}
	}
	//오른쪽
	else if (dic == 1)
	{
		for (int r = 0; r < N; r++)
		{
			queue<int> tempQueue;
			for (int c = N - 1; c >= 0; c--)
				if (NowMap[r][c] != 0)
					tempQueue.push(NowMap[r][c]);

			int q = N - 1;

			while (!tempQueue.empty())
			{
				NewMap[r][q] = tempQueue.front();
				tempQueue.pop();
				q--;
			}
		}

		for (int r = 0; r < N; r++)
		{
			queue<int> tempQueue;
			for (int c = N - 1; c >= 0; c--)
			{
				if (NewMap[r][c] != 0)
				{
					if (c - 1 >= 0 && NewMap[r][c] == NewMap[r][c - 1])
					{
						tempQueue.push(NewMap[r][c] * 2);
						NewMap[r][c] = 0;
						NewMap[r][c - 1] = 0;
					}
					else
					{
						tempQueue.push(NewMap[r][c]);
						NewMap[r][c] = 0;
					}
				}
			}

			int q = N - 1;

			while (!tempQueue.empty())
			{
				Map[r][q] = tempQueue.front();
				tempQueue.pop();
				q--;
			}
		}
	}
	//위쪽
	else if (dic == 2)
	{
		for (int c = 0; c < N; c++)
		{
			queue<int> tempQueue;
			for (int r = 0; r < N; r++)
				if (NowMap[r][c] != 0)
					tempQueue.push(NowMap[r][c]);

			int q = 0;

			while (!tempQueue.empty())
			{
				NewMap[q][c] = tempQueue.front();
				tempQueue.pop();
				q++;
			}
		}


		for (int c = 0; c < N; c++)
		{
			queue<int> tempQueue;
			for (int r = 0; r < N; r++)
			{
				if (NewMap[r][c] != 0)
				{
					if (r + 1 < N && NewMap[r][c] == NewMap[r + 1][c])
					{
						tempQueue.push(NewMap[r][c] * 2);
						NewMap[r][c] = 0;
						NewMap[r + 1][c] = 0;
					}
					else
					{
						tempQueue.push(NewMap[r][c]);
						NewMap[r][c] = 0;
					}
				}
			}

			int q = 0;

			while (!tempQueue.empty())
			{
				Map[q][c] = tempQueue.front();
				tempQueue.pop();
				q++;
			}
		}
	}
	//아래쪽
	else if (dic == 3)
	{
		for (int c = 0; c < N; c++)
		{
			queue<int> tempQueue;
			for (int r = N - 1; r >= 0; r--)
				if (NowMap[r][c] != 0)
					tempQueue.push(NowMap[r][c]);

			int q = N - 1;

			while (!tempQueue.empty())
			{
				NewMap[q][c] = tempQueue.front();
				tempQueue.pop();
				q--;
			}
		}

		for (int c = 0; c < N; c++)
		{
			queue<int> tempQueue;
			for (int r = N - 1; r >= 0; r--)
			{
				if (NewMap[r][c] != 0)
				{
					if (r - 1 >= 0 && NewMap[r][c] == NewMap[r - 1][c])
					{
						tempQueue.push(NewMap[r][c] * 2);
						NewMap[r][c] = 0;
						NewMap[r - 1][c] = 0;
					}
					else
					{
						tempQueue.push(NewMap[r][c]);
						NewMap[r][c] = 0;
					}
				}
			}

			int q = N - 1;

			while (!tempQueue.empty())
			{
				Map[q][c] = tempQueue.front();
				tempQueue.pop();
				q--;
			}
		}
	}

	return Map;
}


void Run(vector<vector<int>> NowMap, int T)
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
			cout << NowMap[r][c] << " ";
		cout << endl;
	}

	Debug("-------------------------------------------", "]");

	if (T < 5)
	{
		Run(Move(NowMap, 0), T + 1);
		Run(Move(NowMap, 1), T + 1);
		Run(Move(NowMap, 2), T + 1);
		Run(Move(NowMap, 3), T + 1);
	}
	else
	{
		int R = 0;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				R = max(NowMap[r][c], R);

		Result = max(Result, R);

	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<vector<int>> Map;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp(N);
		Map.push_back(temp);
	}

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> Map[r][c];

	Run(Map, 0);

	cout << Result << endl;
}
