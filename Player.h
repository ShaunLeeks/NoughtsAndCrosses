#pragma once
#include <string>
#include "Piece.h"
class Player
{
public:
	Player() = default;
	Player(std::string pName, Piece pPiece) :
		name(std::move(pName)), piece(std::move(pPiece)) {};
	const std::string getname();
	Piece getPiece();
private:
	std::string name;
	Piece piece;
};

