#pragma once
#include"Dim2.h"
#include"Figura.h"


template<class T>
class Krug : public Figura, public Dim2 {

private:
	T r;
public:
	Krug(T r = 0) {
		this->r = r;
	}

	virtual std::string opis() {
		return "Krug[" + to_string(r) + "]";
	}

	virtual double povrsina() {
		return r * r * 3.14;
	}

	~Krug() {

	}

};