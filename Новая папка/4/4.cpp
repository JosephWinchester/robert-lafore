#include <iostream>
using namespace std;

struct employee
{
 char empl[15];
 double salary;
};
int main()
{
 employee empl_1, empl_2, empl_3;
 cout << "name of the employee 1" << endl;
 cin >> empl_1.empl;
 cout << "salary of the enployee 1" << endl;
 cin >> empl_1.salary;
 cout << "name of the employee 2" << endl;
 cin >> empl_2.empl;
 cout << "salary of the enployee 2" << endl;
 cin >> empl_2.salary;
 cout << "name of the employee 3" << endl;
 cin >> empl_3.empl;
 cout << "salary of the enployee 3" << endl;
 cin >> empl_3.salary;
 cout << "1-st employee " <<  empl_1.empl << ", " << empl_1.salary << "$" << endl
  << "2-nd employee " <<  empl_2.empl << ", " << empl_2.salary << "$" << endl
  << "3-rd employee " <<  empl_3.empl << ", " << empl_3.salary << "$" << endl;
 system ("pause");
 return 0;
}