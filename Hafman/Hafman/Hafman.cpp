// Hafman.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Hafman
{
	char simbol;
	double freqeuncy;
	Hafman(){}
	Hafman(char s, double f)
	{
		simbol = s;
		freqeuncy = f;
	}
};
class Tree
{
	
	struct Node
	{
		Hafman item;
		Node * left;
		Node * right;

		Node(Hafman i, Node *l = NULL, Node *r = NULL)
		{
			item = i;
			left = l;
			right = r;
		}
	};
	Node * root;
public:
	Tree()
	{
		root = NULL;
	}
	Node * GetRoot()
	{
		return root;
	}
	void Add(const Hafman &item)
	{
		Add(root, item);
	}
	void Print(Node * node)
	{
		if (node != NULL)
		{
			Print(node->left);
			cout << node->item.simbol<<" "<<node->item.freqeuncy << endl;
			Print(node->right);
		}

	}
private:
	void Add(Node *&node, const Hafman &item)
	{
		if (node == NULL)
		{
			node = new Node(item);
		}
		else if (item.freqeuncy < node->item.freqeuncy)
		{
			Add(node->left, item);
		}
		else
		{
			Add(node->right, item);
		}

	}
};

int main()
{
	Hafman h1('a', 0.3);
	Hafman h2('b', 0.25);
	Hafman h3('c', 0.15);
	Hafman h4('d', 0.06);
	Hafman h5('e', 0.24);

	Tree t;
	t.Add(h1);
	t.Add(h2);
	t.Add(h3);
	t.Add(h4);
	t.Add(h5);
	t.Print(t.GetRoot());

    return 0;
}

