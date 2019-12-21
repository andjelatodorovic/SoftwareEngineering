#pragma once

class Edge
{
public:
	int poc, kraj, weight;
	Edge(){}
	Edge(int poc, int kraj, int weight)
	{
		this->poc = poc; this->kraj = kraj; this->weight = weight;
	}
	~Edge(){}
	bool operator < (const Edge & e2) const
	{
		bool res = false;
		if(weight < e2.weight || (weight == e2.weight && poc < e2.poc) 
			|| (weight == e2.weight && poc == e2.poc && kraj < e2.kraj ) )
			res = true;
		return res;
	}

};