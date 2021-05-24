#pragma once
#include <string>
#include "Piece.h"
#include <memory>
class Player
{
public:
	Player(std::string pName, Piece pPiece);
	const std::string & getname();
	const std::shared_ptr<Piece> getPiece();
private:
	const std::string name;
	const std::shared_ptr<Piece> piece;
};
