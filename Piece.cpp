#include "Piece.h"

Piece::Piece():
	name()
{
	symbol = ' ';
}

Piece::Piece(const std::string pieceName, char pieceSymble):
name(pieceName), symbol(pieceSymble)
{}

Piece::Piece(state move)
{
	switch (move) {
	case state::Nought:
		name = "Nought";
		symbol = '0';
		break;
	case state::Cross:
		name = "Cross";
		symbol = 'X';
		break;
	}
}

const std::string Piece::getName()
{
	std::string temp = name;
	return temp;
}

const char Piece::getSymbol()
{
	return symbol;
}

bool Piece::operator==(const Piece& other)
{
	return (name == other.name && symbol == other.symbol);
}
