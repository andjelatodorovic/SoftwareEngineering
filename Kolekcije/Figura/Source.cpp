#include"Kocka.h"
#include"Krug.h"
#include"Kupa.h"
#include"Kvadrat.h"

#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

int main() {

	vector<Figura*> figure;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		int r = rand() % 4;
		int a, h, R;
		switch (r) {
		case 0:
			a = rand() % 100 + 1;
			figure.push_back(new Kocka<int>(a));
			break;
		case 1:
			a = rand() % 100 + 1;
			figure.push_back(new Kvadrat<int>(a));
			break;
		case 2:
			R = rand() % 100 + 1;
			figure.push_back(new Krug<int>(R));
			break;
		case 3:
			R = rand() % 100 + 1;
			h = rand() % 100 + 1;
			figure.push_back(new Kupa<int>(R, h));
			break;
		}
	}

	for (auto it = figure.begin(); it != figure.end(); ++it) {
		cout << (*it)->opis() << endl;
	}

	system("pause");
	return 0;
}