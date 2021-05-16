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
//
//// C++ 
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
//
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
#define float double
#define Debug(a,b) cout << a << " " << b << endl


int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return (int)n + 1;
	else
		return n;
}

int Pow(int a, int b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	int temp = Pow(a, b / 2);

	return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

#define Start 0
#define End 29
#define Escape 30

vector<int> Next[40];

void MakeMap()
{
	for (int i = 0; i <= 15; i++)
	{
		if (i == 5)
			continue;
		if (i == 10)
			continue;
		if (i == 15)
			continue;
		Next[i].push_back(i + 1);
		Next[i].push_back(i + 2);
		Next[i].push_back(i + 3);
		Next[i].push_back(i + 4);
		Next[i].push_back(i + 5);
	}
	Next[5].push_back(20);
	Next[5].push_back(21);
	Next[5].push_back(22);
	Next[5].push_back(23);
	Next[5].push_back(24);

	Next[10].push_back(25);
	Next[10].push_back(26);
	Next[10].push_back(22);
	Next[10].push_back(27);
	Next[10].push_back(28);

	Next[15].push_back(16);
	Next[15].push_back(17);
	Next[15].push_back(18);
	Next[15].push_back(19);
	Next[15].push_back(End);

	Next[16].push_back(17);
	Next[16].push_back(18);
	Next[16].push_back(19);
	Next[16].push_back(End);
	Next[16].push_back(Escape);

	Next[17].push_back(18);
	Next[17].push_back(19);
	Next[17].push_back(End);
	Next[17].push_back(Escape);
	Next[17].push_back(Escape);

	Next[18].push_back(19);
	Next[18].push_back(End);
	Next[18].push_back(Escape);
	Next[18].push_back(Escape);
	Next[18].push_back(Escape);

	Next[19].push_back(End);
	Next[19].push_back(Escape);
	Next[19].push_back(Escape);
	Next[19].push_back(Escape);
	Next[19].push_back(Escape);

	Next[End].push_back(Escape);
	Next[End].push_back(Escape);
	Next[End].push_back(Escape);
	Next[End].push_back(Escape);
	Next[End].push_back(Escape);

	Next[20].push_back(21);
	Next[20].push_back(22);
	Next[20].push_back(23);
	Next[20].push_back(24);
	Next[20].push_back(15);

	Next[21].push_back(22);
	Next[21].push_back(23);
	Next[21].push_back(24);
	Next[21].push_back(15);
	Next[21].push_back(16);

	Next[22].push_back(27);
	Next[22].push_back(28);
	Next[22].push_back(End);
	Next[22].push_back(Escape);
	Next[22].push_back(Escape);

	Next[23].push_back(24);
	Next[23].push_back(15);
	Next[23].push_back(16);
	Next[23].push_back(17);
	Next[23].push_back(18);

	Next[24].push_back(15);
	Next[24].push_back(16);
	Next[24].push_back(17);
	Next[24].push_back(18);
	Next[24].push_back(19);

	Next[25].push_back(26);
	Next[25].push_back(22);
	Next[25].push_back(27);
	Next[25].push_back(28);
	Next[25].push_back(End);

	Next[26].push_back(22);
	Next[26].push_back(27);
	Next[26].push_back(28);
	Next[26].push_back(End);
	Next[26].push_back(Escape);

	Next[27].push_back(28);
	Next[27].push_back(End);
	Next[27].push_back(Escape);
	Next[27].push_back(Escape);
	Next[27].push_back(Escape);

	Next[28].push_back(End);
	Next[28].push_back(Escape);
	Next[28].push_back(Escape);
	Next[28].push_back(Escape);
	Next[28].push_back(Escape);

	Next[Escape].push_back(Escape);
	Next[Escape].push_back(Escape);
	Next[Escape].push_back(Escape);
	Next[Escape].push_back(Escape);
	Next[Escape].push_back(Escape);
}

#define Do 0
#define Gae 1
#define Gul 2
#define Yut 3
#define Mo 4
int Arr[60];
int ResultA[2];
int ResultB[2];
bool DP[31][31][31][31][50][2];
bool FindAns = false;
int U, N, A, B;
void D(int aX, int aY, int bX, int bY, int n, int turn)
{
	//cout << aX << " ";
	//cout << aY << " ";
	//cout << bX << " ";
	//cout << bY << " ";
	//cout << n << " ";
	//cout << turn << " ";
	//cout << endl;
	//cout << Value << endl;

	if (DP[aX][aY][bX][bY][n][turn])
		return;
	DP[aX][aY][bX][bY][n][turn] = true;

	if (FindAns)
		return;

	if (n == N || (U == 2 && aX == aY && aX == Escape) || (U == 2 && bX == bY && bX == Escape)
		|| (U == 1 && aX == Escape) || (U == 1 && bX == Escape))
	{
		if (n != N)
			return;

		if (U == 1)
		{
			bool A_Check = false;
			if (A == 0)
			{
				if (aX == 0 || aX == Escape)
					A_Check = true;
			}
			else if (A == 1)
			{
				if (aX == ResultA[0])
					A_Check = true;
				if (ResultA[0] == 0)
					A_Check = false;
			}

			bool B_Check = false;
			if (B == 0)
			{
				if (bX == 0 || bX == Escape)
					B_Check = true;
			}
			else if (B == 1)
			{
				if (bX == ResultB[0])
					B_Check = true;
				if (ResultB[0] == 0)
					B_Check = false;
			}

			FindAns = A_Check && B_Check;

		}
		else
		{


			bool A_Check = false;
			if (A == 0)
			{
				if ((aX == 0 || aX == Escape) && (aY == 0 || aY == Escape))
					A_Check = true;
			}
			else if (A == 1)
			{
				if ((aX == ResultA[0] && aY == Escape) || (aY == ResultA[0] && aX == Escape) ||
					(aX == ResultA[0] && aY == 0) || (aY == ResultA[0] && aX == 0))
					A_Check = true;
				if (ResultA[0] == 0)
					A_Check = false;
			}
			else if (A == 2)
			{
				if ((aX == ResultA[0] && aY == ResultA[1]) || (aY == ResultA[0] && aX == ResultA[1]))
					A_Check = true;
				if (ResultA[0] == 0)
					A_Check = false;
				if (ResultA[1] == 0)
					A_Check = false;
			}

			bool B_Check = false;
			if (B == 0)
			{
				if ((bX == 0 || bX == Escape) && (bY == 0 || bY == Escape))
					B_Check = true;
			}
			else if (B == 1)
			{
				if ((bX == ResultB[0] && bY == Escape) || (bY == ResultB[0] && bX == Escape) ||
					(bX == ResultB[0] && bY == 0) || (bY == ResultB[0] && bX == 0))
					B_Check = true;
				if (ResultB[0] == 0)
					B_Check = false;
			}
			else if (B == 2)
			{
				if ((bX == ResultB[0] && bY == ResultB[1]) || (bY == ResultB[0] && bX == ResultB[1]))
					B_Check = true;
				if (ResultB[0] == 0)
					B_Check = false;
				if (ResultB[1] == 0)
					B_Check = false;
			}

			FindAns = A_Check && B_Check;
		}
		return;
	}



	if (turn == 0)
	{
		if (aX == aY && aX != Start)
		{
			int t_aX, t_aY, t_bX, t_bY, t_n, t_turn;
			t_aX = aX;
			t_aY = aY;
			t_bX = bX;
			t_bY = bY;
			t_n = n;
			t_turn = turn;

			int Value = Arr[t_n];
			int NextV = Next[t_aX][Value];

			t_aX = NextV;
			t_aY = NextV;

			bool moreTurn = false;
			if (t_bX == NextV && t_bX != Escape)
			{
				t_bX = Start;
				moreTurn = true;
			}

			if (t_bY == NextV && t_bY != Escape)
			{
				t_bY = Start;
				moreTurn = true;
			}

			if (Value == Yut || Value == Mo)
				moreTurn = true;

			t_turn = moreTurn ? 0 : 1;

			D(t_aX, t_aY, t_bX, t_bY, t_n + 1, t_turn);
		}
		else
		{
			if (aX != Escape)
			{

				int t_aX, t_aY, t_bX, t_bY, t_n, t_turn;
				t_aX = aX;
				t_aY = aY;
				t_bX = bX;
				t_bY = bY;
				t_n = n;
				t_turn = turn;

				int Value = Arr[t_n];
				//cout << Value << endl;
				int NextV = Next[t_aX][Value];


				t_aX = NextV;

				bool moreTurn = false;
				if (t_bX == NextV && t_bX != Escape)
				{
					t_bX = Start;
					moreTurn = true;
				}

				if (t_bY == NextV && t_bY != Escape)
				{
					t_bY = Start;
					moreTurn = true;
				}

				if (Value == Yut || Value == Mo)
					moreTurn = true;

				t_turn = moreTurn ? 0 : 1;

				D(t_aX, t_aY, t_bX, t_bY, t_n + 1, t_turn);

			}

			if (aY != Escape)
			{
				int t_aX, t_aY, t_bX, t_bY, t_n, t_turn;
				t_aX = aX;
				t_aY = aY;
				t_bX = bX;
				t_bY = bY;
				t_n = n;
				t_turn = turn;

				int Value = Arr[t_n];
				int NextV = Next[t_aY][Value];

				t_aY = NextV;

				bool moreTurn = false;
				if (t_bX == NextV && t_bX != Escape)
				{
					t_bX = Start;
					moreTurn = true;
				}

				if (t_bY == NextV && t_bY != Escape)
				{
					t_bY = Start;
					moreTurn = true;
				}

				if (Value == Yut || Value == Mo)
					moreTurn = true;

				t_turn = moreTurn ? 0 : 1;

				D(t_aX, t_aY, t_bX, t_bY, t_n + 1, t_turn);
			}
		}
	}
	else if (turn == 1)
	{
		if (bX == bY && bX != Start)
		{
			int t_aX, t_aY, t_bX, t_bY, t_n, t_turn;
			t_aX = aX;
			t_aY = aY;
			t_bX = bX;
			t_bY = bY;
			t_n = n;
			t_turn = turn;

			int Value = Arr[t_n];
			int NextV = Next[t_bX][Value];

			t_bX = NextV;
			t_bY = NextV;

			bool moreTurn = false;
			if (t_aX == NextV && t_aX != Escape)
			{
				t_aX = Start;
				moreTurn = true;
			}

			if (t_aY == NextV && t_aY != Escape)
			{
				t_aY = Start;
				moreTurn = true;
			}

			if (Value == Yut || Value == Mo)
				moreTurn = true;

			t_turn = moreTurn ? 1 : 0;

			D(t_aX, t_aY, t_bX, t_bY, t_n + 1, t_turn);
		}
		else
		{
			if (bX != Escape)
			{
				int t_aX, t_aY, t_bX, t_bY, t_n, t_turn;
				t_aX = aX;
				t_aY = aY;
				t_bX = bX;
				t_bY = bY;
				t_n = n;
				t_turn = turn;

				int Value = Arr[t_n];
				int NextV = Next[t_bX][Value];

				t_bX = NextV;

				bool moreTurn = false;
				if (t_aX == NextV && t_aX != Escape)
				{
					t_aX = Start;
					moreTurn = true;
				}

				if (t_aY == NextV && t_aY != Escape)
				{
					t_aY = Start;
					moreTurn = true;
				}

				if (Value == Yut || Value == Mo)
					moreTurn = true;

				t_turn = moreTurn ? 1 : 0;

				D(t_aX, t_aY, t_bX, t_bY, t_n + 1, t_turn);

			}

			if (bY != Escape)
			{
				int t_aX, t_aY, t_bX, t_bY, t_n, t_turn;
				t_aX = aX;
				t_aY = aY;
				t_bX = bX;
				t_bY = bY;
				t_n = n;
				t_turn = turn;

				int Value = Arr[t_n];
				int NextV = Next[t_bY][Value];

				t_bY = NextV;

				bool moreTurn = false;
				if (t_aX == NextV && t_aX != Escape)
				{
					t_aX = Start;
					moreTurn = true;
				}

				if (t_aY == NextV && t_aY != Escape)
				{
					t_aY = Start;
					moreTurn = true;
				}

				if (Value == Yut || Value == Mo)
					moreTurn = true;

				t_turn = moreTurn ? 1 : 0;

				D(t_aX, t_aY, t_bX, t_bY, t_n + 1, t_turn);
			}
		}
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	MakeMap();

	int T;
	cin >> T;
	int castT = 1;
	while (T--)
	{
		memset(DP, false, sizeof(DP));
		FindAns = false;

		cin >> U >> N >> A >> B;
		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;
			if (temp.compare("Do") == 0)
				Arr[i] = Do;
			else if (temp.compare("Gae") == 0)
				Arr[i] = Gae;
			else if (temp.compare("Gul") == 0)
				Arr[i] = Gul;
			else if (temp.compare("Yut") == 0)
				Arr[i] = Yut;
			else if (temp.compare("Mo") == 0)
				Arr[i] = Mo;
		}

		for (int i = 0; i < 2; i++)
		{
			ResultA[i] = Escape;
			ResultB[i] = Escape;
		}

		for (int i = 0; i < A; i++)
			cin >> ResultA[i];

		for (int i = 0; i < B; i++)
			cin >> ResultB[i];

		int S = ((U == 2) ? Start : Escape);

		D(Start, S, Start, S, 0, 0);

		cout << "Case #" << castT++ << ": ";
		if (FindAns)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}