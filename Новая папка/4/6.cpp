#include <iostream>
using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};


int main()
{
    char letter;
    etype post;
 setlocale (0, "");

    cout << "(laborer, secretary, manager, accountant, executive, researcher)"
    <<"\nВведите первую букву должности: ";
    cin>> letter;

    switch (letter)
    {
        case 'l':
            post = laborer;
            break;
        case 's':
            post = secretary;
            break;

        case 'm':
           post = manager;
            break;
        case 'a':
            post = accountant;
            break;

        case 'e':
           post = executive;
            break;

        case 'r':
            post = researcher;
            break;
    }

    switch(post)
    {
        case laborer:
           cout << "Полное название должности: laborer";
            break;

        case secretary:
            cout << "Полное название должности: secretary";
            break;
        case manager:
            cout << "Полное название должности: manager";
            break;
        case accountant:
            cout << "Полное название должности: accountant";
            break;
        case executive:
            cout << "Полное название должности: executive";
            break;
        case researcher:
            cout << "Полное название должности: researcher";
            break;
    }
 cout << endl;
  system ("pause");
    return 0;
}
