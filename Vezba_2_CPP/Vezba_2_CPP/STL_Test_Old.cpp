// Druga_CPP.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "NodeWeight.h"
#include <set>
#include <unordered_set>
#include <time.h>
#include <unordered_map>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <vector>
#include<windows.h>
#include <functional>

using namespace std;



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


void main_Old()
{
	//int a[5] = {2,3,2,1,4}, n=5;

	//qsort(a, 4, sizeof(int), compareInt);
	//print(a,n);

	//qsort(a, 4, sizeof(int), compareInt1);
	//print(a,n);

	//qsort(a, 4, sizeof(int), compareInt2);
	//print(a,n);

	//int i;
	//Array<int,10> arInt;
	//for(i=0; i<5; i++)
	//	arInt[i] = i;

	//for(i=5; i<10; i++)
	//	arInt(i) = i;


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


	//unordered_map<int,int> m;
	//for(int i = 0; i<10; i++)
	//	//for(int j = 0; j < (i/2); j++)
	//	for(int  j = (i/2) - 1;  j >= 0; j --)
	//		m.insert(make_pair(i,(10*(j+1)*i)));
	//printf("\n map  \n");
	//for(unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	//	printf(" i = %d    val = %d\n", it->first, (*it).second);


	//set<pair<int,int>> s;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s.insert(make_pair(i,(10*(j+1)*i)));
	//printf("\n set  \n");
	//for(set<pair<int,int>>::iterator it = s.begin(); it != s.end(); it++)
	//	printf(" first = %d    second = %d\n", (*it).first, (*it).second);

	//unordered_set<int> s1;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s1.insert(j);
	//printf("\n unordered set  \n");
	//for(unordered_set<int>::iterator its = s1.begin(); its != s1.end(); its++)
	//	printf(" first = %d\n", *its);


	deque<int> dq;
	list<int> l;
	queue<int> q;
	stack<int> s;

	//priority_queue<int, vector<int>, std::greater<int>> pq1;

	//priority_queue<nodeWeight, vector<nodeWeight>, std::greater<nodeWeight>> pq;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		pq.push(nodeWeight((10*(j+1)*i),i));
	//printf("\n priority queue  \n");
	//while(!pq.empty())
	//{
	//	printf(" weight = %d    index = %d\n", pq.top().Weight, pq.top().Index);
	//	pq.pop();
	//}

	//unordered_set<nodeWeight> s1;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//		s1.insert(nodeWeight((10*(j+1)*i),i));
	//printf("\n set  \n");
	//for(unordered_set<nodeWeight>::iterator it = s1.begin(); it != s1.end(); it++)
	//	printf(" first = %d    second = %d\n", (*it).Weight, (*it).Index);

	//s1.erase(nodeWeight(10,30));

	//multiset<nodeWeight> s2;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		s2.insert(nodeWeight((10*(j+1)*i),i));
	//		s2.insert(nodeWeight((10*(j+1)*i),i));
	//	}
	//printf("\n set  \n");
	//for(multiset<nodeWeight>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
	//	printf(" first = %d    second = %d\n", (*it2).Weight, (*it2).Index);
	//printf("\n\n");
	//auto pairIt = s2.equal_range(nodeWeight(40,4));
	//for(multiset<nodeWeight>::iterator it2 = pairIt.first;  it2 != pairIt.second; it2++)
	//	printf("\n first = %d    second = %d\n", it2->Weight, it2->Index);

	//multimap<int, int> smm;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		smm.insert(make_pair((10*(j+1)*i),i));
	//		smm.insert(make_pair((10*(j+1)*i),i));
	//	}
	//printf("\n set  \n");
	//auto pairItMM = smm.equal_range(40);
	//for(multimap<int, int>::iterator it3 = pairItMM.first;  it3 != pairItMM.second; it3++)
	//	printf("\n key = %d    second = %d\n", it3->first, it3->second);

	//smm.erase(40);
	//pairItMM = smm.equal_range(40);
	//for (multimap<int, int>::iterator it3 = pairItMM.first; it3 != pairItMM.second; it3++)
	//	printf("\n key = %d    second = %d\n", it3->first, it3->second);

	//multiset<tuple<int,int,int>> t;
	//for(int i = 0; i<10; i++)
	//	for(int j = 0; j < (i/2); j++)
	//	{
	//		t.insert(make_tuple(i,j,i));
	//		t.insert(make_tuple(i,j,i));
	//	}
	//printf("\n multiset  \n");
	//auto pairItT = t.equal_range(make_tuple(4,1,4));
	//for(multiset<tuple<int, int, int>>::iterator it3 = pairItT.first;  it3 != pairItT.second; it3++)
	//	printf("\n first = %d    second = %d   third = %d\n", get<0>(*it3), get<1>(*it3), get<2>(*it3));



}

