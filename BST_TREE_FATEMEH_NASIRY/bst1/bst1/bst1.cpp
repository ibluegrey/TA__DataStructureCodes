// bst1.cpp : Defines the entry point for the console application.
//

// tree.cpp : Defines the entry point for the console application.
#include"stdafx.h"
#include"iostream"
#include"conio.h"
using namespace std;
class node
{
	friend class tree;
private:
	node  *left, *right;
	long num;
};
class tree
{
private:
	node *root;

public:
	tree();
	void add(long k);
	void del(long k);  ///////////////////////////////
	void inorder(node *st);
	void preoder(node *s);
	void postorder(node *s);
	void chap();
	node *getroot() {
		return root;
	}
	void search(long num, long *found, node **loc, node **parent);////////////////



};
tree::tree()
{
	root = NULL;
}
void tree::chap()
{
	node *s;
	s = root;
	inorder(s);
}

void tree::add(long kk)
{
	node *p, *k;
	p = new node;
	p->right = NULL;
	p->left = NULL;
	p->num = kk;
	if (root == NULL)
		root = p;
	else
	{
		k = root;
		while (1)
		{
			if (k->num > p->num)
			{
				if (k->left == NULL)
				{
					k->left = p;
					break;
				}
				k = k->left;
			}
			else
			{
				if (k->right == NULL)
				{
					k->right = p;
					break;
				}
				k = k->right;
			}

		}
	}



}
void tree::inorder(node *s)
{
	if (s)
	{
		inorder(s->left);
		cout << "  =  " << s->num;
		inorder(s->right);
	}
}
void tree::preoder(node *s)
{
	if (s)
	{
		cout << "  =  " << s->num;
		preoder(s->left);
		preoder(s->right);
	}
}
void tree::postorder(node *s)
{
	if (s)
	{
		postorder(s->left);
		postorder(s->right);
		cout << "  =  " << s->num;
	}
}


void tree::search(long n, long *found, node **loc, node **parent)
{
	*found = 0;
	*loc = root;
	*parent = NULL;
	while (1)
	{
		if (*found || *loc == NULL)
		{
			return;
		}
		if (n > (*loc)->num)
		{
			*parent = *loc;
			*loc = (*loc)->right;

		}
		else
			if (n < (*loc)->num)
			{
				*parent = *loc;
				*loc = (*loc)->left;
			}
			else
				*found = 1;
	}

}
void tree::del(long k)
{
	long found;
	node *x, *parent, *next, *sub;
	search(k, &found, &x, &parent);
	if (!found)
	{
		cout << "not found . . . ";
		return;
	}
	if (x->right != NULL && x->left != NULL)
	{

		next = x->right;
		parent = x;
		while (next->left != NULL)
		{
			parent = next;
			next = next->left;
		}
		x->num = next->num;
		x = next;
	}
	sub = x->left;
	if (sub == NULL)
		sub = x->right;
	if (parent = NULL)
		root = sub;
	else
		if (parent->right == x)
			parent->right = sub;
		else
			parent->left = sub;
	delete x;
}
//////////////////////////////////////////////////
void main()
{
	long a;
	char d;
	tree w;
	do
	{
		cout << "\n\n 1. ADD A NODE TO TREE. . . . ";
		cout << "\n\n 2. PRINT preorder TREE. . . . ";
		cout << "\n\n 3. PRINT postoder TREE. . . . ";
		cout << "\n\n 4. chap  TREE. . . . ";
		cout << "\n\n 5. DEL  A NODE FROM  TREE. . . . ";
		cout << "\n\n 6. EXIT. . . . ";
		d = _getch();
		if (d == '1')
		{
			cout << "\n\n enter a number to add . . . . ";
			cin >> a;
			w.add(a);
		}
		if (d == '2')
		{
			w.preoder(w.getroot());

		}

		if (d == '3')
		{
			w.postorder(w.getroot());

		}

		if (d == '5')
		{
			cout << "\n\n enter a number to del . . . . ";
			cin >> a;
			w.del(a);
		}
		if (d == '4')
		{
			w.chap();

		}
		if (d == '6')
			break;
	} while (1);
}