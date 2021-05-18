#pragma once
#include <string>

class Piece
{
public:
	Piece();
	Piece(std::string name, char symble);
	const std::string getName();
	const char getSymbol();
	bool operator==(const Piece);

private:
	std::string name {};
	char symbol {};
};
