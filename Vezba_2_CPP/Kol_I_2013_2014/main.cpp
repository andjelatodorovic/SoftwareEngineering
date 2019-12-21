#include <tuple>
#include<vector>
#include<set>
#include<unordered_map>
#include<map>
#include<iostream>
#include<algorithm>
#include "Pravougaonik.h"
using namespace std;


void main(){
	vector<pair<Pravougaonik<int>,int>> niz;
	niz.push_back(make_pair(Pravougaonik<int>(Tacka<int>(1,1),Tacka<int>(2,2)),3));
	niz.push_back(make_pair(Pravougaonik<int>(Tacka<int>(2,2),Tacka<int>(3,3)), 4));
	niz.push_back(make_pair(Pravougaonik<int>(Tacka<int>(2,2),Tacka<int>(4,4)), 2));
	niz.push_back(make_pair(Pravougaonik<int>(Tacka<int>(2,2),Tacka<int>(6,6)), 1));
	niz.push_back(make_pair(Pravougaonik<int>(Tacka<int>(3,3),Tacka<int>(6,6)), 2));

	unordered_map<double,Pravougaonik<int>> unsorted;
	for(vector<pair<Pravougaonik<int>,int>>::iterator it = niz.begin(); it!=niz.end(); it++){
		if(unsorted.find(it->first.getMera()) == unsorted.end())
			unsorted.insert(make_pair(it->first.getMera(),(*it).first));
	}
	double suma = 0.0;
	cout << "nesortirana kolekcija " << endl;
	for(unordered_map<double,Pravougaonik<int>>::iterator it = unsorted.begin(); it!=unsorted.end(); it++){
		cout << it->first <<" "<< it->second << endl;
		suma += it->first;
	}

	multiset<tuple<int, Pravougaonik<int>,double>> sorted;
	for(vector<pair<Pravougaonik<int>,int>>::iterator it = niz.begin(); it!=niz.end(); it++){
		sorted.insert(make_tuple(it->second, it->first, it->first.getNajduzaStrana()));
	}

	suma = 0.0;
	cout << endl << "sortirana kolekcija " << endl;
	for(multiset<tuple<int, Pravougaonik<int>,double>>::iterator its = sorted.begin(); its!=sorted.end(); its++){
		cout << get<0>(*its) << " " << get<1>(*its) << " " << get<2>(*its) << " " << endl;
		suma += get<1>(*its).getMera();
	}

	cout << "Zbir mera u sortiranoj kolekciji  " << suma << endl;

}

