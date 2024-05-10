#include "MyTriangle.h"

bool MyTriangle::IsRightTriangle() const
{
    return ((size1 + size2 >= size3)
        && (size1 + size3 >= size2)
        && (size2 + size3 >= size1));
}

double MyTriangle::Perimeter() const
{
    return size1 + size2 + size3;
}

double MyTriangle::Space() const
{
    double perimeter = Perimeter() / 2.00;
    return sqrt(perimeter * (perimeter - size1) * (perimeter - size2) * (perimeter - size3));
}