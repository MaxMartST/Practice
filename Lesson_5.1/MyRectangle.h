#pragma once
#include "Figure.h"

class MyRectangle : public Figure
{
protected:
    double size1, size2;
public:
    MyRectangle(TypeFigure typeFigureg, string nameFigure, double size) : Figure(typeFigureg, nameFigure)
    {
        SetSize(size, size);
    }

    MyRectangle(string nameFigure, double size1, double size2) : Figure(TypeFigure::Rectangle, nameFigure)
    {
        SetSize(size1, size2);
    }
private:
    double Perimeter() const override;
    double Space()  const override;
    void SetSize(double size1, double size2);
};

