#include "stdafx.h"
#include "Neighbour.h"


int Neighbour::getWeight()
const
{
	 return weight; 
}

int Neighbour::getEnd()
const
{
	return end;
}

Neighbour::Neighbour(int weight, int end)
{
	this->weight = weight;
	this->end = end;
}

Neighbour::Neighbour()
{
}


Neighbour::~Neighbour()
{
	
}

bool Neighbour::operator < (const Neighbour & right) 
{
	return weight > right.weight;
}

void Neighbour::print()
{
	cout << end << " | " << weight << " | ";
}

bool Neighbour::operator==(const Neighbour & right)
{
	if (end = right.end)
	{
		return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream &out, const Neighbour *n)
{
	

	out << "S: [" << n->getEnd() << "] W: [" << n->getWeight() << "]";
	return out;
}