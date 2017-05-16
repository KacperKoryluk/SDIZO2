#include "stdafx.h"
#include "Kruskal.h"

int findPrevious(int u, int *previous)	//Funkcja rekurencyjnie wyszukuj¹ca poprzednika, jako argumenty otrzymuje wierzcho³ek i tablicê wierzcho³ków, w której ma szukaæ poprzednika
{
	if (u != previous[u])	//Jeœli wierzcho³ek nie jest pocz¹tkowym danego poddrzewa
	{
		previous[u] = findPrevious(previous[u], previous);
	}

	return previous[u];
}

bool compareVector(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first < b.first; } //Do sortowania
void Kruskal::execute()
{

	//Listowa(u¿ywaj¹c wektorów)-------------------------------------------------------------------------------------------------------------------------
	int MSTWeight = 0; //waga
	int **tempMatrix = _graph->getGraphMatrix();


	cout << "Listowa. Zawarte krawêdzie:" << endl;
	typedef pair<int, int> neighbour;	//Para integerów, podobnie jak w algorytmie prima, ³atwiejsze sortowanie
	list <pair<int, neighbour>> edges; //Lista par int i para integerów, reprezentuje krawêdzie <waga <wierzcho³ek u,wierzcho³ek v>>

	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisujê graf do lokalnej listy par <<int> <int,int>>. £atwiejsze sortowanie (domyœlnie po pierwszym elemencie pary - wadze.)
	{														//To nie jest czêœæ algorytmu
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			edges.push_back({ tempMatrix[i][j], {i,j} });
		}
	}


	edges.sort();	//Sortuje krawêdzie wed³ug wagi, rosn¹co
	

	int *rank = new int[_graph->getVerticeAmount()+1];	//Tablica rang
	int *previous = new int[_graph->getVerticeAmount() + 1]; //Tablica poprzedników

	for (int i = 0; i <= _graph->getVerticeAmount(); i++)
	{
		rank[i] = 0; //Pocz¹tkowo wszystkie wierzcho³ki maj¹ rangê 0 i s¹ w osobnych drzewach

		previous[i] = i; //Ka¿dy element pocz¹tkowych jednoelementowych poddrzew jest swoim poprzednikiem
	}

	list <pair<int, neighbour>>::iterator i;

	for (i = edges.begin(); i != edges.end(); i++)
	{
		int u = i->second.first;	//Wybieram wierzcho³ki z pary neighbour <u,v>
		int v = i->second.second;

		int setU= findPrevious(u, previous);
		int setV = findPrevious(v, previous);

		if (setU != setV)	//Sprawdzam czy nie tworzy cyklu(u i v nie mog¹ nale¿eæ do tego samego setu)
		{
			cout << u << " -- " << v << " Waga: " << tempMatrix[u][v] << endl; //Operacja wyœwietlania jest nieistotna dla samego algorytmu, dlatego korzysta z macierzy do wyœwietlenia wagi


			MSTWeight += i->first; //Zwiêkszam wagê ca³kowit¹ drzewa


			//Zestaw kroków maj¹cy na celu ³¹czenie poddrzew wed³ug rangi zawartej w tablicy rang
			setU = findPrevious(setU, previous);
			setV = findPrevious(setV, previous);

			if (rank[setU] > rank[setV])
			{
				previous[setV] = setU;	//Jeœli ranga setU jest wiêksza od rangi setV, setU staje siê poprzednikiem setV
			}
			else if (rank[setU] <= rank[setV])
			{
				previous[setU] = setV;	
			}

			if (rank[setU] == rank[setV])
			{
				rank[setV]++;	//Jeœli rangi s¹ równe inkrementujê rangê setV
			}
		}

	}
	


	cout << "Waga calkowita: " << MSTWeight << endl;

	

	//Macierzowa-------------------------------------------------------------------------------------------------------------------------------------------
	

	cout << "Macierzowa. Zawarte krawêdzie:" << endl;
	for (int i = 0; i <= _graph->getVerticeAmount(); i++)	//Przywracam tablice rang i poprzedników do stanu pocz¹tkowego
	{
		rank[i] = 0; 

		previous[i] = i; 
	}

	MSTWeight = 0;

	vector <pair<int, neighbour>> edgesV; //Lista par int i para integerów, reprezentuje krawêdzie <waga <wierzcho³ek u,wierzcho³ek v>>

	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisujê graf do lokalnej listy par <<int> <int,int>>. £atwiejsze sortowanie (domyœlnie po pierwszym elemencie pary - wadze.)
	{														//To nie jest czêœæ algorytmu
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			edgesV.push_back({ tempMatrix[i][j],{ i,j } });
		}
	}
	
	sort(edgesV.begin(), edgesV.end(), compareVector);	//Sortowanie krawêdzi w wektorze =, biblioteka algorithm, funkcja sortuj¹ca 14 linia tego pliku

	for (int i = 0; i < edgesV.size(); i++)
	{
		int u = edgesV[i].second.first;	//Wybieram wierzcho³ki z pary neighbour <u,v>
		int v = edgesV[i].second.second;

		int setU = findPrevious(u, previous);
		int setV = findPrevious(v, previous);

		if (setU != setV)	//Sprawdzam czy nie tworzy cyklu(u i v nie mog¹ nale¿eæ do tego samego setu)
		{
			cout << u << " -- " << v << " Waga: " << tempMatrix[u][v] << endl;


			MSTWeight += edgesV[i].first; //Zwiêkszam wagê ca³kowit¹ drzewa


								   //Zestaw kroków maj¹cy na celu ³¹czenie poddrzew wed³ug rangi zawartej w tablicy rang
			setU = findPrevious(setU, previous);
			setV = findPrevious(setV, previous);

			if (rank[setU] > rank[setV])
			{
				previous[setV] = setU;	//Jeœli ranga setU jest wiêksza od rangi setV, setU staje siê poprzednikiem setV
			}
			else if (rank[setU] <= rank[setV])
			{
				previous[setU] = setV;
			}

			if (rank[setU] == rank[setV])
			{
				rank[setV]++;	//Jeœli rangi s¹ równe inkrementujê rangê setV
			}
		}

	}

	cout << "Waga calkowita: " << MSTWeight << endl;

	delete[] rank;
	delete[] previous;

	cout << "Kruskal executed" << endl;
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


