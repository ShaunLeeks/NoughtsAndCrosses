#pragma once
#include <string>

class Piece
{
public:
	Piece() = default;
	Piece(const std::string name, char symble);
	const std::string getName();
	const char getSymbol();
	bool operator==(const Piece);

private:
	std::string name {};
	char symbol {};
};
