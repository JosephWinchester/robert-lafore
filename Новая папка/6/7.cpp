#include <iostream>   
using namespace std;
class Angle
{
 private:
  int degree;
  float min;
  char dir;
 public:
  Angle() : degree(0), min(0), dir(0)
  {}
  Angle(int deg, float m, char d) : degree(deg), min(m), dir(d)
  {}
  void get_dir()
  {
   cout << "Enter degree" << endl; cin >> degree;
   cout << "Enter minutes" << endl; cin >> min;
   cout << "Enter direction (N, S, E, W)" << endl; cin >> dir;
  }
  void show_dir()
  {
   cout << degree << '\xF8' << min << "'" << dir << endl;
  }

};
int main()
{
 Angle angl_1(179, 59.9, 'E');
 Angle angl_2;
 char ch;
 angl_1.show_dir();
 do
 {
  angl_2.get_dir();
  angl_2.show_dir();
  cout << "repeat? (y/n)" << endl;
  cin >> ch;
 }
 while (ch != 'n');
 return 0;
}
