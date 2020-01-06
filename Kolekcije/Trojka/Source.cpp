#include"Trojka_uredjenje.h"
#include<iostream>
#include<set>
#include<ctime>

using namespace std;

int main() {
	
	set<Trojka, Trojka_uredjenje> s;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		int a = rand() % 10 + 1;
		int b = rand() % 10 + 1;
		int c = rand() % 10 + 1;
		s.insert(Trojka(a, b, c));
	}

	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << it->getAll() << endl;
	}

	return 0;
}