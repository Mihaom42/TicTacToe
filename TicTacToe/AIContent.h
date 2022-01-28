#pragma once
#include "GameMode.h"

class Field;

class AIContent
{
private:
	int _bestScore;
	int _score;

	char _symbol;

public:
	AIContent();
	virtual ~AIContent();

	void BestMove(Field* field);
	int MiniMax(bool isMaximazing, Field* field);

	void SetSymbol(char symbol);
	int GetSymbol() const;
};

