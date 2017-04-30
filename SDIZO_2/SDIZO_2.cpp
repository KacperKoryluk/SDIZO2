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

void mainMenu()	//Menu g��wne, wyb�r problemu do rozwi�zania
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
+Uzupe�ni� klas� grafu
+Uzupe�ni� metody execute, wy�wietlanie wyniku operacji zawrze� w nich.
+Doda� graph jako argument konstruktorach algorytm�w.
+Doda� reprezentacje macierzowe i listowe grafu. Wi�cej w schemacie UML.
+Doda� odczyt grafu z pliku.
+Uzupe�ni� metody wy�wietlaj�ce Posta� macierzow� i listow� grafu
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

