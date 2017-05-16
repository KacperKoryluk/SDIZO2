// SDIZO_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


Algorithm * _currentAlgorithm;
Graph * graph;
GraphGenerator *gen;


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

bool prepareGraph(bool isDirected)	//Wywo³ywana w menu, ¿eby przygotowaæ graf zale¿nie od algorytmu (skierowany/nieskierowany)
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
void mainMenu()	//Menu g³ówne, wybór problemu do rozwi¹zania
{

	cout << "Wybor problemu:" << endl
		<< "1 - MST, minimalne drzewo rozpinajace " << endl
		<< "2 - Poszukiwanie najkrotszej sciezki" << endl
		<< "g - generuj plik z grafem" << endl
		<< "c - czysci ekran" << endl;
	int isDirected;
	char decision;
	string fileName;
	int verticeAmount, density, endVertice;
	bool isGeneratedGraphDirected;
	char directedDecision;

	do
	{
		
		decision = _getch();
		switch (decision)
		{
		case '1': //Naprawiæ
			isDirected = false;
			if (prepareGraph(isDirected)) //Dla problemu MST krawêdzie s¹ traktowane jako nieskierowane, przekazujê false 
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
			if (prepareGraph(isDirected))	//Dla problemu najkrótszej œcie¿ki krawêdzie s¹ traktowane jako skierowane, przekazujê true
			{
				pathMenu();
			}
			else
			{
				cout << "Blad!" << endl;
				cout << "Menu glowne: " << endl;
			}
			break;
		case 'g':	
			gen = new GraphGenerator();

			cout << "Podaj ilosc wierzcholkow: ";
			cin >> verticeAmount;
			while (cin.fail() || verticeAmount <= 0)
			{
				cout << "Blad, podaj liczbe calkowita!" << endl;
				cin.clear();
				cin.ignore();
				cin >> verticeAmount;
			}

			cout << "Podaj gestosc(sama liczba, na przyklad 25% to 25): ";
			do
			{
				cin >> density;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> density;
				}
				if (density <= 0 || density > 100)
				{
					cout << "Gestosc powinna byc wieksza od 0 i mniejsza od 100!" << endl;
				}
			} while (density <= 0 || density > 100);
			cout << "Czy graf ma byc skierowany? [t/n]: ";
			cin >> directedDecision;
			switch(directedDecision)
			{
			case 't':
				isGeneratedGraphDirected = true;
				break;
			case 'n':
				isGeneratedGraphDirected = false;
				break;
			default:
				cout << "Podano niewlasciwy znak, graf bedzie nieskierowany" << endl;
				isGeneratedGraphDirected = false;
				break;
			}
			/*
			cout << "Podaj zakres wartosci: ";
			cin >> valueRange;
			while (cin.fail() || valueRange <= 0)
			{
				cout << "Blad, podaj liczbe calkowita!" << endl;
				cin.clear();
				cin.ignore();
				cin >> valueRange;
			}
			cout << "Od ktorej wartosci losowac: ";
			cin >> start;
			while (cin.fail())
			{
				cout << "Blad, podaj liczbe calkowita!" << endl;
				cin.clear();
				cin.ignore();
				cin >> start;
			}
			*/
			cout << "Wierzcholek koncowy: ";
			do
			{
				cin >> endVertice;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> endVertice;
				}
				if (endVertice < 0 || endVertice > verticeAmount)
				{
					cout << "Wierzcholek koncowy powinien byc nieujemny i mniejszy od ilosci wierzcholkow w grafie!" << endl;
				}
			} while (endVertice < 0 || endVertice > verticeAmount);
			
			cout << "Nazwa pliku (bez .txt): ";
			cin >> fileName;
			gen->generateGraph(verticeAmount, density, isGeneratedGraphDirected, 20, 5, fileName, endVertice);
			delete gen;
			break;
		case 't':

			break;
		case 'c':
			system("cls");
			cout << "Wybor problemu:" << endl
				<< "1 - MST, minimalne drzewo rozpinajace " << endl
				<< "2 - Poszukiwanie najkrotszej sciezki" << endl
				<< "g - generuj plik z grafem" << endl
				<< "c - czysci ekran" << endl;
			break;
		case 27:
			break;
		}
	} while (decision != 27);

}




/*
TODO 
+Uzupe³niæ metody execute, wyœwietlanie wyniku operacji zawrzeæ w nich. Operacje dla reprezentacji listowej i macierzowej w jednej metodzie.
+Uzupe³niæ destruktor grafu o usuwanie wektora list
*/

int main()
{

	

	mainMenu();

	
	delete graph;
	system("PAUSE");
    return 0;
}


/*
generowanie plików z grafami

temp->generateGraph(100, 99, true, 20, 1, "graf100skierowany99", 0);
temp->generateGraph(100, 99, false, 20, 1, "graf100nieskierowany99", 0);

temp->generateGraph(200, 25, true, 20, 1, "graf200skierowany25", 0);
temp->generateGraph(200, 25, false, 20, 1, "graf200nieskierowany25", 0);
temp->generateGraph(200, 50, true, 20, 1, "graf200skierowany50", 0);
temp->generateGraph(200, 50, false, 20, 1, "graf200nieskierowany50", 0);
temp->generateGraph(200, 75, true, 20, 1, "graf200skierowany75", 0);
temp->generateGraph(200, 75, false, 20, 1, "graf200nieskierowany75", 0);
temp->generateGraph(200, 99, true, 20, 1, "graf200skierowany99", 0);
temp->generateGraph(200, 99, false, 20, 1, "graf200nieskierowany99", 0);

temp->generateGraph(300, 25, true, 20, 1, "graf300skierowany25", 0);
temp->generateGraph(300, 25, false, 20, 1, "graf300nieskierowany25", 0);
temp->generateGraph(300, 50, true, 20, 1, "graf300skierowany50", 0);
temp->generateGraph(300, 50, false, 20, 1, "graf300nieskierowany50", 0);
temp->generateGraph(300, 75, true, 20, 1, "graf300skierowany75", 0);
temp->generateGraph(300, 75, false, 20, 1, "graf300nieskierowany75", 0);
temp->generateGraph(300, 99, true, 20, 1, "graf300skierowany99", 0);
temp->generateGraph(300, 99, false, 20, 1, "graf300nieskierowany99", 0);

temp->generateGraph(500, 25, true, 20, 1, "graf500skierowany25", 0);
temp->generateGraph(500, 25, false, 20, 1, "graf500nieskierowany25", 0);
temp->generateGraph(500, 50, true, 20, 1, "graf500skierowany50", 0);
temp->generateGraph(500, 50, false, 20, 1, "graf500nieskierowany50", 0);
temp->generateGraph(500, 75, true, 20, 1, "graf500skierowany75", 0);
temp->generateGraph(500, 75, false, 20, 1, "graf500nieskierowany75", 0);
temp->generateGraph(500, 99, true, 20, 1, "graf500skierowany99", 0);
temp->generateGraph(500, 99, false, 20, 1, "graf500nieskierowany99", 0);
*/