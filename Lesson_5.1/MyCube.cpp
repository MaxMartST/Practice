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
    return "\t��� ������: " + type
        + "\n\t��� ������: " + name
        + "\n\t�������: " + to_string(Space())
        + "\n\t��������: " + to_string(Perimeter())
        + "\n\t�����: " + to_string(Volume())
        + "\n";
}