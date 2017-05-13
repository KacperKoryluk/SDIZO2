#include "stdafx.h"
#include "Kruskal.h"

int findPrevious(int u, int *previous)	//Funkcja rekurencyjnie wyszukuj�ca poprzednika
{
	if (u != previous[u])
	{
		previous[u] = findPrevious(previous[u], previous);
	}

	return previous[u];
}

void Kruskal::execute()
{

	//Tablicowa(u�ywaj�c wektor�w)-------------------------------------------------------------------------------------------------------------------------
	int MSTWeight = 0; //waga
	int **tempMatrix = _graph->getGraphMatrix();

	typedef pair<int, int> neighbour;	//Para integer�w, podobnie jak w algorytmie prima, �atwiejsze sortowanie
	vector <pair<int, neighbour>> edges; //wektor par int i para integer�w, reprezentuje kraw�dzie <waga <wierzcho�ek u,wierzcho�ek v>>

	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisuj� graf do listy par <<int> <int,int>>. �atwiejsze sortowanie (domy�lnie po pierwszym elemencie - wadze.)
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			edges.push_back({ tempMatrix[i][j], {i,j} });
		}
	}

	sort(edges.begin(), edges.end()); //Sortuje kraw�dzie niemalej�co wed�ug wagi

	int *rank = new int[_graph->getVerticeAmount()+1];
	int *previous = new int[_graph->getVerticeAmount() + 1];;

	for (int i = 0; i <= _graph->getVerticeAmount(); i++)
	{
		rank[i] = 0; //Pocz�tkowo wszystkie wierzcho�ki maj� rang� 0 i s� w osobnych drzewach

		previous[i] = i; //Ka�dy element jest swoim poprzednikiem
	}

	vector <pair<int, neighbour>>::iterator i;

	for (i = edges.begin(); i != edges.end(); i++)
	{
		int u = i->second.first;	//Wybieram wierzcho�ki z pary neighbour <u,v>
		int v = i->second.second;

		int setU= findPrevious(u, previous);
		int setV = findPrevious(v, previous);

		if (setU != setV)	//Sprawdzam czy nie tworzy cyklu(u i v nie mog� nale�e� do tego samego setu)
		{
			cout << u << " -- " << v << " Waga: " << tempMatrix[u][v] << endl; 


			MSTWeight += i->first; //Zwi�kszam wag� ca�kowit� drzewa


			//Zestaw krok�w maj�cy na celu ��czenie poddrzew wed�ug rangi zawartej w tablicy rank
			setU = findPrevious(setU, previous);
			setV = findPrevious(setV, previous);

			if (rank[setU] > rank[setV])
			{
				previous[setV] = setU;
			}
			else if (rank[setU] <= rank[setV])
			{
				previous[setU] = setV;
			}

			if (rank[setU] == rank[setV])
			{
				rank[setV]++;
			}
		}

	}
	


	cout << "Waga ca�kowita: " << MSTWeight << endl;

	cout << "Kruskal executed" << endl;

	//Listowa-------------------------------------------------------------------------------------------------------------------------------------------
}

Kruskal::Kruskal()
{
}


Kruskal::~Kruskal()
{
}

Kruskal::Kruskal(Graph * graph)
{
	_graph = graph;
}
