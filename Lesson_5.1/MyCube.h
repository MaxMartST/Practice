#pragma once
#include "MySquare.h"

class MyCube : public MySquare
{
public:
    MyCube(string nameFigure, double sizeSide) : MySquare(TypeFigure::Cube, nameFigure, sizeSide) {}

    double Volume() const;

    double Perimeter() const override;
    double Space() const override;
    string GetInformationStringFigure() const override;
};

