#include "Figure.h"

Figure::Figure(TypeFigure typeFigure, string nameFigure)
{
    name = nameFigure;

    switch (typeFigure)
    {
    case TypeFigure::Rectangle:
        type = "�������������";
        break;
    case TypeFigure::Square:
        type = "�������";
        break;
    case TypeFigure::Cube:
        type = "���";
        break;
    case TypeFigure::Triangle:
        type = "�����������";
        break;
    case TypeFigure::Circle:
        type = "����";
        break;
    case TypeFigure::Ball:
        type = "���";
        break;
    default:
        break;
    }
}

string Figure::GetInformationStringFigure()
{
    return "\t��� ������: " + type
        + "\n\t��� ������: " + name
        + "\n\t�������: " + to_string(Space())
        + "\n\t��������: " + to_string(Perimeter())
        + "\n";
}

ostream& operator<<(std::ostream& os, Figure& _figure) {
    return os << "������ � ������: \n" << _figure.GetInformationStringFigure() << std::endl;
};