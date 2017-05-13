#include "stdafx.h"
#include "Prim.h"

#define INF INT_MAX

void Prim::execute()	//Posprz¹taæ!
{
	struct CompareEdges
	{
		bool operator() ( Edge & left, Edge & right)
		{
			return left.getWeight()> right.getWeight();
		}
	};

	typedef pair<int, int> neighbour; //Definujê parê integerów jako s¹siada (³atwiejsza implementacja, pierwszy int to waga, drugi to wierzcho³ek, domyœlnie porównywany jest wed³ug pierwszego w kolejce priorytetowej)

	
	//Listowa
	int **tempMatrix = _graph->getGraphMatrix();
	vector <std::list<class Neighbour*>> *templist;
	Edge *tempEdge;
	


	list <pair<int, int>> *adjacencyList;
	adjacencyList = new list<neighbour>[_graph->getVerticeAmount()];
	

	int startingVertex = 0; //wierzcho³ek startowy algorytmu, zawsze 0

	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			int weight = tempMatrix[i][j];
			int vertice = j;
			if (tempMatrix[i][j] != INF)
			{
				adjacencyList[i].push_back(make_pair(weight, vertice));
			}
		}
	}




	


	vector <bool> visited(_graph->getVerticeAmount(), false); //Odwedzone wierzcho³ki, pocz¹tkowo ustawiam wszystkie na false
	vector<int> key(_graph->getVerticeAmount(), INF);	//Tu przechowujê poszczególne wagi, pocz¹tkowo int_max (umowna nieskoñczonoœæ)
	vector <int> previous(_graph->getVerticeAmount(), -1); //Tablica poprzedników, pocz¹tkowo ustawiona na -1
	
	priority_queue <neighbour, vector<neighbour>, greater<neighbour>> queue;
	queue.push(make_pair(0, startingVertex)); //Umieszczam pierwszy wierzcho³ek z wag¹ 0 w kolejce
	key[startingVertex] = 0; //Waga dotarcia do pierwszego wierzcho³ka wynosi 0


	

	while (!queue.empty())
	{
		int u = queue.top().second; //Druga liczba z pary - aktualny wierzcho³ek z góry kolejki
		queue.pop();
		visited[u] = true; //Wierzcho³ek odwiedzono

		list<neighbour>::iterator i;
		for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
		{
			int v = (*i).second;
			int weight = (*i).first;

			if (visited[v] == false && key[v] > weight)
			{
				key[v] = weight;
				queue.push(make_pair(key[v], v));
				previous[v] = u;
			}
		}
		



		
	}
	int totalWeight = 0;

	cout << "Zawarte krawedzie: " << endl;
	for (int i = 1; i < _graph->getVerticeAmount(); ++i)
	{
	
			totalWeight += key[i];
			cout << previous[i] << "--" << i << " Waga krawedzi: " << tempMatrix[i][previous[i]] <<endl;
		
	}
	cout << "Waga calkowita: " << totalWeight << endl;

	

	//Dodaæ kolejkê priorytetow¹ wierzcho³ków
	//Dalsza czêœæ algorytmu, dokoñczyæ



	cout << "Prim executed" << endl;



	
	

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


/*
//Œmietnik

for (int i = 0; i < _graph->getVerticeAmount(); i++)
{


for (int j = 0; j < _graph->getVerticeAmount(); j++)
{



int v = j;
int weight = _graph->getGraphMatrix()[i][j];

if (visited[v] == false && key[v] > weight)
{
key[v] = weight;
queue.push(make_pair(key[v], v));
previous[v] = u;

}
}
}


*/