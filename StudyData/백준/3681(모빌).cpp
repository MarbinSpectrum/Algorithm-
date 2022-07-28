#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

struct Node
{
	Node* left;
	Node* right;
	int deep;
	int value;
	Node()
	: left(NULL)
	, right(NULL)
	, deep(0)
	, value(0)
	{
	}
};
vector<Node*> Arr;

int MakeV(Node* node)
{
	return (node->value)* (1 << (node->deep));
}

int C(const Node* node,int v)
{
	if (node->left != NULL && node->right != NULL)
	{
		return C(node->left, v / 2) + C(node->right, v / 2);
	}
	else
	{
		return (node->value != v);		
	}
}
void D(const string& s,Node* node, int d)
{
	node->deep = d;
	int st = 0;
	int p = -1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
			st++;
		else if (s[i] == ']')
			st--;
		else if (s[i] == ',' && st == 1)
		{
			p = i;
			break;
		}
	}

	if (p == -1)
	{
		node->value = std::stol(s);
		Arr.push_back(node);
	}
	else
	{
		node->left = new Node();
		node->right = new Node();
		D(s.substr(1, p - 1), node->left, d + 1);
		D(s.substr(p + 1, s.length() - p - 2), node->right, d + 1);
	}
}
void F()
{
	std::string s;
	std::cin >> s;

	Node* now = new Node();

	D(s, now, 0);

	int ans = INF;
	for (int i = 0; i < Arr.size(); i++)
	{
		int V = MakeV(Arr[i]);
		ans = min(ans,C(now, V));
	}

	std::cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		F();
	}
}