#pragma once
#include "stdafx.h"

class Neighbour
{
private:
	int weight;
	int end;
public:
	int getWeight()const;
	int getEnd()const;
	Neighbour(int weight, int end);
	Neighbour();
	~Neighbour();
	bool Neighbour::operator < (const Neighbour & right);
	void print();
	friend std::ostream& operator<< (std::ostream& , const Neighbour*);
	bool operator== (const Neighbour &right);
};

