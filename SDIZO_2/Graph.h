#pragma once
#include "stdafx.h"

class Graph
{


private:
	
	int edgeAmount;
	int verticeAmount;
	int firstVertex;
	int lastVertex;
	int **_graphMatrix;
	
public:

	int getEdgeAmount();
	int getVerticeAmount();
	int getFirstVertex();
	int getLastVertex();
	int getWeight(int vertex1, int vertex2);
	
	bool loadFromFile(std::string fileName, bool isDirected);
	void printMatrix();
	void printList();
	Graph();
	~Graph();
	Graph(std::string fileName);

	
	
};


//Rzeczy które nie dzia³aj¹, ale kiedyœ bêd¹ musia³y
/*
list<Element> _graphList;

*/