// IN_TO_POST.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include"iostream"
#include"conio.h"
#include"string.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class stack2     // این پشته برای محاسبه مقدار عددی عبارت تعریف شده است و در آن می توانیم عدد های صحیح را نگهداری کنیم 
{
private:
	long k[40];
	int top;
public:
	stack2();
	long pop();
	void push(long b);
	int empty();  // تابع تشخیص خالی بودن پشته 

};
int stack2::empty()
{
	if (top == -1) //اگر شاخص پشته برابر با منفی یک باشد خوب پس پشته خالی شده است 
		return 1;
	else
		return 0;
}
stack2::stack2()
{

	top = -1;
}
long stack2::pop()
{
	long y;

	y = k[top];
	top--;
	return y;

}
void stack2::push(long b)
{
	if (top == 39)
		cout << "\nSTACK IS FULL / / / ";
	else
	{
		top++;
		k[top] = b;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class stack
{
private:
	char k[40];
	int top;
public:
	stack();
	char pop();
	void push(char b);
	int empty();  // تابع تشخیص خالی بودن پشته 

};
int stack::empty()
{
	if (top == -1) //اگر شاخص پشته برابر با منفی یک باشد خوب پس پشته خالی شده است 
		return 1;
	else
		return 0;
}
stack::stack()
{
	strcpy_s(k, "");
	top = -1;
}
char stack::pop()
{
	char y;

	y = k[top];
	top--;
	return y;

}
void stack::push(char b)
{
	if (top == 39)
		cout << "\nSTACK IS FULL / / / ";
	else
	{
		top++;
		k[top] = b;
	}
}
int type(char p)  // این تابع نوع  کاراکتر ها را مشخص می کند و با توجه به اولویت عملگر ها یک عدد بر می گرداند 
{
	int fl = 0;
	if (p == '(')// پرانتز باز در میان عملگر های درون پشته کمترین اولویت را دارد 
		fl = 0;
	if (p == '-' || p == '+') // بعدش جمع و تفریق
		fl = 1;
	if (p == '*' || p == '/')  // بعدش ضرب و تقسیم 
		fl = 2;
	if (p == '^-') // و بالاترین اولویت برای توان 
		fl = 3;
	if (p == ')')
		fl = -1;
	if (p >= 'a' && p <= 'z') // اگر عملوند باشد 
		fl = -2;
	return fl;
}
void hesab(char k[40])   // این تابع یک رشته عبارت پسوندی حرفی را می گیرد  و سپس به ازای هر حرف یک مقدار عددی دریافت می کند و مقدار عددی نهایی حاصل محاسبات را چاپ می کند 
{
	char a[20], m;  // آرایه برای ذخیره حرف های رون رشته پسوندی تعریف شده است 
	stack2 num;;
	int b[20];   // این آرایه نیز برای ذخیر ه مقدار های عددی معادل هر حرف تعریف شده است 
	int t, c, j = 0, i, r, x;
	long adad1, adad2, javab, s;
	for (i = 0; i < strlen(k); ++i)
	{
		m = k[i];   // حرفهای عبارت پسوندی را دونه دونه بر می داریم 
		if (m >= 'a' && m <= 'z')  // اگر حرف بودن 
		{

			c = 0;     //  اینجا بررسی می کنیم که حرف تکرای در آرایه قرار نگیرد 
			for (t = 0; t < j; ++t)
				if (m == k[t])
					c++;
			if (c == 0)  // اگر  حرف تکرای نبود  آنرا در آرایه بذار
			{
				a[j] = m;
				j++;
			}
		}
	}
	for (i = 0; i < j; ++i)   //  این حلیه به ازای هر حرف آرایه یک عدد برایش می خواند و در آرایه بی ذخیره می کند 
	{
		cout << "\n PLEASE ENTER VALUE FOR THIS CHAR ->" << a[i] << "->";
		cin >> b[i];
	}

	for (x = 0; x < strlen(k); ++x)   //  این حلقه عبارت پسوندی را مقدار عددی اش را محاسبه می کند 
	{
		m = k[x];                        // از اول عبارت یکی یکی بردار
			if (m >= 'a' && m <= 'z')    // اگر حرف بود 
			{
				for (r = 0; r < j; ++r)
					if (m == a[r])
					{
						num.push(b[r]);  // مقدار معادل آنرا در پشته ببر
					}
			}
			else  // و اگر عملگر بود 
			{
				adad2 = num.pop();  // دو تا دونه از پشته در بیار و مقدار عددی را حساب کن و دوباره به پشته ببر
				adad1 = num.pop();
				if (m == '+')
					javab = adad1 + adad2;
				if (m == '-')
					javab = adad1 - adad2;
				if (m == '*')
					javab = adad1 * adad2;
				if (m == '/')
					javab = adad1 / adad2;
				if (m == '^')
					javab = pow(adad1, adad2);
				if (m == '%')
					javab = adad1 % adad2;

				num.push(javab);
			}
	}//for
	s = num.pop();  //  در پایان آخرین عددی که در پشته مونده مقدار عددی کل می باشد آنرا در میاریم و چاپ می کنیم
	cout << "	\n\n THE FINAL RESULT IS->" << s;
}




void main()
{
	stack w;
	char s[50] = "", ns[50] = "";
	char u, f = '0', t, d;
	int i, j, x;
	cout << "PLEASE ENTER A INORDER STRING . . . ";
	cin >> s;
	_strlwr_s(s);

	j = 0;
	for (i = 0; i < strlen(s); ++i) // به ترتیب یکی یکی از ابتدای عبارت میانوندی بر می داریم 
	{
		u = s[i];   // کاراکتر برداشته شده 
		d = type(u); // نوعش را مشخص می کنیم
		switch (d)
		{
		case 0:     // پرانتز باز را در پشته بذار
			w.push(u);
			break;
		case -2:   // عملوند را در عبارت جدید بگذار
		{
			ns[j] = u;
			j++;
			break;
		}
		case -1:   // پرانتز بسته بود آنقدر از پشته در بیار و به عبارت جدید ببر تا برسی به پرانتز باز و البته پرانتز باز حذف می شه  
		{

			f = w.pop();
			while (f != '(')   // در آوردن از پشنه و افزودن به 
			{
				ns[j] = f;
				j++;
				f = w.pop();
			}
			break;
		}
		case 1:   // اگر یکی از عملگر های عملیاتی بود
		case 2:
		case 3:
		{
			//f = w.pop();
			if (w.empty()) // اگر پشته خالی است اولین عملگر به پشته برده شود
				w.push(u);
			else
			{
				f = w.pop();
				if (type(u) > type(f))
				{
					w.push(f);  // یکی در میاریم اگر اولویت عملگر جدا کرده بیشتر بود آنرا به پشته می بریم 
					w.push(u);
				}
				else // در غیر این صورت 
				{
					while (1)
					{
						ns[j] = f;  // عملگر در آورده را به عبارت جدید ببر 
						j++;

						if (w.empty())
							break;
						f = w.pop(); // و یک دونه عملگر دیگه از پشته در بیار و مقایسه کن

						if (type(u) >= type(f))
						{
							break;
						}
					}
					w.push(u); //  در آخر همون عملگر جدا شده هم به پشته برود


				}
			}
		}//case
		}
	}//for


	do  //  در پایان هر چی تو پشته بود در بیار و به عبارت جدید ببر
	{
		t = w.pop();
		ns[j] = t;
		j++;
		t = w.pop();
	} while (w.empty());
	ns[j] = '\0';

	cout << "\n" << s << "=" << ns;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	hesab(ns);
	_getch();
}



