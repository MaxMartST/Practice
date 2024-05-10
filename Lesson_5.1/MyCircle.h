#pragma once
#include "Figure.h"

class MyCircle : public Figure
{
protected:
    double const PI = 3.14;
    double radiusSize;
public:
    MyCircle(TypeFigure typeFigure, string nameFigure, double radiusSize) : Figure(typeFigure, nameFigure)
    {
        SetSize(radiusSize);
    }

    MyCircle(string nameFigure, double radiusSize) : Figure(TypeFigure::Circle, nameFigure)
    {
        SetSize(radiusSize);
    }

    double Perimeter() const override;
    double Space() const override;
private:
    void SetSize(double radiusSize);
};

