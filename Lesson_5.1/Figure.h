#include <string>
#include "TypeFigure.h"
using namespace std;

class Figure
{
protected:
    string name, type;
public:
    Figure(TypeFigure typeFigure, string nameFigure)
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

    virtual double Perimeter() const;
    virtual double Space() const;
    virtual string GetInformationStringFigure() const;
};