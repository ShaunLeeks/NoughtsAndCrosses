#pragma once
#include <string>

class Piece
{
public:
	Piece(std::string name, char symble);
	Piece(const Piece & other);
	const std::string & getName();
	const char getSymbol();

private:
	const std::string name {""};
	const char symbol {' '};
};
