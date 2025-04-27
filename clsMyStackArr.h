#pragma once
#include "clsMyQueueArr.h"
#include <iostream>

template <class T>
class clsMyStackArr : public clsMyQueueArr <T>
{

public:

	void push(T value)
	{
		clsMyQueueArr<T>::_MyArr.InsertAtBeginning(value);
	}

	T Top()
	{
		return clsMyQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::back();
	}


};

