#include <iostream>
#include <iomanip>
using namespace std;
struct fraction
 {
 int numerator;
 int denominator;
};
int main()
{
 fraction f1, f2, sumf;
 char ch = '/', zn;
 do
 {
  cout << "enter 1-st fraction" << endl;
  cin >> f1.numerator >> ch >> f1.denominator;
  cout << "Enter symbol" << endl;
  cin >> zn;
  cout << "enter 2-nd fraction" << endl;
  cin >> f2.numerator >> ch >> f2.denominator;
  switch (zn)
  {
   case '+': sumf.numerator =f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    sumf.denominator = f1.denominator * f2.denominator; break;
   case '-':  sumf.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
    sumf.denominator = f1.denominator * f2.denominator; break;
   case '*': sumf.numerator = f1.numerator * f2.denominator;
    sumf.denominator = f1.denominator * f2.denominator; break;
   case '/': sumf.numerator = f1.numerator * f2.denominator;
    sumf.denominator = f1.denominator * f2.numerator; break;
  }
  cout << sumf.numerator << ch << sumf.denominator << endl;
  cout << "esche raz? (y,n)" << endl;
  cin >> ch;
 }
 while (ch != 'n');
 return 0;                                                    
}