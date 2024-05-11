#include "MyBall.h"

string MyBall::GetInformationStringFigure()
{
    return "\tТип фигуры: " + type
        + "\n\tИмя фигуры: " + name
        + "\n\tПлощадь: " + to_string(Space())
        + "\n\tПериметр: " + to_string(Perimeter())
        + "\n";
}

double MyBall::Volume()
{
    return 4.00 / 3.00 * PI * radiusSize * radiusSize * radiusSize;
}

double MyBall::Space()
{
    return 4 * PI * radiusSize * radiusSize;
}