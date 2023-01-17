#include <iostream>
using namespace std;

int hour, mins, secs;

unsigned long hms_to_secs(int, int, int);

int main()
{
 unsigned long seconds;
 char ch;
 do
 {
  cout << "Enter the hours" << endl; cin >> hour;
  cout << "Enter the minutes" << endl; cin >> mins;
  cout << "Enter the seconds" << endl; cin >> secs;
  seconds = hms_to_secs(hour, mins, secs);
  cout << "all seconds: " << seconds << endl;
  cout << "Repeat? (y/n) ";
  cin >> ch;
 }
 while (ch != 'n');

}
 
 unsigned long hms_to_secs(int h, int m, int s)
 {
  unsigned long seconds = h*60*60 + m*60 + s;
  return seconds;
 }