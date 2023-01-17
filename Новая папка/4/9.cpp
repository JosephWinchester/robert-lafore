#include <iostream>
using namespace std;
struct Time
{
 int hours;
 int minutes;
 int seconds;
};
int main()
{
 Time t1;
 cout << "Enter the time through the gap (hours, minutes, seconds)" << endl;
 cin >> t1.hours >> t1.minutes >> t1.seconds;
 long totalsecs = (t1.hours * 3600) + (t1.minutes * 60) + t1.seconds;
 cout << "number of seconds: " << totalsecs << endl;
 system ("pause");
 return 0;                                                    
}