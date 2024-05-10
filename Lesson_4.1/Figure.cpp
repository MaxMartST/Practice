#include <string>
using namespace std;

enum class TypeFigure
{
    Square,
    Rectangle,
    Triangle,
    Circle,
    Cube,
    Ball,
    MinValue = Square,
    MaxValue = Ball
};

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
};

class MyRectangle : public Figure
{
protected:
    double size1, size2;
public:
    MyRectangle(TypeFigure typeFigureg, string nameFigure, double size) : Figure(typeFigureg, nameFigure)
    {
        SetSize(size, size);
    }

    MyRectangle(string nameFigure, double size1, double size2) : Figure(TypeFigure::Rectangle, nameFigure)
    {
        SetSize(size1, size2);
    }

    string GetInformationStringFigure()
    {

        return "Тип фигуры: " + type
            + "\nИмя фигуры: " + name
            + "\nПлощадь: " + to_string(Space())
            + "\nПериметр: " + to_string(Perimeter());
    }

    double Perimeter() const
    {
        return 2 * (this->size1 + this->size2);
    }

    double Space() const
    {
        return this->size1 * this->size2;
    }
private:
    void SetSize(double size1, double size2)
    {
        if (size1 <= 0 || size2 <= 0)
            throw exception("Размер стороны фигуры должен быть больше нуля");

        this->size1 = size1;
        this->size2 = size2;
    }
};

class MySquare : public MyRectangle
{
public:
    MySquare(TypeFigure typeFigure, string nameFigure, double sizeSide) : MyRectangle(typeFigure, nameFigure, sizeSide) {}
    MySquare(string nameFigure, double sizeSide) : MyRectangle(TypeFigure::Square, nameFigure, sizeSide){}

    double Perimeter() const
    {
        return this->size1 * 4;
    }

    double Space() const
    {
        return pow(this->size1, 2);
    }
};

class MyCube : public MySquare
{
public:
    MyCube(string nameFigure, double sizeSide) : MySquare(TypeFigure::Cube, nameFigure, sizeSide){}

    string GetInformationStringFigure()
    {
        return "Тип фигуры: " + type
            + "\nИмя фигуры: " + name
            + "\nПериметр: " + to_string(Perimeter())
            + "\nПлощадь: " + to_string(Space())
            + "\nОбъём: " + to_string(Volume());
    }

    double Volume() const
    {
        return this->size1 * this->size1 * this->size1;
    }
    double Perimeter() const
    {
        return 12 * this->size1;
    }

    double Space() const
    {
        return 6 * pow(this->size1, 2);
    }
};

class MyTriangle : public Figure
{
private:
    double size1, size2, size3;

    bool IsRightTriangle()
    {
        bool result = ((size1 + size2 >= size3) 
            && (size1 + size3 >= size2) 
            && (size2 + size3 >= size1));

        if(!result)
            throw exception("Заданы некорректно заданы стороны у фигуры");
        
        return result;
    }

public:
    MyTriangle(string nameFigure, double size1, double size2, double size3) : Figure(TypeFigure::Triangle, nameFigure)
    {
        if (size1 <= 0 || size2 <= 0 || size3 <= 0)
            throw exception("Размер стороны фигуры должен быть больше нуля");

        this->size1 = size1;
        this->size2 = size2;
        this->size3 = size3;
    }

    string GetInformationStringFigure()
    {

        return "Тип фигуры: " + type
            + "\nИмя фигуры: " + name
            + "\nПлощадь: " + to_string(Space())
            + "\nПериметр: " + to_string(Perimeter());
    }

    double Perimeter() const
    {
        return size1 + size2 + size3;
    }

    double Space() const
    {
        double perimeter = Perimeter() / 2.00;
        return sqrt(perimeter * (perimeter - size1) * (perimeter - size2) * (perimeter - size3));
    }
};

class MyCircle : public Figure
{
protected:
    double const PI = 3.14;
    double radiusSize;
public:
    MyCircle(TypeFigure typeFigure, string nameFigure, double radiusSize) : Figure(typeFigure, nameFigure)
    {
        SetSize(radiusSize);
    }

    MyCircle(string nameFigure, double radiusSize) : Figure(TypeFigure::Circle, nameFigure)
    {
        SetSize(radiusSize);
    }

    string GetInformationStringFigure()
    {
        return "Тип фигуры: " + type
            + "\nИмя фигуры: " + name
            + "\nПлощадь: " + to_string(Space())
            + "\nПериметр: " + to_string(Perimeter());
    }

    double Perimeter() const
    {
        return 2 * PI * radiusSize;
    }

    double Space() const
    {
        return PI * radiusSize * radiusSize;
    }
private:
    void SetSize(double radiusSize)
    {
        if (radiusSize <= 0)
            throw exception("Радиус круга не должен быть меньше или равно нулю");

        this->radiusSize = radiusSize;
    }
};

class MyBall : public MyCircle
{
public:
    MyBall(string nameFigure, double radiusSize) : MyCircle(TypeFigure::Ball, nameFigure, radiusSize) {}

    string GetInformationStringFigure()
    {
        return "Тип фигуры: " + type
            + "\nИмя фигуры: " + name
            + "\nПлощадь: " + to_string(Space())
            + "\nОбъём: " + to_string(Volume());
    }

    double Volume() const
    {
        return 4.00 / 3.00 * PI * radiusSize * radiusSize * radiusSize;  
    }

    double Space() const
    {
        return 4 * PI * radiusSize * radiusSize;
    }
};