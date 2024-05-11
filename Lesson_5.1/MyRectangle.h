#pragma once
#include "Figure.h"

class MyRectangle : public Figure
{
protected:
    double size1, size2;
public:
    MyRectangle(TypeFigure typeFigureg, string nameFigure, double size);
    MyRectangle(string nameFigure, double size1, double size2);

    friend istream& operator>>(std::istream&, MyRectangle&);
private:
    double Perimeter();
    double Space();
    void SetSize(double size1, double size2);
};

