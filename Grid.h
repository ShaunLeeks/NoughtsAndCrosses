#pragma once
#include <vector>
#include <memory>
#include <array>
#include "Piece.h"

enum orientation { X = 0, Y = 1, };


class cell
{
public:
	bool insertPiece(Piece move);
	Piece getPiece();
	bool isEmpty();
private:
	bool empty{ true };
	Piece piece;
};


class Grid
{
public:
	Grid();
	std::tuple<int, int> getSize();
	void draw();
	bool insertState(Piece move, unsigned int column, unsigned int row);
	bool isFull();
	bool matchRow(Piece move, unsigned int row);
	bool matchColumn(Piece move, unsigned int column);
	bool matchLeftDiag(Piece move);
	bool matchRightDiag(Piece move);

private:	
	const int size [2] {3,3}; // {w,h}
	int numContained{};
	int maxContents;
	std::vector<std::vector<cell>> content;

	void printLine(bool fill);
	void printEmptyLine();
	void printHorizontalLine();
};
