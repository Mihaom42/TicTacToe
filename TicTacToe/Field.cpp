#include "pch.h"
#include "Field.h"

Field::Field(GameMode* gameMode)
{
	_width = 8;
	_height = 8;
	_gameMode = gameMode;
	_checkData = nullptr;

	cells = nullptr;
}


Field::Field(CheckInputData* checkData)
{
	_width = 0;
	_height = 0;
	_checkData = checkData;

	cells = nullptr;
}

Field::~Field()
{
	for (int i = 0; i < _height; i++)
	{
		delete[] cells[i];
	}

	delete[] cells;
}

void Field::InputFieldParam() //input field size
{
	char playerAnswer = '\0';
	cout << "\nDo you want to enter game field size? Default size is 8x8.\n\nPlease, Enter 'y' or 'n'-> ";
	cin >> playerAnswer;

	if (!_checkData->CheckPlayerAnswer(playerAnswer))
	{
		return;
	}

	do
	{
		cout << "Enter height-> ";
		cin >> _height;
		_height = _checkData->CheckData(_height);

		cout << "Enter width-> ";
		cin >> _width;
		_width = _checkData->CheckData(_width);
	}while(!_checkData->CheckData(_width, _height));
	
	cout << '\n';
}

void Field::DrawIndexOfCells()
{
	int count = 1;
	cout << "\n--------------------------------------\n";
	cout << "|--Move options--|\n\n";
	cout << "Move options:\n\n";
	for (int i = 1; i <= _height; i++)
	{
		for (int j = count; j < _width + count; j++)
		{
			cout << "|-" << j << "-|";
		}
		count += _width;
		cout << '\n';
	}
	cout << '\n';
}

void Field::InitializeMass()
{
	cells = new char* [_height];
	for (int i = 0; i < _height; ++i)
	{
		cells[i] = new char[_width];
	}

	/////initialization////

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			cells[i][j] = '-';
		}
	}
}

void Field::Update()
{
	for (int x = 0; x < _height; x++)
	{
		for (int y = 0; y < _width; y++)
		{
			cout << "|-" << cells[x][y] << "-|";
		}
		cout << '\n';
	}
	cout << "\n--------------------------------------\n";
}


void Field::SetValueForCell(int index, char symbol)
{
	int count = 0;

	for (int x = 0; x < _height; x++)
	{
		for (int y = 0; y < _width; y++)
		{
			count++;
			if (count == index)
			{
				cells[x][y] = symbol;
				return;
			}
		}
		cout << '\n';
	}
}

bool Field::CheckDiagonals(char symbol, int offsetX, int offsetY)
{
	bool toRight = true;
	bool toLeft = true;

	for (int i = 0; i < 3; i++) {
		toRight &= (cells[i + offsetX][i + offsetY] == symbol);
		toLeft &= (cells[3 - i - 1 + offsetX][i + offsetY] == symbol);
	}

	if (toRight || toLeft) return true;

	return false;
}

bool Field::CheckLines(char symbol, int offsetX, int offsetY)
{
	bool cols = false;
	bool rows = false;

	for (int col = offsetX; col < 3 + offsetX; col++) {
		cols = true;
		rows = true;
		for (int row = offsetY; row < 3 + offsetY; row++) {
			cols &= (cells[col][row] == symbol);
			rows &= (cells[row][col] == symbol);
		}

		if (cols || rows)
		{
			return true;
		}
	}

	return false;
}


bool Field::CheckDraw()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			if (cells[i][j] == '-')
			{
				return false;
			}
		}
	}

	return true;
}

bool Field::CheckPlayerWin()
{
	const char player = _gameMode->GetPlayer()->GetSymbol();

	for (int col = 0; col < _height - 3 + 1; col++) {
		for (int row = 0; row < _width - 3 + 1; row++) {
			if (CheckDiagonals(player, col, row) || CheckLines(player, col, row))
			{
				return true;
			}
		}
	}
	return false;
}

bool Field::CheckAIWin()
{
	const char ai = _gameMode->GetAIContent()->GetSymbol();

	for (int col = 0; col < _height - 3 + 1; col++) {
		for (int row = 0; row < _width - 3 + 1; row++) {
			if (CheckDiagonals(ai, col, row) || CheckLines(ai, col, row))
			{
				return true;
			}
		}
	}
	return false;
}

char Field::GetInfoAboutCell(int x, int y)
{
	return cells[x][y];
}

bool Field::GetInfoAboutCell(int playerMove)
{
	int count = 0;
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			count++;
			if (playerMove == count && cells[i][j] != '-') { return false; }
		}
	}

	return true;
}

void Field::SetWidth(int width)
{
	_width = width;
}

int Field::GetWidth()
{
	return _width;
}

void Field::SetHeight(int height)
{
	_height = height;
}

int Field::GetHeight()
{
	return _height;
}

GameMode* Field::GetGameMode() const
{
	return _gameMode;
}

void Field::SetValueForCell(int x, int y, char symbol)
{
	cells[x][y] = symbol;
}
