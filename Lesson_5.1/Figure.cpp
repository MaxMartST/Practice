#include "Figure.h"

double Figure::Space() const
{
    return 0;
};
double Figure::Perimeter() const
{
    return 0;
};

string Figure::GetInformationStringFigure() const
{
    return "\t��� ������: " + type
        + "\n\t��� ������: " + name
        + "\n\t�������: " + to_string(Space())
        + "\n\t��������: " + to_string(Perimeter())
        + "\n";
}