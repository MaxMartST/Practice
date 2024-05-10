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
    return "��� ������: " + type
        + "\n��� ������: " + name
        + "\n�������: " + to_string(Space())
        + "\n��������: " + to_string(Perimeter());
}