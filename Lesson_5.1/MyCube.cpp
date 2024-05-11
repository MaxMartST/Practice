#include "MyCube.h"
MyCube::MyCube(string nameFigure, double sizeSide) : MySquare(TypeFigure::Cube, nameFigure, sizeSide) {}

double MyCube::Volume() const
{
    return this->size1 * this->size1 * this->size1;
}
double MyCube::Perimeter()
{
    return 12 * this->size1;
}

double MyCube::Space()
{
    return 6 * pow(this->size1, 2);
}

string MyCube::GetInformationStringFigure()
{
    return "\t��� ������: " + type
        + "\n\t��� ������: " + name
        + "\n\t�������: " + to_string(Space())
        + "\n\t��������: " + to_string(Perimeter())
        + "\n\t�����: " + to_string(Volume())
        + "\n";
}