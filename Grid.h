#pragma once
#include <vector>
#include <memory>
#include <array>

enum orientation { Vertical = 0, Horizontal = 1 };
enum state { Empty = 0, Nought = 1, Cross = 2};

class Grid
{
public:
	Grid();
	void draw();
	bool insertState(state move, const int column, const int row);

private:	
	const int size [2] {3,3}; // {h,w}
	void printLine(bool fill);
	void printEmptyLine();
	void printHorizontalLine();
	std::vector<std::vector<state>> content;
};
