#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	node* p;
	node* l;
	node* r;
	int value; //����� ��
	int size;  //�ڽĳ��+�ش����� ũ��
	node(int value, node* p)
		: p(p)
		, l(NULL)
		, r(NULL)
		, value(value)
		, size(1)
	{
	}

	void update()
	{
		//size�� ����
		size = 1;

		if (l)
		{
			size += l->size;
		}
		if (r)
		{
			size += r->size;
		}
	}

};

class SplayTree
{
public:
	SplayTree(const vector<int>& arr)
		: root(NULL)
	{
		//�Է¹��� �迭�� ���ؼ� Ʈ���� �����Ѵ�.
		node* t = NULL;
		for (int i = 0; i < arr.size(); i++)
		{
			node* newNode = new node(arr[i], NULL);
			newNode->size = arr.size() - i;
			if (t == NULL)
			{
				root = newNode;
				t = newNode;
			}
			else
			{
				t->r = newNode;
				newNode->p = t;
				t = t->r;
			}
		}
	}

	node* root;
	void Rotate(node* a)
	{
		//a����� ��ġ�� (a�� �θ���)p�� ��ȯ�ϴ� �����̴�.
		if (a->p != NULL)
		{
			node* ap = a->p;
			node* app = ap->p;

			if (a->p->l == a)
			{
				//�ڽ��� ���� �ڽ��϶�
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

				//�θ��ڽİ���� �ٲ����. ���� �����Ѵ�.
				ap->update();
				a->update();
			}
			else
			{
				//�ڽ��� ������ �ڽ��϶�
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

				//�θ��ڽİ���� �ٲ����. ���� �����Ѵ�.
				ap->update();
				a->update();
			}

		}
	}
	void Splay(node* a)
	{
		//a��带 ��Ʈ ���� ����� �����̴�.
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
		//�ش� Ʈ������ k��° ��带 root���� �����.
		node* x = root;
		if (x == NULL || x->size < k)
			return false;
		while (x != NULL)
		{
			while (x->l && x->l->size >= k)
			{
				x = x->l;
			}
			if (x->l)
				k -= x->l->size;
			k--;
			if (k == 0)
				break;
			x = x->r;
		}
		Splay(x);
		return true;
	}

	node* interval(int s, int e)
	{
		//s�� e������ ���� ���´�.
		//s�� e������ ��ǥ�ϴ� ��带 ���T����.
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
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> Arr;
	Arr.push_back(0); //interval�Լ��� �����Ҷ� ���κ� IndexError�� �����ϱ� ���ؼ� �־����.
	Arr.push_back(1);
	Arr.push_back(2);
	Arr.push_back(3);
	Arr.push_back(4);
	Arr.push_back(5);
	Arr.push_back(6);
	Arr.push_back(0); //interval�Լ��� �����Ҷ� ���κ� IndexError�� �����ϱ� ���ؼ� �־����.

	SplayTree splay(Arr); //���÷��� Ʈ�� ����

}