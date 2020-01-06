#pragma once
#include<string>
using namespace std;

class Trojka {
private:
	int a, b, c;

public:
	Trojka(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	
	string getAll() const {
		return "Trojka[" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + "]";
	}
	friend struct Trojka_uredjenje;
};