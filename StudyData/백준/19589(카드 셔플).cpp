#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

const int INF = 999999999999999;
const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

//////////////////////////////////////////////////////////////////////// 

struct node
{
	node* p;
	node* l;
	node* r;
	int value;
	int size;
	int minV;
	int maxV;
	int sum;
	bool inv;
	node(int value, node* p)
		: p(p)
		, l(NULL)
		, r(NULL)
		, value(value)
		, size(1)
		, minV(value)
		, maxV(value)
		, sum(value)
		, inv(false)
	{
	}
	void pull()
	{
		size = 1;
		sum = value;
		minV = value;
		maxV = value;

		if (l)
		{
			size += l->size;
			minV = min(minV, l->minV);
			maxV = max(maxV, l->maxV);
			sum += l->sum;
		}
		if (r)
		{
			size += r->size;
			minV = min(minV, r->minV);
			maxV = max(maxV, r->maxV);
			sum += r->sum;
		}
	}
	void push()
	{
		if (inv == false)
			return;
		node* t = l;
		l = r;
		r = t;
		inv = false;
		if (l)
		{
			l->inv = !(l->inv);
		}
		if (r)
		{
			r->inv = !(r->inv);
		}
	}
};

node* NodePtr[2000000];
class SplayTree
{
public:
	SplayTree(const vector<int>& arr)
		: root(NULL)
	{
		node* t = NULL;
		for (int i = 0; i < arr.size(); i++)
		{
			NodePtr[i] = new node(arr[i], NULL);
			NodePtr[i]->size = arr.size() - i;
			if (t == NULL)
			{
				root = NodePtr[i];
				t = NodePtr[i];
			}
			else
			{
				t->r = NodePtr[i];
				NodePtr[i]->p = t;
				t = t->r;
			}
		}
	}

	node* root;
	void Rotate(node* a)
	{
		if (a->p != NULL)
		{
			node* ap = a->p;
			node* app = ap->p;
			ap->push();
			a->push();

			if (a->p->l == a)
			{
				node* ar = a->r;
				a->p = app;
				if (ar != NULL)
					ar->p = ap;
				ap->p = a;

				a->r = ap;
				ap->l = ar;
				if (app != NULL)
				{
					if (app->l == ap)
						app->l = a;
					else
						app->r = a;
				}

				ap->pull();
				a->pull();
			}
			else
			{
				node* al = a->l;
				a->p = app;
				if (al != NULL)
					al->p = ap;
				ap->p = a;

				a->l = ap;
				ap->r = al;
				if (app != NULL)
				{
					if (app->l == ap)
						app->l = a;
					else
						app->r = a;
				}

				ap->pull();
				a->pull();
			}

		}
	}
	void Splay(node* a)
	{
		while (a->p != NULL)
		{
			node* p = a->p;
			node* g = p->p;

			if (g == NULL)
			{
				Rotate(a);
			}
			else if ((a == p->r && p == g->r) || (a == p->l && p == g->l))
			{
				Rotate(p);
				Rotate(a);
			}
			else
			{
				Rotate(a);
				Rotate(a);
			}
		}
		root = a;
	}

	bool Find(int k)
	{
		node* x = root;
		if (x == NULL || x->size < k)
			return false;
		x->push();
		while (x != NULL)
		{
			while (x->l && x->l->size >= k)
			{
				x = x->l;
				x->push();
			}
			if (x->l)
				k -= x->l->size;
			k--;
			if (k == 0)
				break;
			x = x->r;
			x->push();
		}
		Splay(x);
		return true;
	}

	node* interval(int s, int e)
	{
		Find(e + 1);
		node* x = root;
		root = root->l;
		root->p = NULL;
		Find(s - 1);
		x->l = root;
		root->p = x;
		root = x;
		return root->l->r;
	}
	int GetMin(int s, int e)
	{
		node* n = interval(s, e);
		return n->minV;
	}
	int GetMax(int s, int e)
	{
		node* n = interval(s, e);
		return n->maxV;
	}
	int GetSum(int s, int e)
	{
		node* n = interval(s, e);
		return n->sum;
	}
	int GetNum(int i)
	{
		Find(i);
		node* n = root;
		return n->value;
	}
	void Reverse(int s, int e)
	{
		node* n = interval(s, e);
		if (n != NULL)
			n->inv = !(n->inv);
	}
	void Shift(int s, int e, int x)
	{
		int len = e - s + 1;
		while (x < 0)
			x += len;
		x %= len;
		x = len - x;
		Reverse(s, s + x - 1);
		Reverse(s + x, e);
		Reverse(s, e);
	}
	void Riffle(int s, int e)
	{
		node* a = interval(s, e);
		vector<int> dummy;
		GetNode(dummy, a);
		queue<int> aQ;
		queue<int> bQ;
		for (int i = 0; i < dummy.size(); i++)
		{
			if (i < dummy.size()/2)
				aQ.push(dummy[i]);
			else 
				bQ.push(dummy[i]);
		}
		bool c = false;
		SetRiffle(aQ, bQ, c, a);
	}
	void SetRiffle(queue<int>& aQ, queue<int>& bQ, bool& c, node* a)
	{
		if (a == NULL)
			return;
		a->push();
		if (a->l)
			SetRiffle(aQ, bQ, c, a->l);
		if (c == false)
		{
			a->value = aQ.front();
			aQ.pop();
		}
		else
		{
			a->value = bQ.front();
			bQ.pop();
		}
		c = !c;
		if (a->r)
			SetRiffle(aQ, bQ,c, a->r);
	}

	void GetNode(vector<int>& ans, node* a)
	{
		if (a == NULL)
			return;
		a->push();
		if (a->l)
			GetNode(ans, a->l);
		ans.push_back(a->value);
		if (a->r)
			GetNode(ans, a->r);
	}
};

int N, Q;
vector<int> Arr;
vector<int> ans;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> Q;
	Arr.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		Arr.push_back(i);
	}
	Arr.push_back(0);

	SplayTree splay(Arr);

	for (int i = 0; i < Q; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		b++;
		c++;
		if (a == 1)
		{
			splay.Shift(2, c, c - b + 1);
		}
		else if (a == 2)
		{
			splay.Shift(b, N + 1, N + 1 - c);
		}
		else
		{
			splay.Riffle(b, c);
		}
	}
	ans.clear();
	splay.GetNode(ans, splay.root);
	for (int i = 1; i < ans.size() - 1; i++)
		cout << ans[i] << " ";
	cout << endl;
}