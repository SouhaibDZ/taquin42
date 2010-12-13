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
	bool								operator==(const Puzzle &);

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
	void									AffPuzzle(short unsigned int **) const;
public:
	//std::string &							LookDirection(short unsigned int** PuzzleMap, int& x, int& y, short unsigned int & Node, std::string & Dir);
	//short unsigned int **					UpState(short unsigned int ** PuzzleMap, int & x, int &y);
	//short unsigned int **					RightState(short unsigned int ** PuzzleMap, int & x, int &y);
	//short unsigned int **					DownState(short unsigned int ** PuzzleMap, int & x, int &y);
	//short unsigned int **					LeftState(short unsigned int ** PuzzleMap, int & x, int &y);
	//void									CreatePossiblities(short unsigned int** PuzzleMap, int& x, int& y, short unsigned int & Node, std::string & Dir);
	//void									PrepareLists(FourTabs & BigStruct);

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