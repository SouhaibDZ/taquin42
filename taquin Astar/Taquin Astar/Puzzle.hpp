#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "SolutionGenerator.hpp"

class										Puzzle
{
public:
	Puzzle();
	~Puzzle();

private:
	Puzzle(const Puzzle &);
	Puzzle &								operator=(const Puzzle &);

public:
	short unsigned int**					CreatePuzzle(const std::string &);
	static unsigned int						GetScale(void);
	static short unsigned int**				GetSolutionGenerator();
	int										ManhattanDistance(short unsigned int ** SolutionMap);

private:
	unsigned int							CountScales(const std::string &) const;

private:
	short unsigned int **					PuzzleMap;
	static unsigned int						PuzzleScale;
	static short unsigned int **			SolutionMap;
};

#endif //__PUZZLE_HPP__