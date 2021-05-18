#pragma once
#include <string>

enum state { Empty = 0, Nought = 1, Cross = 2 };

class Piece
{
public:
	Piece();
	Piece(const std::string name, char symble);
	Piece(state move);
	const std::string getName();
	const char getSymbol();
	bool operator==(const Piece&);

private:
	std::string name {};
	char symbol {};
};
