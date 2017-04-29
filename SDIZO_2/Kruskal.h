#pragma once
#include "Algorithm.h"
class Kruskal :
	public Algorithm
{
public:
	void execute();
	Kruskal();
	~Kruskal();
	Kruskal(Graph * graph);
};

