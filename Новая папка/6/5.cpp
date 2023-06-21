#include <io.h> 
#include <fcntl.h> 
#include <iostream>
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
		{ wcout << day << L"/" << month << L"/" << year; }
};

int main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);

	_setmode(_fileno(stdin), _O_U16TEXT);
	
	date d; 


	d.get();

	
	wcout << L"Вы ввели дату: "; d.display(); wcout << endl;

	return 0;
}
