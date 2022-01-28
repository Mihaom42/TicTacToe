#include "pch.h"
#include "Player.h"

Player::Player() :_moveCellIndex(0)
{
}

Player::~Player()
{
}

void Player::Move(Field* field)
{
	cout << "Your move-> ";
	cin >> _moveCellIndex;

	while (!cin)
	{
		cout << "\nYou have entered incorrect data. Please enter only numbers!\n\n-> ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> _moveCellIndex;
	}

	while (_moveCellIndex < 1 || _moveCellIndex > field->GetWidth() * field->GetHeight())
	{
		cout << "\nPlease, enter numbers in this range [" << 1 << ',' << field->GetWidth() * field->GetHeight() << "]\n\n-> ";
		cin >> _moveCellIndex;
	}

	while (!field->GetInfoAboutCell(_moveCellIndex))
	{
		cout << "\nThis cell has already filled! Please, enter another move.\n\n-> ";
		cin >> _moveCellIndex;
	}

	field->SetValueForCell(_moveCellIndex, _symbol);
}

void Player::SetSymbol(char symbol)
{
	_symbol = symbol;
}

int Player::GetSymbol() const
{
	return _symbol;
}
