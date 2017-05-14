#include "stdafx.h"
#include "Dijkstra.h"
#define INF INT_MAX

int findAndDisplayPrevious(int u, int v, int *previous)	//Funkcja rekurencyjnie wyszukuj¹ca poprzednika, jako argumenty otrzymuje wierzcho³ek i tablicê wierzcho³ków, w której ma szukaæ poprzednika
{
	//Zrobiæ funkcjê szukaj¹c¹ poprzedników
	
	return previous[u];
}

void Dijkstra::execute()
{

	int **tempMatrix = _graph->getGraphMatrix();
	//Listowa------------------------------------------------------------------------------------------------------------------------------
	typedef pair <int, int> neighbour;
	list <pair<int, int>> *adjacencyList;	//Lokalna lista na której wykonywany jest algorytm
	adjacencyList = new list<neighbour>[_graph->getVerticeAmount()];
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisujê graf do lokalnej listy par <int,int>. £atwiejsze sortowanie (domyœlnie po pierwszym elemencie - wadze.)
	{														//To ne jest czêœæ algorytmu
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
	vector<int> distance(_graph->getVerticeAmount(), INF); //wektor odleg³oœci, pocz¹tkowo ustawiony na umown¹ nieskoñczonoœæ
	queue.push(make_pair(0, startingVertex));	//Umieszczam wierzcho³ek pocz¹tkowy w kolejce
	distance[startingVertex] = 0;

	int *previous = new int[_graph->getVerticeAmount()];
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		previous[i] = -1;
	}
	previous[startingVertex] = startingVertex;
	
	while (!queue.empty())
	{
		int u = queue.top().second; //Wybieram wierzcho³ek z kolejki o najmniejszej wadze
		queue.pop();
		list<pair<int, int>>::iterator i;
		for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); i++)
		{
			int v = (*i).second;
			int weight = (*i).first;

			if (distance[v] > distance[u] + weight)	//Jeœli odleg³oœæ v od pocz¹tkowego wierzcho³ka jest wiêksza od odleg³oœci u + wadze krawêdzi do v, podmieniam.
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
	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//przywracam tablice do stanu pocz¹tkowego
	{
		previous[i] = -1;
		distance[i] = INF;
	}
	distance[startingVertex] = 0;
	previous[startingVertex] = startingVertex;
	queue.push(make_pair(0, startingVertex));

	while (!queue.empty())
	{
		int u = queue.top().second; //Wybieram wierzcho³ek z kolejki o najmniejszej wadze
		queue.pop();
		
		for (int i = 0; i < _graph->getVerticeAmount(); i++)
		{
			int v = i;
			int weight = tempMatrix[u][i];

			if (distance[v] > distance[u] + weight && distance[u] + weight > 0)	//Dodatkowy warunek, distance[u]+weight > 0, ¿eby wyeliminowaæ sytuacjê, gdzie MAX_INT po zwiêkszeniu staje siê liczb¹ ujemn¹ i psuje algorytm
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
