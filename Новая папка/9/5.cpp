#include <io.h> 
#include <fcntl.h> 
#include <iostream>
using namespace std;

const int LEN = 80;

class employee 
{
private:
	wchar_t name[LEN];   
	unsigned long number; 
public:
	void getdata()
	{
		wcout << L"\n Введите фамилию: "; wcin >> name;
		wcout << L" Введите номер: "; wcin >> number;
	}
	void putdata() const
	{
		wcout << L"\n Фамилия: " << name;
		wcout << L"\n Номер: " << number;
	}
};

class compensation 
{
private:
	enum period_type {почасовая, еженедельная, ежемесячная};
	period_type period;  
	double compensation; 
public:
	void getdata()
	{
		wcout << L" Введите период выплат ('ч' почасовая, 'н' еженедельная, 'м' ежемесячная): ";
		wchar_t ch; wcin >> ch;
		switch (ch)
		{
		case L'ч': period = почасовая; break;
		case L'н': period = еженедельная; break;
		case L'м': period = ежемесячная; break;
		default: period = почасовая;
		}
		wcout << L" Введите сумму вознаграждения: "; wcin >> compensation;
	}
	void putdata() const
	{
		wcout << L"\n Период выплат: ";
		switch (period)
		{
		case почасовая: wcout << L"почасовая"; break;
		case еженедельная: wcout << L"еженедельная"; break;
		case ежемесячная: wcout << L"ежемесячная"; break;
		}
		wcout << L"\n Сумма вознаграждения: " << compensation;
	}
};

class manager : public employee 
{
private:
	wchar_t title[LEN]; 
	double dues;        
public:
	void getdata()
	{
		employee::getdata();
		wcout << L" Введите должность: "; wcin >> title;
		wcout << L" Введите сумму взносов в гольф-клуб: "; wcin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Должность: " << title;
		wcout << L"\n Сумма взносов в гольф-клуб: " << dues;
	}
};

class manager2 : public manager, public compensation // управленец2 (новый класс)
{
public:
	void getdata()
	{
		manager::getdata();
		compensation::getdata();
	}
	void putdata() const
	{
		manager::putdata();
		compensation::putdata();
	}
};

class scientist : public employee 
{
private:
	int pubs; 
public:
	void getdata()
	{
		employee::getdata();
		wcout << L" Введите количество публикаций: "; wcin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Количество публикаций: " << pubs;
	}
};

class scientist2 : public scientist, public compensation 
{
public:
	void getdata()
	{
		scientist::getdata();
		compensation::getdata();
	}
	void putdata() const
	{
		scientist::putdata();
		compensation::putdata();
	}
};

class laborer : public employee 
	{ };

class laborer2 : public laborer, public compensation 
{
public:
	void getdata()
	{
		laborer::getdata();
		compensation::getdata();
	}
	void putdata() const
	{
		laborer::putdata();
		compensation::putdata();
	}
};

int main()
{
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	_setmode(_fileno(stdin), _O_U16TEXT);

	manager2 m1, m2;
	scientist2 s1;
	laborer2 l1;

	
	wcout << L"Ввод информации о первом управленце";   m1.getdata();
	wcout << L"\nВвод информации о втором управленце"; m2.getdata();
	wcout << L"\nВвод информации о первом ученом";     s1.getdata();
	wcout << L"\nВвод информации о первом рабочем";    l1.getdata();

	
	wcout << L"\nИнформация о первом управленце"; m1.putdata();
	wcout << L"\nИнформация о втором управленце"; m2.putdata();
	wcout << L"\nИнформация о первом ученом";     s1.putdata();
	wcout << L"\nИнформация о первом рабочем";    l1.putdata();
	wcout << endl;

	return 0;
}