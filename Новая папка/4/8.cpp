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
 fraction f1, f2;
 char charvar = '/';
 cout << "enter 1-st fraction" << endl;
 cin >> f1.numerator >> charvar >> f1.denominator;
 cout << "enter 2-nd fraction" << endl;
 cin >> f2.numerator >> charvar >> f2.denominator;
 cout << (f1.numerator * f2.denominator) + (f1.denominator * f2.numerator) << charvar << f1.denominator * f2.denominator << endl;
    system ("pause");
 return 0;                                                    
}