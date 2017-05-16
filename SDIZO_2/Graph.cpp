#include "stdafx.h"
#include "Graph.h"
#define INF INT_MAX

int ** Graph::getGraphMatrix()
{
	return _graphMatrix;
}

int Graph::getEdgeAmount()
{
	return edgeAmount;
}

int Graph::getVerticeAmount()
{
	return verticeAmount;
}

int Graph::getFirstVertex()
{
	return firstVertex;
}

int Graph::getLastVertex()
{
	return lastVertex;
}

int Graph::getWeight(int vertex1, int vertex2)
{
	return _graphMatrix[vertex1][vertex2];
}

std::vector<std::list<class Neighbour*>> Graph::getList()
{
	return _graphList;
}

bool Graph::loadFromFile(string fileName, bool isDirected)
{
	//Macierz------------------------------------------------------------------------------------------------------------
	fstream file;
	file.open(fileName, ios::in);
	if (file.is_open())
	{
		if (file.fail())
		{
			return false;
		}
		file >> edgeAmount;
		file >> verticeAmount;
		file >> firstVertex;
		file >> lastVertex;
		_graphMatrix = new int *[verticeAmount];	//Przydzielam pamiêæ na wiersze
		for (int i = 0; i < verticeAmount; i++)
		{
			_graphMatrix[i] = new int[verticeAmount];
		}

		for (int i = 0; i < verticeAmount; i++)
		{
			for (int j = 0; j < verticeAmount; j++)
			{
				_graphMatrix[i][j] = INF;	//Wype³niam macierz umown¹ nieskoñczonoœci¹
				//Zmieniæ na int max lub int min
			}
		}

		int tempVertex1, tempVertex2, weight;	

		for (int i = 0; i < edgeAmount; i++)
		{
			
			
				file >> tempVertex1;
				file >> tempVertex2;
				file >> weight;

				if (file.fail())
				{
					return false;
				}
			
			_graphMatrix[tempVertex1][tempVertex2] = weight;
			
			if (!isDirected)
			{
				_graphMatrix[tempVertex2][tempVertex1] = weight;
			}

			tempVertex1 = 0; tempVertex2 = 0; weight = 0;
		}

		file.close();
		//Lista----------------------------------------------------------------------------------------------------
		file.open(fileName, ios::in);

		int edge[3]; //Informacje o krawêdzi do pêtli edge[0] - wierzcho³ek pocz¹tkowy, edge[1] - koñcowy, edge[2] - waga
		Neighbour *tempNeighbour; //Tymczasowy wierzcho³ek s¹siaduj¹cy umieszczany na liœcie

		if (file.is_open())
		{
			if (file.fail())
			{
				return false;
			}
			file >> edgeAmount;
			file >> verticeAmount;
			file >> firstVertex;
			file >> lastVertex;
			
			_graphList.resize(verticeAmount);

			for (int i = 0; i < edgeAmount; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					file >> edge[j];
				}
		
				tempNeighbour = new Neighbour(edge[2], edge[1]);
				_graphList[edge[0]].push_front(tempNeighbour);
			//	delete tempNeighbour;
				if (!isDirected)
				{
					tempNeighbour = new Neighbour(edge[2], edge[0]);
					_graphList[edge[1]].push_front(tempNeighbour);
					//delete tempNeighbour;
				}

			}

			 
			file.close();
		}



		return true;
	}
	else
	{
		cout << "Plik nie zostal otwarty, nastapi wyjscie do menu glownego." << endl;
		
	}
	return false;
}

void Graph::printMatrix()
{
	/*cout << "  ";
	for (int i = 0; i < verticeAmount; i++)
	{
		cout << " | " << i;
	}
	cout << " | " << endl;
	for (int i = 0; i < verticeAmount; i++)
	{
		cout << i << "|";
		for (int j = 0; j < verticeAmount; j++)
		{
			if (_graphMatrix[i][j]!=INF)
			{
				cout << " : " << _graphMatrix[i][j];
			}
			else cout << " : " << "-";
		}
		cout <<" : " << endl;
	}*/

	cout << setw(4) << "  ";
	for (int i = 0; i < verticeAmount; i++)
	{
		cout << setw(3) << " | " << setw(3) << i;
	}
	cout << setw(3) << " | " << endl;
	for (int i = 0; i < verticeAmount; i++)
	{
		cout << i << setw(3) << "|";
		for (int j = 0; j < verticeAmount; j++)
		{
			if (_graphMatrix[i][j] != 0 && _graphMatrix[i][j] != INF)
			{
				cout << setw(3) << " : " << setw(3) << _graphMatrix[i][j];
			}
			else cout << setw(3) << " : " << setw(3) << "---";
		}
		cout << setw(3) << " : " << endl;
	}
}

void Graph::printList()
{
	
	cout << " Wierzcholek:" << " S - Sasiad W - Waga." << endl;
	typename list<Neighbour*>::const_iterator j;
	for (int i = 0; i < verticeAmount; i++)
	{
		cout << i << ": ";
		list<Neighbour*>::iterator j;
		
		for (j = _graphList[i].begin(); j != _graphList[i].end();)
		{
			
			cout << *j << " || ";
			++j;
		}
		cout << endl;
	}
}

Graph::Graph()	
{
	verticeAmount = 0;
	firstVertex = 0;
	lastVertex = 0;
	edgeAmount = 0;
	_graphMatrix = nullptr;
}


Graph::~Graph() //Po dodaniu reprezentacji listowej
{
	for (int i = 0; i < verticeAmount; i++)	//Zwalnianie pamiêci zajêtej przez macierz
	{
		delete[] _graphMatrix[i];
	}
	delete[] _graphMatrix;
}

Graph::Graph(string fileName)
{
	
}
