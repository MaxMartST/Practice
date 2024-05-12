#pragma once
#include <iostream>
using namespace std;

template<typename T> class MyVector
{
private:
	T* arr;
	int capacity, size;
public:
	MyVector()
	{
		arr = new T[1];
		capacity = 1;
		size = 0;
	};
	T& Front()
	{
		return arr[0];
	};
	T& Back()
	{
		return arr[size - 1];
	};
	T& End()
	{
		return arr[size];
	};
	auto Begin()
	{
		return arr[0];
	};
	bool Empty()
	{
		return (size == 0);
	};
	void ShrinkToFit()
	{
		capacity = size;
		return;
	};
	void PushBack(T val)
	{
		if (size == capacity)
		{
			T* temp = new T[2 * capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[size] = val;
		size++;
	};
	void PopBack()
	{
		if (size == 0) {
			cout << "Вектор пуст" << endl;
			return;
		}
		size--;
		T* temp = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		ShrinkToFit();
	};
	void Clear()
	{
		while (Empty() == false)
		{
			PopBack();
		};
	};
	void Insert(int n, int c = 1, T val = 0)
	{
		if (n == size) 
		{
			while (c > 0) 
			{
				PushBack(val);
			};
		}
		else {
			T* temp = new T[size + c];

			int i = 0;
			int ni = 0;
			size = size + c;

			for (ni; ni < size + 1; ni++) 
			{
				if (i != n) 
				{
					temp[ni] = arr[i];
					i++;
				}
				else
					if (i == n) 
					{
						if (c > 0) 
						{
							temp[ni] = val;
							c--;
						}
						else 
						{
							temp[ni] = arr[i];
							i++;
						}
					}
					else 
					{
						cout << "ddd" << endl;
					}
			}
			delete[] arr;
			if (size > capacity)
			{
				capacity = size;
			}
			arr = temp;
		}
	};
	void Erase(int pos1, int pos2 = -1)
	{
		if (pos2 == -1) 
		{ 
			pos2 = pos1; 
		}
		if (pos1 > pos2 || pos1 < 0 || pos2 < 0) 
		{
			cout << "Некорректно указаны позиции" << endl;
			return;
		};
		if (pos2 > size - 1) {
			cout << "Позиция выходит допустимый диапозон" << endl;
			return;
		}
		if (Empty() == true) {
			cout << "Вектор пуст" << endl;
			return;
		};

		T* temp = new T[size];
		int nsize = 0;
		for (int i = 0; i < size; i++)
		{
			if (i < pos1 || i >= pos2) 
			{
				temp[nsize] = arr[i];
				nsize++;
			}
		}

		delete[] arr;
		size = nsize;
		arr = temp;
	};
	void Resize(int n, T val = 0)
	{
		if (n < size) 
		{
			while (n < size) 
			{
				PopBack();
			}
		}
		else if (n > size) 
		{
			while (n > size) 
			{
				PushBack(val);
			}
		}
	};
	void Reserve()
	{
		if (size != 0) 
		{
			T* arr_r = new T[size];

			for (int i = size; i > 0; i--)
			{
				arr_r[abs(i - size)] = arr[i - 1];
			}
			delete[] arr;
			arr = arr_r;
		}
	};
	auto Capacity()
	{
		return capacity;
	};
	auto Size()
	{
		return size;
	};
	T& operator[](int i)
	{
		return arr[i];
	};
};

