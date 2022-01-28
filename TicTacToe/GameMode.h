#pragma once
#include "AIContent.h"

class Player;
class Field;

class GameMode
{
public:
	GameMode();
	virtual ~GameMode();

protected:
	Field* _field;
	Player* _player;
	AIContent* _aiContent;

	bool _isGameFinished;

private:
	bool _whoFirst;

public:
	bool ChooseWhoFirst();
	void AssignSymbolForPlayers();
	bool CheckForEndTheGame();

	void Init();
	void Tick();

	bool IsGameFinished() const;

	Player* GetPlayer() const;
	AIContent* GetAIContent() const;
};

