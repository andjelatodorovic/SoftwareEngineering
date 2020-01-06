#include"Trougao.h"
#include"Trougao_h.h"
#include"Trougao_j.h"

#include<iostream>
#include<unordered_map>
#include<ctime>

using namespace std;

int main() {

	unordered_map<Trougao, int, Trougao_h, Trougao_j> mapa;

	int n;
	int a, b, c;

	srand(time(NULL));

	cin >> n;

	for (int i = 0; i < n; ++i) {
		a = rand() % 3 + 1;
		b = rand() % 3 + 1;
		c = rand() % 3 + 1;

		Trougao t(a, b, c);
		cout << "Napravljen je " << t.getAll() << endl;
		if (mapa.find(t) == mapa.end()){
			mapa[t] = 1;
		}
		else {
			mapa[t]++;
		}
	}

	for (auto it = mapa.begin(); it != mapa.end(); ++it) {
		cout << "(" << it->first.getAll() << ", " << it->second << ")" << endl;
	}

	return 0;
}