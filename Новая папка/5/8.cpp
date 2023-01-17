#include <iostream>         
using namespace std;

void swap(int&, int&);

int main()
{
 int n1, n2;
 cout << "Enter 1-st number" << endl;
 cin >> n1;
 cout << "Enter 2-st number" << endl;
 cin >> n2;
 swap(n1, n2);
 cout << n1 << ' ' << n2 << endl;
 system ("pause");
 return 0;
}
void swap(int& num1, int& num2)
{
 int temp = num1;
 num1 = num2;
 num2 = temp;
}