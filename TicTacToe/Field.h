#pragma once
#include "GameMode.h"

class CheckInputData;

class Field
{
public:
	Field(GameMode* gameMode);
	Field(CheckInputData* checkData);
	virtual ~Field();

protected:
	int _width;
	int _height;

	char** cells;

	GameMode* _gameMode;
	CheckInputData* _checkData;
public:

	void DrawIndexOfCells();
	void InputFieldParam();
	void InitializeMass();

	void Update();

	void SetValueForCell(int index, char symbol);
	void SetValueForCell(int x, int y, char symbol);

	bool CheckDiagonals(char, int, int);
	bool CheckLines(char, int, int);
	bool CheckDraw();
	bool CheckAIWin();
	bool CheckPlayerWin();

	char GetInfoAboutCell(int, int);
	bool GetInfoAboutCell(int);

	void SetWidth(int width);
	void SetHeight(int height);

	int GetWidth();
	int GetHeight();

	GameMode* GetGameMode() const;
};