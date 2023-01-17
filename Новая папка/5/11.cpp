#include <iostream>
using namespace std;

struct sterling
{
 int pounds;
 int shilling;
 int pens;
};
sterling s1, s2, sum;
char dot;

sterling input (sterling);
sterling addition (sterling, sterling);
void output (sterling);

int main()
{
 s1 = input(s1);
 s2 = input(s2);
 sum = addition (s1, s2);
 output (sum);
 system ("pause");
}

sterling input (sterling str)
{
 cout << "Enter pounds" << endl;
 cin >> str.pounds >> dot >> str.shilling >> dot >> str.pens;
 return str;
}

sterling addition (sterling str1, sterling str2)
{
 sterling sum;
 int sumpens = (str1.pounds *20*12 + str1.shilling *12 + str1.pens) + (str2.pounds *20*12 + str2.shilling *12 + str2.pens);
 sum.pounds = sumpens/(20*12);
 sum.shilling = sumpens % (20*12)/12;
 sum.pens = sumpens%(20*12)%12;
 return sum;
}

void output (sterling sum)
{
 cout << "All J" << sum.pounds << dot << sum.shilling << dot << sum.pens << endl;
}