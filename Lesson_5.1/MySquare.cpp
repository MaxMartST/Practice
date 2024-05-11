#include "MySquare.h"

MySquare::MySquare(TypeFigure typeFigure, string nameFigure, double sizeSide) : MyRectangle(typeFigure, nameFigure, sizeSide) {}
MySquare::MySquare(string nameFigure, double sizeSide) : MyRectangle(TypeFigure::Square, nameFigure, sizeSide) {}

double MySquare::Perimeter()
{
    return 2 * (this->size1 + this->size2);
}

double MySquare::Space()
{
    return this->size1 * this->size2;
}

istream& operator>>(istream& is, MySquare& _square) {
	cout << "¬ведите им€ фигуры и значение стороны:";
	return is >> _square.name >> _square.size1;
};