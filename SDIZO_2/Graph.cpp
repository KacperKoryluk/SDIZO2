#include "stdafx.h"
#include "Graph.h"


bool Graph::loadFromFile(string fileName)
{
	
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
				_graphMatrix[i][j] = 0;	//Wype³niam macierz zerami
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
			tempVertex1 = 0; tempVertex2 = 0; weight = 0;
		}

		



		file.close();
		return true;
	}
	else
	{
		cout << "Plik nie zostal otwarty, nastapi wyjscie z programu" << endl;
		
	}
	return false;
}

void Graph::printMatrix()
{
	for (int i = 0; i < verticeAmount; i++)
	{
		for (int j = 0; j < verticeAmount; j++)
		{
			cout << _graphMatrix[i][j] << " : ";
		}
		cout << endl;
	}
}

Graph::Graph()
{
}


Graph::~Graph()
{
}

Graph::Graph(string fileName)
{
	
}
