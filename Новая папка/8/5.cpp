#include <iostream>   
using namespace std;

class Time
{
 private:
  unsigned int hour, minutes, seconds;
 public:
  Time() : hour(0), minutes(0), seconds(0)
  {}
  Time (unsigned int h, unsigned int m, unsigned int s) : hour(h), minutes (m), seconds(s)
  {}
  void display()const
  { cout << hour << ":" << minutes << ":" << seconds << endl; };
  Time operator + (Time t2)
  {
   long totalsecs = (hour * 3600) + (minutes * 60) + seconds + (t2.hour * 3600) + (t2.minutes * 60) + t2.seconds;
   int h = totalsecs/(60*60);
   int m = totalsecs % (60*60)/60;
   int s = totalsecs % (60*60) % 60;
   return Time (h, m, s);
  }
  Time operator ++ ()
  {
   return Time (++hour, ++minutes, ++seconds);
  }
  Time operator -- ()
  {
   return Time (--hour, --minutes, --seconds);
  }
  Time operator ++ (int)
  {
   return Time (hour++, minutes++, seconds++);
  }
  Time operator -- (int)
  {
   return Time (hour--, minutes--, seconds--);
  }
};
int main()
{
 Time time_1(3,5,2), time_2(2,5,3);
 Time time_sum, temp;
 time_sum = time_1 + time_2;
 time_1.display();
 time_2.display();
 time_sum.display();
 ++time_sum; time_sum.display();
 --time_sum; time_sum.display();
 temp = time_sum++; temp.display();
 temp = time_sum--; temp.display();
 system ("pause");
 return 0;
}
