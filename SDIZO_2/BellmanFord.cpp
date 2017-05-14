#include "stdafx.h"
#include "BellmanFord.h"
#define INF INT_MAX


void BellmanFord::execute()
{
	int **tempMatrix = _graph->getGraphMatrix();
	int *distance = new int[_graph->getVerticeAmount()];

	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		distance[i] = INF;
	}
	distance[_graph->getFirstVertex()] = 0;


	//Listowa:---------------------------------------------------------------------------------------------------
	vector <list <pair<int, int>>> adjacencyList(_graph->getVerticeAmount()); //Wektor list <waga, wierzcho³ek koñcowy>

	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			int weight = tempMatrix[i][j];
			
			if (weight != INF)
			{
				adjacencyList[i].push_back(make_pair(weight, j));	//Wype³niam lokalny wektor list
			}

		}
		
	}





	//Relaksacja wszystkich krawêdzi V-1 razy

	



	cout << "BellmanFord executed" << endl;
}

BellmanFord::BellmanFord()
{
}


BellmanFord::~BellmanFord()
{
}

BellmanFord::BellmanFord(Graph * graph)
{
	_graph = graph;
}
