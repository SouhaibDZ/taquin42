#include "debug_aff.h"
#include "FileLoader.h"
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"
#include "Manhattan.hpp"

int main()
{
	FileLoader	F;
	std::string S;
	Heuristics* man = new Manhattan();

	F.LoadFile("TaquinA5.txt", S);
	Puzzle		P(S, man);
	P.Resolve();
	return (0);
}
