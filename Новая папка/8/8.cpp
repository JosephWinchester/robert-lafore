include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class bMoney
{
private:
    string strMon;
    long double number;
 
public:
 bMoney() : number(0)
 {}
 bMoney(long double num)
 {
  number = num;
 }
 operator long double () const
 {
  long double num = number;
  return num;
 }
    void mstold()
    {
        cout << "Enter the amount in decimal point. End with a dollar sign" << endl;
        getline(cin, strMon, '$');

        int wlen = strMon.length();
        int n=0;
        string num;

        for (int j = 0; j < wlen; j++)
   if (strMon[j] != ',' && strMon[j] != '$')
                num.push_back(strMon[j]); ;
        number = stold(num);  
 }
 bMoney operator + ( bMoney mon2)
 {
  return number + mon2.number;
 }
 bMoney operator - ( bMoney mon2)
 {
  return number - mon2.number;
 }
 bMoney operator * ( long double mon2)
 {
  return number * mon2;
 }
 bMoney operator / ( bMoney mon2)
 {
  return number / mon2.number;
 }
 bMoney operator / ( long double mon2)
 {
  return number / mon2;
 }
    void display()const
    {
        cout << setiosflags (ios::fixed)
   << setiosflags (ios::showpoint)
   <<setprecision(2)
   << "\n" << number << '$' << endl;
    }
};

int main()
{
    bMoney money1, money2, moneysum;
 long double num = 0;
 do
 {
  money1.mstold();
  money2.mstold();
  moneysum = money1 + money2; moneysum.display();
  moneysum = money1 - money2; moneysum.display();
  num = money2;
  moneysum = money1 * num; moneysum.display();
  moneysum = money1 / money2; moneysum.display();
  moneysum = money1 / num; moneysum.display();
  cout << "\nrepeat?" << endl;
  cin.get();
 }
 while (cin.get() !='n');
    system ("pause");
    return 0;
}