#include <io.h> // _setmode
#include <fcntl.h> // for const _O_U16TEXT
#include <iostream>
#include <iomanip> // setw
using namespace std;

class employee 
{
private:
	int number;   
	float salary; 
public:
	// method for getting class data from the user from the keyboard
	void get()
		{ wcout << L"Number and salary of employees: "; wcin >> number >> salary; }
	// the constant method displays the values of the fields on the screen
	void display() const
		{ wcout << setw(5) << number << setw(9) << salary << endl; }
};

int main()
{
	// switching the standard output stream to Unicode format
	_setmode(_fileno(stdout), _O_U16TEXT);
	// switching the standard input stream to Unicode format
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	employee emp1, emp2, emp3; // object for class employee

	// we get information about three employees from the keyboard
	wcout << L"Enter the details of the three employees\n";
	emp1.get();
	emp2.get();
	emp3.get();

	// displaying information about each of the employees on the screen
	wcout << L"\nInformation about the company's employees:\n"
		  << setw(5) << L"Number" << setw(9) << L"Salary" << endl;
	emp1.display();
	emp2.display();
	emp3.display();

	return 0;
}
