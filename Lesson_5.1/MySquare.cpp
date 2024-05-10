#include "MySquare.h"

double MySquare::Perimeter() const
{
    return 2 * (this->size1 + this->size2);
}

double MySquare::Space() const
{
    return this->size1 * this->size2;
}

string MySquare::GetInformationStringFigure() const
{
    return "Тип фигуры: " + type
        + "\nИмя фигуры: " + name
        + "\nПлощадь: " + to_string(Space())
        + "\nПериметр: " + to_string(Perimeter());
}