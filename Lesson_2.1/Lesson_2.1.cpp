#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class MyFractional
{
private:
    int _numerator, _denominator;

public:
    MyFractional(int a, int b)
    {
        if (b == 0)
            throw exception("Знаменатель не может быть равен нулю");

        _numerator = a;
        _denominator = b;
    };

    int GetNumerator()
    {
        return _numerator;
    };

    void SetNumerator(int a)
    {
        _numerator = a;
    };

    int GetDenominator()
    {
        return _denominator;
    };

    void SetDenominator(int b)
    {
        _denominator = b;
    };

    void Add(MyFractional d)
    {
        _numerator = (_numerator * d.GetDenominator()) + (d.GetNumerator() * _denominator);
        _denominator = _denominator * d.GetDenominator();
    };

    void Remove(MyFractional d)
    {
        _numerator = (_numerator * d.GetDenominator()) - (d.GetNumerator() * _denominator);
        _denominator = _denominator * d.GetDenominator();
    };

    void Multiply(MyFractional d)
    {
        _numerator *= d.GetNumerator();
        _denominator *= d.GetDenominator();
    };

    void Divide(MyFractional d)
    {
        _numerator *= d.GetDenominator();
        _denominator *= d.GetNumerator();
    };

    string Eqels(MyFractional d)
    {
        return (_numerator * d.GetDenominator()) == (d.GetNumerator() * _denominator) ? "true" : "false";
    };

    string Show()
    {
        return to_string(_numerator) + "/" + to_string(_denominator);
    };

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numerator, denominator;
    cout << "Введите делитель: ";
    cin >> numerator;

    cout << "Введите знаменатель: ";
    cin >> denominator;

    MyFractional* d;

    try
    {
        d = new MyFractional(numerator, denominator);

        d->Add(MyFractional(5, 7));
        cout << "Сложение: " << d->Show() << endl;

        d->Remove(MyFractional(5, 7));
        cout << "Вычитание: " << d->Show() << endl;

        d->Multiply(MyFractional(5, 7));
        cout << "Умножение: " << d->Show() << endl;

        d->Divide(MyFractional(5, 7));
        cout << "Деление: " << d->Show() << endl;

        cout << "Равен (1715/8575): " << d->Eqels(MyFractional(1715, 8575)) << endl;

        cout << "Равен (3430/17150): " << d->Eqels(MyFractional(3430, 17150)) << endl;

        cout << "Равен (1/2): " << d->Eqels(MyFractional(1, 2)) << endl;
    }
    catch (const exception err)
    {
        cout << "Ошибка: " << err.what() << endl;
    }
}
