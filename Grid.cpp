#include "Grid.h"
#include <iostream>
#include <string>

void printContentRow(std::vector<state> data);

const char symbols[]{
' ','0','X'
};

Grid::Grid()
{
	content.resize(size[Vertical]);
	for (auto &row : content) {
		row.resize(size[Horizontal]);
		for (state &item : row)
		{
			item = state::Empty;
		}
	}
}

void Grid::draw()
{
	for (int height{ size[Vertical] -1}; height >= 0; height--)
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

bool Grid::insertState(state move, const int column, const int row)
{
	if (move == state::Empty)
		return false;
	if (column > size[Vertical] - 1 || row > size[Horizontal] - 1)
		return false;
	if (content[column][row] != state::Empty)
		return false;
	content[column][row] = move;
	return true;
}

void Grid::printLine(bool fill)
{
	std::string filler;
	filler = (fill) ? "___" : "   ";
	std::string line{};
	for (int count{ size[Horizontal] }; count > 0; count--) {
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
		std::cout << ' ';
		std::cout << symbols[rowData[count]];
		std::cout << ' ';
		if (count < rowData.size() - 1) {
			std::cout << '|';
		}
	}
	std::cout << "\n";
}
