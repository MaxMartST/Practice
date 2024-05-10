#include "MyCube.h"
double MyCube::Volume() const
{
    return this->size1 * this->size1 * this->size1;
}
double MyCube::Perimeter() const
{
    return 12 * this->size1;
}

double MyCube::Space() const
{
    return 6 * pow(this->size1, 2);
}

string MyCube::GetInformationStringFigure() const
{
    return "\tТип фигуры: " + type
        + "\n\tИмя фигуры: " + name
        + "\n\tПлощадь: " + to_string(Space())
        + "\n\tПериметр: " + to_string(Perimeter())
        + "\n\tОбъём: " + to_string(Volume())
        + "\n";
}