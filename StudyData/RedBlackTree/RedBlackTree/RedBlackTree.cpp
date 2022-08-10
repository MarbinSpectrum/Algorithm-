#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
struct Node
{
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
	bool color; //0(black), 1(red)
	T value;

	Node(T value, bool color);
	Node<T>* GetP();
	Node<T>* GetG();
	Node<T>* GetU();
};

template<typename T>
class RedBlackTree
{
public:
	RedBlackTree();
	void InsertData(T v);
	void Print();
private:
	Node<T>* root;
	vector<Node<T>*> SortNode(Node<T>* a, Node<T>* b, Node<T>* c);
	void Print(Node<T>* n);
	void ClearNode(Node<T>* a, Node<T>* b, Node<T>* c);
	void DoubleRed(Node<T>* node);
	void Restructuring(Node<T>* node);
	void ReColoring(Node<T>* node);
};

template<typename T>
Node<T>::Node<T>(T value, bool color)
	: parent(NULL)
	, left(NULL)
	, right(NULL)
	, color(color)
	, value(value)
{
}

template<typename T>
Node<T>* Node<T>::GetP()
{
	//부모노드 반환
	return parent;
}

template<typename T>
Node<T>* Node<T>::GetG()
{
	//조상노드 반환
	if (parent == NULL)
	{
		//부모노드가 없으면
		//조상노드도 없다.
		return NULL;
	}
	else
	{
		return parent->parent;
	}
	return NULL;
}

template<typename T>
Node<T>* Node<T>::GetU()
{
	//삼촌노드 반환
	if (GetG() == NULL)
	{
		//조상노드가 없으면 
		//삼촌노드도 없다.
		return NULL;
	}
	else
	{
		if (GetG()->left == GetP())
		{
			//왼쪽노드가 현재노드라면
			//오른쪽노드가 삼촌노드
			return GetG()->right;
		}
		else
		{
			return GetG()->left;
		}
	}
	return NULL;
}

template<typename T>
RedBlackTree<T>::RedBlackTree<T>()
	: root(NULL)
{
}

template<typename T>
void RedBlackTree<T>::InsertData(T v)
{
	if (root == NULL)
	{
		//루트노드로 설정할 노드가 없다면 삽입
		root = new Node<T>(v, 0);
	}
	else
	{
		Node<T>* find = root;

		while (find != NULL)
		{
			if (find->value > v)
			{
				if (find->left == NULL)
				{
					find->left = new Node<T>(v, 1);
					find->left->parent = find;
					find = find->left;
					break;
				}
				find = find->left;
			}
			else
			{
				if (find->right == NULL)
				{
					find->right = new Node<T>(v, 1);
					find->right->parent = find;
					find = find->right;
					break;
				}
				find = find->right;
			}
		}

		DoubleRed(find);
	}
}

template<typename T>
void RedBlackTree<T>::Print()
{
	Print(root);
}

template<typename T>
vector<Node<T>*> RedBlackTree<T>::SortNode(Node<T>* a, Node<T>* b, Node<T>* c)
{
	//노드를 정렬
	vector<Node<T>*> list = { a,b,c };
	sort(list.begin(), list.end(),
		[](Node<T>* a, Node<T>* b) -> bool
		{
			if (a == NULL)
				return true;
			else if (b == NULL)
				return false;
			return a->value < b->value;
		});
	return list;
}

template<typename T>
void RedBlackTree<T>::Print(Node<T>* n)
{
	if (n->left != NULL)
		Print(n->left);
	std::cout << n->value << " ";
	if (n->right != NULL)
		Print(n->right);
}

template<typename T>
void RedBlackTree<T>::ClearNode(Node<T>* a, Node<T>* b, Node<T>* c)
{
	//Restructuring을 위한 기존 연결관계 제거
	if ((a->left == b) || (a->left == c))
		a->left = NULL;
	if ((a->right == b) || (a->right == c))
		a->right = NULL;
}

template<typename T>
void RedBlackTree<T>::DoubleRed(Node<T>* node)
{
	Node<T>* P = node->GetP();
	Node<T>* G = node->GetG();
	Node<T>* U = node->GetU();

	if (G != NULL && P != NULL && P->color == 1)
	{
		//더블 레드인 상태
		if ((U != NULL && U->color == 0) || U == NULL)
		{
			//삼촌 노드가 검은색
			Restructuring(node);
		}
		else if (U != NULL && U->color == 1)
		{
			//삼촌 노드가 빨간색
			ReColoring(node);
		}
	}
}

template<typename T>
void RedBlackTree<T>::Restructuring(Node<T>* node)
{
	vector<Node<T>*> list = SortNode(node, node->GetP(), node->GetG());
	Node<T>* Link = node->GetG()->GetP();

	if (Link != NULL)
	{
		//루트노드가 아닐때
		if (Link->left == node->GetG())
			Link->left = list[1];
		else if (Link->right == node->GetG())
			Link->right = list[1];
	}
	else
	{
		//루트노드일때
		root = list[1];
	}
	list[1]->parent = Link;
	list[1]->left = list[0];
	list[1]->right = list[2];
	list[1]->color = 0;

	if (list[0] != NULL)
	{
		list[0]->parent = list[1];
		ClearNode(list[0], list[1], list[2]);
		list[0]->color = 1;
	}

	if (list[2] != NULL)
	{
		list[2]->parent = list[1];
		ClearNode(list[2], list[0], list[1]);
		list[2]->color = 1;
	}
}

template<typename T>
void RedBlackTree<T>::ReColoring(Node<T>* node)
{
	Node<T>* P = node->GetP();
	Node<T>* G = node->GetG();
	Node<T>* U = node->GetU();

	if (G->GetP() == NULL)
	{
		//조상이 루트 노드다.
		G->color = 0;
		P->color = 0;
		if (U != NULL)
		{
			U->color = 0;
		}
	}
	else
	{
		G->color = 1;
		P->color = 0;
		if (U != NULL)
		{
			U->color = 0;
		}

		DoubleRed(node);
	}
}

int main()
{
	RedBlackTree<int> rbt;
	rbt.InsertData(12);
	rbt.InsertData(8);
	rbt.InsertData(7);
	rbt.InsertData(6);
	rbt.InsertData(9);
	rbt.InsertData(4);
	rbt.InsertData(5);
	rbt.InsertData(3);

	rbt.Print();

	return 0;
}