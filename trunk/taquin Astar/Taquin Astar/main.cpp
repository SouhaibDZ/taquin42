#include <iostream>
#include "FileLoader.h"
#include <sstream>
#include "Puzzle.hpp"
#include <list>

int main()
{
	FileLoader				F;
	std::string				S;
	Puzzle					P;
	SolutionGenerator		SG;
	short unsigned int**	SolutionMap;
	short unsigned int**	Tab;
	std::list<Puzzle>		OpenedList;
	std::list<Puzzle>		ClosedList;

	F.LoadFile("TaquinA4.txt", S);
	std::istringstream		In(S);
	Tab = P.CreatePuzzle(S);
	SolutionMap = SG.GenerateSolution(P.GetScale());
	std::cout << "Distance de Manhattan du Puzzle: " << P.ManhattanDistance(SolutionMap) << std::endl;

	return (0);
}