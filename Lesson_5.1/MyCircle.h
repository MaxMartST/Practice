#pragma once
#include "Figure.h"

class MyCircle : public Figure
{
protected:
    double const PI = 3.14;
    double radiusSize;
public:
    MyCircle(TypeFigure typeFigure, string nameFigure, double radiusSize);
    MyCircle(string nameFigure, double radiusSize);

    double Perimeter() override;
    double Space() override;

    friend istream& operator>>(istream&, MyCircle&);
private:
    void SetSize(double radiusSize);
};

