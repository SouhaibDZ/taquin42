#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include "SolutionGenerator.hpp"

class										Puzzle
{
public:
	Puzzle();
	~Puzzle();
	Puzzle(const Puzzle &);
	bool									operator==(const Puzzle &);

private:
	Puzzle &								operator=(const Puzzle &);
	
public:
	short unsigned int**					CreatePuzzle(const std::string &);
	static unsigned int						GetScale(void);
	static short unsigned int**				GetSolutionGenerator();
	bool									CanUp() const;
	bool									CanDown() const;
	bool									CanLeft() const;
	bool									CanRight() const;
	void									ExecUp();
	void									ExecDown();
	void									ExecLeft();
	void									ExecRight();
	short unsigned int						GetDistance() const;
	void									AffPuzzle() const;
	void									AffSolution() const;
	void									SetTime(std::string & tmp);
	void									TimeCounter(void);
	void									Show() const;
	void									SetParent(Puzzle& p);

private:
	unsigned int							CountScales(const std::string &) const;
	void									SearchPos(int& x, int& y, short unsigned int & Node);

public:
	void									ManhattanDistance();
	void									ChebyshevDistance();
	void									EuclideanDistance();

public:
	const Puzzle*							Parent;
	short unsigned int **					PuzzleMap;
	short unsigned int						Distance;
	short unsigned int						x0;
	short unsigned int						y0;
	static unsigned int						PuzzleScale;
	static short unsigned int **			SolutionMap;
	short unsigned int						NbMoves;
};

#endif //__PUZZLE_HPP__