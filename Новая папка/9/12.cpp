#include <io.h> //  _setmode
#include <fcntl.h> //  _O_U16TEXT
#include <iostream>
#include <iomanip> // for maniplation setprecision
using namespace std;

class fraction
{
protected:   
	int num; 
	int den; 
public:
	
	fraction()
		{ }

	fraction(int n, int d) : num(n), den(d)
		{ }
	
	void get()
	{
		wchar_t slash; // для косой черты
		wcin >> num >> slash >> den;
	}
	
	void display() const
	{
		wcout << num << L'/' << den;
	}

	fraction operator+ (fraction f) const
	{
		
		return fraction(num * f.den + f.num * den,
			den * f.den).lowterms();
	}
	
	fraction operator- (fraction f) const
	{
		return fraction(num * f.den - f.num * den,
			den * f.den).lowterms();
	}

	fraction operator* (fraction f) const
	{
		return fraction(num * f.num,
			den * f.den).lowterms();
	}

	fraction operator/ (fraction f) const
	{
		return fraction(num * f.den,
			den * f.num).lowterms();
	}

	bool operator== (fraction f) const
	{
		if ((num == f.num) && (den == f.den))
			return true;
		else
			return false;
	}

	bool operator!= (fraction f) const
	{
		if ((num == f.num) && (den == f.den))
			return false;
		else
			return true;
	}
	
	fraction lowterms();
};

class fraction8 : public fraction
{
public:
	fraction8() : fraction()
		{ }
	fraction8(int n) : fraction(n, 8)
		{ lowterms(); }
	operator double() const
		{ return static_cast<double>(num) / den; }
};

class sterling 
{
protected:         
	long pounds;   
	int shillings; 
	int pences;    
public:

	sterling() : pounds(0), shillings(0), pences(0)
		{ }

	sterling(double df)
	{
		
		pounds = df;
		shillings = (df - pounds) * 20;
		pences = round(((df - pounds) * 20 - shillings) * 12);
	}
	sterling(long ps, int s, int p) : pounds(ps), shillings(s), pences(p)
		{ }
	void getSterling()
	{
		wchar_t separator; 
		wcout << L"Введите сумму (фунты, шиллинги и пенсы через точку): £";
		wcin >> pounds >> separator >> shillings >> separator >> pences;
	}
	void putSterling() const
	{
		wcout << L"£" << pounds << L"." << shillings << L"." << pences;
	}
	operator double() const
	{
		return (pounds + shillings / 20.0 + pences / 240.0);
	}
	sterling operator+ (sterling s) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) + double(s));
	}
	sterling operator- (sterling s) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) - double(s));
	}
	sterling operator* (double n) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) * n);
	}
	double operator/ (sterling s) const
	{
		return (double(sterling(pounds, shillings, pences)) / double(s));
	}
	sterling operator/ (double n) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) / n);
	}
};

class sterfrac : public sterling
{
private:
	fraction8 eighths; 
public:
	sterfrac() : sterling(), eighths(0)
		{ }
	sterfrac(double df)
	{
		pounds     = df;
		shillings = (df - pounds) * 20;
		pences   = ((df - pounds) * 20 - shillings) * 12;
		eighths = static_cast<int>(round((((df - pounds) * 20 - shillings) * 12 - pences) * 8));
	}
	sterfrac(long ps, int s, int p, fraction8 e) : sterling(ps, s, p), eighths(e)
		{ }
	void getSterling()
	{
		wchar_t separator;
		wcout << L"Введите сумму в формате '£9.19.11-1/4': £";
		wcin >> pounds >> separator >> shillings >> separator >> pences;
		wcin >> separator;
		eighths.get();
	}
	void putSterling() const
	{
		sterling::putSterling(); wcout << L"-"; eighths.display();
	}
	operator double() const
	{
		return (sterling::operator double() + eighths / 240.0);
	}
	sterfrac operator+ (sterfrac s) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) + double(s));
	}
	sterfrac operator- (sterfrac s) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) - double(s));
	}
	sterfrac operator* (double n) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) * n);
	}
	double operator/ (sterfrac s) const
	{
		return (double(sterfrac(pounds, shillings, pences, eighths)) / double(s));
	}
	sterfrac operator/ (double n) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) / n);
	}
};

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	sterfrac s1, s2, s; 
	double n;           
	wcout << L"1. "; s1.getSterling();
	wcout << L"2. "; s2.getSterling(); wcout << endl;

	wcout << L"1. В десятичных фунтах: " << fixed << setprecision(2) << double(s1) << endl;
	wcout << L"2. В десятичных фунтах: " << fixed << setprecision(2) << double(s2) << endl << endl;

	s = s1 + s2;
	wcout << L"Результат сложения этих сумм: "; s.putSterling(); wcout << endl;

	s = s1 - s2;
	wcout << L"Разность этих сумм: "; s.putSterling(); wcout << endl;

	s = s1 * 1.05;
	wcout << L"Произведение первой суммы и числа 1,05: "; s.putSterling(); wcout << endl;

	n = s1 / s2;
	wcout << L"Частное от деления первой суммы на вторую: " << n << endl;
	s = s1 / 3.5;
	wcout << L"Частное от деления первой суммы на число 3,5: "; s.putSterling(); wcout << endl;

	return 0;
}
fraction fraction::lowterms()
{
	long tnum, tden, 
		temp,       
		gcd;        

	tnum = labs(num); 
	tden = labs(den); 

	if (tden == 0) 
		{ wcout << L"Недопустимый знаменатель!"; exit(1); }
	else if (tnum == 0) 
		{ num = 0; den = 1; return fraction(num, den); }

	while (tnum != 0)
	{
		if (tnum < tden)                            
			{ temp = tnum; tnum = tden; tden = temp; }

		tnum = tnum - tden;
	}
	gcd = tden;

	num = num / gcd;
	den = den / gcd;
	return fraction(num, den);
}
