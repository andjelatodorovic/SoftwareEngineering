#pragma once
#include"Dim3.h"
#include"Figura.h"


template<class T>
class Kocka : public Figura, public Dim3 {

private:
	T a;
public:
	Kocka(T a):a(0) {
		this->a = a;
	}

	virtual std::string opis() {
		return "Kocka[" + to_string(a) + "]";
	}

	virtual double zapremina() {
		return a * a * a;
	}

	~Kocka() {

	}

};