#pragma once
#include <iostream>
#include "Izmerljivo.h"
#include <math.h>

using namespace std;

template<class T> class Tacka : public Izmerljivo{
private:
	T x, y;
public:

	Tacka(T x, T y){
		this->x = x; this->y = y;
	}
	Tacka(){
		x = y = 0;
	}

	Tacka(const Tacka & d){
		x = d.x; y = d.y;
	}

	~Tacka(){}
	T getX() const {return x;}
	T getY() const {return y;}

	void setX(T arg) {x = arg;}
	void setY(T arg) {y = arg;}

	double getMera() const {
		return sqrt(((double) x)*((double) x) + ((double) y) * ((double) y));
	}
};


	template<class T>
	ostream& operator << (ostream& os, const Tacka<T> & d)
	{
		os<<"("<<d.getX()<<","<<d.getY()<<")";
		return os; 
	}
