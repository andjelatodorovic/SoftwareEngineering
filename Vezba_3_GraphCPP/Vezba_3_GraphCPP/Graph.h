#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
#include "Edge.h"
#include "UnionFind.h"

using namespace std;

class Graph
{
private:
	int numNodes, numEdges;
	vector<list<int>> nodes;
	vector<Edge> edges;


public:
	Graph(){}

	// stampanje grafa
	void StampajGraph(ostream & os)
	{
		os << "Graph"  << endl;
		int i=0;
		for(vector<list<int>>::iterator it = nodes.begin(); it != nodes.end(); it++)
		{
			if(i>0)
			{
				os << "node: " << i << "  adj: ";
				for(list<int>::iterator it1 = it->begin(); it1 != it->end(); it1++)
					os << " kraj: " << edges[*it1].kraj << " w: " << edges[*it1].weight;
				os << endl;
			}
			i++;
		}
	}

	vector<int> DfsRekurzivno(int cvor)
	{
		vector<int> result;
		vector<bool> nadjen(nodes.size(),false);
		DfsPom(cvor, result,nadjen);
		// ako graph ima izdvojene komponente
		//for(int i = 1; i < nodes.size(); i++ )
		//	if(! nadjen[i])
		//		DfsPom(i, result,nadjen);
		return result;
	}
private:
	void DfsPom( int  cvor, vector<int> & result, vector<bool> & nadjen) const
	{
		nadjen[cvor] = true;
		result.push_back(cvor);
		// obidji sve susede cvora sa indexom cvor koji nisu obidjeni
		for(auto it = nodes[cvor].cbegin(); it != nodes[cvor].cend(); it++)
		{
			if(! nadjen[edges[*it].kraj])
				DfsPom(edges[*it].kraj, result, nadjen);
		}
	}

public:

	vector<int> DfsNeRekurzivno(int cvor)
	{
		vector<int> result;
		vector<bool> nadjen(nodes.size(),false);
		vector<list<int>::const_iterator> itv(nodes.size());
		for(int i = 0; i < nodes.size(); i++)
			itv[i] = nodes[i].begin();

		DfsNerekurzivnoPomKor(cvor, result,nadjen, itv);

		// ako graph ima izdvojene komponente
		//for(int i = 1; i < nodes.size(); i++ )
		//	if(! nadjen[i])
		//		DfsNerekurzivnoPom(i, result,nadjen);
		return result;
	}
private:

	void DfsNerekurzivnoPomKor( int  cvor, vector<int> & result, vector<bool> & nadjen, vector<list<int>::const_iterator> &itv) const
	{
		stack<int> st;
		st.push(cvor);
		nadjen[cvor] = true;
		result.push_back(cvor);
		while(! st.empty())
		{
			int tmp = st.top();
			// obidji sve susede cvora sa indexom tmp koji nisu obidjeni
			// kad nadjes cvor koji nije obidjen, upisi ga u stek i iskoci iz while petlje i nastavi obradu steka
			while(itv[tmp] != nodes[tmp].end())	// obilazak u redosledu kao kod rekurzivne
			{
				if(! nadjen[edges[*itv[tmp]].kraj])
				{
					st.push(edges[*itv[tmp]].kraj);
					nadjen[edges[*itv[tmp]].kraj] = true;
					result.push_back(edges[*itv[tmp]].kraj);
					itv[tmp]++;
					break;
				}
				else
					itv[tmp]++;
			}
			if(itv[tmp] == nodes[tmp].end())
				st.pop();
		}
	}

public:

