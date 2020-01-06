#pragma once

#include<iostream>

using namespace std;

class Trojka
{
private:
	int a, b, c;

public:
	Trojka(int a = 1, int b = 1, int c = 1) : a(a), b(b), c(c) {}
	~Trojka() {}
	int getA() const
	{
		return a;
	}
	int getB() const
	{
		return b;
	}
	int getC() const
	{
		return c;
	}
};

struct Trojka_uredjenje 
{
	bool operator() (const Trojka& ls, const Trojka& ds) const
	{
		return ((ls.getA() < ds.getA()) || ((ls.getA() == ds.getA()) && (ls.getB() < ds.getB())) || ((ls.getA() == ds.getA()) && (ls.getB() == ds.getB()) && (ls.getC() < ds.getC())));
	}
};