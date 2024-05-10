#include "MyCircle.h"

double MyCircle::Perimeter() const
{
    return 2 * PI * radiusSize;
}

double MyCircle::Space() const
{
    return PI * radiusSize * radiusSize;
}

void MyCircle::SetSize(double radiusSize)
{
    if (radiusSize <= 0)
        throw exception("Радиус круга не должен быть меньше или равно нулю");

    this->radiusSize = radiusSize;
}