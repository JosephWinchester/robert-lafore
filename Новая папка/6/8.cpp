#include <iostream>   
using namespace std;
class Amount
{
 private:
  int number;
  static int amount;
 public:
  Amount()
  {
   amount++;
   number = amount;
  }
  void disp_num()
  { cout << "My serial number " << number << endl; }
};
int Amount :: amount = 0;
int main()
{
 Amount obj1, obj2, obj3;
 obj1.disp_num();
 obj2.disp_num();
 obj3.disp_num();
 system ("pause");
 return 0;
}