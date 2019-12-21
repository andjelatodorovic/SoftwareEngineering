#pragma once

template<class T = int, int S = 40>
class Array
{
	T* a;
	int n;
public:
	Array()
	{	a = new T[S];  n = S;	}

	~Array()
	{	delete [] a;	}

	T& operator[](int index)
	{	return a[index];	}

	T& operator()(int index)
	{	return a[index];	}


};
