#pragma once
#include <iostream>
#include <string>
#include "TypeFigure.h"

using namespace std;

class Figure
{
protected:
    string name, type;
public:
    Figure(TypeFigure typeFigure, string nameFigure);

    virtual double Perimeter() = 0;
    virtual double Space() = 0;
    virtual string GetInformationStringFigure();

    friend std::ostream& operator<<(std::ostream&, Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);
};