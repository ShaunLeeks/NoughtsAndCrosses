#pragma once
#include <vector>
#include <memory>
#include <array>
#include "Piece.h"

enum orientation { X = 0, Y = 1, };


class Cell
{
public:
	bool insertPiece(std::shared_ptr<Piece> move);
	std::shared_ptr<Piece> getPiece();
	bool isEmpty();
private:
	bool empty{ true };
	std::shared_ptr<Piece> piece = std::make_shared<Piece>("", ' ');
};


class Grid
{
public:
	Grid();
	std::tuple<int, int> getSize();
	void draw();
	bool insertState(std::shared_ptr<Piece> move, unsigned int column, unsigned int row);
	bool isFull();
	bool matchRow(std::shared_ptr<Piece> move, unsigned int row);
	bool matchColumn(std::shared_ptr<Piece> move, unsigned int column);
	bool matchLeftDiag(std::shared_ptr<Piece> move);
	bool matchRightDiag(std::shared_ptr<Piece> move);

private:	
	const int size [2] {3,3}; // {w,h}
	int numContained{};
	int maxContents;
	std::vector<std::vector<Cell>> content;

	void printLine(bool fill);
	void printEmptyLine();
	void printHorizontalLine();
};
