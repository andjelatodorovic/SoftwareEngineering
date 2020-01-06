#pragma once
#include"Trougao.h"
#include<iostream>

using namespace std;

class Trougao_h {
public:
	size_t operator()(const Trougao& kljuc) const {
		//cout << "Pozvana funckija hesiranja" << endl;
		size_t p = 0;
		p += (19 * p + hash<int>()(kljuc.a));
		p += (19 * p + hash<int>()(kljuc.b));
		p += (19 * p + hash<int>()(kljuc.c));
		return p;
	}
};