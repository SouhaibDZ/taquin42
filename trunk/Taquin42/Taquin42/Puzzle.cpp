#include "Puzzle.h"
#include "SolutionGenerator.h"
#include <sstream>

Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}

void										Puzzle::CreatePuzzle(const std::string & Contents)
{
	std::istringstream						in(Contents);
	int										pos = Contents.find_first_of('\n');
	unsigned int							scale = this->CountScales(Contents.substr(0, pos));
	SolutionGenerator						Sg(scale);

	this->PuzzleMap = new int*[scale];
	for (unsigned int i = 0; i < scale; ++i)
	{
		this->PuzzleMap[i] = new int[scale];
		for(unsigned int j = 0; j < scale; ++j)
		  in >> this->PuzzleMap[i][j];
	}
	// This part was put only for debug
	// It will be deleted at the end of project.
	for (unsigned int i = 0; i < scale; ++i)
	{
		for (unsigned int j = 0; j < scale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "Puzzle Loaded successfully :)" << std::endl << std::endl;
	std::cout << "##### Solution #####" << std::endl << std::endl;
	Sg.GenerateSolution();
}

unsigned int								Puzzle::CountScales(const std::string & Contents) const
{
	unsigned int							max = Contents.size();
	unsigned int							ret = 0;
	char									prev = '0';

	for (unsigned int i = 0; i < max; ++i)
	{
		if (prev != ' ' && Contents.at(i) == ' ')
			ret++;
		prev = Contents.at(i);
	}
	return (ret + 1);
}

int**	const					Puzzle::GetMap(void) const
{
	return (this->PuzzleMap);
}