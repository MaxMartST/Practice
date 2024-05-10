#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class MyFractional
{
private:
    int _numerator, _denominator;

    int GCD(int a, int b);
    int LCM(int a, int b);
    void Reduce();

public:
    MyFractional(int numerator, int denominator)
    {
        if (denominator == 0)
            throw exception("Знаменатель не может быть равен нулю");

        _numerator = numerator;
        _denominator = denominator;
    };

    string Show();

    int GetNumerator() const;
    int GetDenominator() const;

    MyFractional operator+=(const MyFractional& fractional);
    MyFractional operator-=(const MyFractional& fractional);
    MyFractional operator*=(const MyFractional& fractional);
    MyFractional operator/=(const MyFractional& fractional);
};

int MyFractional::GCD(int a, int b)
{
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int MyFractional::LCM(int a, int b)
{
    return GCD(a, b) * a * b;
}

void MyFractional::Reduce()
{
    int gcd = GCD(abs(_numerator), _denominator);

    if (gcd != 1) 
    {
        _numerator = _numerator / gcd;
        _denominator = _denominator / gcd;
    }
}

string MyFractional::Show()
{
    return to_string(_numerator) + "/" + to_string(_denominator);
}

int MyFractional::GetNumerator() const
{
    return _numerator;
}

int MyFractional::GetDenominator() const
{
    return _denominator;
}

MyFractional MyFractional::operator+=(const MyFractional& fractional)
{
    _numerator = _numerator * fractional.GetDenominator() + _denominator * fractional.GetNumerator();
    _denominator = _denominator * fractional.GetDenominator();

    return *this;
}

MyFractional MyFractional::operator-=(const MyFractional& fractional)
{
    _numerator = _numerator * fractional.GetDenominator() - _denominator * fractional.GetNumerator();
    _denominator = _denominator * fractional.GetDenominator();
    Reduce();

    return *this;
}

MyFractional MyFractional::operator*=(const MyFractional& fractional)
{
    _numerator = _numerator * fractional.GetNumerator();
    _denominator = _denominator * fractional.GetDenominator();
    Reduce();

    return *this;
}

MyFractional MyFractional::operator/=(const MyFractional& fractional)
{
    _numerator = _numerator * fractional.GetDenominator();
    _denominator = _denominator * fractional.GetNumerator();
    Reduce();

    return *this;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        MyFractional myFractional_1(2, 5);
        MyFractional myFractional_2(5, 3);

        myFractional_1 *= myFractional_2;
        cout << myFractional_1.Show() << endl;

        myFractional_1 /= myFractional_2;
        cout << myFractional_1.Show() << endl;

        myFractional_1 -= myFractional_2;
        cout << myFractional_1.Show() << endl;

        myFractional_1 += myFractional_2;
        cout << myFractional_1.Show() << endl;
    }
    catch (const exception err)
    {
        cout << "Ошибка: " << err.what() << endl;
    } 
}
