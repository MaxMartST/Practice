#include "MyCircle.h"

MyCircle::MyCircle(TypeFigure typeFigure, string nameFigure, double radiusSize) : Figure(typeFigure, nameFigure)
{
    SetSize(radiusSize);
}

MyCircle::MyCircle(string nameFigure, double radiusSize) : Figure(TypeFigure::Circle, nameFigure)
{
    SetSize(radiusSize);
}

double MyCircle::Perimeter()
{
    return 2 * PI * radiusSize;
}

double MyCircle::Space()
{
    return PI * radiusSize * radiusSize;
}

void MyCircle::SetSize(double radiusSize)
{
    if (radiusSize <= 0)
        throw exception("������ ����� �� ������ ���� ������ ��� ����� ����");

    this->radiusSize = radiusSize;
}

istream& operator>>(istream& is, MyCircle& _circle) {
    cout << "������� ��� ������ � �������� �������: ";
    return is >> _circle.name >> _circle.radiusSize;
};