#pragma once

#include<iostream>
#include<vector>

using namespace std;

class Figura
{
public:
	virtual void opis() = 0;
	virtual int dim() = 0;
};

class Dim2
{
public:
	virtual double povrsina() = 0;
	int dim()
	{
		return 2;
	}
};

class Dim3
{
public:
	virtual double zapremina() = 0;
	int dim()
	{
		return 3;
	}
};

class Krug :public Figura, public Dim2
{
private:
	double r;

public:
	Krug(double r=3) : r(r) {}
	~Krug() {}
	virtual void opis()
	{
		cout << "Krug(" << r << ")" << endl;
	}
	virtual double povrsina()
	{
		return r * r*3.14;
	}
	int dim()
	{
		return 1;
	}
};

class Kvadrat :public Figura, public Dim2
{
private:
	double a;

public:
	Kvadrat(double a = 3) : a(a) {}
	~Kvadrat() {}
	virtual void opis()
	{
		cout << "Kvadrat(" << a << ")" << endl;
	}
	virtual double povrsina()
	{
		return a * a;
	}
	int dim()
	{
		return 2;
	}
};

class Kocka :public Figura, public Dim3
{
private:
	double a;

public:
	Kocka(double a = 3) : a(a) {}
	~Kocka() {}
	virtual void opis()
	{
		cout << "Kocka(" << a << ")" << endl;
	}
	virtual double zapremina()
	{
		return a * a * a;
	}
	int dim()
	{
		return 3;
	}
};

class Kupa :public Figura, public Dim3
{
private:
	double r;
	double h;

public:
	Kupa(double r = 3, double h = 5) : r(r), h(h) {}
	~Kupa() {}
	virtual void opis()
	{
		cout << "Kupa(" << r << "," << h << ")" << endl;
	}
	virtual double zapremina()
	{
		return (h*r*r*3.14)/3;
	}
	int dim()
	{
		return 4;
	}
};