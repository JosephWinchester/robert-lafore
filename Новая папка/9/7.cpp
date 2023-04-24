#include <io.h> //  _setmode
#include <fcntl.h> //  _O_U16TEXT
#include <iostream>
using namespace std;


class Counter
{
protected:                    
	unsigned int count;       
public:
	Counter() : count(0)      
		{ }
	Counter(int c) : count(c) 
		{ }
	unsigned int get_count() const 
		{ return count; }
	Counter operator++ ()     
		{ return Counter(++count); }
};


class CountDn : public Counter
{
public:
	CountDn() : Counter()       
		{ }
	CountDn(int c) : Counter(c) 
		{ }
	CountDn operator-- ()      
		{ return CountDn(--count); }
};

class Counter2 : public CountDn
{
public:
	Counter2() : CountDn()       
		{ }
	Counter2(int c) : CountDn(c) 
		{ }
	// конструктор с одним параметром (для преобразования из Counter в Counter2)
	Counter2(Counter ctr) : CountDn(ctr.get_count())
		{ }
	// конструктор с одним параметром (для преобразования из CountDn в Counter2)
	Counter2(CountDn cdn) : CountDn(cdn.get_count())
		{ }
	Counter2 operator++ (int)    
		{ return Counter2(count++); }
	Counter2 operator-- (int)    
		{ return Counter2(count--); }
	
	using CountDn::operator++;
	using CountDn::operator--;
};

int main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);

	Counter2 c1;                           
	Counter2 c2(100);                      
	wcout << L"c1 = " << c1.get_count();   
	wcout << L"\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;                     
	wcout << L"\nc1 = " << c1.get_count(); 
	
	--c2; --c2;                           
	wcout << L"\nc2 = " << c2.get_count(); 

	Counter2 c3 = ++c1;                   
	                                      
	wcout << L"\nc3 = " << c3.get_count(); 
	wcout << L", c1 = " << c1.get_count();

	Counter2 c4 = --c2;                    
	wcout << L"\nc4 = " << c4.get_count(); 
	wcout << L", c2 = " << c2.get_count();

	c1++;                                 
	wcout << L"\nc1 = " << c1.get_count(); 

	c2--;                                  
	wcout << L"\nc2 = " << c2.get_count(); 

	Counter2 c5 = c1++;                   
	wcout << L"\nc5 = " << c5.get_count(); 
	wcout << L", c1 = " << c1.get_count();

	Counter2 c6 = c2--;                    
	wcout << L"\nc6 = " << c6.get_count();
	wcout << L", c2 = " << c2.get_count();

	wcout << endl;

	return 0;
}
