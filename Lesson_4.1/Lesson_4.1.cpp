#include <iostream>
#include <string>
#include <regex>
#include <Windows.h>
#include <random>
#include "Figure.cpp"

using namespace std;

//static int GetNumberFromInputString(string inputStr)
//{
//    try
//    {
//        smatch cm;
//        if (!regex_match(inputStr, cm, regex(R"(^[1-9]\d*|0$)")))
//            throw exception("Некорректный ввод. Входная строка не является последовательностью цифр или введёное число меньше нуля.");
//
//        return stoi(cm.str());
//    }
//    catch (invalid_argument)
//    {
//        throw exception("Входная строка не является последовательностью цифр.");
//    }
//    catch (out_of_range)
//    {
//        throw exception("Число не помещается в int.");
//    } 
//}
//
//static int GetNumberOfFigures()
//{
//    int numberOfFigures = 0;
//
//    while (numberOfFigures == 0)
//    {
//        try
//        {
//            cout << "Задайте количество фигур: ";
//            string str;
//            cin >> str;
//
//            numberOfFigures = GetNumberFromInputString(str);
//            cout << "Количество фигур: " << numberOfFigures << endl;
//
//            break;
//        }
//        catch (exception const& ex)
//        {
//            cout << "Ошибка: " << ex.what() << endl;
//        }
//    }
//
//    return numberOfFigures;
//}
//
//static int GetRandomSize()
//{
//    int size = 0;
//
//    do
//    {
//        size = rand() % (1000 - 1) + 1;
//    } while (size <= 0);
//
//    return size;
//}
//
//static Figure GetFigure(int numberFigure, int numberTypeFigure)
//{
//    int sizeSide, sizeSide1, sizeSide2;
//
//    switch (numberTypeFigure)
//    {
//    case (int)TypeFigure::Square:
//        sizeSide = GetRandomSize();
//        return Square("Квадрат №: " + to_string(numberFigure), sizeSide);
//    //case (int)TypeFigure.Rectangle:
//    //    sizeSide = GetRandomSize();
//    //    sizeSide1 = GetRandomSize();
//    //    return new Rectangle($"Прямоугольник №{numberFigure}", sizeSide, sizeSide1);
//    //case (int)TypeFigure.Triangle:
//    //    sizeSide = GetRandomSize();
//    //    sizeSide1 = GetRandomSize();
//    //    sizeSide2 = GetRandomSize();
//    //    return new Triangle($"Треугольник №{numberFigure}", sizeSide, sizeSide1, sizeSide2);
//    //case (int)TypeFigure.Circle:
//    //    sizeSide = GetRandomSize();
//    //    return new Circle($"Круг №{numberFigure}", sizeSide);
//    //case (int)TypeFigure.Cube:
//    //    sizeSide = GetRandomSize();
//    //    return new Cube($"Куб №{numberFigure}", sizeSide);
//    //case (int)TypeFigure.Ball:
//    //    sizeSide = GetRandomSize();
//    //    return new Ball($"Шар №{numberFigure}", sizeSide);
//    default:
//        throw exception("Тип фигуры не найден");
//    }
//}
//
//static Figure* GetArrayFigure(int number)
//{
//    Figure* figures = new Figure[number];
//
//    int max = (int)TypeFigure::MaxValue;
//    int min = (int)TypeFigure::MinValue;
//
//    //for (int i = 0; i < number; i++)
//    //    figures[i] = GetFigure(i + 1, rand() % (max - min + 1) + min);
//
//    for (int i = 0; i < number; i++)
//        figures[i] = GetFigure(i + 1, 0);
//
//    return figures;
//}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        MyRectangle rectangle1("Прямоугольник_1", 37, 27);
        cout << rectangle1.GetInformationStringFigure() << endl;

        MySquare square2("Квадрат_ 2", 10);
        cout << square2.GetInformationStringFigure() << endl;

        MyCube cube3("Куб_3", 6);
        cout << cube3.GetInformationStringFigure() << endl;

        MyTriangle triangle4("Треугольник_4", 20, 15, 8);
        cout << triangle4.GetInformationStringFigure() << endl;

        MyCircle circle5("Круг_5", 15);
        cout << circle5.GetInformationStringFigure() << endl;

        MyBall ball6("Шар_6", 15);
        cout << ball6.GetInformationStringFigure() << endl;
    }
    catch (const exception& ex)
    {
        cout << "Ошибка: " << ex.what() << endl;
    }
}