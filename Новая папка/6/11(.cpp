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
		{ }
	void get()
	{
		wchar_t slash;
		wcout << L"Введите обыкновенную дробь (в формате числитель/знаменатель): ";
		wcin >> num >> slash >> den;
	}
	void display() const
	{
		wcout << L"Результат операции: " << num << L'/' << den << endl;
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

	fraction fr1, fr2, fr3; 
	wchar_t oper;           
	wchar_t ch;             
	
	do {
		fr1.get();
		wcout << L"Введите знак операции (+, -, *, /): "; wcin >> oper;
		fr2.get();

		switch (oper)
		{
		case '+':
			fr3.add(fr1, fr2); fr3.display(); break;
		case '-':
			fr3.sub(fr1, fr2); fr3.display(); break;
		case '*':
			fr3.mul(fr1, fr2); fr3.display(); break;
		case '/':
			fr3.div(fr1, fr2); fr3.display(); break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

		wcout << L"Выполнить еще одну операцию (д/н) ? "; wcin >> ch;
	} while (ch != L'н');

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