#include "debug_aff.h"
#include "FileLoader.h"
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"
#include "Manhattan.hpp"
#include "Manhattan_Star.hpp"
/*
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
*/

int main()
{
	FileLoader	F;
	std::string S;
	Heuristics* man = new ManhattanStar();

	F.LoadFile("TaquinA3.txt", S);
	Puzzle		P(S, man);
	P.Resolve();
	return (0);
}
