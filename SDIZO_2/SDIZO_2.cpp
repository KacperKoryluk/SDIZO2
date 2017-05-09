// SDIZO_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


Algorithm * _currentAlgorithm;
Graph * graph;



void mstMenu()	//Menu minimalnego drzewa rozpinaj�cego, wyb�r mi�dzy algorytmem Kruskala i Prima
{
	cout << "Menu  MST:" << endl
		<< "1 - Wykonaj algorytm Kruskala i wyswietl wyniki" << endl
		<< "2 - Wykonaj algorytm Prima i wyswietl wyniki" << endl
		<< "m - reprezentacja macierzowa grafu" << endl
		<< "l - reprezentacja listowa grafu" << endl
		<< "c - wyczysc ekran" << endl;


	char decision;
	do
	{
		
		decision = _getch();
		switch (decision)
		{
		case '1':
			_currentAlgorithm = new Kruskal(graph);
			_currentAlgorithm->execute();
			delete _currentAlgorithm;
			break;
		case '2':
			_currentAlgorithm = new Prim(graph);
			_currentAlgorithm->execute();
			delete _currentAlgorithm;
			break;
		case 'm':
			cout << "Reprezentacja macierzowa: " << endl;
			graph->printMatrix();
			break;
		case 'l':
			cout << "Reprezentacja listowa: " << endl;
			graph->printList();
			break;
		case 'c':
			system("cls");
			cout << "Menu  MST:" << endl
				<< "1 - Wykonaj algorytm Kruskala i wyswietl wyniki" << endl
				<< "2 - Wykonaj algorytm Prima i wyswietl wyniki" << endl
				<< "m - reprezentacja macierzowa grafu" << endl
				<< "l - reprezentacja listowa grafu" << endl
				<< "c - wyczysc ekran" << endl;
			break;
		case 27:
			cout << "Opuszczono menu drzewa rozpinajacego, menu glowne:" << endl;
			break;
		}
	} while (decision != 27);
}

void pathMenu()	//Menu minimalnej �cie�ki, wyb�r mi�dzy algorytmem Dijkstry i Bellmana-Forda
{

	cout << "Menu  path:" << endl
		<< "1 - Wykonaj algorytm Dijkstry i wyswietl wyniki" << endl
		<< "2 - Wykonaj algorytm Bellmana-Forda i wyswietl wyniki" << endl
		<< "m - reprezentacja macierzowa grafu" << endl
		<< "l - reprezentacja listowa grafu" << endl
		<< "c - wyczysc ekran" << endl;


	char decision;
	do
	{

		decision = _getch();
		switch (decision)
		{
		case '1':
			_currentAlgorithm = new Dijkstra(graph);
			_currentAlgorithm->execute();

			delete _currentAlgorithm;
			break;
		case '2':
			_currentAlgorithm = new BellmanFord(graph);
			_currentAlgorithm->execute();
			delete _currentAlgorithm;
			break;
		case 'm':
			cout << "Reprezentacja macierzowa: " << endl;
			graph->printMatrix();
			break;
		case 'l':
			cout << "Reprezentacja listowa: " << endl;
			graph->printList();
			break;
		case 'c':
			system("cls");
			cout << "Menu  path:" << endl
				<< "1 - Wykonaj algorytm Dijkstry i wyswietl wyniki" << endl
				<< "2 - Wykonaj algorytm Bellmana-Forda i wyswietl wyniki" << endl
				<< "m - reprezentacja macierzowa grafu" << endl
				<< "l - reprezentacja listowa grafu" << endl
				<< "c - wyczysc ekran" << endl;
			break;
		case 27:
			cout << "Opuszczono menu sciezki, menu glowne:" << endl;
			break;
		}
	} while (decision != 27);
}


bool readFromFile(string fileName, bool isDirected)
{
	delete graph;
	graph = new Graph();

	return graph->loadFromFile(fileName, isDirected);


}

bool prepareGraph(bool isDirected)	//Wywo�ywana w menu, �eby przygotowa� graf zale�nie od algorytmu (skierowany/nieskierowany)
{
	string fileName;
	cout << "Nazwa pliku z grafem: ";
	cin >> fileName;
	while (cin.fail())
	{
		cout << "Blad, podaj ponownie nazwe pliku" << endl;
		cin.clear();
		cin.ignore();
		cin >> fileName;
	}

	if (readFromFile(fileName, isDirected))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void mainMenu()	//Menu g��wne, wyb�r problemu do rozwi�zania
{
	cout << "Wybor problemu:" << endl
		<< "1 - MST, minimalne drzewo rozpinajace " << endl
		<< "2 - Poszukiwanie najkrotszej sciezki" << endl
		<< "c - czysci ekran" << endl;
	int isDirected;
	char decision;
	do
	{

		decision = _getch();
		switch (decision)
		{
		case '1': //Naprawi�
			isDirected = false;
			if (prepareGraph(isDirected)) //Dla problemu MST kraw�dzie s� traktowane jako nieskierowane, przekazuj� false 
			{
				mstMenu();
			}
			else
			{
				cout << "Blad!" << endl;
				cout << "Menu glowne: " << endl;
			} 
			break;
		case '2':
			isDirected = true;
			if (prepareGraph(isDirected))	//Dla problemu najkr�tszej �cie�ki kraw�dzie s� traktowane jako skierowane, przekazuj� true
			{
				pathMenu();
			}
			else
			{
				cout << "Blad!" << endl;
				cout << "Menu glowne: " << endl;
			}
			break;
		case 'm':	
		
			break;
		case 't':

			break;
		case 'c':
			system("cls");
			cout << "Wybor problemu:" << endl
				<< "1 - MST, minimalne drzewo rozpinajace " << endl
				<< "2 - Poszukiwanie najkrotszej sciezki" << endl
				<< "m - reprezentacja macierzowa grafu" << endl
				<< "l - reprezentacja listowa grafu" << endl
				<< "c - czysci ekran" << endl;
			break;
		case 27:
			break;
		}
	} while (decision != 27);

}




/*
TODO 
+Uzupe�ni� metody execute, wy�wietlanie wyniku operacji zawrze� w nich. Operacje dla reprezentacji listowej i macierzowej w jednej metodzie.
+Uzupe�ni� destruktor grafu o usuwanie wektora list
*/

int main()
{
	mainMenu();

	
	delete graph;
	system("PAUSE");
    return 0;
}

