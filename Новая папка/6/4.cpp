#include <iostream>   
using namespace std;

class Employee
{
 private:
  int number;
  float salary;
 public:
  Employee() : number(0), salary(0)
  {}
  Employee(int num, float sal) : number(num), salary(sal)
  {}
  void get_empl()
  {
   cout << "number of the employee" << endl;
   cin >> number;
   cout << "salary" << endl;
   cin >> salary;
  }
  void display()const
  { cout << "employee " << number << ", salary " << salary << "$" << endl; };
};
int main()
{
 Employee empl_1, empl_2, empl_3;
 empl_1.get_empl();
 empl_2.get_empl();
 empl_3.get_empl();
 empl_1.display();
 empl_2.display();
 empl_3.display();
 system ("pause");
 return 0;
}