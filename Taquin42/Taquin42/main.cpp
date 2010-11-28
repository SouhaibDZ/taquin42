#include "debug_aff.h"
#include "FileLoader.h"
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"

int main()
{
	FileLoader	F;
	std::string S;
	
	F.LoadFile("TaquinA5.txt", S);
	Puzzle		P(S, NULL);

	return (0);
}
