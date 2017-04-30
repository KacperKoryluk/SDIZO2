// SDIZO_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


Algorithm * _currentAlgorithm;
Graph * graph;



void mstMenu()	//Menu minimalnego drzewa rozpinaj¹cego, wybór miêdzy algorytmem Kruskala i Prima
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
			_currentAlgorithm = new Kruskal();
			_currentAlgorithm->execute();
			delete _currentAlgorithm;
			break;
		case '2':
			_currentAlgorithm = new Prim();
			_currentAlgorithm->execute();
			delete _currentAlgorithm;
			break;
		case 'm':
			cout << "Reprezentacja macierzowa: " << endl;
			graph->printMatrix();
			break;
		case 'l':

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

void pathMenu()	//Menu minimalnej œcie¿ki, wybór miêdzy algorytmem Dijkstry i Bellmana-Forda
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
			_currentAlgorithm = new Dijkstra();
			_currentAlgorithm->execute();

			delete _currentAlgorithm;
			break;
		case '2':
			_currentAlgorithm = new BellmanFord();
			_currentAlgorithm->execute();
			delete _currentAlgorithm;
			break;
		case 'm':
			cout << "Reprezentacja macierzowa: " << endl;
			graph->printMatrix();
			break;
		case 'l':

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

void mainMenu()	//Menu g³ówne, wybór problemu do rozwi¹zania
{
	cout << "Wybor problemu:" << endl
		<< "1 - MST, minimalne drzewo rozpinajace " << endl
		<< "2 - Poszukiwanie najkrotszej sciezki" << endl
		<< "m - reprezentacja macierzowa grafu" << endl
		<< "l - reprezentacja listowa grafu" << endl
		<< "c - czysci ekran" << endl;

	char decision;
	do
	{

		decision = _getch();
		switch (decision)
		{
		case '1':
			mstMenu();
			break;
		case '2':
			pathMenu();
			break;
		case 'm':
			cout << "Reprezentacja macierzowa: " << endl;
			graph->printMatrix();
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

bool readFromFile(string fileName)
{
	graph = new Graph();
	
	return graph->loadFromFile(fileName);


}

/*
TODO 
+Uzupe³niæ klasê grafu
+Uzupe³niæ metody execute, wyœwietlanie wyniku operacji zawrzeæ w nich.
+Dodaæ graph jako argument konstruktorach algorytmów.
+Dodaæ reprezentacje macierzowe i listowe grafu. Wiêcej w schemacie UML.
+Dodaæ odczyt grafu z pliku.
+Uzupe³niæ metody wyœwietlaj¹ce Postaæ macierzow¹ i listow¹ grafu
*/

int main()
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

	if (readFromFile(fileName))
	{
		mainMenu();
	}
	else
	{
		cout << "Program zostanie zamkniety!" << endl;
	}

	

	system("PAUSE");
    return 0;
}

