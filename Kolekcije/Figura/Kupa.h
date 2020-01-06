#pragma once
#include"Dim3.h"
#include"Figura.h"

template<class T>
class Kupa : public Figura, public Dim3 {

private:
	T r, h;
public:
	Kupa(T r = 0, T h = 0) {
		this->r = r;
		this->h = h;
	}

	virtual std::string opis() {
		return "Kupa[" + to_string(r) + ", " + to_string(h) + "]" ;
	}

	virtual double zapremina() {
		return 0.33 * r * r * 3.14 * h;
	}

	~Kupa() {

	}

};