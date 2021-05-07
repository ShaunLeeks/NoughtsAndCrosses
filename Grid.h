#pragma once
#include <vector>
#include <memory>
#include <array>

enum orientation { X = 0, Y = 1, };
enum state { Empty = 0, Nought = 1, Cross = 2};

class Grid
{
public:
	Grid();
	std::tuple<int, int> getSize();
	void draw();
	bool insertState(state move, unsigned int column, unsigned int row);
	bool isFull();
	bool matchRow( state move, unsigned int row);
	bool matchColumn(state move, unsigned int column);
	bool matchLeftDiag(state move);
	bool matchRightDiag(state move);

private:	
	const int size [2] {3,3}; // {w,h}
	int numContained{};
	int maxContents;
	std::vector<std::vector<state>> content;

	void printLine(bool fill);
	void printEmptyLine();
	void printHorizontalLine();
};
