#pragma once
#include "GameMode.h"

class Player
{
protected:
	int _moveCellIndex;
	char _symbol;

public:
	Player();
	virtual ~Player();

	void Move(Field* field);

	void SetSymbol(char symbol);
	int GetSymbol() const;
};