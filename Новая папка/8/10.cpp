#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
using namespace std;

class Cartesian;
class Polar;

class Polar
{
private:
  double corner;
  double radius;
public:
    Polar() : corner(0), radius (0)
    {}
    Polar (double cor, double rad) : corner(cor), radius(rad)
    {}
    Polar (const Cartesian& cartes);
    void get ()
    {
        cout << "Enter polar coordinate. Enter corner: " << endl;
        cin >> corner;
        if (corner < 0)
            if (corner > 360)
                exit(1);
        cout << "Enter radius: " << endl;
        cin >> radius;
    }
    void display() const
    {
        cout << "The result of adding: " << endl
            << "corner: " << corner << endl
            << "radius: " << radius << endl;
    }
    double get_corner () const
    {return corner; }
    double get_radius () const
    {return radius; }
};

class Cartesian
{
private:
    double X;
    double Y;
public:
    Cartesian() : X(0), Y(0)
    {}
    Cartesian (double x, double y) : X(x), Y(y)
    {}
    Cartesian (const Polar& pol);
    Cartesian operator + (Cartesian coord2)
    {
        double tempY = Y + coord2.Y;
        double tempX = X + coord2.X;
        return Cartesian( tempX, tempY);
    }
    double get_X () const
    { return X;}
    double get_Y () const
    {return Y;}
};

Cartesian::Cartesian(const Polar& pol)
{
    double cor = pol.get_corner();
    double rad = pol.get_radius();
    X = rad * cos(cor);
    Y = rad * sin(cor);
}

Polar::Polar(const Cartesian& cartes)
{
    double x = cartes.get_X();
    double y = cartes.get_Y();
    corner = tan(y/x);
    radius = hypot(x, y);
}

int main()
{
    Polar coordinate1, coordinate2, result_coordinate;
    Cartesian coord1, coord2, result_coord;
    coordinate1.get();
    coordinate2.get();
    coord1 = coordinate1;
    coord2 = coordinate2;
    result_coord = coord1 + coord2;
    result_coordinate = result_coord;
    result_coordinate.display();
 system ("pause");
    return 0;
}