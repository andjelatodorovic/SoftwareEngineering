#pragma once
#include"Trojka.h"

struct Trojka_uredjenje {
	bool operator() (const Trojka& prva, const Trojka& druga) const {
		return ((prva.a < druga.a) || (prva.a == druga.a && prva.b < druga.b)
			|| (prva.a == druga.a && prva.b == druga.b && prva.c < druga.c));
	}
};