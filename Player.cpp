#include "Player.h"

Player::Player(std::string pName, Piece pPiece):
	name(std::move(pName)), piece(std::make_shared<Piece>(pPiece))
{}

const std::string & Player::getname()
{
	return name;
}

const std::shared_ptr<Piece> Player::getPiece()
{
	return piece;
}
