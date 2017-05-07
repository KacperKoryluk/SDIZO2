#include "stdafx.h"
#include "Prim.h"


void Prim::execute()	//Posprz¹taæ!
{
	struct Edge	//KrawêdŸ
	{
		int vertice1, vertice2, weight;
	};
	
	//Tu wstawiæ priority queue z uporz¹dkowanymi malej¹co wagami.

	bool *visited = new bool[_graph->getVerticeAmount()];	//Tablica logiczna, zawiera informacjê czy dany element by³ odwiedzony
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		visited[i] = false;	//Przed rozpoczêciem algorytmu nie odwiedzi³em ¿adnego wierzcho³ka, ustawiam na false
	}


	vector <Edge> *tree = new vector<Edge>;	//Drzewo rozpinaj¹ce

	//Dodaæ kolejkê priorytetow¹ wierzcho³ków
	//Dalsza czêœæ algorytmu, dokoñczyæ



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
