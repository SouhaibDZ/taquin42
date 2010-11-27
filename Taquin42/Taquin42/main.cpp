#include "debug_aff.h"
#include "FileLoader.h"
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"

int main()
{
	FileLoader	F;
	Puzzle		P;
	std::string S;
	
	F.LoadFile("TaquinA5.txt", S);
	P.CreatePuzzle(S);
	return (0);
}
