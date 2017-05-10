#pragma once
class Edge
{
private:
	int startVertice;
	int endVertice;
	int weight;
	//Przeci¹¿yæ operatory
public:
	int getStartVertice();
	int getEndVertice();
	int getWeight();
	Edge();
	Edge(int startVertice, int endVertice, int weight);
	~Edge();
};

