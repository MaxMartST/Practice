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

    virtual double Perimeter() const;
    virtual double Space() const;
    virtual string GetInformationStringFigure() const;
};