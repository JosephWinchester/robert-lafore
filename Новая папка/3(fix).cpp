#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
 int funt, funt1, shill, shill1, pens, pens1, funt2, shill2, pens2;
 char ch;
 do {
  cout << "Введите первую сумму: " << endl;
  cin >> funt1 >> ch >> shill1 >> ch >> pens1;
  cout << "Введите вторую сумму: "<< endl;
  cin >> funt2 >> ch >> shill2 >> ch >> pens2;
  funt = funt1 + funt2;
  shill = shill1 + shill2;
  if (shill > 18)
  {
   funt++;
   shill = shill - 20;
  }
  pens = pens1+pens2;
  if (pens > 11)
  {
   shill++;
   pens = pens - 12;
  }
  cout << "Всего: " << funt << ch << shill << ch << pens << endl;
  cout << "Продолжить? (y/n)" << endl;
  cin >> ch;
 }
 while (ch != 'n');
 return 0;                                                     
}