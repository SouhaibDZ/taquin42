#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"

class										Puzzle
{
public:
	Puzzle();
	~Puzzle();

private:
	Puzzle(const Puzzle &);
	Puzzle &								operator=(const Puzzle &);

public:
	int** const								GetMap(void) const;
	void									CreatePuzzle(const std::string &);
	void									SetCurrentNodePos(int CurrentNodeName, sPositions sPos);
private:
	unsigned int								CountScales(const std::string &) const;
	
private:
	int**									PuzzleMap;
};

#endif //__PUZZLE_HPP__
