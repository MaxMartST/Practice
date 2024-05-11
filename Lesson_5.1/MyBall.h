#pragma once
#include "MyCircle.h"

class MyBall : public MyCircle
{
public:
    MyBall(string nameFigure, double radiusSize) : MyCircle(TypeFigure::Ball, nameFigure, radiusSize) {}

    string GetInformationStringFigure() override;
    double Space() override;

    double Volume();
};

