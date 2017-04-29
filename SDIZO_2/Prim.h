#pragma once
#include "Algorithm.h"
class Prim :
	public Algorithm
{
private:

public:
	void execute();
	Prim();
	~Prim();
	Prim(Graph * graph);
};

