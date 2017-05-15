#include "stdafx.h"
#include "BellmanFord.h"
#define INF INT_MAX


void BellmanFord::execute()
{
	int **tempMatrix = _graph->getGraphMatrix();
	int *distance = new int[_graph->getVerticeAmount()];
	int *previous = new int[_graph->getVerticeAmount()];
	int startVertex = _graph->getFirstVertex();
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Wype³niam tablicê odleg³oœci od Ÿród³a oraz poprzedników
	{
		distance[i] = INF;
		previous[i] = -1;
	}
	distance[startVertex] = 0;
	previous[startVertex] = startVertex;

	//Listowa:---------------------------------------------------------------------------------------------------
	list<pair<int, pair<int, int>>> edges(_graph->getVerticeAmount()); //Lista krawêdzi, struktura <waga,<Ÿród³o,cel>>
	list<pair<int, pair<int, int>>>::iterator it;
	vector<pair<int, pair<int, int>>> edgesV(_graph->getVerticeAmount()); //Wektor krawêdzi
	vector<pair<int, pair<int, int>>>::iterator itV;
	bool test = true; //Czy wystapi³ ujemny cykl

	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			int weight = tempMatrix[i][j];
			
			if (weight != INF)
			{
				edges.push_back(make_pair(tempMatrix[i][j], make_pair(i, j))); //Wype³niam listê krawêdzi
				edgesV.push_back(make_pair(tempMatrix[i][j], make_pair(i, j))); //Wype³niam wektor krawêdzi
			}

		}
		
	}


	//Relaksacja wszystkich krawêdzi V-1 razy
	for (int i = 1; i < _graph->getVerticeAmount() - 1; i++)
	{
		for (it = edges.begin(); it != edges.end(); it++)
		{
			int u = (*it).second.first;
			int v = (*it).second.second;
			int weight = (*it).first;

			if (distance[v] > distance[u] + weight && distance[u] != INF)
			{
				distance[v] = distance[u] + weight;
				previous[v] = u;
			}
		}
	}
	
	for (int i = 1; i < _graph->getVerticeAmount() - 1; i++)
	{
		for (it = edges.begin(); it != edges.end(); it++)
		{
			int u = (*it).second.first;
			int v = (*it).second.second;
			int weight = (*it).first;

			if (distance[v] > distance[u] + weight && distance[u] != INF)
			{
				test = false;
				cout << "Wystapil ujemny cykl!" << endl;
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

		cout << "Tablica poprzednikow: " << endl;
		for (int i = 0; i < _graph->getVerticeAmount(); i++)
		{
			cout << "Wierzcholek: " << i << " Poprzednik: " << previous[i] << endl;
		}
	}
	//Macierzowo:------------------------------------------------------------------------------------------------------------------------------------------
	test = true; //Przywracam zmienn¹ test, ¿eby metoda macierzowa te¿ siê wykona³a w razie wyst¹pienia ujemnego cyklu w metodzie listowej
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przywracam tablicê odleg³oœci od Ÿród³a oraz poprzedników do stanu pocz¹tkowego
	{
		distance[i] = INF;
		previous[i] = -1;
	}
	distance[startVertex] = 0;
	previous[startVertex] = startVertex;
	for (int i = 1; i < _graph->getVerticeAmount() - 1; i++)
	{
		for (itV = edgesV.begin(); itV != edgesV.end(); itV++)
		{
			int u = (*itV).second.first;
			int v = (*itV).second.second;
			int weight = (*itV).first;

			if (distance[v] > distance[u] + weight && distance[u] != INF)
			{
				distance[v] = distance[u] + weight;
				previous[v] = u;
			}
		}
	}


	for (int i = 1; i < _graph->getVerticeAmount() - 1; i++)
	{
		for (itV = edgesV.begin(); itV != edgesV.end(); itV++)
		{
			int u = (*itV).second.first;
			int v = (*itV).second.second;
			int weight = (*itV).first;

			if (distance[v] > distance[u] + weight && distance[u] != INF)
			{
				test = false;
				cout << "Wystapil ujemny cykl!" << endl;
			}
		}
	}

	if (test)
	{
		cout << "Macierzowo: " << endl;
		for (int i = 0; i < _graph->getVerticeAmount(); i++)
		{
			cout << "Wierzcholek: " << i << " Odleglosc: " << distance[i] << endl;
		}

		cout << "Tablica poprzednikow: " << endl;
		for (int i = 0; i < _graph->getVerticeAmount(); i++)
		{
			cout << "Wierzcholek: " << i << " Poprzednik: " << previous[i] << endl;
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
