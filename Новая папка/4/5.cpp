#include <iostream>
using namespace std;

struct date
{
 int day, month, year;
};
int main()
{
 date date_1;
 char ch = '/';
 cout << "enter day, month and year (XX/XX/XXXX) " << endl;
 cin >> date_1.day >> ch >> date_1.month >> ch >> date_1.year;
 
 cout << "You entered the date: " <<  date_1.day << ch << date_1.month << ch << date_1.year << endl;
 system ("pause");
 return 0;
}
