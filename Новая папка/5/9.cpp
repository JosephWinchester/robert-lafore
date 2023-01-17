#include <iostream>         
using namespace std;

struct Time
{
 int hours;
 int minutes;
 int seconds;
};
Time t1, t2;
void swap(Time&, Time&);

int main()
{
 char ch;
 cout << "Enter the 1-st time (hours. minutes. seconds)" << endl;
 cin >> t1.hours >> ch >> t1.minutes >> ch >>  t1.seconds;
 cout << "Enter the 2-nd time (hours. minutes. seconds)" << endl;
 cin >> t2.hours >> ch >> t2.minutes >> ch >>  t2.seconds;
 swap(t1, t2);
 cout << t1.hours << ch << t1.minutes << ch << t1.seconds << endl;
 cout << t2.hours << ch << t2.minutes << ch << t2.seconds << endl;
 system ("pause");
 return 0;                                                  
}
void swap(Time& num1, Time& num2)
{
 Time temp = num1;
 num1 = num2;
 num2 = temp;
}