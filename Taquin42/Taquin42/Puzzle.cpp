#include "Puzzle.h"
#include "SolutionGenerator.h"
#include <sstream>

Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}

void									Puzzle::CreatePuzzle(const std::string & Contents)
{
	std::istringstream						in(Contents);
	int										pos = Contents.find_first_of('\n');
	this->PuzzleScale= this->CountScales(Contents.substr(0, pos));
	SolutionGenerator						Sg(this->PuzzleScale);

	this->PuzzleMap = new int*[this->PuzzleScale];
	for (unsigned int i = 0; i < this->PuzzleScale; ++i)
	{
		this->PuzzleMap[i] = new int[this->PuzzleScale];
		for(unsigned int j = 0; j < this->PuzzleScale; ++j)
		  in >> this->PuzzleMap[i][j];
	}
	// This part was put only for debug
	// It will be deleted at the end of project.
	for (unsigned int i = 0; i < this->PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < this->PuzzleScale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "Puzzle Loaded successfully :)" << std::endl << std::endl;
	std::cout << "##### Solution #####" << std::endl << std::endl;
	Sg.GenerateSolution();
}

void									Puzzle::SetCurrentNodePos(int CurrentNodeName, sPositions sPos)
{
    for (unsigned int i = 0; i < PuzzleScale; ++i)
      {
	    for (unsigned int j = 0; j < PuzzleScale; ++j)
	      {
		if (PuzzleMap[i][j] == CurrentNodeName)
		  {
		    sPos.Node_px = i;
		    sPos.Node_py = j; 
		  }
	      }
     }
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
