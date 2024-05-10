#pragma once
#include "MyCircle.h"

class MyBall : public MyCircle
{
public:
    MyBall(string nameFigure, double radiusSize) : MyCircle(TypeFigure::Ball, nameFigure, radiusSize) {}

    string GetInformationStringFigure() const override;
    double Space() const override;

    double Volume() const;
};

