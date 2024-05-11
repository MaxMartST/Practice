#include "MyRectangle.h"

MyRectangle::MyRectangle(TypeFigure typeFigureg, string nameFigure, double size) : Figure(typeFigureg, nameFigure)
{
    SetSize(size, size);
}

MyRectangle::MyRectangle(string nameFigure, double size1, double size2) : Figure(TypeFigure::Rectangle, nameFigure)
{
    SetSize(size1, size2);
}

double MyRectangle::Perimeter()
{
    return 2 * (this->size1 + this->size2);
}

double MyRectangle::Space()
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

istream& operator>>(istream& is, MyRectangle& _rectangle) {
    cout << "¬ведите им€ фигуры и значение стороны1 и стороны2: ";
    return is >> _rectangle.name >> _rectangle.size1 >> _rectangle.size2;
};