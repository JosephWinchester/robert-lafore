#include <io.h> //  _setmode
#include <fcntl.h> // _O_U16TEXT
#include <iostream>
using namespace std;

const int LEN = 80; 

class student 
{
private:
	wchar_t school[LEN]; 
	wchar_t degree[LEN]; 
public:
	void getedu()
	{
		wcout << L" Введите название учебного заведения: "; wcin >> school;
		wcout << L" Введите уровень полученного образования\n";
		wcout << L" (неполное_высшее, бакалавр, магистр, кандидат_наук): "; wcin >> degree;
	}
	void putedu() const
	{
		wcout << L"\n Учебное заведение: " << school;
		wcout << L"\n Уровень полученного образования: " << degree;
	}
};

class employee 
{
private:
	wchar_t name[LEN];    
	unsigned long number; 
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

class manager : private employee, private student // управленец
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
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Должность: " << title;
		wcout << L"\n Сумма взносов в гольф-клуб: " << dues;
		student::putedu();
	}
};


class executive : private manager
{
private:
	double yearly_bonus; 
	unsigned long shares;
public:
	void getdata()
	{
		manager::getdata();
		wcout << L" Введите размер годовой премии: "; wcin >> yearly_bonus;
		wcout << L" Введите количество акций: "; wcin >> shares;
	}
	void putdata() const
	{
		manager::putdata();
		wcout << L"\n Размер годовой премии: " << yearly_bonus;
		wcout << L"\n Количество акций: " << shares;
	}
};

class scientist : private employee, private student // ученый
{
private:
	int pubs; 
public:
	void getdata()
	{
		employee::getdata();
		wcout << L" Введите количество публикаций: "; wcin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		wcout << L"\n Количество публикаций: " << pubs;
		student::putedu();
	}
};

class laborer : public employee 
	{ };

int main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	executive e1;
	manager m1;
	scientist s1;
	laborer l1;

	wcout << L"Ввод информации об управленце высшего звена"; e1.getdata();
	wcout << L"\nВвод информации об управленце";             m1.getdata();
	wcout << L"\nВвод информации об ученом";                 s1.getdata();
	wcout << L"\nВвод информации о рабочем";                 l1.getdata();

	wcout << L"\nИнформация об управленце высшего звена"; e1.putdata();
	wcout << L"\nИнформация об управленце";               m1.putdata();
	wcout << L"\nИнформация об ученом";                   s1.putdata();
	wcout << L"\nИнформация о рабочем";                   l1.putdata();
	wcout << endl;

	return 0;
}
