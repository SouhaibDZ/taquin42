#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"
#include "Heuristics.hpp"
#include "SolutionGenerator.hpp"

class										Heuristics;

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
	unsigned int							GetScale(void) const;
	void									SearchCurrentNodePos(int CurrentNodeName, sPositions& sPos) const;

private:
	void									CreatePuzzle(const std::string &);
	unsigned int							CountScales(const std::string &) const;

public:
	void									Resolve();
	const SolutionGenerator*				GetSolutionGenerator() const;
	void									SwapNode(const sPositions& , const sPositions&);
	friend std::ostream&					operator<<(std::ostream&, const Puzzle&);
	
private:
	int** 									PuzzleMap;
	unsigned int							PuzzleScale;
	Heuristics*								AlgoResolution;
	SolutionGenerator*						SolutionPlate;
};

#endif //__PUZZLE_HPP__
