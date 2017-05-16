#include "stdafx.h"
#include "GraphGenerator.h"
#define INF INT_MAX

void GraphGenerator::generateGraph(int verticeAmount, float density, bool isDirected, int valueRange, int startValue, string fileName, int endVertice)
{
	//argumenty:(ilo�� wierzcho�k�w, g�sto�� grafu, czy jest skierowany, zasi�g warto�ci, warto�� pocz�tkowa od kt�rej liczymy zasi�g warto�ci, nazwa pliku, wierzcho�ek ko�cowy)
	srand(time(NULL));
	/*
	Generator wybiera wierzcho�ek z wektora wierzcho�k�w "wolnych"(freeVertice) i umieszcza go w wektorze "po��czonych"(connectedVertice). 
	P�niej wybiera losowy wierzcho�ek z wektora "po��czonych" i losowy z "wolnych",
	odwzorowuje kraw�d� w macierzy i przerzuca wierzcho�ek z "wolnych" do "po��czonych". 
	Jak sko�cz� si� "wolne" wierzcho�ki to powstaje drzewo, nast�pnie w macierzy s�siedztwa przypisywane s� wagi do losowych kraw�dzi
	a� do osi�gni�cia po��danej ilo�ci.
	
	*/
		vector<int> connectedVertice(0);	//Wierzcho�ki po��czone
		vector<int> freeVertice(verticeAmount); //Wierzcho�ki niepo��czone
		int** graphMatrix = new int*[verticeAmount];

		for (int i = 0; i < verticeAmount; i++)
		{
			freeVertice[i] = i;
			graphMatrix[i] = new int[verticeAmount];
			for (int j = 0; j < verticeAmount; j++)
				graphMatrix[i][j] = INF;
		}

		int v1;
		int v2;
		int value;
		int counter = 0;
		float wanted = (density / 100)*(verticeAmount * verticeAmount);
		int begin = 0;

		v1 = (rand() % freeVertice.size()) + 0;
		connectedVertice.push_back(freeVertice[v1]);
		begin = freeVertice[v1];
		freeVertice.erase(freeVertice.begin() + v1);


		while (freeVertice.size() != 0)
		{
			v1 = (rand() % connectedVertice.size()) + 0;
			v2 = (rand() % freeVertice.size()) + 0;
			value = (rand() % valueRange) + startValue;
			if (isDirected == false)
			{
				graphMatrix[freeVertice[v2]][connectedVertice[v1]] = value;
				counter++;
			}
			graphMatrix[connectedVertice[v1]][freeVertice[v2]] = value;
			counter++;
			connectedVertice.push_back(freeVertice[v2]);
			freeVertice.erase(freeVertice.begin() + v2);

		}
		if (wanted > (verticeAmount*verticeAmount) - verticeAmount)
			wanted = (verticeAmount*verticeAmount) - verticeAmount;
		while (counter < wanted)
		{
			value = (rand() % valueRange) + startValue;
			v1 = (rand() % verticeAmount) + 0;
			v2 = (rand() % verticeAmount) + 0;

			if (v2 != v1 && graphMatrix[connectedVertice[v1]][connectedVertice[v2]] == INF && value != 0)
			{
				if (isDirected == false)
				{
					graphMatrix[connectedVertice[v2]][connectedVertice[v1]] = value;
					counter++;
				}
				graphMatrix[connectedVertice[v1]][connectedVertice[v2]] = value;
				counter++;
			}

		}


		
		string buffer;
		buffer.append(fileName);
		buffer.append(".txt");
		ofstream graph_file;
		graph_file.open(buffer);


		if (isDirected == true)
		{
			graph_file << counter << " " << verticeAmount << " " << begin << " " << endVertice << "\n";
			for (int i = 0; i < verticeAmount; i++)
				for (int j = 0; j < verticeAmount; j++)
					if (graphMatrix[i][j] != INF)
						graph_file << i << " " << j << " " << graphMatrix[i][j] << "\n";
		}
		else
		{
			int j = 0;
			int k = 0;
			counter = counter / 2;
			graph_file << counter << " " << verticeAmount << " " << begin << " " << endVertice << "\n";
			for (int i = 0; i < verticeAmount; i++)
			{
				for (j = 0 + k; j < verticeAmount; j++)
					if (graphMatrix[i][j] != INF)
					{
						graph_file << i << " " << j << " " << graphMatrix[i][j] << "\n";

					}
				k++;
			}

		}

		graph_file.close();

		cout << "Otrzymany graf: " << endl << endl;
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
				if (graphMatrix[i][j] != INF)
				{
					cout << setw(3) << " : " << setw(3) << graphMatrix[i][j];
				}
				else cout << setw(3) << " : " << setw(3) << "---";
			}
			cout << setw(3) << " : " << endl;
		}
		
}

GraphGenerator::GraphGenerator()
{
}
