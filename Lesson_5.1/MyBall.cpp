#include "MyBall.h"

string MyBall::GetInformationStringFigure()
{
    return "\t��� ������: " + type
        + "\n\t��� ������: " + name
        + "\n\t�������: " + to_string(Space())
        + "\n\t��������: " + to_string(Perimeter())
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