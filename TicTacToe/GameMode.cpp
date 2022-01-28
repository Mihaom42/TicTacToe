#include "pch.h"
#include "GameMode.h"

GameMode::GameMode()
{
	_field = nullptr;
	_player = nullptr;
	_aiContent = nullptr;

	_isGameFinished = false;
	_whoFirst = false;
}

GameMode::~GameMode()
{
	delete _field;
	delete _player;
	delete _aiContent;
}

bool GameMode::ChooseWhoFirst()
{
	srand((unsigned)time(NULL));

	int selelction = rand() % 2;

	if (selelction == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameMode::AssignSymbolForPlayers()
{
	srand((unsigned)time(NULL));

	int selection = rand() % 2;
	if (selection == 0)
	{
		_aiContent->SetSymbol('X');
		_player->SetSymbol('0');
	}
	else if (selection == 1)
	{
		_aiContent->SetSymbol('0');
		_player->SetSymbol('X');
	}
}

bool GameMode::CheckForEndTheGame()
{
	char symbol = '\0';

	if (_field->CheckAIWin())
	{
		symbol = _aiContent->GetSymbol();
		cout << "\n\n[" << symbol << "] wins!\n\n";
		return true;
	}

	if (_field->CheckPlayerWin())
	{
		symbol = _player->GetSymbol();
		cout << "\n\n[" << symbol << "] wins!\n\n";
		return true;
	}

	if (_field->CheckDraw())
	{
		cout << "\n\nDRAW!\n\n";
		return true;
	}

	return false;
}

void GameMode::Init()
{
	char symbol;

	_field = new Field(this);
	_player = new Player();
	_aiContent = new AIContent();

	_field->InputFieldParam();
	_field->InitializeMass();

	AssignSymbolForPlayers();

	_whoFirst = ChooseWhoFirst();
	symbol = _player->GetSymbol();

	system("cls");
	cout << "\n\nYour symbol is [" << symbol << "]\n\n"; //Util
}

void GameMode::Tick()
{
	_field->DrawIndexOfCells();

	if (_whoFirst)
	{
		_player->Move(_field);

		if (CheckForEndTheGame())
		{
			_isGameFinished = true;
		}

		if (!_isGameFinished)
		{
			_aiContent->BestMove(_field);

			if (CheckForEndTheGame())
			{
				_isGameFinished = true;
			}
		}
		_field->Update();
	}
	else
	{
		_aiContent->BestMove(_field);

		if (CheckForEndTheGame())
		{
			_isGameFinished = true;
		}
		_field->Update();

		if (!_isGameFinished)
		{
			_player->Move(_field);

			if (CheckForEndTheGame())
			{
				_isGameFinished = true;
			}
			_field->Update();
		}
	}
}

bool GameMode::IsGameFinished() const
{
	return _isGameFinished;
}

Player* GameMode::GetPlayer() const
{
	return _player;
}

AIContent* GameMode::GetAIContent() const
{
	return _aiContent;
}
