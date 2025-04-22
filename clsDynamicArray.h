#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:

	int _Size = 0;

public:

	T* DynamicArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0) Size = 0;

		_Size = Size;
		DynamicArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] DynamicArray;
	}

	bool SetItem(int index, T value)
	{
		if (index < 0 || index >= _Size) return false;

		DynamicArray[index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}
	
	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++) {
			cout << DynamicArray[i] << " ";
		}
		cout << "\n";
	} 

};

