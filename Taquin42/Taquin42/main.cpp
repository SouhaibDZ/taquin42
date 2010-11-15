#include "debug_aff.h"
#include "FileLoader.h"
#include "Puzzle.h"

int main()
{
	FileLoader	F;
	Puzzle		P;
	std::string S;

	F.LoadFile("TaquinA3.txt", S);
	P.CreatePuzzle(S);
	return (0);
}
