#include <io.h> // _setmode
#include <fcntl.h> //  _O_U16TEXT
#include <iostream>
using namespace std;


struct Pair // пара чисел
{
	int x;
	int y;
};

class Stack                   
{
protected:                    
	// enum { MAX = 7 };      
	static const int MAX = 7; 
	                          
	int st[MAX];              
	int top;                  
public:
	Stack()                   
		{ top = -1; }
	void push(int var)       
		{ st[++top] = var; }
	int pop()                 
		{ return st[top--]; }
};

class Stack2 : public Stack   
{
public:
	void push(int var)        
	{
		if (top >= MAX - 1)  
			{ wcout << L"\nОшибка: стек полон!\n"; exit(1); }
		Stack::push(var);    
	}
	int pop()                 
	{
		if (top < 0)          
			{ wcout << L"\nОшибка: стек пуст!\n"; exit(1); }
		return Stack::pop();  
	}
};

// новый класс, реализующий стек, работающий с парой чисел (производный от Stack2)
class pairStack : public Stack2
{
public:
	void push(Pair unit) 
	{
		Stack2::push(unit.x); 
		Stack2::push(unit.y); 
	}
	Pair pop()          
	{
		Pair temp_unit;
		
		temp_unit.y = Stack2::pop(); 
		temp_unit.x = Stack2::pop(); 
		return temp_unit;
	}
};

int main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);

	Pair p1 = { 23, 56 },    
		 p2 = { 8, 0 },
		 p3 = { -34, 5 },
		 p4 = { 1003, -345 };

	pairStack s1;             

	s1.push(p1);            
	s1.push(p2);
	s1.push(p3);
   

	Pair p;
	p = s1.pop(); wcout << p.x << L", " << p.y << endl;
	p = s1.pop(); wcout << p.x << L", " << p.y << endl;
	p = s1.pop(); wcout << p.x << L", " << p.y << endl;


	return 0;
}
