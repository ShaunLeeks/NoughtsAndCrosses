#pragma once
#include "Grid.h"
#include "Player.h"

class GameManager
{
public:
	GameManager();
	void playGame();
private:
	Grid board;
	void makeMove();
	bool checkIfWon();
	Player playerOne;
	Player playerTwo;
	Player* curentPlayer = &playerOne;
};

