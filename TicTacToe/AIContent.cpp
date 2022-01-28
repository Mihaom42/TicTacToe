#include "pch.h"
#include "AIContent.h"

AIContent::AIContent()
{
}

AIContent::~AIContent()
{
}

void AIContent::BestMove(Field* field)
{
	int x = 0;
	int y = 0;

	int bestScore = -10;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (field->GetInfoAboutCell(i, j) == '-')
			{
				field->SetValueForCell(i, j, _symbol);
				_score = MiniMax(false, field);
				field->SetValueForCell(i, j, '-');
				if (_score > bestScore)
				{
					bestScore = _score;
					x = i;
					y = j;
				}
			}
		}
	}

	field->SetValueForCell(x, y, _symbol);
}

int AIContent::MiniMax(bool isMaximazing, Field* field)
{
	if (field->CheckAIWin())
	{
		return 10;
	}

	else if (field->CheckPlayerWin())
	{
		return -10;
	}

	else if (field->CheckDraw())
	{
		return 0;
	}

	if (isMaximazing)
	{
		_bestScore = -10;
		for (int i = 0; i < field->GetHeight(); i++)
		{
			for (int j = 0; j < field->GetWidth(); j++)
			{
				if (field->GetInfoAboutCell(i, j) == '-')
				{
					field->SetValueForCell(i, j, _symbol);
					_score = MiniMax(false, field);
					field->SetValueForCell(i, j, '-');

					_bestScore = max(_score, _bestScore);
				}
			}
		}
		return _bestScore;
	}
	else
	{
		_bestScore = 10;
		for (int i = 0; i < field->GetHeight(); i++)
		{
			for (int j = 0; j < field->GetWidth(); j++)
			{
				if (field->GetInfoAboutCell(i, j) == '-')
				{
					field->SetValueForCell(i, j, field->GetGameMode()->GetPlayer()->GetSymbol());
					_score = MiniMax(true, field);
					field->SetValueForCell(i, j, '-');

					_bestScore = min(_score, _bestScore);
				}
			}
		}
		return _bestScore;
	}
}

void AIContent::SetSymbol(char symbol)
{
	_symbol = symbol;
}

int AIContent::GetSymbol() const
{
	return _symbol;
}


