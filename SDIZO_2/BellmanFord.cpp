#include "stdafx.h"
#include "BellmanFord.h"
#define INF INT_MAX


void BellmanFord::execute()
{
	int **tempMatrix = _graph->getGraphMatrix();
	int *distance = new int[_graph->getVerticeAmount()];
	int *previous = new int[_graph->getVerticeAmount()];
	int startVertex = _graph->getFirstVertex();
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Wype�niam tablic� odleg�o�ci od �r�d�a oraz poprzednik�w
	{
		distance[i] = INF;
		previous[i] = -1;
	}
	distance[startVertex] = 0;
	

	//Listowa:---------------------------------------------------------------------------------------------------
	vector <list <pair<int, int>>> adjacencyList(_graph->getVerticeAmount()); //Lokalny wektor list <waga, wierzcho�ek ko�cowy>
	list<pair<int, pair<int, int>>> edges(_graph->getVerticeAmount()); //Lista kraw�dzi, struktura <waga,<�r�d�o,cel>>
	list <pair<int, int>>::iterator it;
	
	bool test = true; //Czy wystapi� ujemny cykl

	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			int weight = tempMatrix[i][j];
			
			if (weight != INF)
			{
				adjacencyList[i].push_back(make_pair(weight, j));	//Wype�niam lokalny wektor list
				edges.push_back(make_pair(tempMatrix[i][j], make_pair(i, j))); //Wype�niam list� kraw�dzi
			}

		}
		
	}


	//Relaksacja wszystkich kraw�dzi V-1 razy
	
	for (int i = 0; i < _graph->getVerticeAmount() - 1; i++) //Wykonujemy relaksacj� ilo�� wierzcho�k�w - 1 razy
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)	//Do poprawy
		{
			for (it = adjacencyList[j].begin(); it != adjacencyList[j].end(); it++)
			{
				if (distance[j] > (*it).first + distance[(*it).second] && (*it).first + distance[(*it).second] > 0)
				{

					distance[j] = (*it).first + distance[(*it).second];
					previous[j] = (*it).second;
				}
			}
		}
			
	}
	

	for (int i = 0; i < _graph->getVerticeAmount() - 1; i++) //Wykonujemy relaksacj� ilo�� wierzcho�k�w - 1 razy
	{
		
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			for (it = adjacencyList[j].begin(); it != adjacencyList[j].end(); it++)
			{
				if (distance[j] >(*it).first + distance[(*it).second] && (*it).first + distance[(*it).second] > 0)
				{

					test = false;
					cout << "Ujemny cykl. Blad!" << endl;
				}
			}
		}

	}

	if (test)
	{
		cout << "Listowo: " << endl;
		for (int i = 0; i < _graph->getVerticeAmount(); i++)
		{
			cout << "Wierzcholek: " << i << " Odleglosc: " << distance[i] << endl;
		}
	}
	



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
