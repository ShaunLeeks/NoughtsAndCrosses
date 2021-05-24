#include "Grid.h"
#include <iostream>
#include <string>

void printContentRow(std::vector<Cell> data);

Grid::Grid()
{
	content.resize(size[Y]);
	for (auto &row : content) {
		row.resize(size[X]);
	}
	maxContents = size[X] * size[Y];
}

std::tuple<int, int> Grid::getSize()
{
	return std::tuple<int, int>(size[0],size[1]);
}

void Grid::draw()
{
	for (int height{ size[Y] -1}; height >= 0; height--)
	{	
		printEmptyLine();
		printContentRow(content[height]);
		if (height > 0) {
			printHorizontalLine();
		}
		else {
			printEmptyLine();
		}
	}
}

bool Grid::insertState(std::shared_ptr<Piece> move, unsigned int column, unsigned int row)
{
	if (column > size[X] - 1 || row > size[Y] - 1)
		return false;
	if (!content[row][column].isEmpty())
		return false;
	content[row][column].insertPiece(move);
	numContained++;
	return true;
}

bool Grid::isFull()
{
	return numContained == maxContents;
}

bool Grid::matchRow(std::shared_ptr<Piece> move, unsigned int row)
{
	for (Cell item : content[row])
	{
		if (move != item.getPiece()) {
			return false;
		}
	}
	return true;
}

bool Grid::matchColumn(std::shared_ptr<Piece> move, unsigned int column)
{
	for (auto row : content)
	{
		if (move != row[column].getPiece())
		{
			return false;
		}
	}
	return true;
}

bool Grid::matchLeftDiag(std::shared_ptr<Piece> move)
{
	for (int x{}, y{ size[Y] - 1 }; x < size[X] && y >= 0 ; x++, y--)
	{
		if (move != content[x][y].getPiece())
		{
			return false;
		}
	}
	return true;
}

bool Grid::matchRightDiag(std::shared_ptr<Piece> move)
{
	for (int cell{}; cell < size[Y] && cell < size[X]; cell++)
	{
		if (move != content[cell][cell].getPiece())
		{
			return false;
		}
	}
	return true;
}

void Grid::printLine(bool fill)
{
	std::string filler;
	filler = (fill) ? "___" : "   ";
	std::string line{};
	for (int count{ size[X] }; count > 0; count--) {
		line.append(filler);
		if (count > 1) {
			line.append("|");
		}
	}
	std::cout << line << "\n";
}

void Grid::printHorizontalLine()
{
	printLine(true);
}

void Grid::printEmptyLine()
{
	printLine(false);
}

void printContentRow(std::vector<Cell> rowData)
{
	for (unsigned int count{}; count < rowData.size(); count++)
	{
		std::cout << ' ' << rowData[count].getPiece().get()->getSymbol() << ' ';
		if (count < rowData.size() - 1) {
			std::cout << '|';
		}
	}
	std::cout << "\n";
}

bool Cell::insertPiece(std::shared_ptr<Piece> move)
{
	if (empty) {
		piece = move;
		empty = false;
		return true;
	}
	else {
		return false;
	}
}

const std::shared_ptr<Piece> Cell::getPiece()
{
	return piece;
}

bool Cell::isEmpty()
{
	return empty;
}
