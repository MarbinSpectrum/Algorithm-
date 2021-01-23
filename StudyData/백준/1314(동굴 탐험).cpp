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
#define float double
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N;
int B;
//몸무게 //동굴을 통과하는데 걸리는시간
pair<int, int> Explorer[13];
//모험가들 몸무게 //모험가들이 동굴을 통과하는데 걸리는시간
pair<int, int> explorerData[1 << 13];
pair<int, int> ExplorerData(int bit)
{
	if (explorerData[bit].first != -1)
		return explorerData[bit];
	explorerData[bit] = { 0,0 };
	for (int i = 0; i < N; i++)
		if (bit & (1 << i))
		{
			explorerData[bit].first += Explorer[i].first;
			explorerData[bit].second = max(explorerData[bit].second, Explorer[i].second);
		}
	return explorerData[bit];
}

//신뢰관계도
char RD[13][13];

//비트에 1의 갯수를 구해줌
int bitNum[1 << 13];
int BitNum(int n)
{
	if (bitNum[n] != -1)
		return bitNum[n];
	bitNum[n] = 0;
	int nn = n;
	while (nn > 0)
	{
		if (nn % 2 != 0)
			bitNum[n]++;
		nn /= 2;
	}
	return bitNum[n];
}

//각자 신뢰하는 사람이 있으면 1반환 아니면 0반환
int intimacy[1 << 13];
int Intimacy(int bit)
{
	if (intimacy[bit] != -1)
		return intimacy[bit];
	if (bit == 0)
		return intimacy[bit] = 0;
	if (BitNum(bit) == 1)
		return intimacy[bit] = 1;
	for (int i = 0; i < N; i++)
	{
		if (bit & (1 << i))
		{
			bool flag = false;
			for (int j = 0; j < N; j++)
				if (bit & (1 << j))
					if (i != j)
						if (RD[i][j] == 'Y')
						{
							flag = true;
							break;
						}
			if (!flag)
				return intimacy[bit] = 0;
		}
	}
	return intimacy[bit] = 1;
}

int D[1 << 13][2];

vector<tuple<int,int,int>> V[1 << 13][2];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < (1 << 13); i++)
		explorerData[i] = { -1, -1 };
	Init(bitNum, -1);
	Init(intimacy, -1);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Explorer[i].first >> Explorer[i].second;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> RD[i][j];
	cin >> B;

	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			if ((i | j) == j && i < j)
			{
				//Debug(j - i, Intimacy(j - i));
				if (Intimacy(j - i) == 1)
				{
					pair<int, int> temp = ExplorerData(j - i);
					if (temp.first <= B)
					{
						V[i][0].push_back({ j,1,temp.second });
						//cout << i << "->" << j << endl;
					}
				}
			}
			if ((i | j) == i && i > j && Intimacy(i - j) == 1)
			{
				pair<int, int> temp = ExplorerData(i - j);
				if (temp.first <= B)
				{
					V[i][1].push_back({ j,0,temp.second });
					//cout << i << "->" << j << endl;
				}
			}
		}
	}

	for (int i = 0; i < (1 << N); i++)
	{
		D[i][0] = INF;
		D[i][1] = INF;
	}

	D[0][0] = 0;
	priority_queue<tuple<int, int, int>> pq;
	pq.push({ 0,0,0 });

	while (!pq.empty())
	{
		int a = get<0>(pq.top());
		int b = get<1>(pq.top());
		int dis = -get<2>(pq.top());
		pq.pop();

		if (D[a][b] < dis)
			continue;
		for (int i = 0; i < V[a][b].size(); i++)
		{
			int nextA = get<0>(V[a][b][i]);
			int nextB = get<1>(V[a][b][i]);
			int nextDis = dis + get<2>(V[a][b][i]);

			if (nextDis < D[nextA][nextB])
			{
				D[nextA][nextB] = nextDis;
				pq.push({ nextA ,nextB,-nextDis });
			}
		}
	}

	if (D[(1 << N) - 1][1] == INF)
		cout << -1 << endl;
	else
	cout << D[(1 << N) - 1][1] << endl;
}
