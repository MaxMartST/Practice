#pragma once
#include "MySquare.h"

class MyCube : public MySquare
{
public:
    MyCube(string nameFigure, double sizeSide);

    double Volume() const;

    double Perimeter() override;
    double Space() override;
    string GetInformationStringFigure() override;
};

