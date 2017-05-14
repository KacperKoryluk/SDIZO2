#include "stdafx.h"
#include "Dijkstra.h"
#define INF INT_MAX

int findAndDisplayPrevious(int u, int v, int *previous)	//Funkcja rekurencyjnie wyszukuj�ca poprzednika, jako argumenty otrzymuje wierzcho�ek i tablic� wierzcho�k�w, w kt�rej ma szuka� poprzednika
{
	//Zrobi� funkcj� szukaj�c� poprzednik�w
	
	return previous[u];
}

void Dijkstra::execute()
{

	int **tempMatrix = _graph->getGraphMatrix();
	//Listowa------------------------------------------------------------------------------------------------------------------------------
	typedef pair <int, int> neighbour;
	list <pair<int, int>> *adjacencyList;	//Lokalna lista na kt�rej wykonywany jest algorytm
	adjacencyList = new list<neighbour>[_graph->getVerticeAmount()];
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisuj� graf do lokalnej listy par <int,int>. �atwiejsze sortowanie (domy�lnie po pierwszym elemencie - wadze.)
	{														//To ne jest cz�� algorytmu
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

	int startingVertex = _graph->getFirstVertex();
	priority_queue <neighbour, vector<neighbour>, greater<neighbour>> queue;
	vector<int> distance(_graph->getVerticeAmount(), INF); //wektor odleg�o�ci, pocz�tkowo ustawiony na umown� niesko�czono��
	queue.push(make_pair(0, startingVertex));	//Umieszczam wierzcho�ek pocz�tkowy w kolejce
	distance[startingVertex] = 0;

	int *previous = new int[_graph->getVerticeAmount()];
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		previous[i] = -1;
	}
	previous[startingVertex] = startingVertex;
	
	while (!queue.empty())
	{
		int u = queue.top().second; //Wybieram wierzcho�ek z kolejki o najmniejszej wadze
		queue.pop();
		list<pair<int, int>>::iterator i;
		for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); i++)
		{
			int v = (*i).second;
			int weight = (*i).first;

			if (distance[v] > distance[u] + weight)	//Je�li odleg�o�� v od pocz�tkowego wierzcho�ka jest wi�ksza od odleg�o�ci u + wadze kraw�dzi do v, podmieniam.
			{
				distance[v] = distance[u] + weight;
				queue.push(make_pair(distance[v], v));
				previous[v] = u;
			}

		}
	}
	cout << "Listowo: " << endl;
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		cout << "Wierzcholek: " << i << " Odleglosc: " << distance[i] << " Droga: " << endl;
	}
	
	cout << "Tablica poprzednikow: " << endl;
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		cout << "Wierzcholek: " << i << " Poprzednik: " << previous[i] << endl;
	}
	

	//Macierzowa---------------------------------------------------------------------------------------------------------------------------------
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//przywracam tablice do stanu pocz�tkowego
	{
		previous[i] = -1;
		distance[i] = INF;
	}
	distance[startingVertex] = 0;
	previous[startingVertex] = startingVertex;
	queue.push(make_pair(0, startingVertex));

	while (!queue.empty())
	{
		int u = queue.top().second; //Wybieram wierzcho�ek z kolejki o najmniejszej wadze
		queue.pop();
		
		for (int i = 0; i < _graph->getVerticeAmount(); i++)
		{
			int v = i;
			int weight = tempMatrix[u][i];

			if (distance[v] > distance[u] + weight && distance[u] + weight > 0)	//Dodatkowy warunek, distance[u]+weight > 0, �eby wyeliminowa� sytuacj�, gdzie MAX_INT po zwi�kszeniu staje si� liczb� ujemn� i psuje algorytm
			{
				distance[v] = distance[u] + weight;
				queue.push(make_pair(distance[v], v));
				previous[v] = u;
			}
		}
	}

	cout << "Macierzowo: " << endl;
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		cout << "Wierzcholek: " << i << " Odleglosc: " << distance[i] << " Droga: " << endl;
	}

	cout << "Tablica poprzednikow: " << endl;
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		cout << "Wierzcholek: " << i << " Poprzednik: " << previous[i] << endl;
	}


	delete[] adjacencyList;
	delete[] previous;
	cout << "Dijkstra executed" << endl;
}

Dijkstra::Dijkstra()
{
}


Dijkstra::~Dijkstra()
{
}

Dijkstra::Dijkstra(Graph * graph)
{
	_graph = graph;
}
