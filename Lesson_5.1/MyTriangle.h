#pragma once
#include "Figure.h"

class MyTriangle : public Figure
{
protected:
    double size1, size2, size3;

public:
    MyTriangle(string nameFigure, double size1, double size2, double size3);

    double Perimeter() override;
    double Space() override;

    friend std::istream& operator>>(std::istream&, MyTriangle&);
private:
    bool IsRightTriangle();
};