	vector<int> Bfs(int cvor)
	{
		vector<int> result;
		vector<bool> nadjen(nodes.size(),false);
		BfsPom(cvor, result,nadjen);
		// ako graph ima izdvojene komponente
		//for(int i = 1; i < nodes.size(); i++ )
		//	if(! nadjen[i])
		//		BfsPom(i, result,nadjen);
		return result;
	}
private:
	void BfsPom( int  cvor, vector<int> & result, vector<bool> & nadjen) const
	{
		queue<int> red;
		red.push(cvor);
		nadjen[cvor] = true;
		while(! red.empty())
		{
			int tmp = red.front();
			result.push_back(tmp);
			red.pop();
			// obidji sve susede cvora sa indexom tmp koji nisu obidjeni
			// obilazak u potomaka u obrnutomredosledu od rekurzivne
			//for(auto it = nodes[tmp].cbegin(); it != nodes[tmp].cend(); it++)  
			// obilazak u redosledu kao kod rekurzivne
			for(auto it = nodes[tmp].rbegin(); it != nodes[tmp].rend(); it++)	// obilazak u redosledu kao kod rekurzivne
			{
				if(! nadjen[edges[*it].kraj])
				{
					red.push(edges[*it].kraj);
					nadjen[edges[*it].kraj] = true;
				}
			}
		}
	}

public:
	// nalazi nakrace rastojanje od startnog cvora do svih ostalih cvorova
	vector<int> Dijkstra( int  start) const
	{
		int beskonacno = 2000000000;
		vector<int> dist(nodes.size(),beskonacno);
		vector<bool> nadjen(nodes.size(),false);
		dist[start] = 0;
		set<pair<int,int>> minHeap;
		for(unsigned int i = 1; i < nodes.size(); i++)
		{
			if(i == start)
				minHeap.insert(make_pair(0,start));
			else
				minHeap.insert(make_pair(beskonacno, i));
		}

		while(! minHeap.empty())
		{
			pair<int,int> pairWeightCvor = *minHeap.begin();
			minHeap.erase(minHeap.begin());
			int tmp = pairWeightCvor.second;
			nadjen[tmp] = true;
			// obidji sve susede cvora tmp u oznaci u i azuriraj na bolju, tj manju duzinu puta
			// ako dist[u] > dist[tmp] + edgeWeight[tmp -> u] onda je bolje dist[u] = dist[tmp] + edgeWeight[tmp -> u]
			for(auto it = nodes[tmp].begin(); it != nodes[tmp].end(); it++)	
			{
				Edge edge;
				edge = edges[*it];
				int u;
				u = edge.kraj;
				if( dist[u] > dist[tmp] + edge.weight)
				{
					auto itFind = minHeap.find(make_pair(dist[u],u));
					minHeap.erase(itFind); //minHeap.erase(make_pair(dist[u],u));
					dist[u] = dist[tmp] + edge.weight;
					minHeap.insert(make_pair(dist[u], u));
				}
			}
		}
		return dist;
	}

public:
	// nalazi minimum waight spaning tree MST Kruskal-ovim algoritmom
	// vraca vector Edge koji predstavljaju ivice od kojih je sacinjeno stablo
	vector<Edge> Mst_Kruskal() const
	{
		vector<Edge> mst;
		set<Edge> minHeapEdges;
		for(auto it=edges.begin(); it != edges.end(); it++)
		{
			minHeapEdges.insert(*it);
		}
		UnionFind uf(nodes.size());
		while(! minHeapEdges.empty())
		{
			Edge e;
			e = *minHeapEdges.begin();
			minHeapEdges.erase(e);
			if(! uf.IsConnected(e.poc, e.kraj))
			{
				uf.Connect(e.poc, e.kraj);
				mst.push_back(e);
			}
		}
		return mst;
	}

public:
	// nalazi minimum weight spaning tree MST Kruskal-ovim algoritmom
	// vraca vector Edge koji predstavljaju ivice od kojih je sacinjeno stablo
	vector<Edge> Mst_KruskalPQ() const
	{
		vector<Edge> mst;
		priority_queue<Edge> minHeap;
		for(auto it=edges.begin(); it != edges.end(); it++)
		{
			Edge e = *it;
			e.weight = -1 * e.weight;
			minHeap.push(e);
		}
		UnionFind uf(nodes.size());
		while(! minHeap.empty())
		{
			Edge e;
			e = minHeap.top();
			minHeap.pop();
			if(! uf.IsConnected(e.poc, e.kraj))
			{
				uf.Connect(e.poc, e.kraj);
				e.weight = -1 * e.weight;
				mst.push_back(e);
			}
		}
		return mst;
	}

public:
	// nalazi minimum waight spaning tree MST Primovim-ovim algoritmom
	// vraca vector Edge koji predstavaljaju ivice od kojih je sacinjeno stablo
	vector<Edge> Mst_Prim(int start) const
	{
		vector<bool> dvaSkupa(nodes.size(),false);	// sa false vrednoscu su u jednom skupu, a sa true u drugom
		vector<Edge> mst;
		set<Edge> betweenEdges;
		for(auto it=nodes[start].begin(); it != nodes[start].end(); it++)
		{
			betweenEdges.insert(edges[*it]);
		}
		dvaSkupa[start] = true;
		//UnionFind uf(nodes.size());
		while(! betweenEdges.empty())
		{
			Edge e;
			e = *betweenEdges.begin();
			//betweenEdges.erase(e);
			mst.push_back(e);
			dvaSkupa[e.kraj] = true;
			for(auto it = nodes[e.kraj].begin(); it != nodes[e.kraj].end(); it++)
			{
				if(! dvaSkupa[edges[*it].kraj])
				{
					betweenEdges.insert(edges[*it]);
				}
				else
				{
					Edge toErase;
					toErase.poc = edges[*it].kraj;
					toErase.kraj = edges[*it].poc;
					toErase.weight = edges[*it].weight;
					betweenEdges.erase(toErase);
				}
			}
		}
		return mst;
	}




public:

	// read DIMACS format graph
	void ReadGraphFromFile(char * fileName)
	{
		ifstream inputFile(fileName);
		if ( ! inputFile )
		{
				cout << "Fajl " << fileName << " nije nadjen" << endl;
				return;
		}
		nodes.erase(nodes.begin(), nodes.end());
		edges.erase(edges.begin(), edges.end());
		char prva[5], druga[5];
		inputFile >> prva >> druga >> numNodes >> numEdges;
		nodes.resize(numNodes+1);
		edges.resize(numEdges);
		list<int> adj;
		Edge e;
		int i=0;
		while(! inputFile.eof() )
		{
			inputFile >> prva;
			if(strlen(prva) > 0)
			{
				inputFile >> e.poc >> e.kraj >> e.weight;
				edges[i]=e;
				nodes[e.poc].push_back(i);
				i++;
			}
		}
		inputFile.close();
	}

	~Graph()
	{
		nodes.erase(nodes.begin(), nodes.end());
		edges.erase(edges.begin(), edges.end());
	}





};


ostream & operator << (ostream & os, Graph & g)
{
	g.StampajGraph(os);
	return os;
}
