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


Edge::~Edge()
{
}
