#include "ChainLine.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
namespace Lab2
{
    Chain::Chain(double a, double x0):x(x0)
    {
        if(a == 0 || a < 0)
        {
            throw std::invalid_argument("invalid parameter");
        }
        A = a;
    }

    Chain& Chain::setA(double a)
    {
        if(a == 0 || a < 0)
        {
            throw std::invalid_argument("invalid parameter");
        }
        A = a;
        return *this;
    }

    Chain& Chain::setAX(double a, double x0)
    {
        if(a == 0 || a < 0)
        {
            throw std::invalid_argument("invalid parameter");
        }
        A = a;
        x = x0;
        return *this;
    }

    double Chain::Square(double x1, double x2) const
    {
        double res = A*A*(sinh(x2/A) - sinh(x1/A));
        if(res >=0)
        {
            return res;
        }
        else
        {
            return -res;
        }
    }

    double Chain::ArcLength() const
    {
        double res = A * sinh(x/A);
        if(res >= 0)
        {
            return res;
        }
        else
        {
            return -res;
        }
    }
}