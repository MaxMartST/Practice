#include "MyBall.h"

string MyBall::GetInformationStringFigure() const
{
    return "Тип фигуры: " + type
        + "\nИмя фигуры: " + name
        + "\nПлощадь: " + to_string(Space())
        + "\nОбъём: " + to_string(Volume());
}

double MyBall::Volume() const
{
    return 4.00 / 3.00 * PI * radiusSize * radiusSize * radiusSize;
}

double MyBall::Space() const
{
    return 4 * PI * radiusSize * radiusSize;
}