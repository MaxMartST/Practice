#pragma once
#include "Figure.h"

class MyTriangle : public Figure
{
protected:
    double size1, size2, size3;
private:
    bool IsRightTriangle() const;

    double Perimeter() const override;
    double Space() const override;

public:
    MyTriangle(string nameFigure, double size1, double size2, double size3) : Figure(TypeFigure::Triangle, nameFigure)
    {
        if (size1 <= 0 || size2 <= 0 || size3 <= 0)
            throw exception("������ ������� ������ ������ ���� ������ ����");

        if(!IsRightTriangle())
            throw exception("������ ����������� ������ ������� � ������");

        this->size1 = size1;
        this->size2 = size2;
        this->size3 = size3;
    }
};

