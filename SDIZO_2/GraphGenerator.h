#pragma once
#include "stdafx.h"
class GraphGenerator
{
public:
	void generateGraph(int verticeAmount, float density, bool isDirected, int valueRange, int start, std::string fileName, int startVertice);
	GraphGenerator();
};

