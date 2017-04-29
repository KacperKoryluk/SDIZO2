#pragma once
#include "stdafx.h"

class Algorithm
{
protected:
	Graph graph;
public:
	virtual void execute();
	virtual void printResult();
	Algorithm();
	~Algorithm();
};

