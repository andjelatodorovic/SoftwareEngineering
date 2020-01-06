#pragma once

#include<iostream>
#include<vector>

using namespace std;

template<class T>
int zad3(vector<vector<T>>& mat, int n, int m)
{	
	T max=mat[0][0];
	for (int i = 1;i < m; i++)
		max += mat[0][i];
	int index = -1;
	for (int i = 1; i < n; i++)
	{
		T s = 0;
		for (int j = 0; j < m; j++)
			s += mat[i][j];
		if (s > max)
			max = s;
		index = i;
	}
	return index;
}