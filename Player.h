#pragma once
#include <string>
#include "Piece.h"
#include <memory>
class Player
{
public:
	Player(std::string pName, Piece pPiece);
	const std::string getname();
	std::shared_ptr<Piece> getPiece();
private:
	std::string name;
	std::shared_ptr<Piece> piece;
};

