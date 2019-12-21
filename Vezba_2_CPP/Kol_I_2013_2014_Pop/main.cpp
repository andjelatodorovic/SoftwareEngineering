#pragma once;


#include <tuple>
#include<vector>
#include<set>
#include<unordered_map>
#include<map>
#include<iostream>
#include<algorithm>
#include "PravougliTrougao.h"

using namespace std;


void main(){
	vector<pair<PravougliTrougao<int>,int>> niz;
	niz.push_back(make_pair(PravougliTrougao<int>(Point2D<int>(1,1),Point2D<int>(2,1),Point2D<int>(2,3)),3));
	niz.push_back(make_pair(PravougliTrougao<int>(Point2D<int>(2,2),Point2D<int>(4,2),Point2D<int>(2,5)), 2));
	niz.push_back(make_pair(PravougliTrougao<int>(Point2D<int>(3,3),Point2D<int>(5,3),Point2D<int>(3,0)), 1));
	niz.push_back(make_pair(PravougliTrougao<int>(Point2D<int>(3,4),Point2D<int>(6,4),Point2D<int>(6,7)), 2));
	niz.push_back(make_pair(PravougliTrougao<int>(Point2D<int>(2,2),Point2D<int>(5,2),Point2D<int>(5,5)), 2));

	unordered_map<double,pair<PravougliTrougao<int>, int>> unsorted;
	for(vector<pair<PravougliTrougao<int>,int>>::iterator it = niz.begin(); it!=niz.end(); it++){
		if(unsorted.find(it->first.getMera()) == unsorted.end())
			unsorted.insert(make_pair ( it->first.getMera(),make_pair ( (*it).first, it->second)));
	}
	double suma = 0.0;
	cout << "nesortirana kolekcija " << endl;
	for(unordered_map<double,pair<PravougliTrougao<int>,int>>::iterator it = unsorted.begin(); it!=unsorted.end(); it++){
		cout << it->first <<" "<< it->second.first << " " <<  it->second.second  << endl;
		suma += it->first;
	}

	multiset<tuple<int, double, PravougliTrougao<int>>> sorted;
	for(vector<pair<PravougliTrougao<int>,int>>::iterator it = niz.begin(); it!=niz.end(); it++){
		sorted.insert(make_tuple(it->second, it->first.getMera(), it->first));
	}
	cout << "Zbir mera u nesortiranoj kolekciji  " << suma << endl;

	suma = 0.0;
	cout << endl << "sortirana kolekcija " << endl;
	for(multiset<tuple<int, double, PravougliTrougao<int>>>::iterator its = sorted.begin(); its!=sorted.end(); its++){
		cout << get<0>(*its) << " " << get<1>(*its) << " " << get<2>(*its) << " " << endl;
		suma += get<2>(*its).getMera();
	}

	cout << "Zbir mera u sortiranoj kolekciji  " << suma << endl;

}


