#include <iostream>
using namespace std;

struct Time
{
 int hours;
 int minutes;
 int seconds;
};
Time t1, t2, tsum;

long time_to_secs (Time);

Time secs_to_time (long);

int main()
{
 long totalsecs;
 char ch;
 cout << "Enter the 1-st time (hours. minutes. seconds)" << endl;
 cin >> t1.hours >> ch >> t1.minutes >> ch >>  t1.seconds;
 cout << "Enter the 2-nd time (hours. minutes. seconds)" << endl;
 cin >> t2.hours >> ch >> t2.minutes >> ch >>  t2.seconds;
 totalsecs = time_to_secs(t1) + time_to_secs(t2);
 tsum = secs_to_time(totalsecs);
 cout << "Time: " << tsum.hours << ch << tsum.minutes << ch << tsum.seconds << endl;
 system ("pause");
 return 0;                                                  
}

long time_to_secs (Time time)
{
 long totalsecs = ((time.hours * 3600) + (time.minutes * 60) + time.seconds);
 return totalsecs;
}

Time secs_to_time (long totalsecs)
{
 tsum.hours = totalsecs/(60*60);
 tsum.minutes = totalsecs % (60*60)/60;
 tsum.seconds = totalsecs % (60*60) % 60;
 return tsum;
}
