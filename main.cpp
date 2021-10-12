#include <iostream>
#include "../lib/src/ChainLine.h"
using std::cin;
using std::cout;
using std::endl;

using namespace Lab2;

int main()
{
    Chain c(2, 3);
    int fl1 = 1;
    double A_new, X_new;
    while(fl1)
    {
        cout << "Parameter A is: " << c.getA() << endl;
        cout << "Coordinate X is: " << c.getX() << endl;
        cout << "Ordinate: " << c.ordinate() << endl;
        cout << "Arc length: " << c.ArcLength() << endl;
        cout << "Radius curvature: " << c.RCurvature() << endl;
        cout << "Coordinates of the center of curvature: x = 0, y = " << c.CoordinatesOfCenter() << endl;
        int fl2 = 1;
        while(fl2)
        {
            cout << "Enter x1 and x2 coordinates for calculate square or press shift+z t0 quit:" << endl;
            double x1, x2, S;
            cin >> x1 >> x2;
            fl2 = cin.good();
            if(!fl2)
            {
                continue;
            }
            S = c.Square(x1, x2);
            cout << "Square is: " << S << endl;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter new A and x to continue or press shift+z to quit:" << endl;
        cin >> A_new >> X_new;
        if(cin.good())
        {
            try
            {
                c.setAX(A_new, X_new);
            }
            catch(std::exception &ex)
            {
                cout << ex.what() << endl;
            }
        }
        else
        {
            fl1 = 0;
        }
    }
    return 0;
}
