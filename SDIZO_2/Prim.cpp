#include "stdafx.h"
#include "Prim.h"


void Prim::execute()	//Posprz�ta�!
{
	struct Edge	//Kraw�d�
	{
		int vertice1, vertice2, weight;
	};
	
	//Tu wstawi� priority queue z uporz�dkowanymi malej�co wagami.

	bool *visited = new bool[_graph->getVerticeAmount()];	//Tablica logiczna, zawiera informacj� czy dany element by� odwiedzony
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		visited[i] = false;	//Przed rozpocz�ciem algorytmu nie odwiedzi�em �adnego wierzcho�ka, ustawiam na false
	}


	vector <Edge> *tree = new vector<Edge>;	//Drzewo rozpinaj�ce

	//Doda� kolejk� priorytetow� wierzcho�k�w
	//Dalsza cz�� algorytmu, doko�czy�



	cout << "Prim executed" << endl;



	delete[] visited;
	delete tree;

}

Prim::Prim()
{
}


Prim::~Prim()
{
}

Prim::Prim(Graph * graph)
{
	_graph = graph;
}
