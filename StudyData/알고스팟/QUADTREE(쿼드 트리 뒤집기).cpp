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
#include <unordered_map> 
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

int Mul(int x, int y, int mod)
{
	return x * y % mod;
}

int GCD(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
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
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		b = b >> 1;
		a = (a * a);
	}
	return res;
}
int Pow(int a, int b, int p)
{
	int res = 1;
	a = a % p;
	while (b > 0)
	{
		if (b & 1)
			res = Mul(res, a, p);
		b = b >> 1;
		a = Mul(a, a, p);
	}
	return res;
}

const int INF = 0x3f3f3f3f;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

int N, M;

class Node
{
public :
	Node(char c);
	~Node();
	void Insert(char c, bool& flag);
	Node* node[4];
	void Print();
	void Print2();
	char color;
};
Node::Node(char c)
: color(c)
{
	for (int i = 0; i < 4; i++)
		node[i] = nullptr;
}
Node::~Node()
{
	for (int i = 0; i < 4; i++)
	{
		delete node[i];
		node[i] = nullptr;
	}
}
void Node::Insert(char c, bool& flag)
{
	for (int i = 0; i < 4 && !flag; i++)
		if (node[i] == nullptr)
		{
			node[i] = new Node(c);
			flag = true;
		}
		else if(node[i]->color == 'x')
			node[i]->Insert(c,flag);
}

void Node::Print()
{
	cout << color;
	for (int i = 0; i < 4; i++)
		if (node[i] != nullptr)
			node[i]->Print();
}
void Node::Print2()
{
	cout << color;
	for (int i = 2; i <= 3; i++)
		if (node[i] != nullptr)
			node[i]->Print2();
	for (int i = 0; i <= 1; i++)
		if (node[i] != nullptr)
			node[i]->Print2();
}
int C;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> C;
	while (C--)
	{
		string s;
		cin >> s;
		Node *root = new Node(s[0]);
		for (int i = 1; i < s.length(); i++)
		{
			bool flag = false;
			root->Insert(s[i], flag);
		}
		root->Print2();
		cout << endl;
	}
}