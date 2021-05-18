#include "GameManager.h"
#include <iostream>
#include <windows.h>

void ClearScreen();

GameManager::GameManager()
{
	std::cout << "Player One what is your name?" << std::endl;
	std::string player1Name;
	std::cin >> player1Name;
	std::cout << "Player Two what is your name?" << std::endl;
	std::string player2Name;
	std::cin >> player2Name;
	playerOne = Player{ player1Name, Piece{"Nought",'0' } };
	playerTwo = Player{ player2Name, Piece{"Nought",'X' } };
}

void GameManager::playGame()
{
	bool playerWon{ false };
	bool gameOver{ false };
	while (!gameOver)
	{
		//playturn
		makeMove();
		//checkifwon
		playerWon = gameOver = checkIfWon();
		//if not swapplayer
		if (!playerWon)
		{
			gameOver = board.isFull();
			if (curentPlayer == &playerOne)
			{
				curentPlayer = &playerTwo;
			}
			else
			{
				curentPlayer = &playerOne;
			}
		}
	}
	ClearScreen();
	std::cout << "Game Over!" << std::endl;
	board.draw();
	if (playerWon)
	{
		std::cout << curentPlayer->getname() << " has Won!." << std::endl;
	}else
	{
		std::cout << "Draw!" << std::endl;
	}
}

void GameManager::makeMove()
{
	bool inValidMove{ false };
	auto size{ board.getSize() };
	do
	{
		ClearScreen();
		std::cout << "It's " << curentPlayer->getname() << "'s turn." << std::endl;
		if (inValidMove)
		{
			std::cout << "Invalid move entered please try again." << std::endl;
		}
		board.draw();
		std::cout << "Plase enter the coordinates where you would like to place your "
			<< curentPlayer->getPiece().getSymbol() << '.' << std::endl;
		std::cout << "Enter the coordinates in the format \"x y\" where 'x' is the column and 'y' is the row of choice." << std::endl;
		std::cout << "And \"0 0\" is the bottom left cell." << std::endl;
		std::cout << "And press enter to confirm." << std::endl;
		int column, row;
		std::cin >> column;
		std::cin >> row;
		if (column < 0 || row < 0)
		{
			inValidMove = true;
		}
		if (column > std::get<0>(size) || row > std::get<1>(size))
		{
			inValidMove = true;
		}
		else {
			bool test = !board.insertState(curentPlayer->getPiece(), column, row);
			inValidMove = test;
		}
	} while (inValidMove);
}

bool GameManager::checkIfWon()
{
	auto size{ board.getSize() };

	bool hasWon{ false };
	if (board.matchLeftDiag(curentPlayer->getPiece()))
	{
		return true;
	}
	if (board.matchRightDiag(curentPlayer->getPiece()))
	{
		return true;
	}
	for (int x{}; x < std::get<Y>(size); x++)
	{ 
		if (board.matchRow(curentPlayer->getPiece(), x)) {
			return true;
		}
	}
	for (int y{}; y < std::get<X>(size); y++)
	{
		if (board.matchColumn(curentPlayer->getPiece(), y))
		{
			return true;
		}
	}
	return false;
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
