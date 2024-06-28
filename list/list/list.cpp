// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include"conio.h"
using namespace std;

class node
{
	friend class list;
	private:
		long a;
		node *next;
};
class list
{
	private:
		node *first,*last;
	public:
		list();
	//	~list();
		void add();
		void chap();
		void del();
};
list::list()
{
	first= NULL;
	
	last = NULL;
}
void list::add()
{
	node *k;
	long u;
	k = new node;
	cout << "\n\nenter number . . . ";
	cin >> u;
	k->a = u;
	k->next = NULL;

	if (first == NULL)
	{
		first = k;
		last = k;
	}
	else
	{
		last->next = k;
		last = k;
	}
}
void list::chap()
{
	node *p;
	p = first;
	if (p == NULL)
		cout << "LIST IS EMPTY";
	else
	{
		cout << "\n\n===============================list =============================";
		do 
		{
			cout << "\n"<<p->a;
			p = p->next;
		} while (p != NULL);
	}

}
void list::del()
{
	long d;
	node *p1, *p2;


	if (first == NULL)
	{
		cout << "\n list is empty. . . . ";
	}
	else
	{
		cout << "\n\n enter a number for delete . . . ";
		cin >> d;
		p1 = p2 = first;
		while (p1 != NULL)
		{
			if (p1->a == d)
				break;
			else
			{
				p2 = p1;
				p1 = p1->next;
			}
		}
		if (p1 == NULL)
			cout << "not found . . . .";
		else
		{
			p2->next = p1->next;
			delete(p1);
		}
	}

	
}


int main()
{
	list w;
	char f;
	do
	{

		cout << "\n 1. add a number to list  . . . ";
		cout << "\n 2. del  a number to list  . . . ";
		cout << "\n 3. print all number   . . . ";
		cout << "\n 4. exit  . . . ";
		f = _getch();
		if (f == '1')
			w.add();
		if (f == '2')
			w.del();
		if (f == '3')
			w.chap();
		if (f == '4')
			break;


	} while (1);
		
	return 0;
}

