// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include"conio.h"
using namespace std;
class sort
{
private:
	//long a[20];
	//	char s[10][20];
public:
	long a[20];
	void input();
	void print();
	void search();
	void binarysearch();
	void bouble_sort();
	void selection_sort();
	void insert_sort();
	void split(long a[], long first, long last, long *position);
	void quick_sort(long a[], long first, long last);
};
void sort::split(long a[], long first, long last, long *position)
{
	int left, right, cut,x;
	left = first;
	right = last;
	cut = a[first];
	while (left < right)
	{
		while (a[right]>cut)
			right--;
		while (a[left] <= cut && left < right)
			left++;
		if (left < right)
		{
			x = a[left];
			a[left] = a[right];
			a[right] = x;
		}
	}
	
	*position = right;
	a[first] = a[*position];
	a[*position] = cut;
}
void sort::quick_sort(long a[],long first , long last )
{
	long pos;
	if (first < last)
	{
		split(a, first, last, &pos);
		quick_sort(a, first, pos - 1);
		quick_sort(a,  pos + 1 , last);

	}
}
void sort::input()
{
	cout << "\n\n ENTER 20 NUMBERS . . . .";
	for (int i = 0; i < 20; ++i)
		cin >> a[i];
}
void sort::print()
{
	cout << "\n======================THE SORTED NUMBERS ==================================\n";
	for (int i = 0; i < 20; ++i)
		cout << " - " << a[i];
}
void sort::search()
{
	long k, flag = 0;
	cout << "\n ENTER A NUMBER FOR SEARCH. . . ";
	cin >> k;
	for (int i = 0; i < 20; ++i)
		if (a[i] == k)
		{
			flag = 1;
			break;
		}
	if (flag)
		cout << "\n NUMBERS IS FOUND . . . .";
	else
		cout << "\nNUMBERS IS NOT FOUND . . . .";
}
void  sort::binarysearch()
{
	long  mid, min, max, k, flag = 0;;
	cout << "\n ENTER A NUMBER FOR SEARCH. . . ";
	cin >> k;

	min = 0;
	max = 19;
	while (min<max - 1)
	{
		mid = (min + max) / 2;
		if (a[mid] > k)

			max = mid;
		else
			if (a[mid] < k)
				min = mid;
			else
			{
				flag = 1;
				break;
			}
	}
	if (flag)
		cout << "\nNUMBERS IS FOUND . . . .";
	else
		cout << "\nNUMBERS IS NOT FOUND . . . .";

}

void sort::bouble_sort()
{
	long n = 20;
	int i, j, m, flag = 1;
	for (i = n - 1; i > 0 && flag; --i)
	{
		flag = 0;
		for (j = 0; j < i; ++j)
			if (a[j]>a[j + 1])
			{
				flag = 1;
				m = a[j];
				a[j] = a[j + 1];
				a[j + 1] = m;
			}
	}

}
void sort::selection_sort()
{
	int i, j, minindex, n = 20, x;
	for (i = 0; i < n - 1; ++i)
	{
		minindex = i;
		for (j = i + 1; j < n; ++j)
			if (a[j] < a[minindex])
				minindex = j;
		x = a[minindex];
		a[minindex] = a[i];
		a[i] = x;

	}
}
void sort::insert_sort()
{
	int x, i, j, n = 20;
	for (i = 1; i < n; ++i)
	{
		x = a[i];
		for (j = i; j > 0 && a[j - 1]>x; --j)
			a[j] = a[j - 1];
		a[j] = x;
	}
}


void main()
{
	sort w;
	char d;
	do
	{
		cout << "\n 1. input 20 number";
		cout << "\n 2. print  numbers";
		cout << "\n 3. simple search ";
		cout << "\n 4. binary search";
		cout << "\n 5. bouble sort";
		cout << "\n 6. selection sort";
		cout << "\n 7. insert sort";
		cout << "\n 8 quick sort";
		cout << "\n 9. exit";
		d = _getch();
		if (d == '1')
			w.input();
		if (d == '2')
			w.print();
		if (d == '3')
			w.search();
		if (d == '4')
			w.binarysearch();
		if (d == '5')
			void bouble_sort();
		if (d == '6')
			w.selection_sort();
		if (d == '7')
			w.insert_sort();
		if (d == '8')
			w.quick_sort(w.a,0,19);
		if (d == '9')
			break;
	} while (1);
}

