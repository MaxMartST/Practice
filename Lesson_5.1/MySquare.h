#pragma once
#include "MyRectangle.h"

class MySquare : public MyRectangle
{
public:
    MySquare(TypeFigure typeFigure, string nameFigure, double sizeSide);
    MySquare(string nameFigure, double sizeSide);

    double Perimeter() override;
    double Space() override;

    friend istream& operator>>(std::istream&, MySquare&);
};