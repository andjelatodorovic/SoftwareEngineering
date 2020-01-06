#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<climits>

using namespace std;

//Odstampati svaki drugi element celobrojnog vektora ako je taj element neparan.

void zad4(const vector<int>& v) {

	for (int i = 0; i < v.size(); i += 2) {
		if (v[i] % 2)
			cout << v[i] << " ";
	}
	cout << endl;

}

template<class T>

//Zadatak 3. Napisati sablonsku funkciju za nalazenje vrste matrice (vector < vector < T >>), sa najvecom sumom.
int zad3(const vector<vector<T>>& mat) {
	int maxs = INT_MIN;
	int indMaxV = -1;
	for (int i = 0; i < mat.size(); ++i) {
		int s = 0;
		for (int j = 0; j < mat[i].size(); ++j){
			s += mat[i][j];
		}
		if (s > maxs) {
			maxs = s;
			indMaxV = i;
		}
	}
	return indMaxV;
}

template<class T>
void printMat(vector<vector<T>> mat) {
	for (auto itv = mat.begin(); itv != mat.end(); ++itv) {
		for (auto it = (*itv).begin(); it != (*itv).end(); ++it) {
			cout << *it << " ";
		}
		cout << endl; 
	}

}

//Dat je ceo broj m. Odstampati svaki element vektora koji je veci od prethodnih m brojeva i manji od narednih m brojeva.

void zad5(const vector<int>& v, int m) {
	for (auto it = v.begin() + m; it != v.end(); ++it) {
		int tr = *it;
		bool ok = true;
		for (int i = 1; i <= m; ++i) {
			if ((it - i != v.begin() && tr <= *(it - i)) || (it + i != v.end() && tr >= *(it + i))) {
				ok = false;
				break;
			}
		}
		if (ok) cout << tr << " ";
	}
	cout << endl;
}

template<class T>
void printVec(const vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main() {

	vector<int> v;

	v.push_back(5);
	v.push_back(21);
	v.push_back(232);
	v.push_back(444);
	v.push_back(4664);
	v.push_back(677);
	v.push_back(2321);
	v.push_back(442);
	v.push_back(46641);
	v.push_back(6771);
	printVec(v);

	/*zad4(v);

	srand(time(NULL));

	int m = 3, n = 4;
	vector<vector<int>> mat;


	for (int i = 0; i < m; ++i){
		vector<int> red;
		for (int j = 0; j < n; ++j) {
			red.push_back(rand() % 100);
		}
		mat.push_back(red);
	}
	printMat(mat);


	cout << zad3(mat) << endl;*/

	zad5(v, 3);

	system("pause");
	return 0;
}
