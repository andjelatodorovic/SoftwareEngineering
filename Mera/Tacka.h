#pragma once
#include"IMera.h"

template<class T>
class Tacka :public IMera {
private: 
	T x, y;
public:
	Tacka() {
		this->x = x;
		this->y = y;
	}

	Tacka(T x, T y) {
		this->x = x;
		this->y = y;
	}

	T getX() {
		return x;
	}

	T getY() {
		return y;
	}

	void setX(T x) {
		this->x = x;
	}

	void setY(T y) {
		this->y = y;
	}

	virtual double getMera() {
		return sqrt(x*x + y*y);
	}

	bool operator<(const Tacka<T>& tacka) {
		return getMera < tacka.getMera();
	}

	~Tacka();
};

