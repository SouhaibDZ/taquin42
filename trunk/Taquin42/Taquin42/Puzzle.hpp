#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"
#include "Heuristics.hpp"

class										Puzzle
{
public:
	Puzzle(const std::string&, Heuristics* AlgoResolution);
	~Puzzle();

private:
	Puzzle(const Puzzle &);
	Puzzle &								operator=(const Puzzle &);

public:
	int**									GetMap(void) const;
	void									SetCurrentNodePos(int CurrentNodeName, sPositions& sPos);

private:
	void									CreatePuzzle(const std::string &);
	unsigned int								CountScales(const std::string &) const;
	
private:
	int** 									PuzzleMap;
	unsigned int								PuzzleScale;
	Heuristics*								AlgoResolution;
};

#endif //__PUZZLE_HPP__
