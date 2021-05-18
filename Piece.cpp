#include "Piece.h"

Piece::Piece(const std::string pieceName, char pieceSymble):
name(pieceName), symbol(pieceSymble)
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