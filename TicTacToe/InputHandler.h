#pragma once
#include "pch.h"

class Field;

class InputHandler
{
public:
	InputHandler();
	virtual ~InputHandler();

public:
	int CheckData(int);
	bool CheckData(int, int);
	bool CheckPlayerAnswer(char);
};

