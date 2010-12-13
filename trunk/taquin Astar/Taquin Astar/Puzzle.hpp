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
	Puzzle(const Puzzle &);

private:
	Puzzle &								operator=(const Puzzle &);

public:
	short unsigned int**					CreatePuzzle(const std::string &);
	static unsigned int						GetScale(void);
	static short unsigned int**				GetSolutionGenerator();
	bool									CanUp();
	bool									CanDown();
	bool									CanLeft();
	bool									CanRight();
	void									ExecUp();
	void									ExecDown();
	void									ExecLeft();
	void									ExecRight();
	short unsigned int						GetManhattanDistance();
	
private:
	unsigned int							CountScales(const std::string &) const;
	void									SearchPos(int& x, int& y, short unsigned int & Node);
	void									ManhattanDistance();
	

private:
	short unsigned int **					PuzzleMap;
	short unsigned int						Distance;
	short unsigned int						x0;
	short unsigned int						y0;

	static unsigned int						PuzzleScale;
	static short unsigned int **			SolutionMap;
};

#endif //__PUZZLE_HPP__