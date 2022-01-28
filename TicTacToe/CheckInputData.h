#pragma once
#include "pch.h"

class Field;

class CheckInputData
{
private:
	Field* _field;

public:
	CheckInputData();
	virtual ~CheckInputData();

public:
	int CheckData(int);
	bool CheckData(int, int);
	bool CheckPlayerAnswer(char);
};

