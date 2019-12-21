#pragma once

#include <stdio.h>
#include <stdlib.h>


struct nodeWeight
{
	int Index, Weight;

	nodeWeight()
	{	Index = 0; Weight = 0;	}

	nodeWeight(int ind, int we)
	{	Index = ind; Weight = we;	}

	bool operator<(const nodeWeight &b) const
	{
		if(Weight < b.Weight)
			return true;
		else
			if(Weight == b.Weight)
				return (Index < b.Index);
			else
				return false;
	}

	bool operator<=(const nodeWeight &b)  const
	{
		if(Weight < b.Weight)
			return true;
		else
			if(Weight == b.Weight)
				return (Index <= b.Index);
			else
				return false;
	}


	bool operator>(const nodeWeight &b)  const
	{
		if(Weight > b.Weight)
			return true;
		else
			if(Weight == b.Weight)
				return (Index > b.Index);
			else
				return false;
	}

	bool operator>=(const nodeWeight &b)  const
	{
		if(Weight > b.Weight)
			return true;
		else
			if(Weight == b.Weight)
				return (Index >= b.Index);
			else
				return false;
	}

	bool operator==(const nodeWeight &b)  const
	{
		return (Weight == b.Weight && Index == b.Index);
	}

};
