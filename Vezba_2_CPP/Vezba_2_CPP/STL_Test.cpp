// Druga_CPP.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include <windows.h>
#include <functional>
#include <time.h>

#include "Array.h"
#include "NodeWeight.h"


using namespace std;


//struct string_hash {
//	size_t operator()(const std::string &str ) const
//	{
//		return std::hash<string>()(str);
//	}
//};


int compareInt( const void * const pa, const void * const pb)
{
	return (*((int*) pa) - *((int*) pb));
}


int compareInt1( const void * const pa, const void * const pb)
{
	int ret = (*((int*) pa) - *((int*) pb));
	int retValue;
	if(ret > 0)
		retValue = 1;
	else
		if(ret < 0)
			retValue = -1;
		else
			retValue = 0;
	return retValue;
}


int compareInt2( const void * const pa, const void * const pb)
{
	int ret = (*((int*) pa) - *((int*) pb));
	int retValue;
	if(ret > 0)
		retValue = -1;
	else
		if(ret < 0)
			retValue = 1;
		else
			retValue = 0;
	return retValue;
}


void print(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf(" %d ", a[i]);
	printf("\n");
}

int f() 
{  return 8;  }


bool compareNodeWeightP(const nodeWeight* a, const nodeWeight * b)
{
	return (a->Weight < b->Weight);
}


// Hash funcija treba da:
//	1. vraca vrednost tipa std::size_t
//	2. vraca vrednost u intervalu [0, size_t_max)
// size_t_max je najveca vrednost koju compiler podrzava kao vrednost size_of operatora i unsinged je tipa, najcesce kao unsigned int


// Boost biblioteka ima dobru hash funciju
template <typename T>
inline void hash_combine (std::size_t& seed, const T& val)
{
	seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}


template <typename T>
inline void hash_val (std::size_t& seed, const T& val)
{
	hash_combine(seed,val);
}

template <typename T, typename /* ... */ Types>
inline void hash_val (std::size_t& seed,
const T& val, const Types& /*...*/ args)
{
	hash_combine(seed,val);
	hash_val(seed,args...);
}
// auxiliary generic function to create a hash value out of a heterogeneous list of arguments
template <typename /*...*/ Types>
inline std::size_t hash_val (const Types& /*...*/ args)
{
	std::size_t seed = 0;
	hash_val (seed, args /*...*/);
	return seed;
}

std::size_t nodeWeight_hash_func (const nodeWeight& c)
{
	//pocetnicko resenje
	//return	std::hash<int>()(c.Weight) + std::hash<int>()(c.Index);

	std::size_t seed = 0;
	hash_val (seed, c.Weight);
	hash_val (seed, c.Index);
	return	seed;
}


class nodeWeightHash
{
	public:
	std::size_t operator() (const nodeWeight& c) const {
		std::size_t seed = 0;
		hash_val (seed, c.Weight);
		hash_val (seed, c.Index);
		return	seed;
	}
};




