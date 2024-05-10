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
    return "\tТип фигуры: " + type
        + "\n\tИмя фигуры: " + name
        + "\n\tПлощадь: " + to_string(Space())
        + "\n\tПериметр: " + to_string(Perimeter())
        + "\n";
}