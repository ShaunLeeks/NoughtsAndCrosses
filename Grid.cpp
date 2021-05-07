#include "Grid.h"
#include <iostream>
#include <string>

void printContentRow(std::vector<state> data);

const char symbols[]{
' ','0','X'
};

Grid::Grid()
{
	content.resize(size[Y]);
	for (auto &row : content) {
		row.resize(size[X]);
		for (state &item : row)
		{
			item = state::Empty;
		}
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

bool Grid::insertState(state move, unsigned int column, unsigned int row)
{
	if (move == state::Empty)
		return false;
	if (column > size[X] - 1 || row > size[Y] - 1)
		return false;
	if (content[row][column] != state::Empty)
		return false;
	content[row][column] = move;
	numContained++;
	return true;
}

bool Grid::isFull()
{
	return numContained == maxContents;
}

bool Grid::matchRow(state move, unsigned int row)
{
	for (state item : content[row])
	{
		if (move != item) {
			return false;
		}
	}
	return true;
}

bool Grid::matchColumn(state move, unsigned int column)
{
	for (auto row : content)
	{
		if (move != row[column])
		{
			return false;
		}
	}
	return true;
}

bool Grid::matchLeftDiag(state move)
{
	for (int x{}, y{ size[Y] - 1 }; x < size[X] && y >= 0 ; x++, y--)
	{
		auto temp{ content[x][y] };
		if (move != content[x][y])
		{
			return false;
		}
	}
	return true;
}

bool Grid::matchRightDiag(state move)
{
	for (int cell{}; cell < size[Y] && cell < size[X]; cell++)
	{
		if (move != content[cell][cell])
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

void printContentRow(std::vector<state> rowData)
{
	for (unsigned int count{}; count < rowData.size(); count++)
	{
		std::cout << ' ' << symbols[rowData[count]] << ' ';
		if (count < rowData.size() - 1) {
			std::cout << '|';
		}
	}
	std::cout << "\n";
}
