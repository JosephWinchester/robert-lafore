#include <iostream>  
#include <cmath>
using namespace std;
class Fraction
{
 private:
  int numerator, denominator;
 public:
  Fraction():numerator(0), denominator(0)
  {}
  Fraction (int num, int denom) : numerator(num), denominator(denom)
  {}
  void get_fr()
  {
   char ch;
   cout << "enter fraction" << endl;
   cin >> numerator >> ch >> denominator;
   if (numerator == 0 && denominator ==0)
    {
     if (numerator == 1 && denominator ==1)
     {
      if (numerator == 0 && denominator ==1)
      {
       cout << "Error!" << endl;
       exit (1);
      }
     }
    }
  }
  Fraction operator + (Fraction f2)
  {
   int num = numerator * f2.denominator + denominator * f2.numerator;
   int denom = denominator * f2.denominator;
   return Fraction(num, denom);
  }
  Fraction operator - (Fraction f2)
  {
   int num = numerator * f2.denominator - denominator * f2.numerator;
   int denom = denominator * f2.denominator; 
   return Fraction(num, denom);
  }
  Fraction operator * (Fraction f2)
  {
   int num = numerator * f2.denominator;
   int denom = denominator * f2.denominator;
   return Fraction(num, denom);
  }
  Fraction operator / (Fraction f2)
  {
   int num = numerator * f2.denominator;
   int denom = denominator * f2.numerator;
   return Fraction(num, denom);
  }
  void lowterms ()
  {
   long tnum, tden, temp, gcd;
   tnum = labs(numerator);            // используем неотрицательные
   tden = labs(denominator);            // значения (нужен cmath)
   if( tden == 0 )              // проверка знаменателя на 0
     { cout << "Недопустимый знаменатель!"; exit(1); }
   else if( tnum == 0 )         // проверка числителя на 0
     { numerator=0; denominator = 1; return; }
   while(tnum !=0)
   {
     if( tnum < tden )          // если числитель больше знаменателя,
       { temp=tnum; tnum=tden; tden=temp; } //меняем их местами
     tnum = tnum - tden;        // вычитание
   }
   gcd = tden;                  // делим числитель и знаменатель на
   numerator = numerator / gcd;             // полученный наибольший общий делитель
   denominator = denominator / gcd;
  }
  void disp_fr()const
  { cout << numerator << "/" << denominator << endl; }
};
int main()
{
 char zn;
 do
 {
  Fraction fr1, fr2, fr_sum;
  fr1.get_fr();
  cout << "Enter sign" << endl; cin >> zn;
  fr2.get_fr();
  
  switch (zn)
  {
   case '+': fr_sum = fr1 + fr2; break;
   case '-': fr_sum = fr1 - fr2; break;
   case '*': fr_sum = fr1 * fr2; break;
   case '/': fr_sum = fr1 / fr2; break;
  }
  fr_sum.lowterms();
  fr_sum.disp_fr();
  cout << "repeat? (y/n)" << endl; cin >> zn;
 }
 while (zn != 'n');
 return 0;
}