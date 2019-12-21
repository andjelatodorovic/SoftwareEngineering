#pragma once
#include<vector>


using namespace std;


class UnionFind
{
// - 1 je da nema roditelja, a > 0 da mu je roditelj cvor sa tim indeksom
private:
	vector<int> parent;
public:
	UnionFind(int n)
	{
		parent.resize(n, -1);
	}

	~UnionFind()
	{}

	bool IsConnected(int cvor1, int cvor2)
	{
		int cvor1Component, cvor2Component;
		cvor1Component = FindRootOfComponent(cvor1);
		cvor2Component = FindRootOfComponent(cvor2);
		return ( cvor1Component == cvor2Component);
	}

public:
	void Connect(int cvor1, int cvor2)
	{
		int cvor1Component = FindRootOfComponent(cvor1);
		int cvor2Component = FindRootOfComponent(cvor2);
		parent[cvor2Component] = cvor1Component;
	}

private:
	int FindRootOfComponent(int cvor)
	{
		int root = cvor;
		while(parent[root] != -1)
			root = parent[root];
		return root;
	}








};