#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <fstream>
#include <Windows.h>
#include "Figure.h"
#include "MyRectangle.h"
#include "MySquare.h"
#include "MyCube.h"
#include "MyTriangle.h"
#include "MyCircle.h"
#include "MyBall.h"

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

static int GetRandom(int start = 10, int end = 1000)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(start, end);

    return dist(gen);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numberOfFigures = GetNumberOfFigures();
    Figure** figures = new Figure * [numberOfFigures];

    int max = (int)TypeFigure::MaxValue;
    int min = (int)TypeFigure::MinValue;

    for (int index = 0; index < numberOfFigures; index++)
    {
        int randomTypeFigure = GetRandom(min, max);
        bool isCorrectFigure = false;

        while (!isCorrectFigure)
        {
            try
            {
                switch (randomTypeFigure)
                {
                case (int)TypeFigure::Square:
                    figures[index] = new MySquare("Квадрат №" + to_string(index + 1), GetRandom());
                    break;
                case (int)TypeFigure::Rectangle:
                    figures[index] = new MyRectangle("Прямоугольник №" + to_string(index + 1), GetRandom(), GetRandom());
                    break;
                case (int)TypeFigure::Triangle:
                    figures[index] = new MyTriangle("Треугольник №" + to_string(index + 1), GetRandom(), GetRandom(), GetRandom());
                    break;
                case (int)TypeFigure::Circle:
                    figures[index] = new MyCircle("Круг №" + to_string(index + 1), GetRandom());
                    break;
                case (int)TypeFigure::Cube:
                    figures[index] = new MyCube("Куб №" + to_string(index + 1), GetRandom());
                    break;
                case (int)TypeFigure::Ball:
                    figures[index] = new MyBall("Шар №" + to_string(index + 1), GetRandom());
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
    }

    string sResultFileName = "figures.txt";
    ofstream out(sResultFileName);
    double maxSpace = 0.00;
    int indexFigure = 0;

    out << "Фигуры :" << endl;
    for (int i = 0; i < numberOfFigures; i++) {
        out << figures[i]->GetInformationStringFigure() << endl;

        if (maxSpace < figures[i]->Space())
        {
            maxSpace = figures[i]->Space();
            indexFigure = i;
        }
    };
    
    out << "Фигура с максимальной площадью: \n" << figures[indexFigure]->GetInformationStringFigure() << endl;

    out.close();
}