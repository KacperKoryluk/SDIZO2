#include "stdafx.h"
#include "Edge.h"


int Edge::getStartVertice()
{
	return startVertice;
}

int Edge::getEndVertice()
{
	return endVertice;
}

int Edge::getWeight()
{
	return weight;
}

Edge::Edge()
{
}

Edge::Edge(int startVertice, int endVertice, int weight)
{
	this->startVertice = startVertice;
	this->endVertice = endVertice;
	this->weight = weight;
}

bool Edge::operator< (const Edge & right)
{
	return weight > right.weight;
}

bool Edge::operator> (const Edge & right)
{
	return weight < right.weight;
}

bool Edge::operator==(const Edge & right)
{
	if ((endVertice == right.endVertice) && (startVertice == right.startVertice))
	{
		return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream &out, const Edge *n)
{


	out << "S: [" << n->startVertice <<"] E: [" <<n->endVertice << "] W: [" << n->weight << "]";
	return out;
}

Edge::~Edge()
{
}
