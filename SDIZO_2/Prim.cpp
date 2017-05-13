#include "stdafx.h"
#include "Prim.h"

#define INF INT_MAX

void Prim::execute()	//Posprz�ta�!
{
	struct CompareEdges
	{
		bool operator() ( Edge & left, Edge & right)
		{
			return left.getWeight()> right.getWeight();
		}
	};

	typedef pair<int, int> neighbour; //Definuj� par� integer�w jako s�siada (�atwiejsza implementacja, pierwszy int to waga, drugi to wierzcho�ek, domy�lnie por�wnywany jest wed�ug pierwszego w kolejce priorytetowej)

	
	//Listowa---------------------------------------------------------------------------------------------------------------------------------
	int **tempMatrix = _graph->getGraphMatrix();
	vector <std::list<class Neighbour*>> *templist;
	Edge *tempEdge;
	


	list <pair<int, int>> *adjacencyList;
	adjacencyList = new list<neighbour>[_graph->getVerticeAmount()];
	

	int startingVertex = 0; //wierzcho�ek startowy algorytmu, zawsze 0

	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisuj� graf do listy par <int,int>. �atwiejsze sortowanie (domy�lnie po pierwszym elemencie - wadze.)
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




	


	vector <bool> visited(_graph->getVerticeAmount(), false); //Odwedzone wierzcho�ki, pocz�tkowo ustawiam wszystkie na false
	vector<int> key(_graph->getVerticeAmount(), INF);	//Tu przechowuj� poszczeg�lne wagi, pocz�tkowo int_max (umowna niesko�czono��)
	vector <int> previous(_graph->getVerticeAmount(), -1); //Tablica poprzednik�w, pocz�tkowo ustawiona na -1
	
	priority_queue <neighbour, vector<neighbour>, greater<neighbour>> queue;
	queue.push(make_pair(0, startingVertex)); //Umieszczam pierwszy wierzcho�ek z wag� 0 w kolejce
	key[startingVertex] = 0; //Waga dotarcia do pierwszego wierzcho�ka wynosi 0


	

	while (!queue.empty())
	{
		int u = queue.top().second; //Druga liczba z pary - aktualny wierzcho�ek z g�ry kolejki
		queue.pop();
		visited[u] = true; //Wierzcho�ek odwiedzono

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

	cout << "Listowa. Zawarte krawedzie: " << endl;
	for (int i = 1; i < _graph->getVerticeAmount(); ++i)
	{
	
			totalWeight += key[i];
			cout << previous[i] << "--" << i << " Waga krawedzi: " << tempMatrix[i][previous[i]] <<endl;
		
	}
	cout << "Waga calkowita: " << totalWeight << endl;

	

	//Macierzowa:------------------------------------------------------------------------------------------------------------------------------------------
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przywracam tablice do stanu pocz�tkowego
	{
		visited[i] = false;
	}
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		previous[i] = -1;
	}
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		key[i] = INF;
	}
	totalWeight = 0;
	queue.push(make_pair(0, startingVertex)); //Umieszczam pierwszy wierzcho�ek z wag� 0 w kolejce
	key[startingVertex] = 0; //Waga dotarcia do pierwszego wierzcho�ka wynosi 0

	
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			
			int weight = tempMatrix[i][j];
			int v = j;

			if (visited[v] == false && key[v] > weight)
			{
				key[v] = weight;
				queue.push(make_pair(key[v], v));
				previous[v] = i;
			}
		}
	}



	cout << "Macierzowa. Zawarte krawedzie: " << endl;
	for (int i = 1; i < _graph->getVerticeAmount(); ++i)
	{

		totalWeight += key[i];
		cout << previous[i] << "--" << i << " Waga krawedzi: " << tempMatrix[i][previous[i]] << endl;

	}
	cout << "Waga calkowita: " << totalWeight << endl;
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


