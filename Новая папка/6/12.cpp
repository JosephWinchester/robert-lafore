#include <io.h> 
#include <fcntl.h> 
#include <iostream>
using namespace std;

class fraction 
{
private:
	int num; 
	int den; 
public:
	
	fraction()
		{ }
	
	fraction(int n, int d) : num(n), den(d)
		{ lowterms(); }
	
	void get()
	{
		wchar_t slash; 
		wcout << L"Введите обыкновенную дробь (в формате числитель/знаменатель): ";
		wcin >> num >> slash >> den;
		lowterms();
	}
	
	void display(int width = 5) const
	{
		int i = 1, tnum = num, tden = den;
		
			{ tnum = tnum / 10; i++; }
		while (tden)
			{ tden = tden / 10; i++; }
		wcout << num << L'/' << den; 
		
		for (int j = 1; j <= (width - i); j++)
			wcout << L' ';
	}
	
	void add(fraction f1, fraction f2)
	{
		num = f1.num * f2.den + f2.num * f1.den;
		den = f1.den * f2.den;
		lowterms();
	}

	void sub(fraction f1, fraction f2)
	{
		num = f1.num * f2.den - f2.num * f1.den;
		den = f1.den * f2.den;
		lowterms();
	}

	void mul(fraction f1, fraction f2)
	{
		num = f1.num * f2.num;
		den = f1.den * f2.den;
		lowterms();
	}

	void div(fraction f1, fraction f2)
	{
		num = f1.num * f2.den;
		den = f1.den * f2.num;
		lowterms();
	}

	void lowterms();
};

int main()
{
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	_setmode(_fileno(stdin), _O_U16TEXT);

	int den;
	wcout << L"Введите знаменатель обыкновенной дроби (положительный, больше 1): "; wcin >> den;
	wcout << endl;

	int width1 = 1; 
	int tnum = den - 1, tden = den;
	while (tnum) 
		{ tnum = tnum / 10; width1++; }
	while (tden) 
		{ tden = tden / 10; width1++; }

	
	int width2 = 1;
	tnum = den * den - 1, tden = den * den;
	while (tnum) 
		{ tnum = tnum / 10; width2++; }
	while (tden) 
		{ tden = tden / 10; width2++; }


	for (int i = 1; i <= width1; i++)
		wcout << L' ';
	wcout << L"  ";

	for (int num1 = 1; num1 < den; num1++)
	{
		fraction f1(num1, den);
		wcout << L' '; f1.display(width2);
	}
	wcout << endl;

	for (int i = 1; i <= (width1 + 2 + (width2 + 1) * (den - 1)); i++)
		wcout << L'-';
	wcout << endl;
	for (int num1 = 1; num1 < den; num1++)
	{
		fraction f1(num1, den);
		f1.display(width1); wcout << L" |"; 

		for (int num2 = 1; num2 < den; num2++)
		{
			fraction f2(num2, den), f;
			f.mul(f1, f2);
			wcout << L' '; f.display(width2); 
		}
		wcout << endl; 
	}

	return 0;
}

void fraction::lowterms()
{
	long tnum, tden, 
		 temp,       
		 gcd;        

	tnum = labs(num);
	tden = labs(den); 
	
	if (tden == 0)
		{ cout << "Недопустимый знаменатель!"; exit(1); }
	else if (tnum == 0) 
		{ num = 0; den = 1; return;	}


	while (tnum != 0)
	{

		if (tnum < tden)                               
			{ temp = tnum; tnum = tden; tden = temp; } 
		
		tnum = tnum - tden;
	}
	gcd = tden;

	num = num / gcd; 
	den = den / gcd; 
}