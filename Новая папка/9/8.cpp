#define _CRT_SECURE_NO_WARNINGS // function wcscpy
#include <io.h> // _setmode
#include <fcntl.h> // _O_U16TEXT
#include <iostream>
using namespace std;
// #include <string.h> 

class String 
{
protected:                    


	static const int SZ = 80; 
	wchar_t str[SZ];          
public:
	String() 
		{ str[0] = L'\0'; }
	String(const wchar_t s[]) 
	{
		wcscpy(str, s);

	}
	void display() const 
		{ wcout << str; }

	operator wchar_t* ()
		{ return str; }
};


class Pstring : public String
{
public:
	Pstring() : String() // конструктор без параметров
		{ }
	Pstring(const wchar_t s[]) : String(test(s)) // конструктор с одним параметром
		{ }
private:

	const wchar_t* test(const wchar_t s[])
	{	

		if (wcslen(s) >= SZ)
		{
			wchar_t ts[SZ];
			int i;                     
			for (i = 0; i < SZ - 1; i++) 
				ts[i] = s[i];          
			ts[i] = L'\0';              
									
			return ts;                   
		}
		else          
			return s;
	}
};

class Pstring2 : public Pstring
{
public:
	Pstring2() : Pstring() // конструктор без параметров
		{ }
	Pstring2(const wchar_t s[]) : Pstring(s) // конструктор с одним параметром
		{ }
	Pstring2& left(Pstring2 source_str, unsigned int n)
	{
		int i;
		for (i = 0; i < n; i++)
			str[i] = source_str[i];
		str[i] = L'\0';
		return *this; 
	}
	Pstring2& mid(Pstring2 source_str, unsigned int pos, unsigned int n)
	{
		int j = 0;
		for (int i = pos; i < pos + n; i++)
			str[j++] = source_str[i];
		str[j] = L'\0';
		return *this; // возвращаем ссылку на текущий объект
	}
	Pstring2& right(Pstring2 source_str, unsigned int n)
	{
		int j = 0;
		for (int i = wcslen(source_str) - n; i < wcslen(source_str); i++)
			str[j++] = source_str[i];
		str[j] = L'\0';
		return *this; 
	}
};

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	Pstring2 s1; 

	wchar_t xstr[] = L"Ура, товарищи! "; 

	s1 = xstr;

	s1.display(); 

	Pstring2 s2 = L"Мы победим!";

	wcout << static_cast<wchar_t*>(s2);
	wcout << endl;

	Pstring2 s3 = L"Эта строка имеет очень большую длину и мы можем быть уверены, что она не "
	               "уместится в отведенный буфер, что приведет к непредсказуемым последствиям.";
	
	s3.display();
	wcout << endl;

	wcout << L"s1 = "; s1.display(); wcout << endl;
	
	s2.left(s1, 3); // применение нового метода
	wcout << L"s2 = "; s2.display(); wcout << endl;

	Pstring2 s4;
	s4 = s2.left(s1, 3);
	wcout << L"s2 = "; s2.display(); wcout << L", s4 = "; s2.display(); wcout << endl;

	s4 = L"xxx";
	s2.left(s1, 3) = s4;
	wcout << L"s2 = "; s2.display(); wcout << endl;


	return 0;
}
