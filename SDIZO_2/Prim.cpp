#include "stdafx.h"
#include "Prim.h"


void Prim::execute()
{
	cout << "Prim executed" << endl;
}

Prim::Prim()
{
}


Prim::~Prim()
{
}

Prim::Prim(Graph * graph)
{
	_graph = graph;
}
