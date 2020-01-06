#pragma once
#include"Trougao.h"

class Trougao_j {
public:
	bool operator() (const Trougao& t1, const Trougao& t2) const {
		return ((t1.a == t2.a) && (t1.b == t2.b) && (t1.c == t2.c));
	}
};