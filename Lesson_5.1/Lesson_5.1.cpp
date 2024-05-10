#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <fstream>
#include <Windows.h>
#include "MyRectangle.h"
//#include "MySquare.h"
//#include "MyCube.h"
#include "MyTriangle.h"
#include "MyCircle.h"

using namespace std;

static int GetNumberFromInputString(string inputStr)
{
    try
    {
        smatch cm;
        if (!regex_match(inputStr, cm, regex(R"(^[1-9]\d*|0$)")))
            throw exception("Некорректный ввод. Входная строка не является последовательностью цифр или введёное число меньше нуля.");

        return stoi(cm.str());
    }
    catch (invalid_argument)
    {
        throw exception("Входная строка не является последовательностью цифр.");
    }
    catch (out_of_range)
    {
        throw exception("Число не помещается в int.");
    } 
}

static int GetNumberOfFigures()
{
    int numberOfFigures = 0;

    while (numberOfFigures == 0)
    {
        try
        {
            cout << "Задайте количество фигур: ";
            string str;
            cin >> str;

            numberOfFigures = GetNumberFromInputString(str);
            cout << "Количество фигур: " << numberOfFigures << endl;

            break;
        }
        catch (exception const& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
        }
    }

    return numberOfFigures;
}

static int GetRandomSize()
{
    int size = 0;

    do
    {
        size = rand() % (1000 - 1) + 1;
    } while (size <= 0);

    return size;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //int numberOfFigures = GetNumberOfFigures();
    int numberOfFigures = 5;

    Figure** figures = new Figure * [numberOfFigures];

    figures[0] = new MyRectangle("Прямоугольник №1" , 37, 27);
    //figures[1] = new MySquare("Квадрат №2", 15);
    //figures[2] = new MyCube("Куб №3", 6);
    //figures[3] = new MyTriangle("Треугольник №4", 20, 15, 8);
    //figures[4] = new MyCircle("Круг №4", 15);

    //int max = (int)TypeFigure::MaxValue;
    //int min = (int)TypeFigure::MinValue;

    /*for (int index = 0; index < numberOfFigures; index++)
    {
        int sizeSide, sizeSide1, sizeSide2;
        int randomTypeFigure = rand() % (max - min + 1) + min;

        bool isCorrectFigure = false;

        while (!isCorrectFigure)
        {
            try
            {
                switch (randomTypeFigure)
                {
                case (int)TypeFigure::Square:
                    sizeSide = GetRandomSize();
                    figures[index] = new MySquare("Квадрат №" + to_string(index + 1), sizeSide);
                    break;
                case (int)TypeFigure::Rectangle:
                    sizeSide = GetRandomSize();
                    sizeSide1 = GetRandomSize();
                    figures[index] = new MyRectangle("Прямоугольник №" + to_string(index + 1), sizeSide, sizeSide1);
                    break;
                case (int)TypeFigure::Triangle:
                    sizeSide = GetRandomSize();
                    sizeSide1 = GetRandomSize();
                    sizeSide2 = GetRandomSize();
                    figures[index] = new MyTriangle("Треугольник №" + to_string(index + 1), sizeSide, sizeSide1, sizeSide2);
                    break;
                case (int)TypeFigure::Circle:
                    sizeSide = GetRandomSize();
                    figures[index] = new MyCircle("Круг №" + to_string(index + 1), sizeSide);
                    break;
                case (int)TypeFigure::Cube:
                    sizeSide = GetRandomSize();
                    figures[index] = new MyCube("Куб №" + to_string(index + 1), sizeSide);
                    break;
                case (int)TypeFigure::Ball:
                    sizeSide = GetRandomSize();
                    figures[index] = new MyBall("Шар №" + to_string(index + 1), sizeSide);
                    break;
                default:
                    throw exception("Тип фигуры не найден");
                }

                isCorrectFigure = true;
            }
            catch (const exception& ex)
            {
                cout << "Ошибка: " << ex.what() << endl;
            }
        } 
    }*/

    string sResultFileName = "figures.txt";
    ofstream out(sResultFileName);

    out << "Фигуры :" << endl;
    for (int i = 0; i < numberOfFigures; i++) {
        out << figures[i]->GetInformationStringFigure() << endl;
    };
    out << endl << endl;
}