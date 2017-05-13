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
	//Dodaæ reprezentacjê listow¹ grafu
	std::vector<std::list<class Neighbour*>> _graphList;
	
	 
	
public:
	int** getGraphMatrix();
	int getEdgeAmount();
	int getVerticeAmount();
	int getFirstVertex();
	int getLastVertex();
	int getWeight(int vertex1, int vertex2);
	std::vector<std::list<class Neighbour*>> getList();
	
	bool loadFromFile(std::string fileName, bool isDirected);
	void printMatrix();
	void printList();
	Graph();
	~Graph();
	Graph(std::string fileName);

	
	
};


