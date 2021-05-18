#include "Piece.h"

Piece::Piece():
	name()
{
	symbol = ' ';
}

Piece::Piece(std::string pieceName, char pieceSymble):
name(std::move(pieceName)), symbol(std::move(pieceSymble))
{}

const std::string Piece::getName()
{
	std::string temp = name;
	return temp;
}

const char Piece::getSymbol()
{
	return symbol;
}

bool Piece::operator==(const Piece other)
{
	return (name == other.name && symbol == other.symbol);
}
