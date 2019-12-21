// GraphCPP.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
//#include "Array.h"
#include "NodeWeight.h"
#include <set>
#include <time.h>
#include <unordered_map>
#include <queue>
#include <map>
//#include <multimap>
#include <iostream>
#include <vector>
#include<windows.h>

#include"graph.h"
using namespace std;



void main()
{
	Graph g1;
	g1.ReadGraphFromFile("Graph1.gr");
	g1.StampajGraph(cout);
	//cout<<endl<<g1<<endl;

	int i = 0;

	vector<int> redosled = g1.DfsRekurzivno(4);
	for(i=0; i < redosled.size(); i++)
		cout<< redosled[i] << " ";
	cout << endl;

	redosled = g1.DfsNeRekurzivno(4);
	for(i=0; i < redosled.size(); i++)
		cout<< redosled[i] << " ";
	cout << endl;

	//redosled = g1.Bfs(4);


	//vector<int> dist = g1.Dijkstra(1);
	//for(i=1; i < dist.size(); i++)
	//	cout<< dist[i] << " ";
	//cout << endl;

	//vector<Edge> mstK = g1.Mst_Kruskal();
	//for(i=0; i < mstK.size(); i++)
	//	cout << "P: " << mstK[i].poc << " K: " << mstK[i].kraj << "  W: " << mstK[i].weight << ",  ";
	//cout << endl;

	//vector<Edge> mstKPQ = g1.Mst_KruskalPQ();
	//for(i=0; i < mstKPQ.size(); i++)
	//	cout << "P: " << mstKPQ[i].poc << " K: " << mstKPQ[i].kraj << "  W: " << mstKPQ[i].weight << ",  ";
	//cout << endl;

	//vector<Edge> mstP = g1.Mst_Prim(1);
	//for(i=0; i < mstP.size(); i++)
	//	cout << "P: " << mstP[i].poc << " K: " << mstP[i].kraj << "  W: " << mstP[i].weight << ",  ";
	//cout << endl;

}
