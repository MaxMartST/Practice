#include <iostream>
#include <Windows.h>
using namespace std;

int Pyramid(int bols);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int number = 0;

    cout << "Введите количество шаров: ";
    cin >> number;

    cout << "Пирамида из " << number << " шаров, состоит из количества уровней равного: " << Pyramid(number);
}

int Pyramid(int bols)
{
    if (bols <= 0)
        return 0;

    int level = 0;

    while (bols > level)
    {
        level++;
        bols -= level;
    }

    return level;
}