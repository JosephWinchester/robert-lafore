#include <io.h> 
#include <fcntl.h> 
#include <iostream>
using namespace std;

struct fraction 
{
	int num; 
	int den; 
};

fraction fadd(fraction, fraction); 
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);
void outFraction(fraction);

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	fraction fr1, fr2; 
	wchar_t slash;     
	wchar_t oper;      
	wchar_t ch;        
	do {
		wcout << L"Введите первую дробь, знак операции и вторую дробь: ";
		wcin >> fr1.num >> slash >> fr1.den >> oper >> fr2.num >> slash >> fr2.den;

		switch (oper)
		{
		case '+':
			outFraction(fadd(fr1, fr2)); break;
		case '-':
			outFraction(fsub(fr1, fr2)); break;
		case '*':
			outFraction(fmul(fr1, fr2)); break;
		case '/':
			outFraction(fdiv(fr1, fr2)); break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

		wcout << L"Выполнить еще одну операцию (д/н) ? "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}


fraction fadd(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.den + f1.den * f2.num;
	f.den = f1.den * f2.den;
	return f;
}

fraction fsub(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.den - f1.den * f2.num;
	f.den = f1.den * f2.den;
	return f;
}

fraction fmul(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.num;
	f.den = f1.den * f2.den;
	return f;
}

fraction fdiv(fraction f1, fraction f2)
{
	fraction f;
	f.num = f1.num * f2.den;
	f.den = f1.den * f2.num;
	return f;
}

void outFraction(fraction f)
{
	wcout << L"Результат операции: " << f.num << L"/" << f.den << endl;
}