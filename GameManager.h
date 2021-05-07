#pragma once
#include "Grid.h"

enum class PlayersTurn {PlayerOne, PlayerTwo};

class GameManager
{
public:
	void playGame();
private:
	Grid board;
	PlayersTurn currentTurn { PlayersTurn::PlayerOne };
	void makeMove();
	bool checkIfWon();
};

