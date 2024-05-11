#include "MyTriangle.h"

MyTriangle::MyTriangle(string nameFigure, double size1, double size2, double size3) : Figure(TypeFigure::Triangle, nameFigure)
{
    if (size1 <= 0 || size2 <= 0 || size3 <= 0)
        throw exception("–азмер стороны фигуры должен быть больше нул€");

    if (IsRightTriangle())
        throw exception("«аданы некорректно заданы стороны у фигуры");

    this->size1 = size1;
    this->size2 = size2;
    this->size3 = size3;
}

bool MyTriangle::IsRightTriangle()
{
    return ((size1 + size2 >= size3)
        && (size1 + size3 >= size2)
        && (size2 + size3 >= size1));
}

double MyTriangle::Perimeter()
{
    return size1 + size2 + size3;
}

double MyTriangle::Space()
{
    double perimeter = Perimeter() / 2.00;
    return sqrt(perimeter * (perimeter - size1) * (perimeter - size2) * (perimeter - size3));
}

istream& operator>>(istream& is, MyTriangle& _triangle) {
    cout << "¬ведите им€ фигуры и значение стороны1, стороны2, стороны3: ";
    return is >> _triangle.name >> _triangle.size1 >> _triangle.size2 >> _triangle.size3;
};