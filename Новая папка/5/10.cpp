#include <iostream>         
using namespace std;

int times=1;
void call (int&);

int main()
{
 call (times);
 call (times);
 call (times);
 call (times);
 call (times);
 call (times);
 call (times);
 call (times);
 call (times);
 call (times);
 system ("pause");
 return 0;
}
void call (int& tms)
{
 cout << "I was called " << tms << " times" << endl;
 tms++;
}