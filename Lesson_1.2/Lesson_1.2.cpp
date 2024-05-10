#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int divisor, bound, result;

    cout << "Введите делитель: ";
    cin >> divisor;

    cout << "Введите границу: ";
    cin >> bound;
    result = bound;

    for (int n = bound; n > 0; n--)
    {
        if ((n % divisor) == 0)
        {
            result = n;
            break;
        }
    }

    cout << "Результат: " << result;
}