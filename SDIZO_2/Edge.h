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
	bool operator< (const Edge & right);
	bool operator> (const Edge & right);
	friend std::ostream& operator<< (std::ostream&, const Edge*);
	bool operator== (const Edge &right);
	~Edge();
};

