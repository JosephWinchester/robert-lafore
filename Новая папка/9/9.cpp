#include <io.h> //  _setmode
#include <fcntl.h> //  _O_U16TEXT
#include <iostream>
#include <string> //for working string wstring
using namespace std;

class date 
{
private:
	int day;   
	int month; 
	int year;  
public:
	
	void get()
	{
		wchar_t slash; 
		wcout << L"Введите день, месяц и год через косую черту (/): ";
		wcin >> day >> slash >> month >> slash >> year;
	}
	
	void display() const
	{
		wcout << day << L"/" << month << L"/" << year;
	}
};


class publication
{
private:
	wstring title; 
	float price;   
public:
	void getdata()
	{
		
		wcout << L"\n введите название издания: "; getline(ws(wcin), title);
		wcout << L" введите цену экземпляра издания: "; wcin >> price;
	}
	void putdata() const
	{
		wcout << L"\n название издания: " << title;
		wcout << L"\n цена экземпляра издания: " << price << endl;
	}
};


class publication2 : public publication
{
private:
	date pub_date; 
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите дату публикации издания:\n  "; pub_date.get();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" дата публикации издания: "; pub_date.display(); wcout << endl;
	}
};


class book : public publication2
{
private:
	int pages; 
public:
	void getdata()
	{
		publication2::getdata();
		wcout << L" введите количество страниц в книге: "; wcin >> pages;
	}
	void putdata() const
	{
		publication2::putdata();
		wcout << L" количество страниц в книге: " << pages << endl;
	}
};


class tape : public publication2
{
private:
	float playing_time; // время проигрывания аудиокниги в минутах
public:
	void getdata()
	{
		publication2::getdata();
		wcout << L" введите время проигрывания аудиокниги в минутах: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication2::putdata();
		wcout << L" время проигрывания аудиокниги в минутах: " << playing_time << endl;
	}
};

int main()
{
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	_setmode(_fileno(stdin), _O_U16TEXT);

	book b1; // бумажная книга
	tape t1; // аудиокнига

	
	wcout << L"Ввод данных опубликованной бумажной книги"; b1.getdata();
	wcout << L"\nВвод данных опубликованной аудиокниги"; t1.getdata();

	
	wcout << L"\nДанные опубликованной бумажной книги"; b1.putdata();
	wcout << L"\nДанные опубликованной аудиокниги"; t1.putdata();

	return 0;
}
