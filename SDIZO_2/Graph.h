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
	bool loadFromFile(std::string fileName);
	void printMatrix();
	void printList();
	Graph();
	~Graph();
	Graph(std::string fileName);
};



/*
class Element
{
public:
int weight;
int vertice;
};
list <Element> _graphList;
*/