#include "pch.h"
#include "InputHandler.h"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

int InputHandler::CheckData(int data)
{
	if (!cin)
	{
		while (!cin)
		{
			cout << "\nYou have entered incorrect data. Please, enter only numbers!\n\n-> ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> data;
		}
		return data;
	}

	if (data <= 1)
	{
		while (data <= 1)
		{
			cout << "\nYou have entered incorrect data. Please, enter value greater than one!\n\n-> ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> data;
		}
		return data;
	}

	return data;
}

bool InputHandler::CheckData(int width, int height)
{
	if (width != height)
	{
		cout << "\n\nHeight and width must be the same!!!\n\n";
		return false;
	}

	return true;
}

bool InputHandler::CheckPlayerAnswer(char answer)
{
	while (answer != 'y' && answer != 'n')
	{
		cout << "\n\nPlease, enter only 'y' or 'n'\n\n-> ";
		cin >> answer;
	}

	if (answer == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}