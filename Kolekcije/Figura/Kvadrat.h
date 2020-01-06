#pragma once
#include"Dim2.h"
#include"Figura.h"

template<class T>
class Kvadrat : public Figura, public Dim2 {

private :
	T a;
public:
	Kvadrat(T a = 0) {
		this->a = a;
	}

	virtual std::string opis() {
		return "Kvadrat[" + to_string(a) + "]";
	}

	virtual double povrsina() {
		return a * a;
	}

	~Kvadrat() {

	}

};