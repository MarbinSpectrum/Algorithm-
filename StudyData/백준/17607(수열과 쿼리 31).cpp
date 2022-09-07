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
	int sum;
	int lmax;
	int rmax;
	int tmax;
	bool inv;

	node(int value, node* p)
		: p(p)
		, l(NULL)
		, r(NULL)
		, value(value)
		, size(1)
		, lmax(0)
		, rmax(0)
		, tmax(0)
		, sum(value)
		, inv(false)
	{
	}
	void pull()
	{
		push();

		size = 1;
		if (value > 0)
			tmax = lmax = rmax = 1;
		else
			tmax = lmax = rmax = 0;

		if (l)
		{
			size += l->size;
			sum += l->sum;
		}
		if (r)
		{
			size += r->size;
			sum += r->sum;
		}

		if (l != NULL && r != NULL)
		{
			l->push();
			r->push();
			lmax = l->lmax;
			if (l->size == l->lmax && value > 0)
				lmax += r->lmax + value;

			rmax = r->rmax;
			if (r->size == r->rmax && value > 0)
				rmax += l->rmax + value;

			tmax = max(r->tmax, l->tmax);
			if (value > 0)
				tmax = max(tmax, l->rmax + r->lmax + value);
			tmax = max({ tmax, lmax, rmax });
			tmax = max({ tmax, l->rmax + value, r->lmax + value });

		}
		else if (l != NULL)
		{
			l->push();
			lmax = l->lmax;
			if (l->lmax == l->size)
				lmax = l->size + value;
			rmax = value > 0 ? value + l->rmax : 0;
			tmax = max(l->tmax, value);
			tmax = max(tmax, l->rmax + value);
			tmax = max({ tmax, lmax, rmax });
		}
		else if (r != NULL)
		{
			r->push();
			rmax = r->rmax;
			if (r->rmax == r->size)
				rmax = r->size + value;
			lmax = value > 0 ? value + r->lmax : 0;
			tmax = max(r->tmax, value);
			tmax = max(tmax, r->lmax + value);
			tmax = max({ tmax, lmax, rmax });
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

		int temp = lmax;
		lmax = rmax;
		rmax = temp;

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
			}
			ap->pull();
			a->pull();
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
	void Reverse(int s, int e)
	{
		node* n = interval(s, e);
		if (n != NULL)
			n->inv = !(n->inv);
	}
	int GetMax(int s, int e)
	{
		node* n = interval(s, e);
		return n->tmax;
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

	std::cin >> N;
	Arr.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int a;
		std::cin >> a;
		Arr.push_back(a);
	}
	Arr.push_back(0);

	SplayTree splay(Arr);

	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		b++;
		c++;
		if (a == 1)
		{
			splay.Reverse(b, c);
		}
		else if (a == 2)
		{
			int ans = splay.GetMax(b, c);
			if (ans < 0)
				cout << 0 << endl;
			else
				std::cout << splay.GetMax(b, c) << endl;
		}
		//ans.clear();
		//splay.GetNode(ans, splay.root);
		//for (int i = 1; i < ans.size() - 1; i++)
		//	cout << ans[i] << " ";
		//cout << endl;
	}
}