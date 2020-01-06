#pragma once
#include<string>

using namespace std;

class Trougao {
private:
	int a, b, c;
public:
	Trougao(int a, int b, int c): a(a), b(b), c(c) {}

	string getAll() const {
		return "Trougao[" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + "]";
	}
	friend class Trougao_h;
	friend class Trougao_j;
};