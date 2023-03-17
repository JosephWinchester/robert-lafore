#include <iostream>
using namespace std;

class Sterling
{
private:
 long pounds;
 int shilling;
 int pens;

public:
 Sterling () : pounds(0), shilling(0), pens(0)
 {}
 Sterling (double funt)
 {
  pounds = static_cast<long> (funt);
  long deschast = funt - pounds;
  shilling = static_cast <int> (deschast*20);
  pens = static_cast<int>((funt - pounds)*240-shilling*12);
 }
 Sterling (long po, int s, int pe) : pounds(po), shilling(s), pens(pe)
 {}
 void getSterling()
 {
  cout << "Enter pounds: "; cin >> pounds;
  cout << "Enter shillings: "; cin >> shilling;
  cout << "and pens: "; cin >> pens;
 }
 void putSterling() const
 {
  cout << "Result: J" << pounds << "." << shilling << "." << pens << endl;
 }
 Sterling operator + (Sterling str2)
 {
  int sumpens = (pounds *20*12 + shilling *12 + pens) + (str2.pounds *20*12 + str2.shilling *12 + str2.pens);
  long po = sumpens/(20*12);
  int s = sumpens % (20*12)/12;
  int pe = sumpens%(20*12)%12;
  return Sterling(po, s, pe);
 }
 Sterling operator - (Sterling str2)
 {
  int sumpens = (pounds *20*12 + shilling *12 + pens) - (str2.pounds *20*12 + str2.shilling *12 + str2.pens);
  long po = sumpens/(20*12);
  int s = sumpens % (20*12)/12;
  int pe = sumpens%(20*12)%12;
  return Sterling(po, s, pe);
 }
 Sterling operator * (double str2)
 {
  int sumpens = (pounds *20*12 + shilling *12 + pens) * (str2);
  long po = sumpens/(20*12);
  int s = sumpens % (20*12)/12;
  int pe = sumpens%(20*12)%12;
  return Sterling(po, s, pe);
 }
 Sterling operator / (Sterling str2)
 {
  int sumpens = (pounds *20*12 + shilling *12 + pens) / (str2.pounds *20*12 + str2.shilling *12 + str2.pens);
  long po = sumpens/(20*12);
  int s = sumpens % (20*12)/12;
  int pe = sumpens%(20*12)%12;
  return Sterling(po, s, pe);
 }
 Sterling operator / (double str2)
 {
  int sumpens = (pounds *20*12 + shilling *12 + pens) / (str2);
  long po = sumpens/(20*12);
  int s = sumpens % (20*12)/12;
  int pe = sumpens%(20*12)%12;
  return Sterling(po, s, pe);
 }
 operator double ()
 {
  float sum = pens + shilling*12 + (pounds*20) * 12;
  double des_funt = (sum/2.4)/100;
  return des_funt;
 }
};

int main()
{
 Sterling s1, s2, sum;
 double decimal;
 cout << "Enter decimal pounds" << endl;
 cin >> decimal;
 s1.getSterling();
 s2.getSterling();
 sum = s1+s2; sum.putSterling();
 sum = s1-s2; sum.putSterling();
 sum = s1*decimal; sum.putSterling();
 sum = s1/s2; sum.putSterling();
 sum = s1/decimal; sum.putSterling();
 decimal = sum; cout << decimal << endl;
 system ("pause");
};