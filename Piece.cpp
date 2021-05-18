#include "Piece.h"

Piece::Piece(std::string pieceName, char pieceSymble):
name(std::move(pieceName)), symbol(std::move(pieceSymble))
{}

Piece::Piece(const Piece & other): name(other.name), symbol(other.symbol)
{}

const std::string & Piece::getName()
{
	return name;
}

const char Piece::getSymbol()
{
	return symbol;
}

bool Piece::operator==(const Piece other)
{
	return (name == other.name && symbol == other.symbol);
}
