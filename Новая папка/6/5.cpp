#include <iostream>   
using namespace std;
char ch = '/';
class Date
{
 private:
  int day, month, year;
 public:
  Date() : month(0), day(0), year(0)
  {}
  Date(int d, int m, int y) : month(m), day(d), year(y)
  {}
  void getdate()
  {
 cout << "enter day, month and year (XX/XX/XXXX) " << endl;
 cin >> day >> ch >> month >> ch >> year;
  }
  void showdate()const
  { cout << "You entered the date: " <<  day << ch << month << ch << year << endl; };
};
int main()
{
 Date date;
 date.getdate();
 date.showdate();
 system ("pause");
 return 0;
}
