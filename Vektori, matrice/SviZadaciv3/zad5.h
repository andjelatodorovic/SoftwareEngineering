#pragma once

#include<iostream>
#include<vector>

using namespace std;

template<class T>
void zad5(vector<T> v, int m)
{
	for (int i = 0;i < v.size();i++)
		if (veci(v,i,m) && manji(v,i,m))
			cout << i << endl;
}

template<class T>
bool veci(vector<T> v, int x, int m)
{
	bool p = true;
	int g = x - m - 1;
	if (g < 0)
		g = 0;
	for (int i = g;i < x;i++)
		if (v[i] > v[x])
			p = false;
	return p;		
}

template<class T>
bool manji(vector<T> v, int x, int m)
{
	bool p = true;
	int g = x + m + 2;
	if (g > v.size())
		g = v.size();
	for (int i = x + 1;i < g;i++)
		if (v[i] < v[x])
			p = false;
	return p;
}