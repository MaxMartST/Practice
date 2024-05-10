#include "MyBall.h"

string MyBall::GetInformationStringFigure() const
{
    return "��� ������: " + type
        + "\n��� ������: " + name
        + "\n�������: " + to_string(Space())
        + "\n�����: " + to_string(Volume());
}

double MyBall::Volume() const
{
    return 4.00 / 3.00 * PI * radiusSize * radiusSize * radiusSize;
}

double MyBall::Space() const
{
    return 4 * PI * radiusSize * radiusSize;
}