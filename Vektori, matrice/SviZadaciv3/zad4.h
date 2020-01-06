#pragma once

#include<vector>
#include<iostream>


using namespace std;

template<class T>
void zad4(vector<T>& v)
{
	for (int i = 0; i < v.size(); i = i + 2)
		if (v[i] % 2 == 1)
			cout << v[i];
}