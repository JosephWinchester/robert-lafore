#include <iostream>         
using namespace std;

double power(double n, int p=2);
double power(char n, int p=2);
double power(int n, int p=2);
double power(long n, int p=2);
double power(float n, int p=2);
 double n;
 int p;
int main()
{ 
 cout << "result double: " << power (3.563678456434, 5) << endl;
 cout << "result char: " << power ('r', 5) << endl;
 cout << "result int: " << power (3, 5) << endl;
 cout << "result long: " << power (3L, 5) << endl;
 cout << "result float: " << power (3.3F, 5) << endl;
 system ("pause");
 return 0;
}
double power(double n, int p)
{
 double res = n;
 for (int j=1; j <= p; j++)
 res *= n;
 return res;
}
double power(char n, int p)
{
 char res = n;
 for (int j=1; j <= p; j++)
 res *= n;
 return res;
}
double power(int n, int p)
{
 int res = n;
 for (int j=1; j <= p; j++)
 res *= n;
 return res;
}
double power(long n, int p)
{
 long res = n;
 for (int j=1; j <= p; j++)
 res *= n;

 return res;
}
double power(float n, int p)
{
 float res = n;
 for (int j=1; j <= p; j++)
 res *= n;
 return res;
}