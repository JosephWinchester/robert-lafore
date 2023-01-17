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
 Time t1, t2, tsum;
 char ch;
 cout << "Enter the 1-st time (hours. minutes. seconds)" << endl;
 cin >> t1.hours >> ch >> t1.minutes >> ch >>  t1.seconds;
 cout << "Enter the 2-nd time (hours. minutes. seconds)" << endl;
 cin >> t2.hours >> ch >> t2.minutes >> ch >>  t2.seconds;
 long totalsecs = ((t1.hours * 3600) + (t1.minutes * 60) + t1.seconds) + ((t2.hours * 3600) + (t2.minutes * 60) + t2.seconds);
 tsum.hours = totalsecs/(60*60);
 tsum.minutes = totalsecs % (60*60)/60;
 tsum.seconds = totalsecs % (60*60) % 60;
 cout << "Time: " << tsum.hours << ch << tsum.minutes << ch << tsum.seconds << endl;
 system ("pause");
 return 0;                                                    
}