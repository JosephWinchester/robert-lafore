#include <iostream>
using namespace std;

struct date
{
 int day, month, year;
};
enum etype
{
 laborer, secretary, manager, accountant, executive, researcher
};
struct employee
{
 char empl[15];
 double salary;
 etype post;
 date data;
};

int main()
{
 employee empl_1, empl_2, empl_3;
 char ch = '/', s;
 cout << "name of the employee 1, salary, date of employment (xx/xx/xxxx), post (1-st letter)" << endl;
 cin >> empl_1.empl >> empl_1.salary >> empl_1.data.day >> ch >> empl_1.data.month >> ch >> empl_1.data.year >> s;
  switch(s)
    {
  case 'l':{empl_1.post=laborer;break;}
  case 's':{empl_1.post=secretary;break;}
  case 'm':{empl_1.post=manager;break;}
  case 'a':{empl_1.post=accountant;break;}
  case 'e':{empl_1.post=executive;break;}
  case 'r':{empl_1.post=researcher;break;}
  default:cout << "Не корректный ввод";
    }
 cout << "name of the employee 2, salary, date of employment, post (1-st letter)" << endl;
 cin >> empl_2.empl >> empl_2.salary >> empl_2.data.day >> ch >> empl_2.data.month >> ch >> empl_2.data.year >> s;
  switch(s)
    {
  case 'l':{empl_2.post=laborer;break;}
  case 's':{empl_2.post=secretary;break;}
  case 'm':{empl_2.post=manager;break;}
  case 'a':{empl_2.post=accountant;break;}
  case 'e':{empl_2.post=executive;break;}
  case 'r':{empl_2.post=researcher;break;}
  default:cout << "Не корректный ввод";
    }
 cout << "name of the employee 3, salary, date of employment, post (1-st letter)" << endl;
 cin >> empl_3.empl >> empl_3.salary >> empl_3.data.day >> ch >> empl_3.data.month >> ch >> empl_3.data.year >> s;
  switch(s)
    {
  case 'l':{empl_3.post=laborer;break;}
  case 's':{empl_3.post=secretary;break;}
  case 'm':{empl_3.post=manager;break;}
  case 'a':{empl_3.post=accountant;break;}
  case 'e':{empl_3.post=executive;break;}
  case 'r':{empl_3.post=researcher;break;}
  default:cout << "Не корректный ввод";
    }

 cout << "1-st employee " <<  empl_1.empl << ", " << empl_1.salary << "$, " << empl_1.data.day << ch << empl_1.data.month << ch << empl_1.data.year << " date of employment, " << endl;
 cout << "post" << endl;
    switch(empl_1.post)
    {
  case laborer:{cout << "laborer\n";break;}
  case secretary:{cout << "secretary\n";break;}
  case manager:{cout << "manager\n";break;}
  case accountant:{cout << "accountant\n";break;}
  case executive:{cout << "executive\n";break;}
  case researcher:{cout << "researcher\n";break;}
    };
 cout << "2-nd employee " <<  empl_2.empl << ", " << empl_2.salary << "$, " << empl_2.data.day << ch << empl_2.data.month << ch << empl_2.data.year << " date of employment, " << endl;
 cout << "post" << endl;
    switch(empl_2.post)
    {
  case laborer:{cout << "laborer\n";break;}
  case secretary:{cout << "secretary\n";break;}
  case manager:{cout << "manager\n";break;}
  case accountant:{cout << "accountant\n";break;}
  case executive:{cout << "executive\n";break;}
  case researcher:{cout << "researcher\n";break;}
    };
 cout << "3-rd employee " <<  empl_3.empl << ", " << empl_3.salary << "$, " << empl_3.data.day << ch << empl_3.data.month << ch << empl_3.data.year << " date of employment, " << endl;
 cout << "post" << endl;
    switch(empl_3.post)
    {
  case laborer:{cout << "laborer\n";break;}
  case secretary:{cout << "secretary\n";break;}
  case manager:{cout << "manager\n";break;}
  case accountant:{cout << "accountant\n";break;}
  case executive:{cout << "executive\n";break;}
  case researcher:{cout << "researcher\n";break;}
    };
 system ("pause");
 return 0;
}