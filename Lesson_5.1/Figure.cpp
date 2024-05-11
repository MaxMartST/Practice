#include "Figure.h"

Figure::Figure(TypeFigure typeFigure, string nameFigure)
{
    name = nameFigure;

    switch (typeFigure)
    {
    case TypeFigure::Rectangle:
        type = "Прямоугольник";
        break;
    case TypeFigure::Square:
        type = "Квадрат";
        break;
    case TypeFigure::Cube:
        type = "Куб";
        break;
    case TypeFigure::Triangle:
        type = "Треугольник";
        break;
    case TypeFigure::Circle:
        type = "Круг";
        break;
    case TypeFigure::Ball:
        type = "Шар";
        break;
    default:
        break;
    }
}

string Figure::GetInformationStringFigure()
{
    return "\tТип фигуры: " + type
        + "\n\tИмя фигуры: " + name
        + "\n\tПлощадь: " + to_string(Space())
        + "\n\tПериметр: " + to_string(Perimeter())
        + "\n";
}

ostream& operator<<(std::ostream& os, Figure& _figure) {
    return os << "Данные о фигуре: \n" << _figure.GetInformationStringFigure() << std::endl;
};