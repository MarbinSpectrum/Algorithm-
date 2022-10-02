#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	node* p;
	node* l;
	node* r;
	int value; //노드의 값
	int size;  //자식노드+해당노드의 크기
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
		//size값 갱신
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
		//입력받은 배열을 통해서 트리를 생성한다.
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
		//a노드의 위치를 (a의 부모노드)p와 교환하는 연산이다.
		if (a->p != NULL)
		{
			node* ap = a->p;
			node* app = ap->p;

			if (a->p->l == a)
			{
				//자신이 왼쪽 자식일때
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

				//부모자식관계까 바뀌었다. 새로 갱신한다.
				ap->update();
				a->update();
			}
			else
			{
				//자신이 오른쪽 자식일때
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

				//부모자식관계까 바뀌었다. 새로 갱신한다.
				ap->update();
				a->update();
			}

		}
	}
	void Splay(node* a)
	{
		//a노드를 루트 노드로 만드는 연산이다.
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
		//해당 트리에서 k번째 노드를 root노드로 만든다.
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
		//s와 e구간을 따로 묶는다.
		//s와 e구간을 대표하는 노드를 반홚나다.
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
	Arr.push_back(0); //interval함수를 실행할때 끝부분 IndexError를 방지하기 위해서 넣어줬다.
	Arr.push_back(1);
	Arr.push_back(2);
	Arr.push_back(3);
	Arr.push_back(4);
	Arr.push_back(5);
	Arr.push_back(6);
	Arr.push_back(0); //interval함수를 실행할때 끝부분 IndexError를 방지하기 위해서 넣어줬다.

	SplayTree splay(Arr); //스플레이 트리 생성

}