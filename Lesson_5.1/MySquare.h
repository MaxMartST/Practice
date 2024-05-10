#pragma once
#include "MyRectangle.h"

class MySquare : public MyRectangle
{
public:
    MySquare(TypeFigure typeFigure, string nameFigure, double sizeSide) : MyRectangle(typeFigure, nameFigure, sizeSide) {}
    MySquare(string nameFigure, double sizeSide) : MyRectangle(TypeFigure::Square, nameFigure, sizeSide) {}
    double Perimeter() const override;
    double Space() const override;
    string GetInformationStringFigure() const override;
};