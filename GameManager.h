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
	std::shared_ptr<Player> playerOne;
	std::shared_ptr<Player> playerTwo;
	std::shared_ptr<Player> curentPlayer;
};

