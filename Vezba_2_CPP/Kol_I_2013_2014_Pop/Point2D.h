#pragma once
#include <iostream>
//#include "Mera.h"
#include <math.h>

using namespace std;

template<class T> class Point2D{
private:
	T x, y;
public:

	Point2D(T x, T y){
		this->x = x; this->y = y;
	}
	Point2D(){
		x = y = 0;
	}

	Point2D(const Point2D & d){
		x = d.x; y = d.y;
	}

	~Point2D(){}
	T getX() const {return x;}
	T getY() const {return y;}

	void setX(T arg) {x = arg;}
	void setY(T arg) {y = arg;}

};


	template<class T>
	ostream& operator << (ostream& os, const Point2D<T> & d)
	{
		os<<"("<<d.getX()<<","<<d.getY()<<")";
		return os; 
	}
