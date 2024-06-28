// CALC.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include"iostream"
#include"conio.h"
using namespace std;
class node
{
	friend class list;
	private:
		node *next;
		long zarib, nema;
};
class list
{
private:
	node *first1, *last1;
	node *first2, *last2;
	node *firstkol, *lastkol;
public:
	list();
	void add1();
	void add2();
	void sum();
	void multi();
	void mosh();
	void chap();
};
list::list()
{
	first1 = NULL;
	first2 = NULL;
	firstkol = NULL;
	last1 = NULL;
	last2 = NULL;
	lastkol = NULL;
	
}

void list::add1()
{
	node *p;
	p = new node;
	cout << "\n\n(one poly)PLEASE ANTER ZARIB  ";
	cin >> p->zarib;
	cout << "\n\n(one poly)PLEASE ANTER NEMA ";
	cin >> p->nema;
	if (first1 == NULL)
	{
		p->next = NULL;
		first1 = p;
		last1 = p;
	}
	else
	{
		p->next = NULL;
		last1->next = p;
		last1=p;
	}


}
void list::add2()
{
	node *p;
	p = new node;
	cout << "\n\n(two poly)PLEASE ANTER ZARIB  ";
	cin >> p->zarib;
	cout << "\n\n(two poly)PLEASE ANTER NEMA ";
	cin >> p->nema;
	if (first2 == NULL)
	{
		p->next = NULL;
		first2 = p;
		last2 = p;
	}
	else
	{
		p->next = NULL;
		last2->next = p;
		last2 = p;
	}
}
void list::sum()
{
	node *p, *k,*z;
	p = first1;
	while (p != NULL)
	{
		k = first2;
		while (k != NULL)
		{
			if (p->nema == k->nema)
			{
				z = new node;
				z->zarib = p->zarib + k->zarib;
				z->nema = p->nema;
				z->next = NULL;
				if (firstkol == NULL)
				{
					firstkol = z;
					lastkol = z;
				}
				else
				{
					lastkol->next = z;
					lastkol = z;
				}
			}
			k = k->next;
		}
		p = p->next;
	}
}
void list::multi()
{
	node *p, *k, *z;
	p = first1;
	while (p != NULL)
	{
		k = first2;
		while (k != NULL)
		{
			if (p->nema == k->nema)
			{
				z = new node;
				z->zarib = p->zarib + k->zarib;
				z->nema = p->nema;
				z->next = NULL;
				if (firstkol == NULL)
				{
					firstkol = z;
					lastkol = z;  
				}
				else
				{
					lastkol->next = z;
					lastkol = z;
				}
			}
			k = k->next;
		}
		p = p->next;
	}

}
void list::mosh()
{
	node *p, *k, *z;
	p = first1;
	while (p != NULL)
	{
		z = new node;
		z->zarib = p->zarib * p->nema;
		z->nema = p->nema - 1;
		z->next = NULL;
		if (firstkol == NULL)
		{
			firstkol = z;
			lastkol = z;
		}
		else
		{
			lastkol->next = z;
			lastkol = z;
		}
		p = p->next;
	}
}
void list::chap()
{
	node *p;
	p = firstkol;
	cout << "\n============C H A P   O F  R E S U L T============================\n";
	while (p != NULL)
	{
		if (p->zarib > 0)
			cout << "+";
		cout << p->zarib << "X^" << p->nema;
		p = p->next;
	}
}

void main()
{
	list w;
	char d;
	do
	{
		cout << "\n\n 1.ADD A NODE IN FIRST   POLYNOMIAD  ";
		cout << "\n\n 2.ADD A NODE IN SECOND  POLYNOMIAD  ";
		cout << "\n\n 3.SUM TWO  POLYNOMIADS  ";
		cout << "\n\n 4.MULTIPLATE  TWO  POLYNOMIADS  ";
		cout << "\n\n 5.MOSHTGH FOR FIRST  POLYNOMIAD  ";
		cout << "\n\n 6.PRINT RERULT . . .  ";
		cout << "\n\n 7.EXIT ";
		d = _getch();
		if (d == '1')
			w.add1();
		if (d == '2')
			w.add2();
		if (d == '3')
			w.sum();
		if (d == '4')
			w.multi();
		if (d == '5')
			w.mosh();
		if (d == '6')
			w.chap();
		if (d == '7')
			break;


	} while (1);
}

