#include <io.h> 
#include <fcntl.h> 
#include <iostream>
using namespace std;

struct sterling 
{
	int pounds;    
	int shillings;
	int pences;    
};

sterling getSterling();                        
sterling sumSterling(sterling s1, sterling s2);
void outSterling(sterling s);

int main()
{
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	_setmode(_fileno(stdin), _O_U16TEXT);

	sterling ster, ster1, ster2; 

	
	wcout << L"1. "; ster1 = getSterling();
	wcout << L"2. "; ster2 = getSterling();

	ster = sumSterling(ster1, ster2);

	wcout << L"Сумма этих денежных сумм: ";
	outSterling(ster);
	wcout << endl;

	return 0;
}


sterling getSterling()
{
	sterling res;
	wcout << L"Введите сумму (фунты, шиллинги и пенсы через пробел): ";
	wcin >> res.pounds >> res.shillings >> res.pences;
	return res;
}


sterling sumSterling(sterling s1, sterling s2)
{
	sterling sum;
	long p;
	p = s1.pounds * 240 + s1.shillings * 12 + s1.pences +
		s2.pounds * 240 + s2.shillings * 12 + s2.pences;
	sum.pounds = p / 240;
	sum.shillings = (p % 240) / 12;
	sum.pences = (p % 240) % 12;
	return sum;
}


void outSterling(sterling s)
{
	wcout << s.pounds << L" фунтов, " << s.shillings << L" шиллингов, " << s.pences << L" пенсов";
}