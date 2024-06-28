// avl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include"conio.h"
using namespace std;
class node
{
	friend class tree;
	private:
		node *right, *left;
		int num;
		int flag;
};
class tree
{
	private:
		node *root;
	public:
		tree();
		void input();
		void insert(node **, int x, int *ub);
		void rithtr(node **, int *ub);
		void leftr(node **, int *ub);
		void inorder(node *s);
		node *getr() {
		return root;
	}
};
void tree::inorder(node *s)
{
	if (s != NULL)
	{
		inorder(s->left);
		cout << s->num << " - ";
		inorder(s->right);
	}
}
tree::tree()
{
	root = NULL;
}
tree avl;
void tree::input()
{
	node *p;
	int x, ub;
	while (1)
	{
		cout << "\n enter number . . . ";
		cin >> x;
		if (!x)
			break;
		insert(&root, x, &ub);
	}
}
void tree::insert(node **parent, int x, int *ub)
{
	if (!(*parent))
	{
		*ub = 1;
		(*parent) = new node;
		(*parent)->left = (*parent)->right = NULL;
		(*parent)->flag = 0;
		(*parent)->num = x;
	}
	else
		if((*parent)->num>x)
		{
			insert(&(*parent)->left, x, ub);
			if (*ub)
			{
				switch ((*parent)->flag)
				{
				case -1:
						(*parent)->flag = 0;
						*ub = 0;
						break;
					case 0:
						(*parent)->flag = 1;
						break;
					case 1:
						avl.rithtr(parent, ub);

				}

			}
		}
		else
			if ((*parent)->num<x)
			{
					insert(&(*parent)->right, x, ub);
					if (*ub)
					{
						switch ((*parent)->flag)
						{
						case -1:
							(*parent)->flag = 0;
							*ub = 0;
							break;
						case 0:
							(*parent)->flag = -1;
							break;
						case 1:
							avl.leftr(parent, ub);

						}

					}
			}
			else // 
			{
				*ub = 0;
				cout << "number is exist. . . ";
				_getch();
			}
}

void tree::rithtr(node **parent, int *ub)
{
	node *child, *grandghild;
	child = (*parent)->left;

	if (child->flag == 1)// LL
	{
		(*parent)->left = child->right;
		child->right = (*parent) -> left;
		(*parent)->flag = 0;
		*parent = child;

	}
	else  //LR;
	{
		grandghild = child->right;
		child->right = grandghild->left;
		grandghild->left = child;
		(*parent)->left = grandghild->right;
		switch (grandghild->flag)
		{
		case 1:
			(*parent)->flag = -1;
			child->flag = 0;
			break;
		case 0:
			(*parent)->flag = 0;
			child->flag = 0;
			break;
		case -1:
			(*parent)->flag = 0;
			child->flag = 1;

		}

		*parent = grandghild;
	}
	*ub = 0;

}

void tree::leftr(node **parent, int *ub)
{
	node *child, *grandghild;
	child = (*parent)->right;

	if (child->flag == 1) //RR
	{
		(*parent)->right = child->left;
		child->left = (*parent)->right;
		(*parent)->flag = 0;
		*parent = child;

	}
	else  //RL;
	{
		grandghild = child->left;
		child->left = grandghild->right;
		grandghild->right = child;
		(*parent)->right = grandghild->left;
		switch (grandghild->flag)
		{
		case 1:
			(*parent)->flag = -1;
			child->flag = 0;
			break;
		case 0:
			(*parent)->flag = 0;
			child->flag = 0;
			break;
		case -1:
			(*parent)->flag = 0;
			child->flag = 1;

		}

		*parent = grandghild;
	}
	*ub = 0;



}

void main()
{
	tree w;
	char d;
	do
	{
		cout << "\n\n 1.ADD A NUMBER TO AVL_TREE  . . .";
		cout << "\n\n 2.PRINT INORDER ORDER  AVL_TREE  . . .";
		cout << "\n\n 3.EXIT  . . .";
		d =_getch();
		if (d == '1')
			w.input();
		if (d == '2')
			w.inorder(w.getr());
		if (d == '3')
			break;
	} while (1);



	_getch();
}
