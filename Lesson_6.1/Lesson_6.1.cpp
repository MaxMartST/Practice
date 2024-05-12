#include <iostream>
#include <Windows.h>
#include "MyVector.h"
#include <string>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	MyVector<int> myVector1;

	if (myVector1.Empty())
	{
		cout << "Вектор пуст" << endl;
	};

	cout << "Добавть значения в вектор" << endl;
	myVector1.PushBack(1);
	myVector1.PushBack(2);
	myVector1.PushBack(3);
	myVector1.PushBack(4);

	if (!myVector1.Empty())
	{
		cout << "Вектор имеет размер: " + to_string(myVector1.Size()) << endl;
		cout << "Вектор содержит: ";
		for (int i = 0; i < myVector1.Size(); i++)
		{
			cout << myVector1[i] << " ";
		};

		cout << endl;
	};

	cout << "Подставим значение 0 в начало вектора" << endl;
	myVector1.Insert(0, myVector1.Begin(), 0);

	cout << "Вектор содержит: ";
	for (int i = 0; i < myVector1.Size(); i++)
	{
		cout << myVector1[i] << " ";
	};
	cout << endl;

	cout << "Удалить все значения с первой до последней позиции" << endl;
	myVector1.Erase(myVector1.Begin(), myVector1.Size() - 1);

	cout << "Вектор содержит: ";
	for (int i = 0; i < myVector1.Size(); i++)
	{
		cout << myVector1[i] << " ";
	};
	cout << endl;

	cout << "Очистить вектор" << endl;
	myVector1.Clear();

	cout << "Вектор имеет размер: " + to_string(myVector1.Size()) << endl;
}
