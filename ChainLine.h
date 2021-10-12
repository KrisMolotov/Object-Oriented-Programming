#ifndef UNTITLED1_CHAIN_LINE_H
#define UNTITLED1_CHAIN_LINE_H
#include <cmath>
#include <iostream>

namespace Lab2
{
    class Chain
    {
    private:
        double A; // параметр, характеризующий y-координату вершины цепной линии
        double x; // координата конца цепной линии по оси абсцисс
    public:
        explicit Chain(double X = 1):A(1) {x = X;} // пустой конструктор + инициализирующий конструктор 1
        Chain(double a, double x0); // инициализирующий конструктор 2
        // сеттеры
        Chain& setA(double a);
        Chain& setX(double x0) {x = x0; return *this;}
        Chain& setAX(double a, double x0);
        // геттеры
        [[nodiscard]] double getA() const{return A;}
        [[nodiscard]] double getX() const{return x;}
        // методы-операции
        [[nodiscard]] double ordinate() const{return (A * cosh(x/A));}
        [[nodiscard]] double ArcLength() const;
        [[nodiscard]] double RCurvature() const{return (A * pow(cosh(x/A), 2));}
        [[nodiscard]] double CoordinatesOfCenter() const{return (A * (cosh(x/A) - 1));}
        [[nodiscard]] double Square(double x1, double x2) const;
    };
}
#endif