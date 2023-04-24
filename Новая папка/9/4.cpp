#include <io.h> //  _setmode
#include <fcntl.h> //  _O_U16TEXT
#include <iostream>
#include <string> // for wstring
using namespace std;


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


class sales
{
private:
	float sales_sum[3]; 
	
public:
	void getdata()
	{
		wcout << L" введите выручку от продаж за 3 месяца (через пробел): ";
		wcin >> sales_sum[0] >> sales_sum[1] >> sales_sum[2];
	}
	void putdata() const
	{
		wcout << L" выручка от продаж за последние 3 месяца: "
			<< sales_sum[0] << L" " << sales_sum[1] << L" " << sales_sum[2] << endl;
	}
};


class book : public publication, public sales
{
private:
	int pages; 
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите количество страниц в книге: "; wcin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" количество страниц в книге: " << pages << endl;
		sales::putdata();
	}
};


class tape : public publication, public sales
{
private:
	float playing_time; 
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите время проигрывания аудиокниги в минутах: "; wcin >> playing_time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" время проигрывания аудиокниги в минутах: " << playing_time << endl;
		sales::putdata();
	}
};


class disk : public publication, public sales
{
private:
	enum disk_type_enum {CD, DVD};
	disk_type_enum disk_type;     
	void getdata()
	{
		publication::getdata();
		wchar_t ch;
		wcout << L" введите тип оптического диска (русская буква 'к' для CD, 'д' для DVD): "; wcin >> ch;
		switch (ch)
		{
		case L'к': disk_type = CD; break;
		case L'д': disk_type = DVD; break;
		default: disk_type = CD;
		}
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" тип оптического диска: " << ((disk_type == CD) ? L"CD" : L"DVD") << endl;
		sales::putdata();
	}
};

int main()
{
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	_setmode(_fileno(stdin), _O_U16TEXT);

	
	book b1; // бумажная книга
	tape t1; // аудиокнига
	disk d1; // оптический диск

	
	wcout << L"Ввод данных опубликованной бумажной книги"; b1.getdata();
	wcout << L"\nВвод данных опубликованной аудиокниги"; t1.getdata();
	wcout << L"\nВвод данных книги, опубликованной на оптическом диске"; d1.getdata();

	
	wcout << L"\nДанные опубликованной бумажной книги"; b1.putdata();
	wcout << L"\nДанные опубликованной аудиокниги"; t1.putdata();
	wcout << L"\nДанные книги, опубликованной на оптическом диске"; d1.putdata();

	return 0;
}