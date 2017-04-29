#pragma once
#include "Algorithm.h"
class BellmanFord :
	public Algorithm
{
public:
	void execute();
	BellmanFord();
	~BellmanFord();
	BellmanFord(Graph * graph);
};

