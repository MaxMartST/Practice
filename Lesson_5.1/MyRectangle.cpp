#include "MyRectangle.h"

double MyRectangle::Perimeter() const
{
    return 2 * (this->size1 + this->size2);
}

double MyRectangle::Space() const
{
    return this->size1 * this->size2;
}

void MyRectangle::SetSize(double size1, double size2)
{
    if (size1 <= 0 || size2 <= 0)
        throw exception("–азмер стороны фигуры должен быть больше нул€");

    this->size1 = size1;
    this->size2 = size2;
}