#include "debug_aff.h"
#include "FileLoader.h"

int main()
{
	FileLoader	F;
	std::string S;

	F.LoadFile("TaquinA3.txt", S);
	aff(S.c_str());
	return (0);
}
