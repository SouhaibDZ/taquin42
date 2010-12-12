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
	short unsigned int						ManhattanDistance(short unsigned int ** SolutionMap);
	
private:
	unsigned int							CountScales(const std::string &) const;
	void									SearchPos(short unsigned int** SolutionMap, int& x, int& y, short unsigned int & Node);

private:
	short unsigned int **					PuzzleMap;
	short unsigned int						Distance;
	static unsigned int						PuzzleScale;
	static short unsigned int **			SolutionMap;
};

#endif //__PUZZLE_HPP__