void main()	//STL
{
	int a[5] = {2,6,2,1,4}, n=5;

	//qsort(a, 5, sizeof(int), compareInt);
	//print(a,n);

	//qsort(a, 4, sizeof(int), compareInt1);
	//print(a,n);

	//qsort(a, 4, sizeof(int), compareInt2);
	//print(a,n);

	//int i;
	//Array<int,10> arInt;
	//for(i=0; i<5; i++)
	//	arInt[i] = i;
	//for (i = 0; i<10; i++)
	//	printf(" arInt[%d] = %d \n", i, arInt[i]);

	//for(i=5; i<10; i++)
	//	arInt(i) = i*2;

	//for(i=0; i<10; i++)
	//	printf(" arInt[%d] = %d \n", i, arInt[i]);

	//pair<int, int> p1(2,2), p2(2,3), p4(2,1), p5(1,2);
	//if(p1<p2)
	//	printf(" p1 je manje od p2 ");
	//else
	//	printf("  p1 nije manje od p2");

	//if(p1<p4)
	//	printf(" p1 je manje od p4 ");
	//else
	//	printf("  p1 nije manje od p4");


	unordered_map<int,int> m;
	for(int i = 0; i<10; i++)
		for(int j = 0; j < (i/2); j++)
		//for(int  j = (i/2) - 1;  j >= 0; j --)
			m.insert(make_pair(i,(10*(j+1)*i)));
	printf("\n map  \n");
	for(unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	//for (auto it = m.rbegin(); it != m.rend(); it++)
		printf(" i = %d    val = %d\n", it->first, (*it).second);


	//set<pair<int,int>> s;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s.insert(make_pair(i,(10*(j+1)*i)));
	//printf("\n set  \n");
	//for(set<pair<int,int>>::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
	//	printf(" first = %d    second = %d\n", (*it).first, (*it).second);

	//unordered_set<int> s1;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s1.insert(j);
	//printf("\n unordered set  \n");
	//for(unordered_set<int>::iterator its = s1.begin(); its != s1.end(); its++)
	//	printf(" first = %d\n", *its);


	//deque<int> dq;

	//priority_queue<int, vector<int>, std::greater<int>> pq1;
	//priority_queue<int, vector<int>, std::less<int>> pq1;
	//priority_queue<int> pq1;

	//pq1.push(1);
	//pq1.push(2);
	//pq1.push(3);
	//pq1.push(5);
	//pq1.push(4);
	//printf("%d   \n", pq1.top()); pq1.pop();
	//printf("%d   \n", pq1.top()); pq1.pop();
	//printf("%d   \n", pq1.top()); pq1.pop();
	//printf("%d   \n", pq1.top()); pq1.pop();
	//printf("%d   \n", pq1.top()); pq1.pop();



	//priority_queue<nodeWeight, vector<nodeWeight>, std::greater<nodeWeight>> pq;
	////priority_queue<nodeWeight> pq;
	//for (int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		pq.push(nodeWeight((10*(j+1)*i),i));
	//printf("\n priority queue  \n");
	//while(!pq.empty())
	//{
	//	printf(" weight = %d    index = %d\n", pq.top().Weight, pq.top().Index);
	//	pq.pop();
	//}

	
	////hash function 	
	//std::unordered_set<nodeWeight,std::size_t(*)(const nodeWeight&)> s1(20,nodeWeight_hash_func);
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s1.insert(nodeWeight((10*(j+1)*i),i));
	//printf("\n unordered set  \n");
	//for(unordered_set<nodeWeight,std::size_t(*)(const nodeWeight&)>::iterator it = s1.begin(); it != s1.end(); it++)
	//	printf(" first Weight = %d    second Index = %d\n", (*it).Weight, (*it).Index);

	//std::unordered_set<nodeWeight,nodeWeightHash> s2;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s2.insert(nodeWeight((10*(j+1)*i),i));
	//printf("\n unordered set  \n");
	//for(unordered_set<nodeWeight,nodeWeightHash>::iterator it = s2.begin(); it != s2.end(); it++)
	//	printf(" first Weight = %d    second Index = %d\n", (*it).Weight, (*it).Index);



	//s1.erase(nodeWeight(10,30));

	//multiset<nodeWeight> s2;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		s2.insert(nodeWeight((10*(j+1)*i),i));
	//		s2.insert(nodeWeight((10*(j+1)*i),i));
	//		s2.insert(nodeWeight((10*(j + 1)*i), i));
	//	}
	//printf("\n set  \n");
	//for(multiset<nodeWeight>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
	//	printf(" first = %d    second = %d\n", (*it2).Weight, (*it2).Index);
	//printf("\n\n");
	//auto pairIt = s2.equal_range(nodeWeight(40,4));
	//for(multiset<nodeWeight>::iterator it2 = pairIt.first;  it2 != pairIt.second; it2++)
	//	printf("\n first = %d    second = %d\n", it2->Weight, it2->Index);

	
	//multimap<int, int> smm;
	////multimap<int, int, std::greater<int>> smm;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		smm.insert(make_pair((10*(j+1)*i),i+1));
	//		smm.insert(make_pair((10*(j+1)*i),i));
	//		smm.insert(make_pair((10 * (j + 1)*i), i + 1));
	//		smm.insert(make_pair((10 * (j + 1)*i), i));
	//	}
	//printf("\n set  \n");
	//auto pairItMM = smm.equal_range(40);
	//for(multimap<int, int>::iterator it3 = pairItMM.first;  it3 != pairItMM.second; it3++)
	////for (multimap<int, int>::iterator it3 = smm.begin(); it3 != smm.end(); it3++)
	//	printf("\n key = %d    second = %d\n", it3->first, it3->second);

	//smm.erase(40);
	//pairItMM = smm.equal_range(40);
	//for(multimap<int, int>::iterator it3 = pairItMM.first;  it3 != pairItMM.second; it3++)
	////for (multimap<int, int>::iterator it3 = smm.begin(); it3 != smm.end(); it3++)
	//	printf("\n key = %d    second = %d\n", it3->first, it3->second);

	//multiset<tuple<int,int,int>> t;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		t.insert(make_tuple(i,j,i));
	//		t.insert(make_tuple(i,j,i));
	//	}
	//printf("\n set  \n");
	//auto pairItT = t.equal_range(make_tuple(4,1,4));
	//for(multiset<tuple<int, int, int>>::iterator it3 = pairItT.first;  it3 != pairItT.second; it3++)
	//	printf("\n first = %d    second = %d   third = %d\n", get<0>(*it3), get<1>(*it3), get<2>(*it3));

	//multiset<nodeWeight*, bool (*) (const nodeWeight*, const nodeWeight *)> sp(compareNodeWeightP);
	//for (int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		sp.insert(new nodeWeight((10*(j+1)*i),i));
	//		sp.insert(new nodeWeight((10*(j+1)*i),i));
	//	}
	//printf("\n set  \n");
	////for(multiset<nodeWeight*, bool (*) (const nodeWeight*, const nodeWeight *)>::iterator it2 = sp.begin(); it2 != sp.end(); it2++)
	//for (auto it2 = sp.begin(); it2 != sp.end(); it2++)
	//	printf(" weight = %d    index = %d\n", (*(*it2)).Weight,(*(*it2)).Index);
	//printf("\n\n");
	

	//set i multiset:
	//c.count(val);			Returns the number of elements with value val
	//c.find(val);			Returns the position of the first element with value val (or end() if none found)
	//c.lower_bound(val)	Returns the first position, where val would get inserted (the first element >= val)
	//c.upper_bound(val)	Returns the last position, where val would get inserted (the first element > val)
	//c.equal_range(val)	Returns a range with all elements with a value equal to val (i.e., the first and last position, where val would get inserted)
	//
	//set<int> c;
	//c.insert(1);
	//c.insert(2);
	//c.insert(4);
	//c.insert(5);
	//c.insert(6);
	//cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	//cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	//cout << "equal_range(3): " << *c.equal_range(3).first << " "
	//<< *c.equal_range(3).second << endl;
	//cout << endl;
	//cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	//cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	//cout << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << endl;


	//set<Elem,Op>
	//multiset<Elem>
	//multiset<Elem, Op>
	//brisanje set i multiset
	//std::set<Elem> coll;
	//remove all elements with value val
	//coll.erase(value);   

	//std::multiset<Elem> coll;
	//coll.erase(value);	//erase all elements with value remove first element with passed value
	//std::multiset<Elem>::iterator pos;
	//pos = coll.find(value);
	//if (pos != coll.end()) {
	//	coll.erase(pos);
	//}
	// coll2.erase (coll2.begin(), coll2.find(3));  // element with value 3 is the end of the range, so it is not removed

	// multimap
	//c.count(val) Returns the number of elements with key val
	//c.find(val) Returns the position of the first element with key val (or end() if none found)
	//c.lower_bound(val) Returns the first position where an element with key val would get inserted (the first element with a key >= val)
	//c.upper_bound(val) Returns the last position where an element with key val would get inserted (the first element with a key > val)
	//c.equal_range(val) Returns a range with all elements with a key equal to val (i.e., the first and last positions, where an element with key val would get inserted)


	//float aValue;
	//typedef std::map<std::string,float> StringFloatMap;
	//StringFloatMap coll;
	//StringFloatMap::iterator pos;
	//for (pos = coll.begin(); pos != coll.end(); ) {
	//	if (pos->second == aValue) {
	//		coll.erase(pos++);
	//	}
	//	else {
	//		++pos;
	//	}
	//}

	//std::unordered_map<std::string,float, std::hash<string>> sf;	// std::hash<std::string>





}












