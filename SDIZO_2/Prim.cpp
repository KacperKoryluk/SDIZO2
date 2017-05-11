#include "stdafx.h"
#include "Prim.h"

void Prim::execute()	//Posprz¹taæ!
{
	struct CompareEdges
	{
		bool operator() ( Edge & left, Edge & right)
		{
			return left.getWeight()> right.getWeight();
		}
	};
	
	//Macierzowa
	int **tempMatrix = _graph->getGraphMatrix();
	Edge *tempEdge;
	Edge *queueTop = new Edge();


	bool *visited = new bool[_graph->getVerticeAmount()];	//Tablica logiczna, zawiera informacjê czy dany element by³ odwiedzony
	for (int i = 0; i < _graph->getVerticeAmount(); i++)
	{
		visited[i] = false;	//Przed rozpoczêciem algorytmu nie odwiedzi³em ¿adnego wierzcho³ka, ustawiam na false
	}
	
	list<int> *MST = new list<int>;
	MST->push_front(_graph->getFirstVertex()); //Tworzê drzewo rozpinaj¹ce i dodajê do niego pierwszy wierzcho³ek (startowy)
	visited[0] = true;

	std::priority_queue<Edge, vector<Edge>, CompareEdges> queue;
	

	for (int i = 1; i < _graph->getVerticeAmount(); i++)	//To jest wszystko Ÿle
	{
		if (!visited[i])
		{
			for (int j = 0; i < _graph->getVerticeAmount(); i++)
			{
				if (tempMatrix[i][j] != 0)
				{
					tempEdge = new Edge(j, i, tempMatrix[i][j]);
					queue.push(*tempEdge);

					//queueTop = new Edge(queue.top().getStartVertice(), queueTop.getEndVertice(), queueTop.getWeight());	//Bo¿e, wybacz mi, bo nie wiem co czyniê
					
					if (!visited[queueTop->getStartVertice()])
					{
						MST->push_front(queueTop->getStartVertice());
						visited[queueTop->getStartVertice()] = true;
					}
				}
			}
		}
	}
	cout << "Queue size:" << endl;
	while (!queue.empty()) 
	{
		cout << queue.size() << endl;
		queue.pop();

	}
	cout << "MST: " << endl;
	while (!MST->empty())
	{
		cout << MST->front() << endl;
		MST->pop_front();
	}
	

	//Dodaæ kolejkê priorytetow¹ wierzcho³ków
	//Dalsza czêœæ algorytmu, dokoñczyæ



	cout << "Prim executed" << endl;



	delete[] visited;
	delete MST;

}

Prim::Prim()
{
}


Prim::~Prim()
{
}

Prim::Prim(Graph * graph)
{
	_graph = graph;
}
