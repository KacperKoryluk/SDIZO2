#pragma once
#include "Algorithm.h"
class Dijkstra :
	public Algorithm
{
public:
	void execute();
	Dijkstra();
	~Dijkstra();
	Dijkstra(Graph * graph);
};

