#include "stdafx.h"
#include "Kruskal.h"

int findPrevious(int u, int *previous)	//Funkcja rekurencyjnie wyszukuj�ca poprzednika, jako argumenty otrzymuje wierzcho�ek i tablic� wierzcho�k�w, w kt�rej ma szuka� poprzednika
{
	if (u != previous[u])	//Je�li wierzcho�ek nie jest pocz�tkowym danego poddrzewa
	{
		previous[u] = findPrevious(previous[u], previous);
	}

	return previous[u];
}

bool compareVector(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first < b.first; } //Do sortowania
void Kruskal::execute()
{

	//Listowa(u�ywaj�c wektor�w)-------------------------------------------------------------------------------------------------------------------------
	int MSTWeight = 0; //waga
	int **tempMatrix = _graph->getGraphMatrix();


	cout << "Listowa. Zawarte kraw�dzie:" << endl;
	typedef pair<int, int> neighbour;	//Para integer�w, podobnie jak w algorytmie prima, �atwiejsze sortowanie
	list <pair<int, neighbour>> edges; //Lista par int i para integer�w, reprezentuje kraw�dzie <waga <wierzcho�ek u,wierzcho�ek v>>

	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisuj� graf do lokalnej listy par <<int> <int,int>>. �atwiejsze sortowanie (domy�lnie po pierwszym elemencie pary - wadze.)
	{														//To nie jest cz�� algorytmu
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			edges.push_back({ tempMatrix[i][j], {i,j} });
		}
	}


	edges.sort();	//Sortuje kraw�dzie wed�ug wagi, rosn�co
	

	int *rank = new int[_graph->getVerticeAmount()+1];	//Tablica rang
	int *previous = new int[_graph->getVerticeAmount() + 1]; //Tablica poprzednik�w

	for (int i = 0; i <= _graph->getVerticeAmount(); i++)
	{
		rank[i] = 0; //Pocz�tkowo wszystkie wierzcho�ki maj� rang� 0 i s� w osobnych drzewach

		previous[i] = i; //Ka�dy element pocz�tkowych jednoelementowych poddrzew jest swoim poprzednikiem
	}

	list <pair<int, neighbour>>::iterator i;

	for (i = edges.begin(); i != edges.end(); i++)
	{
		int u = i->second.first;	//Wybieram wierzcho�ki z pary neighbour <u,v>
		int v = i->second.second;

		int setU= findPrevious(u, previous);
		int setV = findPrevious(v, previous);

		if (setU != setV)	//Sprawdzam czy nie tworzy cyklu(u i v nie mog� nale�e� do tego samego setu)
		{
			cout << u << " -- " << v << " Waga: " << tempMatrix[u][v] << endl; //Operacja wy�wietlania jest nieistotna dla samego algorytmu, dlatego korzysta z macierzy do wy�wietlenia wagi


			MSTWeight += i->first; //Zwi�kszam wag� ca�kowit� drzewa


			//Zestaw krok�w maj�cy na celu ��czenie poddrzew wed�ug rangi zawartej w tablicy rang
			setU = findPrevious(setU, previous);
			setV = findPrevious(setV, previous);

			if (rank[setU] > rank[setV])
			{
				previous[setV] = setU;	//Je�li ranga setU jest wi�ksza od rangi setV, setU staje si� poprzednikiem setV
			}
			else if (rank[setU] <= rank[setV])
			{
				previous[setU] = setV;	
			}

			if (rank[setU] == rank[setV])
			{
				rank[setV]++;	//Je�li rangi s� r�wne inkrementuj� rang� setV
			}
		}

	}
	


	cout << "Waga calkowita: " << MSTWeight << endl;

	

	//Macierzowa-------------------------------------------------------------------------------------------------------------------------------------------
	

	cout << "Macierzowa. Zawarte kraw�dzie:" << endl;
	for (int i = 0; i <= _graph->getVerticeAmount(); i++)	//Przywracam tablice rang i poprzednik�w do stanu pocz�tkowego
	{
		rank[i] = 0; 

		previous[i] = i; 
	}

	MSTWeight = 0;

	vector <pair<int, neighbour>> edgesV; //Lista par int i para integer�w, reprezentuje kraw�dzie <waga <wierzcho�ek u,wierzcho�ek v>>

	for (int i = 0; i < _graph->getVerticeAmount(); i++)	//Przepisuj� graf do lokalnej listy par <<int> <int,int>>. �atwiejsze sortowanie (domy�lnie po pierwszym elemencie pary - wadze.)
	{														//To nie jest cz�� algorytmu
		for (int j = 0; j < _graph->getVerticeAmount(); j++)
		{
			edgesV.push_back({ tempMatrix[i][j],{ i,j } });
		}
	}
	
	sort(edgesV.begin(), edgesV.end(), compareVector);	//Sortowanie kraw�dzi w wektorze =, biblioteka algorithm, funkcja sortuj�ca 14 linia tego pliku

	for (int i = 0; i < edgesV.size(); i++)
	{
		int u = edgesV[i].second.first;	//Wybieram wierzcho�ki z pary neighbour <u,v>
		int v = edgesV[i].second.second;

		int setU = findPrevious(u, previous);
		int setV = findPrevious(v, previous);

		if (setU != setV)	//Sprawdzam czy nie tworzy cyklu(u i v nie mog� nale�e� do tego samego setu)
		{
			cout << u << " -- " << v << " Waga: " << tempMatrix[u][v] << endl;


			MSTWeight += edgesV[i].first; //Zwi�kszam wag� ca�kowit� drzewa


								   //Zestaw krok�w maj�cy na celu ��czenie poddrzew wed�ug rangi zawartej w tablicy rang
			setU = findPrevious(setU, previous);
			setV = findPrevious(setV, previous);

			if (rank[setU] > rank[setV])
			{
				previous[setV] = setU;	//Je�li ranga setU jest wi�ksza od rangi setV, setU staje si� poprzednikiem setV
			}
			else if (rank[setU] <= rank[setV])
			{
				previous[setU] = setV;
			}

			if (rank[setU] == rank[setV])
			{
				rank[setV]++;	//Je�li rangi s� r�wne inkrementuj� rang� setV
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


