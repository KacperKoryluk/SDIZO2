#pragma once
#include "stdafx.h"

class Algorithm
{
protected:
	Graph * _graph;
public:
	virtual void execute() {};
	Algorithm();
	~Algorithm();
};

//