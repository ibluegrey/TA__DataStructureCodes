// heap3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include"conio.h"
using namespace std;
void heap(long a[], long start, long tedad) // تابع ایجاد یک مین هیپ
{
	long t, j;
	t = a[start];
	while (start < tedad / 2)
	{
		j = 2 * start + 1;
		if (j + 1 <tedad && a[j + 1]<a[j])
			j++;

		if (a[j] > t)
			break;
		a[start] = a[j];
		start = j;
	}
	a[start] = t;
}
void sort(long a[], long n)  // تابع مرتب  سازی توسط مین هیپ
{
	int i, t;
	for (i = n / 2 - 1; i >= 0; i--)
		heap(a, i, n);
	for (i = n - 1; i>0; i--)
	{
			t = a[0];
			a[0] = a[i];
			a[i] = t;
		heap(a, 0, i);
	}
}
void main()
{
	long a[15] = { 491,34,8,9,54,67,32,12,23,45,32,4,87,43,58 };

	sort(a, 15);

	for (int i = 0; i < 15; ++i)
		cout << a[i] << "  -  ";

	_getch();
}



