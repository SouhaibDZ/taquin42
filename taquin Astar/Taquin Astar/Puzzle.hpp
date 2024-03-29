#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <list>
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
	void									DeletePuzzle();
	void									SetParent(Puzzle& p);
	void									SetAlgo(const char c);
	void									AddTab(Puzzle&);
	void									ClearListTab();
	void									ShowMoves() const;
	void									EraseMap();
	short unsigned int						GetNbMoves() const;


private:
	unsigned int							CountScales(const std::string &) const;
	void									SearchPos(int& x, int& y, short unsigned int & Node);

public:
	void									ManhattanDistance();
	void									TChebyshevDistance();
	void									EuclideanDistance();

private:
	short unsigned int **					PuzzleMap;
	short unsigned int						Distance;
	short unsigned int						x0;
	short unsigned int						y0;
	std::list<short unsigned int **>		ListTab;
	void									(Puzzle::*meth)();

	static unsigned int						PuzzleScale;
	static short unsigned int **			SolutionMap;
};

#endif //__PUZZLE_HPP__