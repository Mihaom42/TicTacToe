// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"


int main()
{
	GameMode* gameMode = new GameMode();

	gameMode->Init();

	while (!gameMode->IsGameFinished())
	{
		gameMode->Tick();
	}

	system("pause");

	delete gameMode;

	return 0;
}


